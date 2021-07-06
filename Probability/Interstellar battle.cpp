#include <bits/stdc++.h>
using namespace std;
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
 
#define all(v) v.begin(),v.end()
#define test() int t;cin>>t;while(t--) 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back

vvi g;
vd prob;
vd sm_child_prob;
vi parent;
double ans = 0.0;

void dfs(int v, int p)
{
	parent[v] = p;
	ans += prob[v];

	for(int c : g[v])
	{
		if(c!=p)
		{
			sm_child_prob[v] += prob[c];
			dfs(c, v);
		}
	}

	ans -= prob[v]*sm_child_prob[v]; 
}

int main()
{
	fastio
	int n;cin>>n;

	g.resize(n+1);
	parent.resize(n+1);
	prob.resize(n+1);
	sm_child_prob.resize(n+1);

	for(int i=1; i<=n; i++)
	{
		cin>>prob[i];
		prob[i] = 1.0 - prob[i];
	}
	
	for(int i=0; i<n-1; i++)
	{
		int u, v;
		cin>>u>>v;
		u++; v++;
		g[u].pb(v);
		g[v].pb(u);
	}
	
	dfs(1, 0);
	
	int q;cin>>q;
	for(int i=0; i<q; i++)
	{
		int planet;
		double new_prob;
		cin>>planet>>new_prob;
		planet++;
		new_prob = 1.0 - new_prob;

		ans +=  (new_prob - prob[planet])*(1.0-sm_child_prob[planet] - prob[parent[planet]]);

		sm_child_prob[parent[planet]] += new_prob - prob[planet];
		prob[planet] = new_prob;

		cout<<setprecision(9)<<ans<<'\n';
	}
}
