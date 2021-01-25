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
const int mod =  (int)1e9+7;
const int INF = (int)1e9;
const int N = (int)1e6+1;
void add(int& a, int b)
{
    a+=b;
    if(a>=mod)a-=mod;
}
int mul(int a, int b)
{
    return((a*1LL*b)%mod);
}
int power(int x, int a)
{
    if(a==0)return(1);
    int z = power(x, a/2);
    z=mul(z, z);
    if(a%2)z=mul(z, x);
    return(z);
}
int main()
{
    fastio
    test()
    {
        int n;
        cin>>n;
        vi arr(n);
        vi freq(n+1);
        for(int i=0; i<n; i++)
        {
            int x;
            cin>>x;
            arr[i]=x;
            freq[x]++;
        }
        int no = 0;
        for(no = 0; no<=n; no++)
        {
            if(!freq[no])break;
        }
        if(no==0)
        {
            cout<<power(2, n-1)<<'\n'; //All possible partitions of an array are feasible
        }
        else
        {
            vi dp(n+1);
            dp[0]=1;
            vi last_idx(n+1, -1);
            map<int, int> m;
            int i;
            int dist = 0;
            for(i = 1; i<=n; i++)
            {
                if(arr[i-1]<no)
                {
                    if(m.find(arr[i-1])==m.end())dist++; 
                    m[arr[i-1]]++;
                    if(dist==no)break;
                }
                dp[i]=1;
            }
            last_idx[i]=1;
            for(int idx = i+1; idx<=n; idx++)
            {
                if(arr[idx-1]<no)m[arr[idx-1]]++;
                int j = last_idx[idx-1];
                while(arr[j-1]>no || m[arr[j-1]]!=1)
                {
                    if(arr[j-1]<no)m[arr[j-1]]--;
                    j++;
                }
                last_idx[idx]=j;
            }
            int ans;
            for(int idx = i; idx<=n; idx++)
            {
                dp[idx]=dp[last_idx[idx]-1];                
                if(idx==n)ans=dp[idx];
                add(dp[idx], dp[idx-1]);
            }
            cout<<ans<<'\n';            
        }
    }
}   
