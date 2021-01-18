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
void add(int& a, int b)
{
    a+=b;
    if(a>=mod)a-=mod;
}

int main()
{
    fastio
    test()
    {
        int n, k, r, c;
        cin>>n>>k>>r>>c;
        int inv = power(n, mod-2);
        int mod_inv2 = power(2, mod-2);
        int inv2 = mul(inv, inv);
        int ans = 1, sum_r = 1;
        for(int i = 1; i<=k; i++)
        {
            int val1 = mul(inv2, sum_r);
            int val2 = mul(inv, mul(n-1, ans));
            add(val2, val1);
            ans=val2;
            int val3 = mul(2*n-1, mul(mod_inv2, mul(inv, sum_r)));
            add(val3, mul(mod_inv2, inv2));
            sum_r=val3;
        }
        cout<<ans<<endl;               
    }
}  
