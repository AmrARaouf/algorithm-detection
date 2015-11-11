//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<iostream>
#define maxn 509
#define INF 1e9
using namespace std;
int dp[maxn][maxn],d[maxn][maxn],a[maxn][maxn],n;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i==j)
                d[i][j]=0;
            else
                d[i][j]=INF;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        a[x][y]=a[y][x]=z;
        d[x][y]=d[y][x]=z;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                if(a[i][j]&&a[i][j]+d[j][k]==d[i][k])
                    dp[i][k]++;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
    {
        int ans=0;
        for(int k=1;k<=n;k++)
            if(d[i][k]+d[k][j]==d[i][j])
                ans+=dp[k][j];
        printf("%d ",ans);
    }

}
