#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mod = 998244353;

int mul(int a, int b)
{
	return((a*1LL*b)%mod);
}

int main()
{
	fastio
	int n, m;
	cin>>n>>m;

	map<int, int> mp;
	vi a(n), b(m);
	vi last_idx(m, -1);

	for(int i=0; i<n; i++)cin>>a[i];
	for(int i=0; i<m; i++)
	{
		int x;cin>>x;
		b[i]  = x;
		mp[x] = i;
	}

	for(int i=0; i<n; i++)
	{
		if(mp.find(a[i]) != mp.end())
		{
			last_idx[mp[a[i]]] = i;
		}
	}

	if(last_idx[0] == -1 || last_idx[m-1] == -1)
	{
		cout<<0<<'\n';
		return(0);
	}

	for(int i = 0; i<last_idx[0]; i++)
	{
		if(a[i]<b[0])
		{
			cout<<0<<'\n';
			return(0);
		}
	}
	for(int i = last_idx[m-1]+1; i<n; i++)
	{
		if(a[i]<b[m-1])
		{
			cout<<0<<'\n';
			return(0);
		}
	}

	int ans = 1;
	for(int i = 0; i<m-1; i++)
	{

		int start = last_idx[i];
		int end   = last_idx[i+1];

		if(start == -1)
		{
			cout<<0<<'\n';
			return(0);
		}

		int mid = start;
		for(int j = start+1; j<end; j++)
		{

			if(a[j]<b[i])
			{
				cout<<0<<'\n';
				return(0);
			}

			if(a[j]<b[i+1])
				mid = j;
		}

		ans = mul(ans, end-mid);
	}

	cout<<ans<<'\n';

}
