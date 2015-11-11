//Language: MS C++


#include<iostream>
#include<cmath>
#include<vector>
#include<set>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
#define y1 fjkdsghfasj
#define y0 dkgfsddkjsf

typedef long long ll;
#define pb push_back
#define mp make_pair
const double pi=2*acos(0.0);
#define FOR(i,a,b) for(i=a;i<=b;i++)

set< pair<ll,int> >q;
vector< pair<int,ll> > g[1001];
int x,y,i,j,n,m,s,t,v;
ll D[1001][1001],uns[1001],U,w,T[1001],C[1001];

int main()
{
 // freopen("input.txt","r",stdin);
  U=1000000000000000LL;

  cin>>n>>m;
  cin>>s>>t;
  FOR(i,1,m)
  {
          cin>>x>>y>>w;
          g[x].pb(mp(y,w));
          g[y].pb(mp(x,w));
  }

  FOR(i,1,n)
  FOR(j,1,n)
  if(i==j)D[i][j]=0;else D[i][j]=U;

  FOR(i,1,n)
  {
          FOR(j,1,n)uns[j]=U;

          q.clear();
          uns[i]=0;
          q.insert(mp(0,i));

          for(;;)
          {
                  if(q.empty())break;

                  v=q.begin()->second;
                  q.erase(q.begin());

                  FOR(j,0,(int)g[v].size()-1)
                  {
                          int to;
                          ll len;

                          to=g[v][j].first;
                          len=uns[v]+g[v][j].second;

                          if(len<uns[to])
                          {
                                  q.erase(mp(uns[to],to));
                                  uns[to]=len;
                                  q.insert(mp(uns[to],to));
                          }
                  }
          }

          FOR(j,1,n)
          {
                  D[i][j]=min(D[i][j],uns[j]);
                  D[j][i]=min(D[j][i],uns[j]);
          }
  }


  FOR(i,1,n)cin>>T[i]>>C[i];
  FOR(i,1,n)
  {
          g[i].clear();
          FOR(j,1,n)if(i!=j && D[i][j]<=T[i])
          {
                  g[i].pb(mp(j,C[i]));
          }
  }

      
      FOR(i,1,n)uns[i]=U;
      q.clear();
          uns[s]=0;
          q.insert(mp(0,s));

          for(;;)
          {
                  if(q.empty())break;

                  v=q.begin()->second;
                  q.erase(q.begin());

                  FOR(j,0,(int)g[v].size()-1)
                  {
                          int to;
                          ll len;

                          to=g[v][j].first;
                          len=uns[v]+g[v][j].second;

                          if(len<uns[to])
                          {
                                  q.erase(mp(uns[to],to));
                                  uns[to]=len;
                                  q.insert(mp(uns[to],to));
                          }
                  }
          }

          if(uns[t]>=10000000000000LL)cout<<"-1"<<endl;else cout<<uns[t]<<endl;

} 