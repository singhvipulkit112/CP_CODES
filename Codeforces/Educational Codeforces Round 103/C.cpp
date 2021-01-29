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
        int n;
        cin>>n;
        vll c(n+1), a(n+1), b(n+1);
        for(int i=1; i<=n; i++)cin>>c[i];
        for(int i = 1; i<=n; i++)cin>>a[i];
        for(int i = 1; i<=n; i++)cin>>b[i];
        ll ans = 0;
        ll prev_mx = c[n];
        for(int i  =n-1; i>=1; i--)
        {
            ll diff = abs(a[i+1]-b[i+1])+1;
            ans=max(ans, diff+prev_mx);
            if(a[i+1]!=b[i+1])
            {
                prev_mx=max(c[i], c[i]-diff+2+prev_mx);
            }
            else
            {
                prev_mx=c[i];
            }            
        }
        cout<<ans<<'\n';
    }
}   
