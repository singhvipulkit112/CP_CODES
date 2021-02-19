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
		vi curr_pos(n+1), wgt(n+1), len(n+1);
		for(int i=1; i<=n; i++)cin>>wgt[i];
		for(int i=1; i<=n; i++)cin>>len[i];
		for(int i=1; i<=n; i++)curr_pos[i]=i;
		vi sorted = wgt;
		int hits=0;
		sort(all(sorted));
		for(int idx = 1; idx<=n; idx++)
		{
			int place = 0;
			int pos;
			for(int i=1; i<=n; i++)
			{
				if(sorted[idx]==wgt[i])
				{
					pos=curr_pos[i];
					break;
				}
			}
			for(int i = 1; i<=n; i++)
			{
				if(wgt[i]>sorted[idx])
				{
					if(curr_pos[i]<=pos)
					{
						int freq = ((pos-curr_pos[i])/len[i] + 1);
						hits+=freq;
						curr_pos[i]+=(freq*len[i]);
					}
				}
			}
		}
		cout<<hits<<'\n';
	}
}   
