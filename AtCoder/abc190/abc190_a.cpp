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
const int N = (int)2e5+1;

int main()
{
    fastio
    int a, b, c;
    cin>>a>>b>>c;
    if(c==1)swap(a, b);
    if(a<=b)
    {
        if(!c) cout<<"Aoki"<<'\n';
        else cout<<"Takahashi"<<'\n';
    }
    else
    {
        if(c) cout<<"Aoki"<<'\n';
        else cout<<"Takahashi"<<'\n';
    }    
}   
