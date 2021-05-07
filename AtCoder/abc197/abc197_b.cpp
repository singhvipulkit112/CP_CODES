// AUTHOR -- PULKIT SINGHVI @ps112


#include <bits/stdc++.h>
using namespace std; 
 
#define all(v) v.begin(),v.end()
#define test() int t;cin>>t;while(t--) 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ff first
#define ss second
#define pb push_back


int main()
{
	fastio
	int h, w, x, y;
	cin>>h>>w>>x>>y;
	vector<string> grid(h);
	for(int i=0; i<h; i++)
	{
		cin>>grid[i];
	}
	x--;y--;
	int cnt=1;
	for(int dx = -1; dx<=1; dx++)
	{
		int curr_x = x, curr_y = y;
		for(int dy = -1; dy<=1; dy++)
		{
			if(dx*dy || !(dx||dy))continue;
			curr_x+=dx;
			curr_y+=dy;
			if(curr_x<0 || curr_x>=h || curr_y<0 || curr_y>=w || grid[curr_x][curr_y]=='#')
			{
				curr_x = x;
				curr_y = y;
				continue;
			}
			else dy--;
			cnt++;
		}
	}
	cout<<cnt<<'\n';
}   
