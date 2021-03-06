//Language: GNU C++


#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int maxn=50+10;
const int INF=1000000000;
int a[maxn],p[maxn],dis[maxn],inq[maxn],n,k,s,t,f[maxn][maxn],ss;
struct edge
{
  int from,to,cap,cost,flow;
};
vector<edge> edges;
vector<int> g[maxn];
void addedge(int from,int to,int cap,int cost)
{
  edges.push_back((edge){from,to,cap,cost});
  edges.push_back((edge){to,from,0,-cost});
  int m1=edges.size();
  g[from].push_back(m1-2);
  g[to].push_back(m1-1);
}
bool bellmanford(int s,int t,int &flow,int &cost)
{
  for(int i=s;i<=t;i++) dis[i]=INF;
  memset(inq,0,sizeof(inq));
  memset(a,0,sizeof(a));
  queue<int> Q;Q.push(s);inq[s]=1;dis[s]=0;a[s]=INF;
  while(!Q.empty())
  {
    int x=Q.front();Q.pop();inq[x]=0;
    for(int i=0;i<g[x].size();i++)
    {
      edge e=edges[g[x][i]];
      if(e.cap>e.flow&&dis[e.to]>dis[x]+e.cost)
      {
        dis[e.to]=dis[x]+e.cost;
        a[e.to]=min(a[x],e.cap-e.flow);
        p[e.to]=g[x][i];
        if(!inq[e.to])
        {
          inq[e.to]=1;
          Q.push(e.to);
        }
      }
    }
  }
  //cout<<a[t]<<' '<<dis[t]<<endl;
  if(dis[t]>=INF) return false;
  int u=t;
  if(cost+dis[t]*a[t]>k)
  {
    flow+=(k-cost)/dis[t];
    cost=k;
    return false;
  }
  flow+=a[t];cost+=dis[t]*a[t];
  while(u!=s)
  {
    edges[p[u]].flow+=a[t];
    edges[p[u]^1].flow-=a[t];
    u=edges[p[u]].from;
  }
  return true;
}
int mincost()
{
  int flow=0,cost=0,ans=0;
  while(bellmanford(s,t,flow,cost));
  return flow;
}
int main()
{
  //freopen("362E.in","r",stdin);
  //freopen("362E.out","w",stdout);
  scanf("%d%d",&n,&k);
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
      scanf("%d",&f[i][j]);
      if(f[i][j]) addedge(i,j,f[i][j],0);
    }
  for(int i=1;i<=n;i++) 
    for(int j=1;j<=n;j++)
      if(f[i][j]) addedge(i,j,k,1);
  s=1;t=n;
  printf("%d\n",mincost());
  return 0;
}
  