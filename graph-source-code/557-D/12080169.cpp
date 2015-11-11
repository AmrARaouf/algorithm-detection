//Language: GNU C++11


#include<stdio.h>
#include<string.h>
#include<algorithm>
#define LL long long
using namespace std;
int Now,Head[200005],Point[200005],Next[200005],vis[200005];
LL cnt0,cnt1,ans0;
void add(int x,int y)
{
  Next[++Now]=Head[x];
  Head[x]=Now;
  Point[Now]=y;
}
void dfs(int u,int flag)
{
  if (flag) cnt1++;
  else cnt0++;
  vis[u]=flag;
  for (int i=Head[u];i!=0;i=Next[i])
  {
	int v=Point[i];
	if (vis[v]!=-1)
	{
	  if (vis[v]==flag) ans0++;
	  continue;
	}
	dfs(v,1-flag);
  }
}
int main()
{
  LL n,m,ans1;
  int x,y,ans2,i;
  scanf("%I64d%I64d",&n,&m);
  Now=0;
  for (i=1;i<=m;i++)
  {
	scanf("%d%d",&x,&y);
	add(x,y); add(y,x);
  }
  if (m==0){printf("3 %I64d\n",n*(n-1)*(n-2)/6);return 0;}
  memset(vis,-1,sizeof(vis));
  ans0=0; ans1=0; ans2=1;
  for (i=1;i<=n;i++)
	if (vis[i]==-1)
	{
	  cnt0=cnt1=0;
	  dfs(i,0);
	  if (cnt1>=2) ans1+=cnt1*(cnt1-1)/2;
	  if (cnt0>=2) ans1+=cnt0*(cnt0-1)/2;
	  if (cnt1+cnt0>2) ans2=0;
	}
  if (ans2) printf("2 %I64d\n",(n-2)*m);
  else if (ans0!=0) printf("0 1\n");
  else printf("1 %I64d\n",ans1);
  return 0;
}