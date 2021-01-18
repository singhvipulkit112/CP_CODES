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
const int mod = (int)1e9+7;
const int N = (int)2e6+3;

int main()
{
    fastio
    test()
    {
        int n, m;
        cin>>n>>m;
        vector<map<int, int>> store(n+m-1);
        vvi grid(n, vi(m));
        int bad = 0;
        vector<bool> check(m+n-1, true);
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                int x;
                cin>>x;
                grid[i][j]=x;
                if(check[i-j+m-1] && i-1>=0 && j-1>=0 && grid[i][j]!=grid[i-1][j-1])
                {
                    bad++;
                    check[i-j+m-1]=false;
                }
                store[i-j+m-1][x]++;
            }
        }
        int q;
        cin>>q;
        for(int i = 0; i<q; i++)
        {
            int x, y, v;
            cin>>x>>y>>v;
            x--;y--;            
            if(store[x-y+m-1][grid[x][y]]==1)            
                store[x-y+m-1].erase(grid[x][y]);
            else store[x-y+m-1][grid[x][y]]--;
            store[x-y+m-1][v]++;
            grid[x][y]=v;            
            int sz = (int)store[x-y+m-1].size();
            if(sz==1 && !check[x-y+m-1])
            {
                check[x-y+m-1]=true;
                bad--;
            }
            if(sz>1 && check[x-y+m-1])
            {
                check[x-y+m-1]=false;
                bad++;
            }
            if(!bad)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
}   
