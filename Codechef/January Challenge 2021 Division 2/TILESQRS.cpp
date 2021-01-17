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
const int mod = 998244353;
const int INF = (int)1e9;
const int N = (int)1e5+1;

int query(int x, int y)
{
    cout<<1<<" "<<x<<" "<<y<<endl;
    int k;
    cin>>k;
    return(k);
}

bool check(int r, int c, int& k, int new_k)
{
    if(r==1 || c==1)
    {
        if(new_k!=k)
        {
            if(new_k<k)k=query(r, c);
            else k = new_k;
            return(true);
        }
    }
    else
    {
        if(new_k==k-2)
        {
            k=query(r, c);
            return(true);
        }
        if(new_k==k+2)
        {
            k=new_k;
            return(true);
        }
    }
    k=new_k;
    return(false);
}

int main()
{
    fastio
    vi path{4, 2, 4, 1, 2, 4, 2};
    test()
    {
        int sze, q, k;
        cin>>sze>>q>>k;
        int new_k;
        int n = sze;
        if(sze&1)n--;
        for(int c = 1; c<=n-1; c+=2)
        {
            for(int r = 1; r<=n-1; r+=2)
            {
                new_k = query(r, c);
                if(check(r, c, k, new_k))continue;
                for(int val : path)
                {
                    if(val == 1)
                    {
                        k = query(r, c+1);
                        if(k==-1)return(0);
                    }
                    else if(val == 2)
                    {
                        k = query(r+1, c);
                        if(k==-1)return(0);
                    }
                    else
                    {
                        k = query(r+1, c+1);
                        if(k==-1)return(0);
                    }
                    new_k = query(r, c);
                    if(check(r, c, k, new_k))break;
                }
            }
        }
        if(sze&1)
        {
            for(int c = 1; c<=n; c++)k=query(n, c);
            for(int r = 1; r<=n-1; r++)k=query(r, n);
            for(int c = 1; c<=n-1; c+=2)
            {
                new_k = query(n+1, c+1);
                if(new_k!=k)
                {
                    if(new_k<k)k=query(n+1, c+1);
                    else k=new_k;
                    continue;                    
                }
                k=query(n+1, c);
                if(k==new_k)k=query(n+1, c+1);
            }
            for(int r = 1; r<=n-1; r+=2)
            {
                new_k = query(r+1, n+1);
                if(new_k!=k)
                {
                    if(new_k<k)k=query(r+1, n+1);
                    else k=new_k;
                    continue;                    
                }
                k=query(r, n+1);
                if(k==new_k)k=query(r+1, n+1);
            }
            k=query(n, n);
            k=query(n, n+1);
            new_k = query(n+1, n);
            if(new_k != k)k=query(n+1, n+1);
            k=query(n, n);
            k=query(n, n+1);
            k=query(n+1, n);        
        }
        cout<<2<<endl;
        if(sze & 1)
        {
            for(int r = 1; r<=sze; r++)
            {
                int pos = 1;
                if(r&1)pos = 0;
                for(int c = 1; c<=sze; c++)
                {
                    if(r>=sze-1 || c>=sze-1)cout<<1-pos<<" ";
                    else cout<<pos<<" ";
                    pos=1-pos;
                }
                cout<<endl;
            }
            int verdict;
            cin>>verdict;
            if(verdict==-1)return(0);
        }
        else
        {
            for(int r = 1; r<=n; r++)
            {
                int pos = 1;
                if(r&1)pos = 0;
                for(int c = 1; c<=n; c++)
                {
                    cout<<pos<<" ";
                    pos=1-pos;
                }
                cout<<endl;
            }
            int verdict;
            cin>>verdict;
            if(verdict==-1)return(0);
        }                        
    }
}   
