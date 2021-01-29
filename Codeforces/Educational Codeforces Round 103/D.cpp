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
        int n;cin>>n;
        string s;cin>>s;
        vi ans(n+1, 1);
        int prev_l = 0, prev_r = 0;        
        for(int i = n-1; i>=0; i--)
        {
            if(s[i]=='R')
            {
                ans[i]+=(1+prev_l);
                prev_r=1+prev_l;
                prev_l=0;
            }
            else
            {
                prev_l=1+prev_r;
                prev_r=0;
            }
        }
        prev_l = 0; prev_r = 0;
        if(s[0]=='L')prev_l++;
        else prev_r++;
        for(int i = 1; i<=n; i++)
        {
            if(s[i-1]=='L')
            {
                ans[i]+=prev_l;    
            }
            if(i<n)
            {
                if(s[i]=='R')
                {
                    prev_r=1+prev_l;
                    prev_l=0;
                }
                else
                {
                    prev_l=1+prev_r;
                    prev_r=0;
                }                
            }
        }
        for(int i = 0; i<=n; i++)cout<<ans[i]<<' ';
        cout<<'\n';
    }
}   
