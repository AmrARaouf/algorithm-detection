//Language: GNU C++


#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cstdio>

using namespace std;

#define mp make_pair
#define eps 1e-10
#define INFINITE 1e9

const int MAXN = 2010 ;

double a , b ;
double ax[MAXN] , ay[MAXN] , bx[MAXN] , by[MAXN] , dist[MAXN] ;
bool visit[MAXN] ;
int N ;
// ax <= bx , ay <= by
// st->line[0]  ed->line[1]

inline double sq(double x){
      return x*x ;
}
inline void insert(double x1_,double y1_,double x2_,double y2_){
      if (x1_ > x2_) swap(x1_ , x2_) ;
      if (y1_ > y2_) swap(y1_ , y2_) ;
      ax[N]=x1_, ay[N] = y1_, bx[N] = x2_ , by[N] = y2_ ; N++ ;
}
inline double getdis(int u,int v){
      return sq(max(0.0,max(ax[u],ax[v])-min(bx[u],bx[v])))+sq(max(0.0,max(ay[u],ay[v])-min(by[u],by[v])));
}

void dijkstra(){
      for (int i = 0 ; i < N ; i++)
      {
            dist[i] = INFINITE ;
            visit[i] = 0 ;
      }
      priority_queue<pair<double , int> > q ;
      q.push(mp(0,0)) ; dist[0] = 0 ;
      while (!q.empty()){
            int u = q.top().second , dis = q.top().first; q.pop() ;
            if (visit[u]) continue ;
            visit[u] = 1 ;
            if (u == 1) break ;
            for (int v = 0 ; v < N ; v++){
                  if (visit[v]) continue ;
                  double d = getdis(u,v) ;
                  if (d <= a*a){
                        if (v==1)
                        {
                              if (dist[u]+sqrt(d) < dist[v]){
                                    q.push(mp(-(dist[u]+sqrt(d)),v));
                                    dist[v] = dist[u] + sqrt(d) ;
                              }
                        }
                        else
                        {
                              if (dist[u]+a+b < dist[v]){
                                    q.push(mp(-(dist[u]+a+b),v));
                                    dist[v] = dist[u] + a + b;
                              }
                        }
                  }
            }
      }
}
int main()
{
      scanf("%lf%lf",&a,&b);
      double tx , ty , sx , sy ;
      scanf("%lf%lf%lf%lf",&tx,&ty,&sx,&sy);
      N=0;
      insert(tx,ty,tx,ty);
      insert(sx,sy,sx,sy);
      int M ; scanf("%d",&M);
      while (M--){
            scanf("%lf%lf%lf%lf",&tx,&ty,&sx,&sy);
            insert(tx,ty,sx,sy);
      }
      dijkstra() ;
      if (dist[1]==INFINITE)
            printf("%d\n",-1);
      else
            printf("%.10f\n",dist[1]);
      return 0 ;
}
