//AUTHOR -- PULKIT SINGHVI @ps112

#include <iostream>
#include <vector>
#include <set>

using namespace std;
 
typedef vector<int> vi;
 
#define test() int t;cin>>t;while(t--) 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define ff first
#define ss second

const int mod = (int)998244353;
const int N = (int)1e5 + 1;

vi min_div(N, 1);

void sieve(){

	for(int i = 1; i<=N; i++)min_div[i] = i;

	for(int i = 2; i*i <= N; i++)
	{
		if(min_div[i] == i)
		{
			for(int j = i*i; j<=N; j+=i)
			{
				if(min_div[j] == j)min_div[j] = i;
			}
		}
	}
}

int main()
{

	#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

	#endif

	fastio
	sieve();
	
	int n, m;
	cin>>n>>m;

	set<int> primes;

	for(int i = 0; i<N; i++){
		int x; cin>>x;
		while(min_div[x]!=1)
		{
			primes.insert(min_div[x]);
			x/=min_div[x];
		}
	}

	vi coprime(m+1, 1);

	int ans = m;

	for(int p : primes)
	{
		for(int i = p; i<=m; i+=p)
		{
			if(coprime[i])
			{
				coprime[i]=0;
				ans--;
			}
		}
	}

	
	cout<<ans<<'\n';
	for(int i = 1; i<=m; i++)if(coprime[i])cout<<i<<'\n';
}
