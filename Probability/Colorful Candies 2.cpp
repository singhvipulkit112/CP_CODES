//AUTHOR -- PULKIT SINGHVI @ps112

#include <iostream>
#include <vector>
#include<unordered_map>
#include<utility>

using namespace std;
 
typedef vector<int> vi;
typedef pair<int, int> pii;
 
#define test() int t;cin>>t;while(t--) 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define ff first
#define ss second

const int mod = (int)998244353;
const int N = (int)5e4 + 1;

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

	#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

	#endif

	fastio
	calc_fact();
	
	int n;
	cin>>n;

	unordered_map<int, int> color, count;
	for (int i = 0; i < n; ++i)
	{
		int c;cin>>c;
		color[c]++;

	}
	for(pii p : color)
	{
		count[p.ss]++;
	}

	for(int i=1; i<=n; i++)
	{
		int ans = 0;
		for(pii p : count)
		{
			add(ans, mul(p.ss, ncr(n, i)));
			add(ans, mul(p.ss, mod-ncr(n-p.ff, i)));
		}
		ans = mul(ans, power(ncr(n, i), mod-2));
		cout<<ans<<'\n';
	}

}
