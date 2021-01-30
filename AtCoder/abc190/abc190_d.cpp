// AUTHOR -- PULKIT SINGHVI @ps112
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
const int mod =  (int)1e9+7;
const int INF = (int)1e9;
const int N = (int)2e5+1;

int main()
{
    fastio
    ll n;cin>>n;
    n*=2;
    ll ans = 0;
    
    // Sum of AP = n/2(2A+(n-1)) = N
    // n should be a factor of 2N and (2N/n - (n-1)) should be even
    
    for(ll i = 1; i*i<=n; i++)
    {
        if(n%i==0)
        {
            ll check = n/i-(i-1);
            if(check%2==0)ans++;
            if(n/i != i)
            {
                check = i-((n/i)-1);
                if(check%2==0)ans++;
            }
        }
    }
    cout<<ans<<'\n';
}   
