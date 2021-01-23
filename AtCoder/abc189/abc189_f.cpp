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
    int n, m, k;
    cin>>n>>m>>k;
    vi obs;
    for(int i=0; i<k; i++)
    {
        int x;
        cin>>x;
        obs.pb(x);
    }
    int curr_idx = k-1;
    //Check if not possible to reach N -- size of any contiguos segment of stop points shouldn't be >= m
    for(int i = m-1; i<k; i++)
    {
        if(obs[i]-obs[i-m+1]==m-1)  //All places from obs[i-m+1] to obs[i] (inclusive) are stop points that send you to zero.
        {
            cout<<-1<<'\n';
            return(0);
        }
    }
    vector<double> val_constant(n+m), val_coeff_E0(n+m);
    double sum_constant = 0.0, sum_coeff_E0 = 0.0;
    for(int i=n-1; i>=0; i--)
    {
        if(curr_idx>=0 && obs[curr_idx]==i)
        {
            val_coeff_E0[i]=1;            
            curr_idx--;
        }
        else
        {
            val_constant[i]= 1.0 + sum_constant/m;
            val_coeff_E0[i]=sum_coeff_E0/m;
        }
        sum_constant+=(val_constant[i]-val_constant[i+m]);
        sum_coeff_E0+=(val_coeff_E0[i]-val_coeff_E0[i+m]);        
    }
    cout<<setprecision(16)<<val_constant[0]/(1-val_coeff_E0[0])<<'\n';
}   
