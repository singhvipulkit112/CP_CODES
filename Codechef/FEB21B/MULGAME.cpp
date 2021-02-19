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
		int n,q,m;
		cin>>n>>q>>m;
		vi arr(n+1);
		for(int i=1; i<=n; i++)cin>>arr[i];
		map<pii, int> store;
		vi freq(m+2);
		while(q--)
		{
			int l, r;
			cin>>l>>r;
			if(arr[l]<=m)
			{
				pii p = {arr[l], min(m, arr[r])};
				store[p]++;
			}
		}
		for(auto p : store)
		{
			ll start = p.ff.ff, end = (p.ff.ss)+(p.ff.ff)-1;
			while(start<=(ll)m)
			{
				freq[start]+=(p.ss);
				freq[min(end, (ll)m)+1]-=(p.ss);
				start=end+(p.ff.ff)+1;
				end=start+(p.ff.ss)-1;
			}			
		}
		int ans = 0;
		for(int i=1; i<=m; i++)
		{
			freq[i]+=freq[i-1];
			ans=max(ans, freq[i]);
		}
		ans=max(ans, freq[0]);
		cout<<ans<<'\n';
	}
}   
