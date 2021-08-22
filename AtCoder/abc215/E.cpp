//AUTHOR -- PULKIT SINGHVI @ps112

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>


using namespace std;
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
 
#define test() int t;cin>>t;while(t--) 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) v.begin(), v.end()

#define ff first
#define ss second
#define pb push_back

const int mod = (int)998244353;
const int N = (int)1e5 + 1;

void add(int& a, int b)
{
    a+=b;
    if(a>=mod)a-=mod;
}

int main()
{

	#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

	#endif

	fastio

	int n;cin>>n;
	string s;cin>>s;

	vvi dp(1024, vi(10));
	int val = s[0] - 'A';
	dp[1<<val][val] = 1;

	for(int i = 1; i<n; i++){

		val = s[i] - 'A';

		vvi new_dp(1024, vi(10));

		new_dp[1<<val][val] = 1;

		for (int mask = 1; mask < 1024; mask++){
			if(mask & 1<<val){

				for (int last = 0; last < 10; ++last)
				{
					if(last == val){
						add(new_dp[mask][val], dp[mask][last]);
					}
					add(new_dp[mask][last], dp[mask][last]);
				}

			}
			else{

				for (int last = 0; last < 10; ++last)
				{
					add(new_dp[mask | 1<<val][val], dp[mask][last]);
					add(new_dp[mask][last], dp[mask][last]);
				}

			}

		}

		dp = new_dp;

	}

	int ans = 0;

	for (int i = 1; i < 1024; ++i)
	{
		for(int last = 0; last<10; last++){
			add(ans, dp[i][last]);
		}
	}

	cout<<ans<<'\n';

}
