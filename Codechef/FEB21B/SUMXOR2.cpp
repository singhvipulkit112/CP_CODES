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
const int INF = (int)1e9;
const int mod = 998244353;
const int rt_pw = (1 << 21);
vi fact, ifact, rev;
int sze=1;
int n_inv, lg=0;
int rt=733596141, rt_inv=428961804;

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
 
void calc_rev() {
	rev.resize(sze);
	for(int mask = 0; mask<sze; mask++){
		int res = 0;
		for(int i = 0; i < lg; i++) {
			if((mask >> i) & 1) res |= 1 << (lg - i - 1);
		}
		rev[mask]=res;
	}
}
 
void fft(vi &a, bool inv) {
    int n = a.size();
    
    for(int i = 0; i < n; i++) {
    	int o = rev[i];
		if(i < o) swap(a[i], a[o]);
	}
 
    for (int len = 2; len <= n; len <<= 1) {
        int wn = inv ? rt_inv : rt;
        for (int i = len; i < rt_pw; i <<= 1)
            wn = mul(wn, wn);
 
        for (int i = 0; i < n; i += len) {
            int w = 1;
        	for (int j = 0; j < (len >> 1); j++) {
				int u = a[i + j];
				int v = (1LL * a[i + j + (len >> 1)] * w) % mod;
				
				a[i + j] = u + v;
				if(a[i + j] > mod) a[i + j] -= mod;
				
				a[i + j + (len >> 1)] = u - v;
				if(a[i + j + (len >> 1)] < 0) a[i + j + (len >> 1)] += mod;
                
                w = mul(w, wn);
            }
        }
    }
 
	if(!inv) return;
	for (auto &it : a) it = mul(it, n_inv);
}
 
void mult(vi &a, vi &b) {
	vi fa(all(a)), fb(all(b));
	fa.resize(sze), fb.resize(sze);
	
	fft(fa, 0);
	fft(fb, 0);
	for(int i = 0; i < sze; i++) fa[i] = mul(fa[i] , fb[i]);
	fft(fa, 1);
	
	a.resize(sze);
	for(int i = 0; i < sze; i++)
		a[i] = fa[i];
}

void calc_fact(int N)
{
	N++;
	fact.resize(N);
	ifact.resize(N);
	fact[0]=1;fact[1]=1;
    for(int i = 2; i<N; i++)fact[i]=mul(fact[i-1], i);
    ifact[N-1]=power(fact[N-1], mod-2);
    for(int i = N-2; i>=0; i--)ifact[i]=mul(i+1, ifact[i+1]);
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

int main()
{
	fastio
	int n;cin>>n;
	calc_fact(n);
	while(sze < n+2)sze <<= 1;
    while((1 << lg) < sze) lg++;
	n_inv=power(sze, mod-2);
	calc_rev();
	vi cnt(30);
	vi pwr(n+1);
	pwr[0]=1;
	for(int i=1; i<=n; i++)pwr[i]=mul(2, pwr[i-1]);
	for(int i=0; i<n; i++)
	{
		ll x;cin>>x;
		for(int b=0; b<30; b++)if(((ll)1<<b)&x)cnt[b]++;
	}
	vi ans(n+1);
	for(int b=0; b<30; b++)
	{
		vi A(cnt[b]+1), B(n-cnt[b]+1);
		for(int i=0; i<=cnt[b]; i++)
		{
			if(i&1)A[i]=mul(pwr[b], ncr(cnt[b], i));
		}
		for(int i=0; i<=n-cnt[b]; i++)
		{
			B[i]=ncr(n-cnt[b], i);
		}
		mult(A, B);
		for(int i=1; i<=n; i++)add(ans[i], A[i]);
	}
	for(int i=1; i<=n; i++)add(ans[i], ans[i-1]);
	int q;cin>>q;
	while(q--)
	{
		int len;cin>>len;
		cout<<ans[len]<<'\n';
	}
}   
