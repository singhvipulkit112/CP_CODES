#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

#define all(v) v.begin(),v.end()
#define test() int t;cin>>t;while(t--) 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ff first
#define ss second
#define pb push_back

const int mod = (int)1e9+7;

int ans;
vvi g;
vi cnt;

int mul(int a, int b)
{
    return((a*1LL*b)%mod);
}

void add(int& a, int b)
{
    a+=b;
    if(a>=mod)a-=mod;
}

void calculate(int t, int k)
{
	vvi dp(t+1, vi(k+1));
	dp[0][0] = 1;

	for(int tree_no = 1; tree_no <= t; tree_no++)
	{
		dp[tree_no][0] = 1;
		for(int sel = 1; sel <=k; sel++)
		{
			add(dp[tree_no][sel], dp[tree_no-1][sel]);
			add(dp[tree_no][sel], mul(dp[tree_no-1][sel-1], cnt[tree_no]));
		}
	}
	add(ans, dp[t][k]);
}

int main()
{
	fastio
	test()
	{
		int n, k; cin>>n>>k;
		g.clear();
		g.resize(n);
		ans = 0;

		for(int i=0; i<n-1; i++)
		{
			int u, v;
			cin>>u>>v;
			g[--u].pb(--v);
			g[v].pb(u);
		}

		if(k==2)
		{
			if(n&1)cout<<mul(n, (n-1)/2)<<'\n';
			else cout<<mul(n/2, n-1)<<'\n';

			continue;
		}

		for(int i = 0; i<n; i++)
		{

			int t = g[i].size();

			vi visited(n);			
			cnt.resize(t+1);
			vpii layer;

			visited[i]=1;

			for(int j = 0; j<t; j++)
			{			
				layer.pb(make_pair(g[i][j], j+1));
				cnt[j+1] = 1;
				visited[g[i][j]] = 1;
			}			

			while(!layer.empty())
			{
				calculate(t, k);
				vpii new_layer;
				
				while(!layer.empty())
				{
					int v       = (layer.back()).ff;
					int tree_no = (layer.back()).ss;
					layer.pop_back();
					cnt[tree_no]--;

					for(int child : g[v])
					{
						if(!visited[child])
						{
							visited[child] = 1;
							new_layer.pb(make_pair(child, tree_no));
							cnt[tree_no]++;
						}
					}
				}

				layer = new_layer;
			}	
		}

		cout<<ans<<'\n';
	}
}
