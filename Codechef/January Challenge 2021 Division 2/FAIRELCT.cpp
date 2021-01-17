//AUTHOR PULKIT SINGHVI @ps112iitkgp
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
        int n, m;
        cin>>n>>m;
        int sm_john = 0;
        int sm_jack = 0;
        vi john(n), jack(m);
        for(int i = 0; i<n; i++)
        {
            cin>>john[i];
            sm_john+=john[i];
        }
        for(int j  =0; j<m; j++)
        {
            cin>>jack[j];
            sm_jack+=jack[j];            
        }
        sort(all(john));
        sort(all(jack), greater<int>());
        int ans = 0;
        bool flag = true;        
        for(int i = 0; i<min(n, m); i++)
        {
            if(sm_john-sm_jack>0)
            {
                flag=false;
                cout<<ans<<endl;
                break;
            }
            ans++;
            sm_john+=(jack[i]-john[i]);
            sm_jack-=(jack[i]-john[i]);
        }
        if(flag && (sm_john-sm_jack>0))
        {
            flag=false;
            cout<<ans<<endl;
        }
        if(flag)cout<<-1<<endl;
    }
}   
