// AUTHOR -- PULKIT SINGHVI @ps112iitkgp
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
const int N = (int)1e6+1;
const int INF = (int)1e9;
vvi g;
vi jump;
vector<map<int, int>> m;

void dfs(int v)
{
	int sz = (int)g[v].size();
	if(!sz)
	{
		m[v][1]=1;
		jump[v]=v;
	}
	for(int ngh : g[v])
	{
		dfs(ngh);
		if(sz>1)
		{
			for(auto p : m[jump[ngh]])
			{
				if((ll)(p.ff)*sz > (ll)1e6)break;
				m[v][(p.ff)*sz]+=(p.ss);
			}
		}
	}
	if(sz==1)jump[v]=jump[g[v][0]];
	else jump[v]=v;
}

int main()
{
	fastio
	int n;cin>>n;
	g.resize(n+1);
	m.resize(n+1);
	jump.resize(n+1);
	for(int i=2; i<=n; i++)
	{
		int p;cin>>p;
		g[p].pb(i);
	}
	dfs(1);
	int q;
	cin>>q;
	while(q--)
	{
		int v, w;
		cin>>v>>w;
		int ans = w;
		for(auto p : m[jump[v]])
		{
			int div = (p.ff);
			if(w%div)continue;
			ans-=((w/div) * (p.ss));
		}
		cout<<ans<<'\n';
	}
}   
