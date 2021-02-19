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
		vll freq(26);
		map<string, vi> m;
		ll ans = 0;
		vector<string> store(n);
		for(int i=0; i<n; i++)
		{
			string s;
			cin>>s;
			store[i]=s;
			char c = s[0];
			freq[c-'a']++;
			s.erase(0, 1);
			m[s].pb(c-'a');
		}
		vector<vll> cnt(26, vll(26));
		vll cnt1(26);
		for(auto p : m)
		{
			int sz = (int)((p.ss).size());
			for(int c : (p.ss))
			{
				for(int a : (p.ss))cnt[c][a]++;
				cnt1[c]+=sz;
			}
		}
		for(string s : store)
		{
			ll val = n;
			int c = s[0]-'a';
			val -= cnt1[c];
			s.erase(0, 1);
			for(int a : m[s])
			{
				if(a!=c)val=val-freq[a]+cnt[c][a];
			}
			ans+=val;
		}
		cout<<ans<<'\n';
	}
}   
