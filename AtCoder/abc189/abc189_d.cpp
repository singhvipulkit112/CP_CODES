// AUTHOR -- PULKIT SINGHVI @ps112
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
const int mod =  (int)1e9+7;
const int INF = (int)1e9;
const int N = (int)3e5;

int main()
{
    fastio
    int n;
    cin>>n;
    vector<string> arr(n+1);
    for(int i=1; i<=n; i++)
    {
        cin>>arr[i];
    }
    ll val1 = 1, val2 = 1;
    // val1 -> number of tuples of i variables such that Yi is False
    // val2 -> number of tuples of i variables such that Yi is True
    for(int i=1; i<=n; i++)
    {
        ll new_val1 = 0, new_val2 = 0;
        if(arr[i]=="AND")
        {
            // Yi = FALSE -- (Yi-1 == FALSE) || (Xi == FALSE)
            new_val1=(2*val1+val2);
            // Yi = TRUE -- (Yi-1 == TRUE) && (Xi == TRUE)
            new_val2=val2;
        }
        else
        {
            // Yi = FALSE -- (Yi-1 == FALSE) && (Xi == FALSE)
            new_val1=val1;
            // Yi = TRUE -- (Yi-1 == TRUE) || (Xi == TRUE)
            new_val2=val1+2*val2;
        }
        val1=new_val1;val2=new_val2;
    }
    cout<<val2<<'\n';
}   
