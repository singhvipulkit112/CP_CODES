#include <bits/stdc++.h>
using namespace std;
 
typedef vector<int> vi;
typedef vector<vi> vvi;
 
#define test() int t;cin>>t;while(t--) 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back

int main()
{
	fastio

	test()
	{
		int n, k;
		cin>>n>>k;

		vi cnt(n+1);		
		vi ans(n);
		vi arr(n);
		vvi index(n+1);

		for(int i=0; i<n; i++)
		{
			int x;cin>>x;
			arr[i]=x;
			cnt[x]++;
		}

		int total_painted = 0;
		for(int i=1; i<=n; i++)		
			if(cnt[i]<k)total_painted+=cnt[i];
		
		total_painted = k*(total_painted/k);

		for(int i=0; i<n; i++)
			index[arr[i]].pb(i);		

		int curr = 0;
		for(int i = 1; i<=n; i++)
		{
			if(cnt[i]>=k)
			{
				for(int j = 0; j<k; j++)ans[index[i][j]] = j+1;
			}
			else
			{					
				for(int idx : index[i])
				{
					if(curr == total_painted)break;
					ans[idx] = 1 + (curr%k);
					curr++;
				}
			}
		}
		for(int i=0; i<n; i++)cout<<ans[i]<<' ';
		cout<<'\n';	
	}
}
