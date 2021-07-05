#include <bits/stdc++.h>
using namespace std;
 
typedef vector<double> vd;
typedef vector<vd> vvd;
 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main()
{
	fastio
		
	int n;cin>>n;
	
	vvd prob_matrix(n, vd(n));
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)cin>>prob_matrix[i][j];
	}
	
	vd prob((1<<n));
	prob[(1<<n)-1] = 1.0;

	for(int state = (1<<n)-1; state>0; state--)
	{
		int fish_left = __builtin_popcount(state);			
		int total_pairs = (fish_left * (fish_left-1))/2;
		
		for(int i = 0; i<n; i++)
		{
			if(state & (1<<i))
			{
				for(int j = i+1; j<n; j++)
				{
					if(state & (1<<j))
					{
						prob[state ^ (1<<j)] += (prob_matrix[i][j] * prob[state])/total_pairs;    // Fish i eats Fish j 
						prob[state ^ (1<<i)] += (prob_matrix[j][i] * prob[state])/total_pairs;    // Fish j eats Fish i
					}
				}
			}
		}
	}
	
	for(int i = 1; i<(1<<n); i*=2)cout<<setprecision(9)<<prob[i]<<' ';
	cout<<'\n';
}
