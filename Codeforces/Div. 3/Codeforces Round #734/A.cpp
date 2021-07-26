#include <bits/stdc++.h>
using namespace std;
 
#define test() int t;cin>>t;while(t--) 

int main()
{
	test()
	{
		int n; cin>>n;
		
		int r1 = n%3;
		int r2 = 3 - (n%3);
		int x = min(r1, r2);
		
		int c1 = 0, c2 = 0;
		if(r1<=r2)
		{
			c1 = (n+2*x)/3;
			c2 = c1-x;
		}		
		else
		{
			c1 = (n-2*x)/3;
			c2 = c1+x;
		}
		
		cout<<c1<<' '<<c2<<'\n';	
	}
}
