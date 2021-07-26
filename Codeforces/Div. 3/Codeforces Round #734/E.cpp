#include <bits/stdc++.h>
using namespace std;
 
typedef vector<int> vi;
typedef vector<vi> vvi;
 
#define test() int t;cin>>t;while(t--) 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main()
{
	fastio
	test()
	{
		int n, k; cin>>n>>k;
		vi array(n+1);
		for(int i=1; i<=n; i++)cin>>array[i];
		vvi dp(n+1, vi(n+1));
    
    // dp[i][j] = Max elements with value equal to index in array[1:i] after j deletions
		for(int i = 1; i<=n; i++)
		{
			dp[i][0] = (array[i]==i)+dp[i-1][0];
			for(int d = 1; d<i; d++)
			{
				dp[i][d] = max(dp[i-1][d] + (array[i] == i-d), dp[i-1][d-1]);
			}			
		}
    
		int ans = -1;
		for(int d = 0; d<=n; d++)
		{
			if(dp[n][d]>=k)
			{
				ans = d;
				break;
			}
		}
    
		cout<<ans<<'\n';
	}
}
