// AUTHOR PULKIT SINGHVI @ps112iitkgp
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

bool check(int idx, vi& pfx_sm, int k)
{
    bool flag = false;
    for(int i = 1; i<=idx-1; i++)
    {
        if(pfx_sm[i]>=k && pfx_sm[idx]-pfx_sm[i]>=k)
        {
            flag=true;
            break;
        }
    }
    return(flag);
}

int main()
{
    test()
    {
        int n, k;
        cin>>n>>k;
        vi arr(n+1);
        for(int i = 1; i<=n; i++)cin>>arr[i];
        sort(1+all(arr), greater<int>());
        if(arr[1]>=k)
        {
            int sm = 0, i;
            for(i = 2; i<=n; i++)
            {
                sm+=arr[i];
                if(sm>=k)break;
            }
            if(i!=n+1)cout<<i<<endl;
            else cout<<-1<<endl;
            continue;
        }
        vi dp(k);
        dp[0]=1;
        int sm = arr[1];
        int i;
        for(i =2; i<=n; i++)
        {
            bool flag = false;
            for(int val = k-1; val>=0; val--)
            {
                if(dp[val])
                {
                    int small = val;
                    int greater = sm-val;
                    int new_small = val+arr[i];
                    int mn = min(new_small, greater);
                    if(mn>=k)
                    {
                        flag=true;
                        break;
                    }
                    dp[mn]=1;
                }
            }
            if(flag)break;
            sm+=arr[i];
        }
        if(i==n+1)cout<<-1<<endl;
        else cout<<i<<endl;
    }
}   
