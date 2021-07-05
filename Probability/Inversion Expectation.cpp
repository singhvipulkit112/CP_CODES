#include <bits/stdc++.h>
using namespace std; 

typedef vector<int> vi;
 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mod = 998244353;

struct SegTree 
{
	// 1-Based
	int n;
	vector<int> Tree;
	void init(int sz)
	{
		n = sz;
		Tree.resize(4*n);
	}
	void set(int k, int x) 
	{
		k+=n;
		Tree[k]=x;
		for(k=k/2;k>=1;k/=2)
		{
			Tree[k]=Tree[2*k]+Tree[2*k+1];
		}
	}
	int sum(int a, int b)
	{
		a+=n;b+=n;
		int s=0;
		while(a<=b)
		{
			if(a%2==1) s+=Tree[a++];
			if(b%2==0) s+=Tree[b--];
			a/=2;b/=2;
		}
		return s;
	}
};

int mul(int a, int b)
{
    return((a*1LL*b)%mod);
}

int power(int x, int a)
{
    if(a==0)return(1);
    int z = power(x, a/2);
    z=mul(z, z);
    if(a%2)z=mul(z, x);
    return(z);
}

void add(int& a, int b)
{
    a+=b;
    if(a>=mod)a-=mod;
}

int main()
{
	fastio
        
	int n;cin>>n;

    // pfx_sm[i] is the total elements present in the array <= i
	vi arr(n+1), pfx_sm(n+1, 1);
	SegTree count_fixed_inv_tree;
	count_fixed_inv_tree.init(n);
	int total_missing = 0;

	for(int i=1; i<=n; i++)
	{
		cin>>arr[i];
		if(arr[i] == -1)total_missing++;
		else pfx_sm[arr[i]]=0;
	}

	pfx_sm[0]=0;
	for(int i=1; i<=n; i++)
	{
		pfx_sm[i]+=pfx_sm[i-1];
	}

	//Exp. value of inversions in a permutation of missing numbers  --   (cnt[-1]*(cnt[-1]-1))/4
	int ans = mul(total_missing, mul(total_missing-1, power(4, mod-2))); 

	int missing_till_now = 0;
	int mod_inv_total_missing = power(total_missing, mod-2);

	for(int i = n; i>0; i--)
	{
		if(arr[i]==-1)
		{
			missing_till_now++;
			continue;
		}

		// adding fixed inversions
		add(ans, count_fixed_inv_tree.sum(1, arr[i]-1));
		count_fixed_inv_tree.set(arr[i], 1);

		// adding exp. value of inversions with missing numbers after index i  --  ((total_missing_num < arr[i]) * (cnt[-1] after index i)) / (cnt[-1])
		add(ans, mul(pfx_sm[arr[i]-1], mul(missing_till_now, mod_inv_total_missing)));

		// adding exp. value of inversions with missing numbers before index i  -- ((total_missing_num > arr[i]) * (cnt[-1] before index i)) / (cnt[-1])
		add(ans, mul(pfx_sm[n]-pfx_sm[arr[i]], mul(total_missing-missing_till_now, mod_inv_total_missing)));
	}
	cout<<ans<<'\n';
}
