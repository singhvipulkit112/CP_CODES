// AUTHOR -- PULKIT SINGHVI @ps112

#include <bits/stdc++.h>
using namespace std;
 
typedef vector<int> vi; 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main()
{
	fastio
	
	int n;cin>>n;
	vi arr(n);
	for(int i=0; i<n; i++)cin>>arr[i];
	int min_xor = (1<<30);
	for(int type = 0; type<(1<<(n-1)); type++)
	{
		int curr_xor = 0;
		int curr_or = arr[0];
		for(int b = 0; b<n-1; b++)
		{
			if((1<<b) & type)
			{
				curr_xor ^= curr_or;
				curr_or = arr[b+1];
			}
			else curr_or |= arr[b+1];
		}
		curr_xor ^= curr_or;
		min_xor = min(min_xor, curr_xor);
	}
	cout<<min_xor<<'\n';
}   
