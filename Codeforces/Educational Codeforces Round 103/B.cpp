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

int main()
{
    fastio
    test()
    {
        int n, k;
        cin>>n>>k;
        ll p0;
        cin>>p0;
        ll sm = p0;
        ll ans = 0;
        for(int i = 1; i<n; i++)
        {
            ll p;
            cin>>p;
            if(p*100>sm*k)
            {
                ll diff = p*100-sm*k;                
                ll to_add = diff/k;
                if(diff%k)to_add++;
                ans+=to_add;
                sm+=to_add;
            }
            sm+=p;
        }
        cout<<ans<<'\n';
    }
}   
