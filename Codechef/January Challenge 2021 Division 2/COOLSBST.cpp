//AUTHOR -- PULKIT SINGHVI @ps112iitkgp
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
const int N = (int)1e5+1;
const int len = 320;
vi fact(N, 1), ifact(N, 1), sm_pwr(N), sm_odd_pwr(N), isprime(N, 1);
vvi pfx_sum(N, vi(len));
int mul(int a, int b)
{
    return((a*1LL*b)%mod);
}

void add(int& a, int b)
{
    a+=b;
    if(a>=mod)a-=mod;
}

int ncr(int n, int r)
{
    if(n<r)return(0);
    return(mul(fact[n], mul(ifact[r], ifact[n-r])));
}

int power(int x, int a)
{
    if(a==0)return(1);
    int z = power(x, a/2);
    z=mul(z, z);
    if(a%2)z=mul(z, x);
    return(z);
}

void calc_fact()
{
    for(int i = 2; i<N; i++)fact[i]=mul(fact[i-1], i);
    ifact[N-1]=power(fact[N-1], mod-2);
    for(int i = N-2; i>=0; i--)ifact[i]=mul(i+1, ifact[i+1]);
    int pwr = 2;
    for(int num = 1; num<len; num++)
    {
        pfx_sum[num][0]=pwr;
        pwr=mul(2, pwr);
    }
    for(int num = len; num<N; num++)
    {
        for(int block = 0; block*len<=num; block++)
        {
            int a = len*(block);
            int b = a+319;
            pfx_sum[num][block]=mul(2, pfx_sum[num-1][block]);
            add(pfx_sum[num][block], mod-ncr(num-1, a));
            add(pfx_sum[num][block], mod-ncr(num-1, b));
            add(pfx_sum[num][block], ncr(num, a));
        }
    }
}

void sieve()
{
    isprime[0]=0;isprime[1]=0;
    for(ll i = 2; i<(ll)N; i++)
    {
        if(isprime[i])
        {
            for(ll mul = i*i; mul<(ll)N; mul+=i)isprime[mul]=0;
            ll val = i;
            if(i!=(ll)2)
            {
                while(val<N)
                {
                    for(ll mul = val; mul<(ll)N; mul+=val)
                    {
                        sm_pwr[mul]++;
                        if(mul & (ll)1)sm_odd_pwr[mul]++;
                    }
                    val*=i;
                }
            }
        }
    }
    for(int num = 1; num<N; num++)
    {
        sm_pwr[num]+=sm_pwr[num-1];
        sm_odd_pwr[num]+=sm_odd_pwr[num-1];
    }
}

int get_odd(int l, int r)
{
    int start = l+(1-(l&1));
    int ans = 0;
    if(r>=start)ans=(r-start)/2 + 1;
    return(ans);
}
int get_mul_4(int l, int r)
{
    int start = (l+(4-(l%4))%4);
    int ans = 0;
    if(r>=start)ans=(r-start)/4+1;
    return(ans);
}

int get_sum(int n, int a, int b)
{
    if(a>b || a>n)return(0);
    int ans = 0;
    int c_l = a / len,   c_r = b / len;
    if (c_l == c_r)
        for (int i=a; i<=b; ++i)
            add(ans, ncr(n, i));
    else {
        for (int i=a, end=(c_l+1)*len-1; i<=end; ++i)
            add(ans, ncr(n, i));
        for (int i=c_l+1; i<=c_r-1; ++i)
            add(ans, pfx_sum[n][i]);
        for (int i=c_r*len; i<=b; ++i)
            add(ans, ncr(n, i));
    }
    return(ans);
}

int main()
{
    fastio
    sieve();
    calc_fact();
    int mod_inv_2 = power(2, mod-2);  
    test()
    {
        int l, r, a, b;
        cin>>l>>r>>a>>b;
        b=min(b, r-l+1);
        int ans = 0;
        int total_odd = get_odd(l ,r);
        int total_mul_4 = get_mul_4(l, r);

        int val_ncr_1 = get_sum(r-l+1, a, b);
        int val_ncr_2 = get_sum(total_odd, a, b);
        int val_ncr_3 = val_ncr_2;
        add(val_ncr_3, ncr(total_odd, a-1));
        add(val_ncr_3, mod-ncr(total_odd, b));
        int val_ncr_4 = val_ncr_1;
        add(val_ncr_4, mod-ncr(r-l+1, b));
        add(val_ncr_4, ncr(r-l, a-1));
        add(val_ncr_4, ncr(r-l, b-1));
        val_ncr_4     = mul(val_ncr_4, mod_inv_2);
        int val_ncr_5 = val_ncr_2;
        add(val_ncr_5, mod-ncr(total_odd, b));
        add(val_ncr_5, ncr(total_odd-1, a-1));
        add(val_ncr_5, ncr(total_odd-1, b-1));
        val_ncr_5     = mul(val_ncr_5, mod_inv_2);

        add(ans, mul(3, val_ncr_1));
        add(ans, mod-mul(2, val_ncr_2));
        add(ans, mod-mul(r-l+1-total_odd-total_mul_4, val_ncr_3));
        add(ans, mul(2, mul(sm_pwr[r]-sm_pwr[l-1], val_ncr_4)));
        add(ans, mod-mul(sm_odd_pwr[r]-sm_odd_pwr[l-1], val_ncr_5));

        cout<<ans<<'\n';                      
    }
}   
