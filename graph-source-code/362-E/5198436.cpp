//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define INF 1000000000
#define N 51
int n,k,pre[N],dis[N],inq[N],tot,hh[N],start,end;
struct node
{
	int u,v,w,c,next;
}edge[6*N*N];
void init()
{
	tot=0;
	memset(hh,-1,sizeof(hh));
}
void add(int u,int v,int w,int c)
{
	edge[tot].u=u; edge[tot].v=v;
	edge[tot].w=w; edge[tot].c=c;
	edge[tot].next=hh[u];
	hh[u]=tot++;
}
int spfa()
{
	queue<int> q;
	memset(inq,0,sizeof(inq));
	memset(pre,-1,sizeof(pre));
	for(int i=1;i<=n;i++) dis[i]=INF;
	dis[start]=0; inq[start]=1;
	q.push(start);
	while(!q.empty())
	{ //printf("donw \n");
		int u=q.front(); q.pop();
		for(int i=hh[u];i!=-1;i=edge[i].next)
		{
			int v=edge[i].v;
			if(edge[i].w && dis[v]>dis[u]+edge[i].c)
			{
				pre[v]=i; dis[v]=dis[u]+edge[i].c;
				if(!inq[v])
				{
					inq[v]=1; q.push(v);
				}
			}
		}
		inq[u]=0;
	}
	if(dis[end]==INF) return -1;
	return dis[end];
}
int maxx()
{
	int re=0;
	while(1)
	{
		int now=spfa(); //printf("now: %d\n",now);
		if(now<0) break;
		int tmp=INF;
		for(int i=pre[end];i!=-1;i=pre[edge[i].u])
			tmp=min(tmp,edge[i].w);
		if(k<now) break;
		else
		{
			if(now==0) re+=tmp;
			else
			{
				tmp=min(tmp,k/now);
				re+=tmp;
				k-=now*tmp;
			}
			for(int i=pre[end];i!=-1;i=pre[edge[i].u])
				edge[i].w-=tmp,edge[i^1].w+=tmp;
		}
	}
	return re;
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&k);
	int tmp;
	init();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&tmp);
			//if(i==n) continue;
			if(!tmp) continue;
			add(i,j,tmp,0); add(j,i,0,0);
			add(i,j,INF,1); add(j,i,0,1);
		}
	}
	start=1; end=n;
	int ans=maxx();
	printf("%d\n",ans);
	return 0;
}
