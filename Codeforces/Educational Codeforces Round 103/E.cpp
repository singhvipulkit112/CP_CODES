// AUTHOR -- PULKIT SINGHVI @ps_112
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

vvi g;
vi ans, temp, visited;

// -->TOPOLOGICAL SORT<--

bool dfs(int v)
{
    if(temp[v])return(true); // Checking for cycle
    temp[v]=1;
    for(int ngh : g[v])
    {
        if(!visited[ngh])
        {
            if(dfs(ngh))return(true);
        }
    }
    temp[v]=0;
    visited[v]=1;
    ans.pb(v+1);
    return(false);
}

int main()
{
    fastio
    int n, m, k;
    cin>>n>>m>>k;
    map<string, int> store;    
    for(int i = 0; i<n; i++)
    {
        string s;
        cin>>s;
        store[s]=i;       
    }
    g.resize(n);
    temp.resize(n);
    visited.resize(n);
    bool flag = false;
    for(int i = 0; i<m; i++)
    {
        string s;int mt; 
        cin>>s>>mt;mt--;
        bool check = true;
        for(int mask = 0; mask<(1<<k); mask++)      // Iterating over all possible patterns that match string s
        {
            string p = s;
            for(int b = 0; b<k; b++)
            {
                if(mask&(1<<b))p[b]='_';
            }
            if(store.find(p)!=store.end())
            {
                if(store[p]==mt)check=false;
                else g[mt].pb(store[p]);            // Directed edge from index mt to index store[p] signifying pattern[mt] appears before pattern[store[p]]
            }
        }
        if(check)flag=true;                         // Pattern[mt] doesn't match string s, return(NO)      
    }
    if(flag)cout<<"NO"<<'\n';
    else
    {
        for(int v = 0; v<n; v++)
        {
            if(!visited[v])
            {
                if(dfs(v))
                {
                    cout<<"NO"<<'\n';              // Cycle found, return(NO)
                    return(0);
                }
            }
        }
        reverse(ans.begin(), ans.end());
        cout<<"YES"<<'\n';
        for(int x : ans)cout<<x<<' ';
        cout<<'\n';
    }    
}   
