#include <bits/stdc++.h>
using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;
 
#define test() int t;cin>>t;while(t--) 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

string solve(int n, int m, int k)
{
	if(n&1)	return(solve(m, n, (n*m)/2 - k));
	else if(k%2==0 && k<=n*(m/2))return("YES");	
	
	return("NO");	
}

vvc place_dominoes(int n, int m, int k)
{

	vc h{'a', 'b', 'c', 'd'};
	vc v{'w', 'x', 'y', 'z'};

	if(n&1)return(place_dominoes(m, n, (n*m)/2 - k));

	vvc grid(n, vc(m));
	int cnt = 0;
	int stopi = 0, stopj = 0;

	for(int i = 0; i<n; i+=2)
	{
		for(int j = 0; j<m-1; j+=2)
		{
			grid[i][j]   = h[(i+j)%4];
			grid[i][j+1] = h[(i+j)%4];
			grid[i+1][j]   = h[(i+1+j)%4];
			grid[i+1][j+1] = h[(i+1+j)%4];						
			cnt+=2;
			if(cnt == k)
			{
				stopi = i;
				stopj = j+2;
				break;
			}
		}
		if(cnt==k)break;
	}

	if(m&1)
	{
		for(int i=0; i<n; i+=2)
		{
			grid[i][m-1]   = v[(i+m-1)%4];
			grid[i+1][m-1] = v[(i+m-1)%4];
		}
	}

	for(int i = stopi; i<n; i+=2)
	{
		for(int j = ((i==stopi)?stopj:0); j<m; j++)
		{
			grid[i][j]   = v[(i+j)%4];
			grid[i+1][j] = v[(i+j)%4];
		}
	}

	return(grid);				
}

int main()
{
	fastio
	test()
	{
		int n, m, k;
		cin>>n>>m>>k;

		string check = solve(n, m, k);
		cout<<solve(n, m, k)<<'\n';

		if(check == "YES")
		{
			vvc grid(n, vc(m));
			grid = place_dominoes(n, m, k);
			if(n&1)
			{
				// Print (Transposed) grid
				for(int j=0; j<n; j++)
				{
					for(int i=m-1; i>=0; i--)cout<<grid[i][j];
					cout<<'\n';
				}				
			}			
			else
			{
				for(int i=0; i<n; i++)
				{
					for(char c : grid[i])cout<<c;
					cout<<'\n';
				}				
			}			
		}
	}
}
