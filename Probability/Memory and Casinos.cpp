#include <bits/stdc++.h>
using namespace std;
 
typedef vector<int> vi;
typedef pair<double, double> pdd;
typedef vector<pdd> vpdd;
 
#define test() int t;cin>>t;while(t--) 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ff first
#define ss second

const int mod = (int)1e9+7;
const int N = (int)1e5+1;

struct SegTree 
{
	// 1-Based
	int n;
	vpdd Tree;
	void init(int sz)
	{
		n = sz;
		Tree.resize(2*n+2);
	}
	pdd merge(pdd p1, pdd p2)
	{
		pdd p3;

		p3.ff = ((p1.ff)*(p2.ff))/(1+((p2.ff-1.0)*(p1.ss)));
		p3.ss = (p2.ss) + (((p1.ss)*(p2.ff)*(1.0-p2.ss))/(1+((p2.ff-1.0)*(p1.ss))));

		return(p3);
	}
	void set(int k, double x) 
	{
		k+=n;
		Tree[k].ff = x;
		Tree[k].ss = x;
		for(k=k/2;k>=1;k/=2)
		{
			Tree[k]=merge(Tree[2*k], Tree[2*k+1]);
		}
	}
	double query(int a, int b)
	{
		a+=n;b+=n;
		pdd left, right;
		left.ff  = 1.0; left.ss  = 0.0;
		right.ff = 1.0; right.ss = 0.0;

		while(a<=b)
		{
			if(a&1)    left  = merge(left , Tree[a++]);
			if(!(b&1)) right = merge(Tree[b--], right);
			a/=2;b/=2;
		}

		pdd ans = merge(left, right);
		return(ans.ff);
	}
};

int main()
{
	fastio
	cout<<setprecision(9);

	int n, q; cin>>n>>q;

	SegTree data;
	data.init(n);

	for(int i=1; i<=n; i++)
	{
		double a, b;
		cin>>a>>b;
		data.set(i, a/b);
	}

	for(int i=0; i<q; i++)
	{
		int type; cin>>type;
		if(type == 1)
		{
			int i;
			double a, b;
			cin>>i>>a>>b;
			data.set(i, a/b);
		}
		else
		{
			int l, r;
			cin>>l>>r;
			cout<<data.query(l, r)<<'\n';
		}		
	}	
}
