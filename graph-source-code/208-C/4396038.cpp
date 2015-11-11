//Language: GNU C++


#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<queue>
#include<string>
#include<iostream>
#define N 110
#define CC(x,y) memset(x,y,sizeof(x))
#define inf 0x7ffffff
#define ll long long
#define eps 1e-6
#define M 110000
using namespace std;
ll a[N][N],b[N][N],f[N][N][N],c[N][N];
int i,j,k,m,n,x,y,z;
int main()
{
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
        a[i][j]=i==j?0:inf;
    for (i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        a[x][y]=a[y][x]=b[x][y]=b[y][x]=f[1][x][y]=f[1][y][x]=1;
    }
    for (k=1;k<=n;k++)
        for (i=1;i<=n;i++)
          for (j=1;j<=n;j++)
           a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
    int dis=a[1][n];
    for (k=2;k<=dis;k++)
        for (i=1;i<=n;i++)
          for (j=1;j<=n;j++)
    {
        f[k][i][j]=0;
        for (z=1;z<=n;z++)
            f[k][i][j]+=f[k-1][i][z]*b[z][j];
    }
    double ans=1.0;
    for (i=2;i<n;i++)
    {
        ll cnt=0;
        for (j=0;j<=dis;j++)
            cnt+=f[j][1][i]*f[dis-j][i][n];
        double tmp=(2.0*cnt)/f[dis][1][n];
        ans=max(ans,tmp);
    }
    printf("%.8lf\n",ans);
}
