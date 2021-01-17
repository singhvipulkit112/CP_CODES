//AUTHOR -- PULKIT SINGHVI @ps112iitkgp
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
const int INF = (int)1e9;

int main()
{
    test()
    {
        int n;
        cin>>n;
        vvi arr(n);
        map<int, int> m;
        ll ans = 0;
        for(int i  =0; i<n; i++)
        {
            int k;
            cin>>k;
            for(int j = 0; j<k; j++)
            {
                int x;
                cin>>x;
                m[abs(x)]++;
                arr[i].pb(x);                
            }
        }
        for(int i = 0; i<n; i++)
        {
            int k = (int)arr[i].size();
            int pos = 0;
            vi pfx_sm(k);
            for(int j=k-1; j>=0; j--)
            {
                if(arr[i][j]>0)
                {
                    if(m[arr[i][j]]>1)
                    {
                        ans+=(k-1-j);
                        pfx_sm[j]++;                        
                    }
                    pos++;
                }
                else
                {
                    if(m[-arr[i][j]]>1)
                    {
                        ans+=j;
                    }
                }                
            }
            for(int j = k-pos; j<k; j++)if(j>0)pfx_sm[j]+=pfx_sm[j-1];
            for(int j = 0; j<k-pos; j++)
            {
                int idx = lower_bound(arr[i].begin(), arr[i].end(), (-arr[i][j]))-arr[i].begin()-1;
                if(m[(-arr[i][j])]<=1)
                {
                    ans+=(pos-pfx_sm[idx]);
                }
                else
                {
                    ans+=(idx+pos-k-pfx_sm[idx]+1);
                }                   
            }            
        }
        for(auto p : m)
        {
            if(p.ss>1)ans++;
        }
        cout<<ans<<endl;
    }    
}   
