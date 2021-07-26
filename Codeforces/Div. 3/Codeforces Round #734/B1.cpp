#include <bits/stdc++.h>
using namespace std;
 
typedef vector<int> vi;
 
#define test() int t;cin>>t;while(t--) 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main()
{
	fastio
		
	test()
	{
		string s;
		cin>>s;
		
		vi cnt(26);
		for(char c : s)cnt[c-'a']++;
		
		int f1 = 0, f2 = 0;
		for(int i = 0; i<26; i++)
		{
			if(cnt[i] >= 2)f2++;
			else f1 += cnt[i];
		}
		
		int ans = f2 + (f1/2);
		cout<<ans<<'\n';		
	}
	
}
