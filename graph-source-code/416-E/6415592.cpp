//Language: GNU C++


/**算法分析：

*/
#include<bits/stdc++.h>
#define MAXN 505
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,s,t) for(int i=s; i<=t; i++)
#define mem(a,b)  memset(a,b,sizeof(a))
#define show(x) { cerr<<">>>"<<#x<<" = "<<x<<endl; }
#define show2(x,y) { cerr<<">>>"<<#x<<"="<<x<<"  "<<#y<<" = "<<y<<endl; }
using namespace std;

int dis[MAXN][MAXN];
int ans[MAXN][MAXN];
int gh[MAXN][MAXN];

void floyd(int n)
{
    FOR(i,1,n) dis[i][i] = 0;
    FOR(k,1,n) FOR(i,1,n) if(dis[i][k] < INF)
    {
        FOR(j,1,n) if(dis[k][j] < INF)
            dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
    }
}


int main()
{
    //freopen("E:\\acm\\input.txt","r",stdin);
    //freopen("E:\\acm\\output.txt","w",stdout);
    int n,m; cin>>n>>m;
    mem(dis,0x3f);  mem(ans,0); mem(gh,0x3f);
    REP(i,m)
    {
        int x,y,l; scanf("%d %d %d",&x,&y,&l);
        gh[x][y] = gh[y][x] = l;
        dis[x][y] = dis[y][x] = l;
    }
    floyd(n);
    FOR(i,1,n)
    {
        int cnt[MAXN] = {0};
        FOR(j,1,n) FOR(k,1,n) if(j!=k && dis[i][j]+gh[j][k] == dis[i][k])
            cnt[k] ++;
        FOR(j,1,n) FOR(k,1,n) if(dis[i][j] + dis[j][k] == dis[i][k])
            ans[i][k] += cnt[j];
    }
    FOR(i,1,n) FOR(j,i+1,n)
        if(dis[i][j] == INF) printf("0 ");
        else                 printf("%d ",ans[i][j]);

}










