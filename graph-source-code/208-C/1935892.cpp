//Language: GNU C++


#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <queue>
using namespace std;
#define Clearf(a) memset(a,-1,sizeof(a))
#define Clear(a) memset(a,0,sizeof(a))
typedef __int64 LL;
const int inf=1000000000;
const int maxn=200;
queue <int> q;
int d[maxn][maxn],dis[maxn];
double num[maxn],rnum[maxn];
bool vis[maxn];
int main(){
    int  n,m,i,j,k,u,v;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++) d[i][j]=inf;
    for(i=1;i<=n;i++) d[i][i]=0;
    for(i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
        d[u][v]=d[v][u]=1;  
    }
    while(!q.empty())q.pop();
    for(i=1;i<=n;i++) dis[i]=inf;
    Clear(num);
    q.push(1);Clear(vis);
    vis[1]=1;dis[1]=0;num[1]=1;
    while(!q.empty()){
        int u=q.front();
        //printf("u= %d %d %d\n",u,dis[u],num[u]);
        q.pop();
        for(i=1;i<=n;i++)
        if(d[u][i]==1){
            if(vis[i]==0){
                q.push(i);
                dis[i]=dis[u]+1;
                num[i]=num[u];
                vis[i]=1;
            }else if(dis[u]+1==dis[i]) num[i]+=num[u];
        }
    }
    while(!q.empty())q.pop();
    for(i=1;i<=n;i++) dis[i]=inf;
    Clear(rnum);
    q.push(n);Clear(vis);
    vis[n]=1;dis[n]=0;rnum[n]=1;
    while(!q.empty()){
        int u=q.front();
        //printf("u= %d %d %d\n",u,dis[u],num[u]);
        q.pop();
        for(i=1;i<=n;i++)
        if(d[u][i]==1){
            if(vis[i]==0){
                q.push(i);
                dis[i]=dis[u]+1;
                rnum[i]=rnum[u];
                vis[i]=1;
            }else if(dis[u]+1==dis[i]) rnum[i]+=rnum[u];
        }
    }
    //printf("%d %d\n",dis[n],num[n]);
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    double ans=0;
    int tmp=0;
    
    ans=num[n];
    for(k=2;k<n;k++){
        tmp=0;
        if(d[1][k]+d[k][n]==d[1][n])
        ans=max(ans,2*num[k]*rnum[k]);  
    }
//  printf("%d\n",ans);
    double res=(double)ans/num[n];
    printf("%.6lf\n",res);
    getchar();getchar();
    return 0;   
}
