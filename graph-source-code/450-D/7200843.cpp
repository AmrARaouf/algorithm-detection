//Language: GNU C++


//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: D
// Verdict: 
//******************************************************************
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define dw(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define sz(s) (int)s.size()
#define read(x) cin >> x
#define read2(x,y) cin >> x >> y
#define read3(x,y,z) cin >> x >> y >> z
#define out(x) cout << x
#define DEBUG(x) cout << #x << " = " << x << endl

#define ull unsigned long long
#define ll long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

//8 huong
//int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1};
//int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};

//horse
//int dx[] = {-2,-2,-1,-1, 1, 1, 2, 2};
//int dy[] = {-1, 1,-2, 2,-2, 2,-1, 1};

const int dx[] = {-1, 0, 0, 1};
const int dy[] = { 0,-1, 1, 0};

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a)  (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 100000

vector< pair<ll,ll> > a[maxN+5], train;
set< pair<ll,ll> > s;
ll dist[maxN+5];
bool check[maxN+5];
int n,m,k;

void dijsktra()
{
    dist[1] = 0;
    s.insert(mp(0,1));
    
    while(!s.empty())
    {
        pair<ll,ll> p = *s.begin();
        
        s.erase(p);
        
        ll d = p.ff;
        ll u = p.ss;
        
        rep(i,sz(a[u]))
        {
            ll v = a[u][i].ff;
            ll w = a[u][i].ss;
            
            if(dist[v] >= dist[u] + w) check[v] = false;
            
            if(dist[v] > dist[u] + w)
            {
                if(dist[v] != 1000000000000000000LL) s.erase(mp(dist[v],v));
                
                dist[v] = dist[u] + w;
                s.insert(mp(dist[v],v));
            }
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("D.INP","r",stdin);
    freopen("D.OUT","w",stdout);
    #endif
    
    read3(n,m,k);
    
    rep(i,m)
    {
        ll u,v,w;
        read3(u,v,w);
        
        a[u].pb(mp(v,w));
        a[v].pb(mp(u,w));
    }
    
    fr(i,1,n)
    {
        dist[i] = 1000000000000000000LL;
        check[i] = true;
    }
    
    rep(i,k)
    {
        ll t,y;
        read2(t,y);
        
        if(dist[t] > y)
        {
            if(dist[t] != 1000000000000000000LL) s.erase(mp(dist[t],t));
            dist[t] = y;
            s.insert(mp(dist[t],t));
        }
        
        train.pb(mp(t,y));
    }
    
    dijsktra();
    sort(all(train));
    
    int ans = 0;
    rep(i,sz(train))
    {
        ll u = train[i].ff;
        ll w = train[i].ss;
        
        if(dist[u] <= w) ans++;
    }
    
    fr(i,2,n) if(check[i]) ans--;
    cout << ans << endl;
    
    return 0;
}

