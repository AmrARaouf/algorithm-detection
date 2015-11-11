//Language: GNU C++


//author: Naimul
//task:
//algo:
//date:

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;
#define REP(i,n) for(int i=0, _e(n); i<_e; i++)
#define FOR(i,a,b) for(int i(a), _e(b); i<=_e; i++)
#define FORD(i,a,b) for(int i(a), _e(b); i>=_e; i--)
#define FORIT(i, m) for (__typeof((m).begin()) i=(m).begin(); i!=(m).end(); ++i)
#define SET(t,v) memset((t), (v), sizeof(t))
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize( unique( ALL(c) ) - (c).begin() )
#define pb push_back
#define sz(t) ((int)((t).size()))
#define mp make_pair
typedef pair<int,int> ii;
typedef vector<int> VI;
typedef vector< vector<int> > VVI;
typedef long long LL;
#define D(x) if(1) cout << __LINE__ <<" "<< #x " = " << (x) << endl;
#define D2(x,y) if(1) cout << __LINE__ <<" "<< #x " = " << (x)  <<", " << #y " = " << (y) << endl;
#define PRINT(x) FORIT(i,x){if(i!=x.begin())printf(" ");cout<<*i; }printf("\n");

#define INF 1000000007

namespace MCF {
   #define MAXN 100010
   #define MAXM 100010
   #define wint LL
   #define cint LL
   const wint wEPS = 0;
   const wint wINF = 1001001001001001001LL;
   const cint cEPS = 0;
   const cint cINF = wINF;
   int n, m, ptr[MAXN], next[MAXM], zu[MAXM];
   wint capa[MAXM], tof;
   cint cost[MAXM], toc, d[MAXN], pot[MAXN];
   int vis[MAXN], pree[MAXN];
   void init(int _n) {
      n = _n+2;
      m = 0;
      memset(ptr, ~0, n << 2);
   }
   void add(int u, int v, wint w, cint c) {
      next[m] = ptr[u]; ptr[u] = m; zu[m] = v; 
      capa[m] = w; cost[m] = +c; ++m;
      next[m] = ptr[v]; ptr[v] = m; 
      zu[m] = u; capa[m] = 0; cost[m] = -c; ++m;
   }
   bool flow(int src, int ink, wint flo = wINF) {
      wint f;
      cint c, cc;
      int i, u, v;
      memset(pot, 0, n * sizeof(cint));
   //*
      for (bool cont = 1; cont; ) {
         cont = 0;
         REP(u,n) for (i = ptr[u]; ~i; i = next[i]) 
         if (capa[i] > wEPS) {
            if (pot[zu[i]] > pot[u] + cost[i] + cEPS) {
               pot[zu[i]] = pot[u] + cost[i]; cont = 1;
            }
         }
      }
   //*/
      for (toc = 0, tof = 0; tof + wEPS < flo; ) {
         typedef pair<cint,int> node;
         priority_queue< node,vector<node>,greater<node> > q;
         REP(z,n) { d[z] = cINF; vis[z] = 0; }
         for (q.push(make_pair(d[src] = 0,src));!q.empty();) {
            c = q.top().first; u = q.top().second; q.pop();
            if (vis[u]++) continue;
            for (i = ptr[u]; ~i; i = next[i]){ 
               if (capa[i] > wEPS) {
                  cc = c + cost[i] + pot[u] - pot[v = zu[i]];
                  if (d[v] > cc) { 
                     q.push(make_pair(d[v] = cc, v)); 
                     pree[v] = i; 
                  }
               }
            }
         }
         if (!vis[ink]) return 0;
         f = flo - tof;
         for (v = ink; v != src; v = zu[i ^ 1]) { 
            i = pree[v]; f=min(f, capa[i]); }
         for (v = ink; v != src; v = zu[i ^ 1]) { 
            i = pree[v]; capa[i] -= f; capa[i ^ 1] += f; }
         tof += f;
         toc += f * (d[ink] - pot[src] + pot[ink]);
         //tof=maxflow,toc=mincost
         REP(u,n) pot[u] += d[u];
      }
      return 1;
   }
}

int main(){

    int n , k;
    cin >> n >> k;

    int v[55][55];
    REP( i,n ) REP( j, n ) cin >> v[i][j];
    int lo = 0, hi = INF;
    while ( lo <= hi ) {
        int mid = (lo+hi)/2;
        MCF::init( n );
        REP( i, n ) REP( j, n ) if( v[i][j] ){
            MCF::add( i, j, v[i][j], 0 );
            MCF::add( i, j, INF, 1 );
        }
        if( MCF::flow(0,n-1,mid) && MCF::toc <= k ) lo = mid+1;
        else hi = mid-1;
    }
    cout << lo-1 << "\n";

    return 0;
}
