//AUTHOR : PULKIT SINGHVI @ps112iitkgp
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
const int INF = (int)1e9;
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
    int m, n, k;
    cin>>m>>n>>k;
    if(m==1)
    {
        int ans = 1;
        add(ans, mul(n-1, mul(k-1, power(k, mod-2))));
        cout<<ans<<endl;
    }
    else if(k==1)
    {
        cout<<1<<endl;
    }
    else
    {
        int eq = 1, diff = 2;
        int inv = power(k, mod-2);
        int inv2 = mul(inv, inv);        
        for(int i = 2; i<=n; i++)
        {
            int new_eq = 0, new_diff = 0;
            int val_eq_eq = 0, val_eq_diff = 0;
            int val_diff_eq = 0, val_diff_diff = 0;            
            add(val_eq_eq, eq);
            add(val_eq_eq, mul(k-1, inv));
            add(new_eq, mul(inv, val_eq_eq));
            add(val_eq_diff, diff);
            add(val_eq_diff, mul(k-2, inv));
            add(new_eq, mul(k-1, mul(inv, val_eq_diff)));
            add(val_diff_eq, eq);
            add(val_diff_eq, mul(2, mul(k-1, inv)));
            add(val_diff_diff, diff);
            add(val_diff_diff, mul(2, mul(k-1, inv)));
            add(new_diff, mul(inv, val_diff_eq));
            add(new_diff, mul(k-1, mul(inv, val_diff_diff)));
            eq=new_eq;diff=new_diff;
        }
        int ans = 0;
        add(ans, mul(inv, eq));
        add(ans, mul(k-1, mul(inv, diff)));
        cout<<ans<<endl;
    }        
}   
