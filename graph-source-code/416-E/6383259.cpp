//Language: GNU C++


#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define INF 0x7ffffff
int n,m;
int mpt[505][505];
int dp[505];
int ans[505][505];
struct node
{
    int x,y,len;
}edge[130000];
void init()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
            {
                mpt[i][j]=0;
            }
            else
            {
                mpt[i][j]=INF;
            }
        }
    }
}
void floyd()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(mpt[i][j]>mpt[i][k]+mpt[k][j])
                    mpt[i][j]=mpt[i][k]+mpt[k][j];
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    int a,b,c;
    init();
    int cnt=1;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        edge[cnt].x=a;
        edge[cnt].y=b;
        edge[cnt++].len=c;
        if(c<mpt[a][b])
        {
            mpt[a][b]=mpt[b][a]=c;
        }
    }
    floyd();
    /*
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            printf("%d %d   %d\n",i,j,mpt[i][j]);
        }
    }
    */
    for(int i=1;i<=n;i++)//起点
    {
        memset(dp,0,sizeof(dp));
        for(int j=1;j<=m;j++)//终点
        {
            if(mpt[edge[j].x][i]==mpt[edge[j].y][i]+edge[j].len)dp[edge[j].x]++;
            if(mpt[edge[j].y][i]==mpt[edge[j].x][i]+edge[j].len)dp[edge[j].y]++;
        }
        for(int j=i-1;j>=1;j--)
        {
            for(int k=1;k<=n;k++)
            {
                if(mpt[j][k]+mpt[k][i]==mpt[j][i])ans[j][i]+=dp[k];
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            printf("%d ",ans[i][j]);
        }
    }
    return 0;
}
