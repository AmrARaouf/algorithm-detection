//Language: GNU C++


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<set>
#include<math.h>
using namespace std;
int n,m;
struct hh
{
    int from,to,w,next;
}edge[300000];
int box[101000];
void add(int from,int to,int w,int k)
{
    edge[k].from=from;
    edge[k].to=to;
    edge[k].w=w;
    edge[k].next=box[from];
    box[from]=k;
}
set<int>s[100100];
int visit[100100];
int q[10000000];
int dist[101000];
int main()
{
  //freopen("in.txt","r",stdin);
  memset(box,-1,sizeof(box));
  memset(visit,0,sizeof(visit));
  int i;
  int top=0;
  scanf("%d%d",&n,&m);
  for(i=0;i<m;++i)
  {
      int x,y,z;
      scanf("%d%d%d",&x,&y,&z);
      add(x,y,z,top++);
      add(y,x,z,top++);
  }
  for(i=1;i<=n;++i)
  {
      dist[i]=2100000000;
      s[i].clear();
      int t;
      scanf("%d",&t);
      for(int j=0;j<t;++j)
      {
          int x;
          scanf("%d",&x);
          s[i].insert(x);
      }
  }
  int head=0,end=1;
  q[0]=1;
  visit[1]=1;
  dist[1]=0;
  while(head<end)
  {

      int v=q[head++];
      visit[v]=0;
      int dd=dist[v];
      while(s[v].count(dd)==1)dd++;
      for(i=box[v];i!=-1;i=edge[i].next)
      {
          int to=edge[i].to;
          if(dist[to]-edge[i].w>dd)
          {
               dist[to]=dd+edge[i].w;

          if(!visit[to]){
               q[end++]=to;
               visit[to]=1;
          }
          }
      }


  }

  if(dist[n]==2100000000)printf("-1\n");
  else printf("%d\n",dist[n]);
}
