//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#define maxn 109
#define INF 99999999
using namespace std;
int d[maxn][maxn];
long long  dp[maxn];
long long dp1[maxn];
long long num[maxn];
vector<int>G[maxn];
vector<int>V[maxn];
int n,m;
typedef struct
{
    int u,v,wi;
}node;
node edge[maxn*maxn*2];
long long dfs(int cur)
{
    if(cur==n)
    {
        return dp[cur]=1;
    }
    if(dp[cur]!=-1)
        return dp[cur];
    long long sum=0;
    for(int i=0;i<G[cur].size();i++)
    {
        sum+=dfs(G[cur][i]);
    }
    return dp[cur]=sum;
}
long long dfs1(int cur)
{
    if(cur==1)
    {
        return dp1[cur]=1;
    }
    if(dp1[cur]!=-1)
        return dp1[cur];
    long long sum=0;
    for(int i=0;i<V[cur].size();i++)
        sum+=dfs1(V[cur][i]);
    return dp1[cur]=sum;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        if(i!=j)d[i][j]=INF;
        else d[i][j]=0;
    int tot=0;
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        d[x][y]=d[y][x]=1;
        edge[tot].u=x;
        edge[tot].v=y;
        tot++;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    for(int i=0;i<tot;i++)
    {
        int x=edge[i].u,y=edge[i].v;
        if(d[1][x]+1+d[y][n]==d[1][n])
        {
            G[x].push_back(y);
            V[y].push_back(x);

        }
        if(d[1][y]+1+d[x][n]==d[1][n])
        {
            G[y].push_back(x);
            V[x].push_back(y);
        }
    }
    for(int i=1;i<=n;i++)
        dp[i]=dp1[i]=-1;
    dfs(1);
    dfs1(n);
    for(int i=1;i<=n;i++)
    {
        if(i==1||i==n)num[i]=dp[i]*dp1[i];
        else num[i]=dp[i]*dp1[i]*2;
    }
    long long mmax=0;
    for(int i=1;i<=n;i++)
        mmax=max(mmax,num[i]);
    double ans=1.0*mmax/dp[1];
    printf("%f\n",ans);

}
