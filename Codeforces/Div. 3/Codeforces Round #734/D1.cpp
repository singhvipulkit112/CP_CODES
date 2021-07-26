#include <bits/stdc++.h>
using namespace std;
 
#define test() int t;cin>>t;while(t--) 

string solve(int n, int m, int k)
{
	if(n&1)	return(solve(m, n, (n*m)/2 - k));
	
	else if(k%2==0 && k<=n*(m/2))return("yes");	
	
	return("no");	
}

int main()
{
	test()
	{
		int n, m, k;
		cin>>n>>m>>k;
		cout<<solve(n, m, k)<<'\n';
	}
}
