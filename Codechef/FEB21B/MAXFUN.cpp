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
const int INF = (int)1e9;

int main()
{
	fastio
	test()
	{
		int n;cin>>n;
		int mx = -INF-1, mn = INF+1;
		for(int i=0; i<n; i++)
		{
			int x;cin>>x;
			mn=min(mn, x);
			mx=max(mx, x);
		}
		cout<<(ll)2*(mx-mn)<<'\n';                    
	}
}   
