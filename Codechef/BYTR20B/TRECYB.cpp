// AUTHOR -- PULKIT SINGHVI @ ps112iitkgp
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<ll> vll;
 
#define all(v) v.begin(),v.end()
#define test() int t;cin>>t;while(t--) 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ff first
#define ss second
#define pb push_back
const int mod = (int)1e9+7;
const int N = (int)2e6+3;
vvi g;
vvi level;
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
void dfs(int v, int p, int lev)
{
    lev++;
    level[lev].pb(v);
    for(int ngh : g[v])
    {
        if(ngh!=p)dfs(ngh, v, lev);
    }
}
int main()
{
    fastio
    int n;
    cin>>n;
    g.resize(n+1);
    level.resize(n+1);
    for(int i = 0; i<n-1; i++)
    {
        int u, v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, 0, 0);
    SegTree node;
    node.init(n);
    ll ans = 0;    
    for(int lev = n; lev>=1; lev--)
    {
        for(int x : level[lev])
        {
            ans-=(node.sum(1, x-1));
            ans+=(node.sum(x+1, n));
        }
        for(int x : level[lev])node.set(x, 1);
    }
    cout<<ans<<endl;
}   
