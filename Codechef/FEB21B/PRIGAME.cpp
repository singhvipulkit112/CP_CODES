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
const int N = (int)1e6+1;
vi isprime(N, 1);
void sieve()
{
    isprime[0]=0;isprime[1]=0;
    for(int i = 2; i<=1000; i++)
    {
        if(isprime[i])
        {
            for(int mul = i*i; mul<N; mul+=i)
            {
                isprime[mul]=0;
            }
        }
    }
    for(int i = 1; i<N; i++)isprime[i]+=isprime[i-1];
}
int main()
{
	fastio
	sieve();
	test()
	{
		int x, y;
		cin>>x>>y;
		cout<<((isprime[x]<=y)?"Chef":"Divyam")<<'\n';
	}
}   
