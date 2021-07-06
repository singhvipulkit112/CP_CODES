#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
 
const int mod = 998244353;

int mul(int x, int y)
{
    return((x * 1LL * y)%mod);
}

int add(int x, int y)
{
    return(x+y>=mod ? x+y-mod: x+y);
}

int inv_modulo(int x, int a)
{
    if(a==0)return(1);
    int z = inv_modulo(x, a/2);
    z = mul(z, z);
    if(a%2)z = mul(z , x);
    return(z);
}

int main()
{
    int n, m, k;
    cin>>n>>m>>k;
	
    vi dp(k+1);
	vi new_dp(k+1);
    vi power(k+1);
	
    power[0]=1;
    for(int i = 1; i<=min(n, k); i++)    
        power[i] = mul(power[i-1], m);
    
    dp[1] = n;
    for(int i = 1; i<=k-1; i++)
    {
        for(int j = 1; j<=min(i, n); j++)
        {
            new_dp[j+1] = add(new_dp[j+1], mul(n-j, dp[j]));
            new_dp[j]   = add(new_dp[j]  , mul(j, dp[j]));
        }
		dp = new_dp;
		new_dp.clear();
		new_dp.resize(k+1);
    }
    
    int ans = 0;
    for(int j = 1; j<=min(k, n); j++)    
        ans = add(ans, mul(dp[j], inv_modulo(power[j], mod-2)));
    
    cout<<ans<<endl;
}
