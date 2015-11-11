//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MaxN = 105;
#define two(i) (1<<(i))
const int M = two(7);
const int MaxQ = MaxN*MaxN*M;
const int Inf = 20000000;
int dp[MaxN][MaxN][M];
int px[MaxN][MaxN][M],py[MaxN][MaxN][M];
int ps1[MaxN][MaxN][M],ps2[MaxN][MaxN][M];
int n,m,K,g[MaxN][MaxN],ans[MaxN][MaxN];
int qx[MaxQ],qy[MaxQ],qs[MaxQ];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int check(int x,int y)
{
    return x>=0&&y>=0&&x<n&&y<m;
}

void sol(int x,int y,int s)
{
    if(!check(x,y))return;
    ans[x][y] = 1;
    int nx = px[x][y][s], ny = py[x][y][s];
    int ns1 = ps1[x][y][s], ns2 = ps2[x][y][s];
    if(ns2==-1)
        sol(nx,ny,s);
    else sol(nx,ny,ns1),sol(nx,ny,ns2);
}

int main()
{
    scanf("%d%d%d",&n,&m,&K);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d",&g[i][j]);
    int f=0,r=0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            for(int s = 0; s < two(K); s++)
                dp[i][j][s] = Inf;
    for(int i = 0; i < K; i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);x--;y--;
        qx[r] = x;
        qy[r] = y;
        qs[r++] = two(i);
        px[x][y][two(i)] = -1;
        py[x][y][two(i)] = -1;
        ps1[x][y][two(i)] = ps2[x][y][two(i)] = -1;
        dp[x][y][two(i)] = g[x][y];
    }
    while(f!=r)
    {
        int x = qx[f], y = qy[f], s = qs[f];
        f++;
        for(int i = 0; i < two(K); i++)
        {
            int ns = i|s;
            if(dp[x][y][ns] > dp[x][y][s]+dp[x][y][i]-g[x][y])
            {
                dp[x][y][ns] = dp[x][y][s]+dp[x][y][i]-g[x][y];

                qx[r] = x; qy[r] = y; qs[r++] = ns;
                px[x][y][ns] = x; py[x][y][ns] = y;
                ps1[x][y][ns] = s; ps2[x][y][ns] = i;
            }
        }
        for(int i = 0; i < 4; i++)
        {
            int nx = x+dx[i], ny = y+dy[i];
            if(check(nx,ny) && dp[nx][ny][s]>dp[x][y][s]+g[nx][ny])
            {
                dp[nx][ny][s]=dp[x][y][s]+g[nx][ny];

                qx[r] = nx; qy[r] = ny; qs[r++] = s;
                px[nx][ny][s] = x; py[nx][ny][s] = y;
                ps1[nx][ny][s] = s; ps2[nx][ny][s] = -1;
            }
        }
    }
    int ret = Inf, ax,ay;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(dp[i][j][two(K)-1] < ret)
                ret = dp[i][j][two(K)-1],ax=i,ay=j;
    sol(ax,ay,two(K)-1);
    printf("%d\n",ret);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            printf("%c",ans[i][j]?'X':'.');
        puts("");
    }
    return 0;
}
