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
const int mod = 998244353;
const int N = (int)2e6+3;
vi visited;
void add(int &a, int b)
{
    a+=b;
    if(a>=mod)a-=mod;
}
int mul(int a, int b)
{
    return((a*1LL*b)%mod);
}
void dfs(int v, vvi& g, vi& cnt, vi& color)
{
    visited[v]=1;
    cnt[color[v]]++;
    for(int ngh : g[v])
    {
        if(!visited[ngh])dfs(ngh, g, cnt, color);
    }
}
int main()
{
    fastio
    test()
    {
        int n, k;
        cin>>n>>k;
        vi color(n+1);
        for(int i = 1; i<=n; i++)cin>>color[i];
        vvi g(n+1);
        visited.clear();
        visited.resize(n+1);
        for(int i = 0; i<n-1; i++)
        {
            int u, v;
            cin>>u>>v;
            if(color[u] && color[v])
            {
                g[u].pb(v);
                g[v].pb(u);
            }
        }
        vi cnt(k+1);
        vi dp((1<<k));
        dp[0]=1;
        for(int  i =1; i<=n; i++)
        {
            if(!visited[i])
            {
                fill(cnt.begin(), cnt.end(), 0);
                dfs(i, g, cnt, color);
                vi new_dp((1<<k));
                for(int sel = 0; sel<k; sel++)
                {
                    if(cnt[sel+1])
                    {
                        for(int j = 0; j<(1<<k); j++)
                        {
                            if(!((1<<sel)&j))
                            {
                                add(new_dp[j|(1<<sel)], mul(dp[j], cnt[sel+1]));
                            }                            
                        }
                    }
                }
                for(int j = 0; j<(1<<k); j++)add(new_dp[j], dp[j]);
                dp=new_dp;
            }
        }
        cout<<dp[(1<<k)-1]<<endl;
    }
}   
