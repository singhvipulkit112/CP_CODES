
// AUTHOR -- PULKIT SINGHVI @ps112iitkgp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
typedef vector<int> vi;
typedef vector<vi> vvi;

#define pb push_back
#define all(v) v.begin(),v.end()
#define test() int t;cin>>t;while(t--) 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF (int)1e9;

vi winners, dp;
vvi g;

void dfs1(int v, int p)
{
	// Leaf Node
	if((int)g[v].size() == 1 && g[v][0]==p)return;

	int min_time_child = INF;

	for(int ngh : g[v])
	{
		if(ngh != p)
		{
			dfs1(ngh, v);
			min_time_child = min(min_time_child, dp[ngh]);
		}
	}

	bool check = true;

	for(int ngh : g[v])
	{
		if(ngh != p)check = check & (min_time_child == dp[ngh]);		
	}

	// All assassins reach at the same time
	if(check)dp[v] = min_time_child + 1 ;
	// The first one to reach gets killed by others	
	else     dp[v] = min_time_child + 2 ;
}

void dfs2(int v, int p)
{
	// This assassin will get the reward
	if((int)g[v].size() == 1 && g[v][0]==p)
	{
		winners.pb(v);
		return;
	}

	int min_time_child = INF;

	for(int ngh : g[v])
	{
		if(ngh != p) min_time_child = min(min_time_child, dp[ngh]);		
	}

	bool flag = (dp[v] == min_time_child + 1);	

	for(int ngh : g[v])
	{
		if(ngh != p)
		{
			if(flag || (dp[ngh] != min_time_child))dfs2(ngh, v);
		}
	}
}

int main()
{
	fastio
	test()
	{
		int n; cin>>n;
		winners.clear();
		g.clear(); g.resize(n+1);
		dp.clear(); dp.resize(n+1);
		for(int i=0; i<n-1; i++)
		{
			int u, v;
			cin>>u>>v;
			g[u].pb(v);
			g[v].pb(u);
		}
		dfs1(1, 0);
		dfs2(1, 0);
		sort(all(winners));
		cout<<winners.size()<<' '<<dp[1]<<'\n';
		for(int x : winners)cout<<x<<' ';
		cout<<'\n';
	}	
} 
