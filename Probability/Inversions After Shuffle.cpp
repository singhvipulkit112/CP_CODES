#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

struct SegTree 
{
	// 1-Based
	int n;
	vector<ll> Tree;
	void init(int sz)
	{
		n = sz;
		Tree.resize(4*n);
	}
	void set(int k, ll x) 
	{
		k+=n;
		Tree[k]=x;
		for(k=k/2;k>=1;k/=2)
		{
			Tree[k]=Tree[2*k]+Tree[2*k+1];
		}
	}
	ll sum(int a, int b)
	{
		a+=n;b+=n;
		ll s=0;
		while(a<=b)
		{
			if(a%2==1) s+=Tree[a++];
			if(b%2==0) s+=Tree[b--];
			a/=2;b/=2;
		}
		return s;
	}
};

int main()
{
	fastio
	int n;cin>>n;

	vi arr(n+1);
	SegTree count_fixed_inv_tree;
	SegTree subseq_inv_sum_tree;
	count_fixed_inv_tree.init(n);
	subseq_inv_sum_tree.init(n);

	for(int i=1; i<=n; i++)cin>>arr[i];

	double ans = 0.0, diff_sum = 0.0;

	ll subseq_inv_sum = 0;									  // at index i, its value is (summation r = i to n) of (count_of_inv[subseq(i, r)])
	ll exp_inv_subseq_sum = 0;                                // at index i , its value is (summation k = 1 to n-i+1) of (k*(k-1))

	for(int i = n; i>0; i--)
	{
		ans += (1.0 * count_fixed_inv_tree.sum(1, arr[i]-1));  // adding total js for which (i, j) is an inversion in the original permutation

		count_fixed_inv_tree.set(arr[i], 1);
		subseq_inv_sum_tree.set(arr[i], n-i+1);

		exp_inv_subseq_sum += ((n-i+1) * 1LL * (n-i));

		subseq_inv_sum += subseq_inv_sum_tree.sum(1, arr[i]-1);

		diff_sum += (1.0 * exp_inv_subseq_sum)/4;
		diff_sum -= (1.0 * subseq_inv_sum);
	}
	
	ans += (2.0 * diff_sum)/(n * 1LL * (n+1));
	cout<<setprecision(16)<<ans<<'\n';
}
