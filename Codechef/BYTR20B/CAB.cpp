// AUTHOR -- PULKIT SINGHVI @ps112iitkgp
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<ll> vll;
 
#define all(v) v.begin(),v.end()
#define test() int t;cin>>t;while(t--) 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ff first
#define ss second
#define pb push_back
const int mod = (int)1e9+7;
const int N = (int)2e6+3;

int main()
{
    fastio
    test()
    {
		int n, k;
		cin>>n>>k;
		if(n>k)
		{
			cout<<-1<<endl;
			continue;
		}
		vi bit(32);
		int cnt = 0;
		for(int b = 0; b<32; b++)
		{
			if(k&(1<<b))
			{
				cnt++;
				bit[b]=1;
			}
		}
		if(cnt>n)
		{
			cout<<-1<<endl;
			continue;
		}
		if(cnt==n)
		{
			for(int b = 0; b<32; b++)
			{
				if(bit[b])cout<<(char)('a'+b);
			}
			cout<<endl;
			continue;
		}
        int diff = n-cnt;
        for(int b = 32; b>=1; b--)
        {
            if(bit[b])
            {
                if(diff)
                {   
                    if(bit[b]<=diff)
                    {
                        bit[b-1]+=(2*bit[b]);
                        diff-=bit[b];
                        bit[b]=0;
                    }
                    else
                    {
                        bit[b-1]+=(2*diff);
                        bit[b]-=diff;
                        diff=0;
                    }
                }
            }
        }
        for(int b = 32; b>=0; b--)
        {
            for(int f = 0; f<bit[b]; f++)cout<<(char)('a'+b);
        }
        cout<<endl;
    }
} 
