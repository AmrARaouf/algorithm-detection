//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,int> edge;
int n,m,k;
vector<edge>g[100003];
vector<pii>vis;
ll dis[100003];
int mark[100003],sum[100003];
void dij()
{
 for(int i=0;i<100003;i++)
 dis[i]=1e15;
 priority_queue<edge>q;
 q.push(edge(pii(0,0),0));
 while(q.size())
{ 
 int w=q.top().second;
 int d=-q.top().first.first;
 int v=q.top().first.second;
 q.pop();
 if(dis[w]!=1e15)
 continue; 
 dis[w]=d;
 mark[w]=v;
 for(int i=0;i<g[w].size();i++)
 {
  int nxt=g[w][i].first.first;
  ll nw=d+g[w][i].first.second;
  int xx=g[w][i].second;
  if(nw<dis[nxt])
   q.push(edge(pii(-nw,xx),nxt));
 }
 }
}
int main()
{
  scanf("%d %d %d",&n,&m,&k);
  for(int i=0;i<m;i++)
  {
   int u,v,d;
   scanf("%d %d %d ",&u,&v,&d);
  u--;v--;
  g[u].push_back(edge(pii(v,d),1));
  g[v].push_back(edge(pii(u,d),1));
  //vis.push_back(pii(u,d));
  }
 for(int i=0;i<k;i++)
 {
 int u,v,d;
   scanf("%d %d",&u,&d);
  u--;
  g[u].push_back(edge(pii(0,d),0));
  g[0].push_back(edge(pii(u,d),0));
  vis.push_back(pii(u,d));
 }
  dij();
   int ans=0;
 for(int i=0;i<k;i++)
 {
  int a=vis[i].first,d=vis[i].second;
  if(d>dis[a])
   ans++;
  else
   {
    if(mark[a])ans++;
    else
    sum[a]++;
   }
  }
  for(int i=0;i<n;i++)
  if(sum[i])
   ans+=sum[i]-1;
  printf("%d\n",ans);
 return 0;
 }
