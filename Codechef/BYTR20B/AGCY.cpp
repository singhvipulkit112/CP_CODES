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
		int n, q;
		cin>>n>>q;
		vll sm1(n+2);
        vll sm2(n+2);
		for(int i = 0; i<q; i++)
		{
			int l, r;
			cin>>l>>r;
			sm2[l]++;
			sm2[r+1]--;
            sm1[l]+=(1-l);
            sm1[r+1]-=(1-l);
		}
		for(int i =1; i<=n; i++)
		{
			sm1[i]+=sm1[i-1];
            sm2[i]+=sm2[i-1];
			cout<<sm2[i]*i + sm1[i]<<" ";
		}
		cout<<endl;
    }
} 
