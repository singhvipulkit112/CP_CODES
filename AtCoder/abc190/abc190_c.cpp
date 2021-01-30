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
    int n, m;
    cin>>n>>m;
    vi a(m), b(m);
    for(int i=0; i<m; i++)
    {
        cin>>a[i]>>b[i];
    }
    int k;cin>>k;
    vi c(k), d(k);
    for(int i=0; i<k; i++)
    {
        cin>>c[i]>>d[i];
    }
    int mx = 0;
    for(int mask = 0; mask<(1<<k); mask++)                //Iterating over all possible choices and selecting the best one -> TIME COMPLEXITY -- O(m*(2^k))
    {
        vi freq(n+1);
        for(int bit = 0; bit<k; bit++)
        {
            if(mask&(1<<bit))freq[d[bit]]++;
            else freq[c[bit]]++;
        }
        int val = 0;
        for(int i = 0; i<m; i++)
        {
            if(freq[a[i]] && freq[b[i]])val++;
        }
        mx=max(mx, val);
    }
    cout<<mx<<'\n';
}   
