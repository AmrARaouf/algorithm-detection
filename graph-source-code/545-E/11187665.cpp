//Language: GNU C++


/*   W          w           w        mm          mm             222222222       7777777777777    */
/*    W        w w         w        m  m        m  m          222        22              7777    */
/*    w        w w         w        m  m        m  m                     22              777     */
/*     w      w   w       w        m    m      m    m                    22              77      */
/*     w      w    w      w        m    m      m    m                 222                77      */
/*      w    w      w    w        m      m    m      m              222                  77      */
/*      w    w      w    w        m      m    m      m            222                    77      */
/*       w  w        w  w        m        m  m        m         222                      77      */
/*       w  w        w  w        m        m  m        m      222                         77      */
/*        ww          ww        m          mm          m     222222222222222             77      */

//#pragma comment(linker, "/STACK:102400000,102400000")

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

typedef long long ll;
const int maxn=300005;
const ll inf=((ll)1<<50)-1;
struct Edge
{
  int from,to,dist,id;
};
struct HeapNode
{
  int d,u;
  bool operator < (const HeapNode& rhs)const
  {
    return d>rhs.d;
  }
};
struct Dijkstra
{
  int n,m;
  vector<Edge>edges;
  vector<int>G[maxn];
  bool done[maxn];
  ll d[maxn];
  int p[maxn];
  int cost[maxn];
  void init(int n)
  {
    this->n=n;
    for(int i=0;i<n;i++)
    {
      G[i].clear();
    }
    edges.clear();
  }
  void AddEdge(int from,int to,int dist,int id)
  {
    edges.push_back((Edge){from,to,dist,id});
    m=edges.size();
    G[from].push_back(m-1);
  }
  void dijkstra(int s)
  {
    priority_queue<HeapNode>Q;
    while(!Q.empty())Q.pop();
    memset(p,-1,sizeof(p));
    for(int i=0;i<n;i++)
    {
      d[i]=inf;
    }
    d[s]=0;
//    memset(done,0,sizeof(done));
    Q.push((HeapNode){0,s});
    while(!Q.empty())
    {
      HeapNode x=Q.top();
      Q.pop();
      int u=x.u;
//      if(done[u])continue;
//      done[u]=true;
      for(int i=0;i<G[u].size();i++)
      {
        Edge e=edges[G[u][i]];
        if(d[e.to]>d[u]+e.dist)
        {
          d[e.to]=d[u]+e.dist;
          p[e.to]=e.id;
          Q.push((HeapNode){d[e.to],e.to});
        }
        else if(d[e.to]==d[u]+e.dist)
        {
          if(cost[p[e.to]]>cost[e.id])
          {
            p[e.to]=e.id;
          }
        }
      }
    }
    ll ans=0;
    for(int i=0;i<n;i++)
    {
      if(i==s)
      {
        continue;
      }
      ans+=(ll)cost[p[i]];
    }
    printf("%I64d\n",ans);
    for(int i=0;i<n;i++)
    {
      if(i==s)
      {
        continue;
      }
      printf("%d ",p[i]+1);
    }
    printf("\n");
  }
  void debug()
  {
    for(int i=0;i<n;i++)
    {
      printf("d[%d]=%d\n",i,d[i]);
    }
  }
  void debug2()
  {
    for(int i=0;i<n;i++)
    {
      printf("p[%d]=%d id=%d dist=%d\n",i,p[i],edges[p[i]].id,edges[p[i]].dist);
    }
  }
}Dij;
int main()
{
  #ifdef ONLINE_JUDGE
  #else
    freopen("test.in","r",stdin);
  #endif
  int nn,mm;
  while(~scanf("%d%d",&nn,&mm))
  {
    Dij.init(nn);
    for(int i=0;i<mm;i++)
    {
      int u,v,c;
      scanf("%d%d%d",&u,&v,&c);
      Dij.AddEdge(u-1,v-1,c,i);
      Dij.AddEdge(v-1,u-1,c,i);
      Dij.cost[i]=c;
    }
    int st;
    scanf("%d",&st);
    Dij.dijkstra(st-1);
    //Dij.debug2();
    //cout<<inf<<endl;
  }
  return 0;
}
