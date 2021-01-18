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
const int mod = 998244353;
const int N = (int)2e6+3;
vvi I(3, vi(3));
void add(int& a, int b)
{
    a+=b;
    if(a>=mod)a-=mod;
}
int mul(int a, int b)
{
    return((a*1LL*b)%mod);
}
vvi mul(vvi A, vvi B)
{
    vvi C(3, vi(3));
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            for(int k = 0; k<3; k++)
            {
                add(C[i][j], mul(A[i][k], B[k][j]));
            }
        }
    }
    return(C);
}

vvi power(vvi A, int a)
{    
    if(a==0)return(I);
    vvi z = power(A, a/2);
    z = mul(z, z);
    if(a%2)z=mul(z, A);
    return(z);
}

int power(int x, int a)
{
    if(a==0)return(1);
    int z = power(x, a/2);
    z=mul(z, z);
    if(a%2)z=mul(z, x);
    return(z);
}
vvi matrix(int n)
{
    vvi A(3, vi(3));
    int inv = power(n, mod-2);
    int mod_inv2 = power(2, mod-2);
    int inv2 = mul(inv, inv);
    A[0][0] = mul(n-1, inv);
    A[0][1] = inv2;
    A[1][1] = mul(2*n-1, mul(mod_inv2, inv));
    A[1][2] = mul(mod_inv2, inv2);
    A[2][2] = 1;
    return(A);
}

int main()
{
    fastio
    I[0][0]=1;
    I[1][1]=1;
    I[2][2]=1;
    test()
    {
        int n, k, r, c;
        cin>>n>>k>>r>>c;
        vvi A = matrix(n);
        A = power(A, k);
        int ans = A[0][0];
        add(ans, A[0][1]);
        add(ans, A[0][2]);
        cout<<ans<<endl;
    }
}
