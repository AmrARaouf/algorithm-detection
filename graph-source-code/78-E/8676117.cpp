//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 10000000
#define N 210
#define M 21000
struct Edge
{
    int v,w;
}edge[M];
int adj[M],head[N],e;
void addedge(int u,int v,int w)
{
    edge[e].v=v;edge[e].w=w;adj[e]=head[u];head[u]=e++;
    edge[e].v=u;edge[e].w=0;adj[e]=head[v];head[v]=e++;
}
int S,T;

int dist[N],q[N*2],arc[N],gap[N],inq[N],pre[N];
int SAP(int s,int t)
{
    memset(arc,-1,sizeof(arc));
    memset(pre,-1,sizeof(pre));
    int qf=0,qr=0;
    q[qr++]=t;inq[t]=1;gap[0]++;dist[t]=0;
    while(qf<qr)
    {
        int u=q[qf++];
        for(int i=head[u];i!=-1;i=adj[i])
            if(!inq[edge[i].v])
        {
            int v=edge[i].v;
            q[qr++]=v;
            inq[v]=1;
            dist[v]=dist[u]+1;
            gap[dist[v]]++;
            arc[v]=head[v];
        }
    }
    int low=INF,u=s,ans=0;
    pre[s]=s;
    while(dist[s]<t)
    {
        bool flag=false;
        for(int &i=arc[u];i!=-1;i=adj[i])
            if(edge[i].w && dist[edge[i].v]+1==dist[u])
        {
            flag=true;
            low=min(low,edge[i].w);
            pre[edge[i].v]=u;
            u=edge[i].v;
            if(u==t)
            {
                while(u!=s)
                {
                    u=pre[u];
                    edge[arc[u]].w-=low;
                    edge[arc[u]^1].w+=low;
                }
                ans+=low;
                low=INF;
            }
            break;
        }
        if(flag)
            continue;
        int mindis=t+1;
        for(int i=head[u];i!=-1;i=adj[i])
            if(edge[i].w && mindis>dist[edge[i].v])
        {
           mindis=dist[edge[i].v];
           arc[u]=i;
        }
        gap[dist[u]]--;
        if(gap[dist[u]]==0)
            return ans;
        dist[u]=mindis+1;
        gap[dist[u]]++;
        u=pre[u];
    }
    return ans;
}

char str[12][12],str2[12][12];
int sci[12][12],ca[12][12],stone[62][12][12];
int dp[62][12][12][12][12];
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int n,t;

void expand()
{
    for(int k=1;k<=t;++k)
        for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
    {
        if(stone[k-1][i][j]==1)
            stone[k][i][j]=1;
        else if(stone[k-1][i][j]==2)
            stone[k][i][j]=2;
        else
        {
            int nx,ny;
            for(int z=0;z<4;++z)
            {
                nx=i+dir[z][0];
                ny=j+dir[z][1];
                if(nx>=1&&nx<=n&&ny>=1&&ny<=n)
                {
                    if(stone[k-1][nx][ny]==2)
                        stone[k][i][j]=2;
                }
            }
        }
    }
}
int vis[12][12];
void dfs(int x,int y,int nowx,int nowy,int k)
{
    vis[nowx][nowy]=1;
    dp[k][x][y][nowx][nowy]=1;
    if(k>=t || stone[k][nowx][nowy])
        return;
    int nx,ny;
    for(int z=0;z<4;++z)
    {
        nx=nowx+dir[z][0];
        ny=nowy+dir[z][1];
        if(nx>=1&&nx<=n&&ny>=1&&ny<=n && !vis[nx][ny])
        {
            if(stone[k][nx][ny])
                continue;
            dfs(x,y,nx,ny,k+1);
        }
    }
}
int main ()
{
    scanf("%d%d",&n,&t);
    for(int i=1;i<=n;++i)
    {
        scanf("%s",str[i]+1);
        for(int j=1;j<=n;++j)
        {
            if(str[i][j]=='Z')
                stone[0][i][j]=2;
            else if(str[i][j]=='Y')
                stone[0][i][j]=1;
            else sci[i][j]=str[i][j]-'0';
        }
    }
    for(int i=1;i<=n;++i)
    {
        scanf("%s",str2[i]+1);
        for(int j=1;j<=n;++j)
        {
            if(str2[i][j]>='0' && str2[i][j]<='9')
                ca[i][j]=str2[i][j]-'0';
        }
    }

    expand();
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
        if(sci[i][j])
    {
        memset(vis,0,sizeof(vis));
        dfs(i,j,i,j,0);
    }
    for(int k=1;k<=t;++k)
        for(int x=1;x<=n;++x)
            for(int y=1;y<=n;++y)
            for(int nx=1;nx<=n;++nx)
            for(int ny=1;ny<=n;++ny)
        {
            dp[k][x][y][nx][ny]+=dp[k-1][x][y][nx][ny];
        }
    S=0;T=n*n*2+1;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
        addedge(S,(i-1)*n+j,sci[i][j]);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
        addedge(n*n+(i-1)*n+j,T,ca[i][j]);
    for(int x=1;x<=n;++x)
        for(int y=1;y<=n;++y)
        for(int nx=1;nx<=n;++nx)
        for(int ny=1;ny<=n;++ny)
            if(sci[x][y] && ca[nx][ny])
    {
        if(dp[t][x][y][nx][ny])
        addedge((x-1)*n+y,n*n+(nx-1)*n+ny,INF);
    }
    int ans=SAP(S,T);
    printf("%d\n",ans);
    return 0;
}
