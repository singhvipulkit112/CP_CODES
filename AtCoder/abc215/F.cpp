//AUTHOR -- PULKIT SINGHVI @ps112

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>


using namespace std;
 
typedef vector<int> vi;
typedef pair<int, int> pii;
 
#define test() int t;cin>>t;while(t--) 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) v.begin(), v.end()

#define ff first
#define ss second
#define pb push_back

const int mod = (int)998244353;
const int N = (int)1e5 + 1;


int main()
{

	#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

	#endif

	fastio

	int n; cin>>n;

	vector<pii> coordinates;

	for (int i = 0; i < n; ++i)
	{
		int x, y;
		cin>>x>>y;

		coordinates.pb(make_pair(x, y));
	}

	sort(all(coordinates));

	vi min_y_right(n), max_y_right(n), min_y_left(n), max_y_left(n);
	min_y_left[0] = max_y_left[0] = coordinates[0].ss;
	min_y_right[n-1] = max_y_right[n-1] = coordinates[n-1].ss;

	for(int i = 1; i<n; i++)
	{
		min_y_left[i] = min(coordinates[i].ss, min_y_left[i-1]);
		max_y_left[i] = max(coordinates[i].ss, max_y_left[i-1]);
	}

	for(int i = n-2; i>=0; i--)
	{
		min_y_right[i] = min(coordinates[i].ss, min_y_right[i+1]);
		max_y_right[i] = max(coordinates[i].ss, max_y_right[i+1]);
	}

	int low = 0, high = (int)1e9, ans = 0;

	while(low<=high)
	{
		int mid = low + (high-low)/2 ;
		int possible = false;

		for (int i = 0; i < n; ++i)
		{
			int x = coordinates[i].ff, y = coordinates[i].ss;

			int left  = upper_bound(all(coordinates), make_pair(x-mid, 0)) - coordinates.begin()-1;
			int right = lower_bound(all(coordinates), make_pair(x+mid, 0)) - coordinates.begin();

			if(left>=0){
				if(min_y_left[left] <= y-mid || max_y_left[left] >=y+mid)possible = true;
			}

			if(right<n){
				if(min_y_right[right] <=y-mid || max_y_right[right] >= y+mid)possible=true;
			}
			if(possible)break;
		}

		if(possible){
			ans = mid;
			low = mid+1;
		}
		else{
			high = mid-1;
		}
	}

	cout<<ans<<'\n';
}
