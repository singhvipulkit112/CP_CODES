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
        int n;
        cin>>n;
        string s, p;
        cin>>s;
        cin>>p;
        int cnt = 0;
        bool flag = true;
        for(int i = 0; i<n; i++)
        {
            if(s[i]!=p[i])
            {
                if(s[i]=='1')cnt++;
                else cnt--;
            }
            if(cnt<0)
            {
                flag=false;
                break;
            }
        }
        if(flag && !cnt)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}   
