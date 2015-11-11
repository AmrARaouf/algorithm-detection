//Language: GNU C++


#include<stdio.h>
#include<string.h>
#include<algorithm>
#define maxn 2222
using namespace std;
int dfn[maxn],low[maxn],sta[maxn],st[maxn],map[maxn][maxn];
int index,top,n,cnt;
void tarjan(int u)
{
    int i,v;
    dfn[u]=low[u]=++index;
    sta[u]=1;
    st[++top]=u;
    for(i=1;i<=n;i++)
    {
        if(!map[u][i]) continue;
        v=i;
        if(dfn[v]==-1)
        {
            tarjan(v);
			low[u]=min(low[u],low[v]);
        }
        else if(sta[v]&&dfn[v]<low[u]) low[u]=dfn[v];
    }
    if(dfn[u]==low[u])
    {
        cnt++;
        do
        {
            v=st[top--];
            sta[v]=0;
        }while(u!=v);
    }
}

void solve()
{
    int i;
    top=cnt=index=0;
    memset(dfn,-1,sizeof(dfn));
	memset(sta,0,sizeof(sta));
    for(i=1;i<=n;i++)
        if(dfn[i]==-1) tarjan(i);
}

int main()
{
	int i,j,k;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
		 for(j=1;j<=n;j++)
		  {scanf("%d",&k);
		   if(k)map[i][j]=1;
		  }
		  solve();
		  if(cnt>1)printf("NO\n");
		  else printf("YES\n");
	}
}

 	   									 		 	  		 	