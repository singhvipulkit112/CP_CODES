#include <bits/stdc++.h>
using namespace std;
 
typedef vector<int> vi;
typedef vector<vi> vvi;
 
#define all(v) v.begin(),v.end()
#define test() int t;cin>>t;while(t--) 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back

int main()
{
    fastio
	test()
	{
		int n;
		cin>>n;
		vector<string> store(n);
		vvi val(n, vi(5));
		
		for(int i=0; i<n; i++)
		{
			cin>>store[i];
			for(char c : store[i])val[i][c-'a']++;
			for(int j=0; j<5; j++)val[i][j] = 2*val[i][j] - (store[i].length());
		}
		
		int ans = 0;
		for(int i=0; i<5; i++)
		{
			vi diff;
			for(int j =0; j<n; j++)
			{
				diff.pb(val[j][i]);
			}
			sort(all(diff));

			// DIFF = count('a' + i) - count(other letters)
			int DIFF = 0;
			for(int j = n-1; j>=0; j--)
			{
				DIFF+=diff[j];
				if(DIFF<=0)break;
				ans = max(ans, n-j);
			}
		}
		
		cout<<ans<<'\n';
	}
}
