#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const int mod = (int)1e9+7;

int main()
{
	vll lcm(48);
	lcm[1]=1;
	for(int i=2; i<=47; i++)lcm[i] = (lcm[i-1]/__gcd(lcm[i-1], (ll)i))*i;
	
	int t;cin>>t;
	for(int a = 0; a<t; a++)
	{
		ll n; cin>>n;
		ll ans = 2*n;
		ans%=mod;
		for(int i = 2; i<=46; i++)
		{
			ans+=(n/lcm[i]);
			ans%=mod;
		}
		ans += (n/lcm[47])*47;
		ans%=mod;

		cout<<ans<<'\n';
	}
}
