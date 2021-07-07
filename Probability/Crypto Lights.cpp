#include <bits/stdc++.h>
using namespace std;
 
typedef vector<int> vi;
 
#define test() int t;cin>>t;while(t--) 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mod = (int)1e9+7;
const int N = (int)1e5+1;

vi fact(N, 1), ifact(N);

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

void calc_fact()
{
    for(int i = 2; i<N; i++)fact[i]=mul(fact[i-1], i);
    ifact[N-1]=power(fact[N-1], mod-2);
    for(int i = N-2; i>=0; i--)ifact[i]=mul(i+1, ifact[i+1]);
}

int ncr(int n, int r)
{
    if(n<r)return(0);
    return(mul(fact[n], mul(ifact[r], ifact[n-r])));
}

int main()
{
	fastio
	calc_fact();

	// E(lights on) = Σ P(lights on > on) from on = 0 to n
	// P(lights on > on) = (1/ncr(n, on))*ncr(n-(k-1)*(on-1), on)
	test()
	{
		int n, k; cin>>n>>k;
		int ans = 1;
		for(int on = 1; n>=(k-1)*(on-1); on++)
		{
			int prob = mul(fact[on], mul(fact[n-on], ifact[n]));
			prob = mul(prob, ncr(n-((k-1)*(on-1)), on));
			add(ans, prob);
		}			
		cout<<ans<<'\n';
	}	
}
