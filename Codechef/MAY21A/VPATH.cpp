
// AUTHOR -- PULKIT SINGHVI @ps112iitkgp
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

#define ff first
#define ss second
#define pb push_back
#define test() int t;cin>>t;while(t--) 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mod = (int)1e9+7;

vvi g;

int mul(int a, int b)
{
    return((a*1LL*b)%mod);
}

void add(int& a, int b)
{
    a+=b;
    if(a>=mod)a-=mod;
}

pii dfs(int v, int p)
{
	int straight_ans = 0;
	int curved_ans   = 0;
	for(int child : g[v])
	{
		if(child!=p)
		{
			pii child_ans    = dfs(child, v);
			add(curved_ans   , child_ans.ss);
			add(straight_ans , child_ans.ff);
			add(curved_ans   , mod-mul(child_ans.ff, child_ans.ff));
		}
	}
	add(curved_ans  , mul(straight_ans, straight_ans));
	add(straight_ans, straight_ans);
	add(straight_ans, 1);	
	pii ans = {straight_ans, curved_ans};
	return(ans);
}

int main()
{
	fastio
	test()
	{
		g.clear();
		int n; cin>>n;
		g.resize(n+1);
		for(int i=0; i<n-1; i++)
		{
			int u, v; cin>>u>>v;
			g[u].pb(v);
			g[v].pb(u);
		}
		pii ans = dfs(1, 0);
		int answer = ans.ff;
		add(answer, ans.ss);
		cout<<answer<<'\n';
	}	
} 
