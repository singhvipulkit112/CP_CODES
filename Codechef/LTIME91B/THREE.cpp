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
        string s;
        cin>>s;
        vi cnt(26);
        for(char c : s)cnt[c-'a']++;
        int ans = 0;
        int cnt2 = 0, cnt1 = 0;
        for(int i = 0; i<26; i++)
        {
            cnt2+=(cnt[i]/2);
            cnt1+=(cnt[i]%2);
        }
        int mn = min(cnt1, cnt2);
        ans+=mn;
        cnt2-=mn;
        ans+=((2*cnt2)/3);
        cout<<ans<<endl;
    }
}   
