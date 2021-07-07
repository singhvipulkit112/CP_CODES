#include <bits/stdc++.h>
using namespace std;
 
typedef vector<int> vi;
typedef pair<double, double> pdd;
typedef vector<pdd> vpdd;
 
#define test() int t;cin>>t;while(t--) 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ff first
#define ss second

struct SegTree 
{
	// 1-Based
	int n;
	vpdd Tree;
	void init(int sz)
	{
		n = sz;
		Tree.resize(2*n+2);

		Tree[2*n+1].ff = 1.0;
		Tree[2*n+1].ss = 0.0;

		if(!(n&2))
		{
			Tree[n+1].ff = 1.0;
			Tree[n+1].ss = 0.0;
		}
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
	pdd query(int v, int il, int ih, int l, int r)
	{
		if(l>r)
		{
			pdd ans;
			ans.ff = 1.0;
			ans.ss = 0.0;
			return(ans);
		}
		if(il == l && ih == r)return(Tree[v]);

		int im = (il+ih)/2;
		return(merge(query(2*v, il, im, l, min(r, im)), query(2*v+1, im+1, ih, max(l, im+1), r)));
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
			cout<<((data.query(1, 1, n, l, r)).ff)<<'\n';
		}		
	}
}
