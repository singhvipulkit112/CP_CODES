// AUTHOR -- PULKIT SINGHVI @ps112iitkgp
#include <bits/stdc++.h>
using namespace std;

#define test() int t;cin>>t;while(t--) 
const int mod = (int)1e9+7;

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

int main()
{
    int mod_inv_4 = power(4, mod-2);
    test()
    {
        int n;cin>>n;
        int ans = mul(power(2, n+1), mod_inv_4);

        cout<<ans<<'\n';
    }
} 