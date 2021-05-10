
// AUTHOR -- PULKIT SINGHVI @ps112iitkgp
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define pb push_back
#define all(v) v.begin(),v.end()
#define test() int t;cin>>t;while(t--) 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mod = (int)1e9+7;
const int N = (int)5e5 + 1;

vvi fct(N);

void factorize()
{
	for(int num = 1; num<N; num++)
	{
		for(ll mul = num; mul<(ll)N; mul+=num)
		{
			fct[mul].pb(num);
		}
	}
}

int main()
{
	fastio
	factorize();
	test()
	{
		int n, m;cin>>n>>m;
		ll ans = 0;
		for(int b = 2; b<=n; b++)
		{
			int new_m = (m/b)*b;
			if(!new_m)ans+=(b-1);
			else ans+=(lower_bound(all(fct[new_m]) , b)-fct[new_m].begin());
		}
		cout<<ans<<'\n';
	}	
} 
