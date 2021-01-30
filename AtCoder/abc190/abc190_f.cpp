// AUTHOR -- PULKIT SINGHVI @ps112
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
const int mod =  (int)1e9+7;
const int INF = (int)1e9;
const int N = (int)2e5+1;

// --> Segment Tree <--

struct SegTree 
{
	// 1-Based
	int n;
	vector<int> Tree;
	void init(int sz)
	{
		n = sz;
		Tree.resize(4*n);
	}
	void set(int k, int x) 
	{
		k+=n;
		Tree[k]=x;
		for(k=k/2;k>=1;k/=2)
		{
			Tree[k]=Tree[2*k]+Tree[2*k+1];
		}
	}
	int sum(int a, int b)
	{
		a+=n;b+=n;
		int s=0;
		while(a<=b)
		{
			if(a%2==1) s+=Tree[a++];
			if(b%2==0) s+=Tree[b--];
			a/=2;b/=2;
		}
		return s;
	}
};

int main()
{
    fastio
    int n;cin>>n;
    SegTree node;
    node.init(n);
    vi a(n);
    for(int i=0; i<n; i++)cin>>a[i];
    ll ans = 0;
    node.set(a[n-1], 1);
    for(int i = n-2; i>=0; i--)
    {
        ans+=(node.sum(0, a[i]-1));
        node.set(a[i], 1);                
    }
    cout<<ans<<'\n';
    for(int i = 0; i<n-1; i++)
    {
        int val = a[i];
        ans-=(val);
        ans+=(n-1-val);
        cout<<ans<<'\n';
    }
}   
