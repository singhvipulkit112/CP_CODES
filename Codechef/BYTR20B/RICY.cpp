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
        vi arr(n+1);
        vi b(m+1);
        for(int i = 1; i<=n; i++)
        {
            cin>>arr[i];            
        }
        for(int i = 1; i<=m; i++)cin>>b[i];
        vi left(n+1, 0);
        vi right(n+1, n+1);
        stack<int> s;
        for(int i = 1; i<=n; i++)
        {
            while(!s.empty() && arr[s.top()]>arr[i])
            {
                right[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        stack<int> q;
        for(int i = n; i>=1; i--)
        {
            while(!q.empty() && arr[q.top()]>arr[i])
            {
                left[q.top()]=i;
                q.pop();
            }
            q.push(i);
        }
        ll ans = 0;
        for(int i = 1; i<=n; i++)
        {
            int l = left[i], r = right[i];            
            int rf = lower_bound(b.begin(), b.end(), i)-b.begin();
            int rs = lower_bound(b.begin(), b.end(), right[i])-b.begin()-1;
            int lf = rf-1;
            int ls = upper_bound(b.begin(), b.end(), left[i])-b.begin();
            ans+=((ll)arr[i]*((ll)(rs-rf+1))*(lf-ls+1));   
            if(b[rf]==i)ans+=((ll)arr[i]*(max(0, rs-rf)));         
        }
        for(int i  =1; i<=m; i++)ans+=(arr[b[i]]);        
        cout<<ans<<endl;
    }
}   
