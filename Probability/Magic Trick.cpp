#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	cout<<setprecision(9);

	int n, m;
	cin>>n>>m;

	if(n+m == 2)cout<<1<<'\n';
	else cout<<(1.0/n)*(1.0+((1.0*(m-1)*(n-1))/(n*m-1)))<<'\n';	
}
