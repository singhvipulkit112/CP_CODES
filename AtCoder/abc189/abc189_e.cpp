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

struct transform
{
    /*
        [new_x  new_y] = [old_x old_y][A B] + [offset_x offset_y];   
                                      [C D]
    */
   ll A=1, B=0, C=0, D=1;
   ll offset_x = 0, offset_y=0;
};

pll transformate(pll old_point, struct transform var)
{
    ll new_x, new_y;
    ll old_x = old_point.ff, old_y = old_point.ss;
    new_x = var.A*old_x+var.C*old_y+var.offset_x;
    new_y = var.B*old_x+var.D*old_y+var.offset_y;
    pll new_point = {new_x, new_y};
    return(new_point);  
}
int main()
{
    fastio
    int n;
    cin>>n;
    vpll point(n);
    for(int i=0; i<n; i++)
    {
        ll x, y;
        cin>>x>>y;
        point[i]={x, y};
    }
    int m;
    cin>>m;
    vector<struct transform> store_oper(m+1); 
    for(int i = 1; i<=m; i++)
    {
        int type;cin>>type;
        if(type<=2)
        {
            if(type==2) // 90 deg anti-clkwise -> (x, y) -> (-y, x)
            {
                store_oper[i].A = - store_oper[i-1].B;
                store_oper[i].C = - store_oper[i-1].D;
                store_oper[i].B = store_oper[i-1].A;
                store_oper[i].D = store_oper[i-1].C;
                store_oper[i].offset_x = - store_oper[i-1].offset_y;
                store_oper[i].offset_y =  store_oper[i-1].offset_x;
            }
            else // 90 deg clkwise -> (x, y) -> (y, -x)
            {
                store_oper[i].A =  store_oper[i-1].B;
                store_oper[i].C =  store_oper[i-1].D;
                store_oper[i].B = - store_oper[i-1].A;
                store_oper[i].D = - store_oper[i-1].C;
                store_oper[i].offset_x =  store_oper[i-1].offset_y;
                store_oper[i].offset_y = - store_oper[i-1].offset_x;
            } 
        }
        else
        {
            ll p;
            cin>>p;
            if(type==3) // ref about x=p (x, y) -> (2p-x, y)
            {
                store_oper[i].A = - store_oper[i-1].A;
                store_oper[i].C = - store_oper[i-1].C;
                store_oper[i].B = store_oper[i-1].B;
                store_oper[i].D = store_oper[i-1].D;
                store_oper[i].offset_x =  -store_oper[i-1].offset_x + 2*p;
                store_oper[i].offset_y =  store_oper[i-1].offset_y;
            }
            else // ref about y=p (x, y) -> (x, 2p-y)
            {
                store_oper[i].A =  store_oper[i-1].A;
                store_oper[i].C =  store_oper[i-1].C;
                store_oper[i].B = - store_oper[i-1].B;
                store_oper[i].D = - store_oper[i-1].D;
                store_oper[i].offset_x =  store_oper[i-1].offset_x;
                store_oper[i].offset_y =  -store_oper[i-1].offset_y + 2*p;
            }            
        }        
    }
    int q; cin>>q;
    while(q--)
    {
        int a, b;
        cin>>a>>b;
        b--;
        pll new_point;
        new_point = transformate(point[b], store_oper[a]);
        cout<<new_point.ff<<" "<<new_point.ss<<'\n';
    }
}   
