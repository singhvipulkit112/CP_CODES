
// AUTHOR -- PULKIT SINGHVI @ps112iitkgp
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;

#define pb push_back
#define all(v) v.begin(),v.end()
#define test() int t;cin>>t;while(t--) 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mod = (int)1e9+7;

vvi g;

int mul(int a, int b)
{
    return((a*1LL*b)%mod);
}

ll dfs(int v, int p)
{
	vll store_child_ans;
	for(int child : g[v])
	{
		if(child!=p)
		{
			store_child_ans.pb(dfs(child, v));
		}
	}	
	sort(all(store_child_ans));
	ll ans = 0;
	int sze = (int)store_child_ans.size();
	for(int i = 1; i<=sze; i++)
	{
		ans+=(store_child_ans[sze-i]*i);
	}
	ans+=1;
	return(ans);
}

int main()
{
	fastio
	test()
	{
		g.clear();
		int n, x; cin>>n>>x;
		g.resize(n+1);
		for(int i=0; i<n-1; i++)
		{
			int u, v; cin>>u>>v;
			g[u].pb(v);
			g[v].pb(u);
		}
		cout<<mul((dfs(1, 0)%mod), x)<<'\n';
	}	
} 
