//Language: GNU C++


#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int maxn=111111;
int bleg[maxn],n,m;
int ans[maxn];
struct node
{
    int u,v,w,cnt;
}edge[maxn*4];
const int inf=0x7fffffff;
int head[maxn],low[maxn],num,vis[maxn];
int tol,tim,dfn[maxn],stk[maxn],tp;
struct Node
{
    int to,next,cnt;
    bool vis,bge;
}edges[maxn*4];
void INIT()
{
    tol=0,tim=1;
    memset(head,-1,sizeof(head));
    memset(dfn,-1,sizeof(dfn));
}
void init_edge()
{
	int u,tot=tol;
	tol=0,tim=1;
 	for(int i=0;i<tot;i++)
  	{
  		u=edges[i].to;
  		head[u]=-1;
  		dfn[u]=-1;
    }
}
void add(int a,int b,int c)
{
    edges[tol].to=b;
    edges[tol].cnt=c;
	edges[tol].bge=false;
    edges[tol].next=head[a];
    edges[tol].vis=false;
    head[a]=tol++;
}
void tarjan(int u)
{
    int i,v;
    vis[u]=0;
    dfn[u]=low[u]=tim++;
    for(i=head[u];i!=-1;i=edges[i].next)
    {
        v=edges[i].to;
        if(edges[i].vis) continue;
        edges[i].vis=edges[i^1].vis=true;        
		if(dfn[v]==-1)
        {
			
            tarjan(v);        
            low[u]=min(low[u],low[v]);
            if(dfn[u]<low[v])
            {
            	ans[edges[i].cnt]=2;
            }
        }
        else low[u]=min(low[u],dfn[v]); 
    }
}
bool cmp(node a,node b)
{
    return a.w<b.w;
}
int Find (int x)
{
    int p,y=x;
    while(y!=bleg[y])
    y=bleg[y];
    while(x!=bleg[x])
    {
        p=bleg[x];
        bleg[x]=y;
        x=p;
    }
    return y;
}
void Union(int a,int b)
{
    int ra=Find(a),rb=Find(b);
    if(rand()%2) bleg[ra]=rb;
    else bleg[rb]=ra;
}
int main()
{
    int i,j,las=-1,len,tol,u,v,c;
    scanf("%d%d",&n,&m);
    INIT();
    for(i=0;i<=n;i++)
    bleg[i]=i;
    for(i=0;i<m;i++)
    scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w),edge[i].cnt=i;
    sort(edge,edge+m,cmp);
    memset(ans,0,sizeof(ans));
    memset(vis,0,sizeof(vis));
    for(i=0;i<m;i++)
    {
        if(Find(edge[i].u)!=Find(edge[i].v))
        {
            len=edge[i].w;
            init_edge(),num=0,tp=0;
            for(j=i;j<m&&j>las;j++)
            {
                if(edge[j].w>len) break;
                las=j;
                u=Find(edge[j].u),v=Find(edge[j].v),c=edge[j].cnt;
                if(Find(edge[j].u)!=Find(edge[j].v))
                {
					ans[edge[j].cnt]=1;
					if(!vis[u])
					vis[u]=1,stk[tp++]=u;
					if(!vis[v])
					vis[v]=1,stk[tp++]=v;
					add(u,v,c);
					add(v,u,c);
				}
            }
            for(j=i;j<m&&j<=las;j++)
            {
            	if(Find(edge[j].u)!=Find(edge[j].v))
				{
					Union(edge[j].u,edge[j].v);
				}
            }
            while(tp>0)
            {
            	u=stk[--tp];
            	if(dfn[u]==-1) tarjan(u);
            }
        }
    }
    for(i=1;i<=n;i++)
    if(dfn[i]==-1) tarjan(i);
    for(i=0;i<m;i++)
    {
    	if(ans[i]==0) printf("none\n");
    	else if(ans[i]==2) printf("any\n");
    	else if(ans[i]==1) printf("at least one\n");
    }
}
/*
6 6
1 2 1
2 3 1
3 4 1
3 5 1
4 6 1
5 6 1

4 5
1 2 101
1 3 100
2 3 2
2 4 2
3 4 1
*/
