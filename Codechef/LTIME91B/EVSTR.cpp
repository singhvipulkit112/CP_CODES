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
const int INF = (int)1e9;
int main()
{
    fastio
    test()
    {
        int n;
        cin>>n;
        int x;
        cin>>x;
        int mx_len = 0;
        vi dp(n+1, -INF);
        dp[x]=1;
        for(int i = 1; i<n; i++)
        {
            cin>>x;
            int len = dp[x];
            dp[x]=max(len, mx_len+1);
            mx_len=max(mx_len, len+1);
        }
        cout<<n-mx_len<<endl;
    }
}   
