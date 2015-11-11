//Language: GNU C++


#include <algorithm>
#include <stdio.h>
#include <vector>
#define  fi        first
#define  se        second
#define  maxn      100002
#define  maxm      300002
#define  pb        push_back
using    namespace std;
typedef  pair<int,int> pi;

int n,m,last;
int S[maxn];
int sz[2][maxn];
bool edge[maxm];
bool mark[2][maxn];
vector<pi>ans;
vector<pi>adj[2][maxn];

void dfs2(int node)
{
  mark[1][node]=true;
  for(int i=0 ; i<sz[1][node] ; i++)
    if(!mark[1][adj[1][node][i].fi])
      dfs2(adj[1][node][i].fi);
}

void dfs1(int node)
{
  mark[0][node]=true;
  for(int i=0 ; i<sz[0][node] ; i++)
    if(!edge[adj[0][node][i].se])
    {
      edge[adj[0][node][i].se]=true;
      ans.pb(pi(node,adj[0][node][i].fi));
      adj[1][adj[0][node][i].fi].pb(pi(node,0));
      sz[1][adj[0][node][i].fi]++;
      if(!mark[0][adj[0][node][i].fi])
        dfs1(adj[0][node][i].fi);
    }
  S[++last]=node;
}

int main()
{
  scanf("%d%d",&n,&m);
  for(int i=0,x,y ; i<m ; i++)
  {
    scanf("%d%d",&x,&y);
    adj[0][x].pb(pi(y,i));
    adj[0][y].pb(pi(x,i));
    sz[0][x]++;
    sz[0][y]++;
  }
  dfs1(1);
  bool ok=true;
  for(int i=n ; i>=1 ; i--)
    if(!mark[1][S[i]])
    {
      if(i!=n)    { ok=false;  break; }
      dfs2(S[i]);
    }
  if(!ok) printf("0\n");
  else
    for(int i=0 ; i<m ; i++)
      printf("%d %d\n",ans[i].fi,ans[i].se);
  return 0;
}
