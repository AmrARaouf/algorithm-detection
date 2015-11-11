//Language: GNU C++11


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <stack>
#include <algorithm>
using namespace std;

const int MOD = (int)1e9+7;
const int MAXN = 100005;
int head[MAXN],edge[MAXN<<1],next1[MAXN<<1],esz;
int is[MAXN],vis[MAXN],cent[MAXN],dp[MAXN][20],P[MAXN];

void addedge(int u,int v){
    edge[esz]=v;
    next1[esz]=head[u];
    head[u]=esz++;
}

void dfs(int u,int p,int val){
    dp[u][0]=p;
    cent[u]=val;
    for(int i=head[u];i+1;i=next1[i]){
        int v=edge[i];
        if(cent[v]>0 && cent[v]<cent[u])continue;
        if(cent[v]>0){
            vis[u]=is[u]=1;
            while(v!=u){
                vis[v]=1;
                v=dp[v][0];
            }
        }
        else dfs(v,u,val+1);
    }
}

void dfs2(int u,int p){
    is[u]=is[p]+is[u];
    for(int i=head[u];i+1;i=next1[i]){
        int v=edge[i];
        if(cent[v]<cent[u] || cent[v]-cent[u]>1)continue;
        dfs2(v,u);
    }
}

void build(int n){
    for(int j=1;j<20;j++)
        for(int i=1;i<=n;i++)dp[i][j]=dp[dp[i][j-1]][j-1];
}

int fx(int tu,int u){
    int res=is[tu]-is[dp[u][0]];
    if(vis[u] && is[u]==is[dp[u][0]]){
        res++;
    }
    return res;
}

int call(int u,int v){
    if(cent[u]<cent[v])swap(u,v);
    int cha=cent[u]-cent[v];
    int tu=u;
    for(int i=0;i<20;i++){
        if((1<<i)&cha){
            u=dp[u][i];
        }
    }
    if(u==v){
        return fx(tu,u);
    }
    int tv=v;
    for(int i=19;i>=0;i--){
        if(dp[u][i]!=dp[v][i]){
            u=dp[u][i];
            v=dp[v][i];
        }
    }
    int f=dp[u][0];
    int res=fx(tu,f)+fx(tv,f);
    if(vis[f])res--;
    return res;
}

int main()
{
    int n,m;memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int u,v;scanf("%d%d",&u,&v);
        addedge(u,v);
        addedge(v,u);
    }
    P[0]=1;
    for(int i=1;i<=n;i++)P[i]=P[i-1]*2%MOD;
    dfs(1,0,1);
    dfs2(1,0);
    build(n);
    int k;scanf("%d",&k);
    while(k--){
        int u,v;scanf("%d%d",&u,&v);
        printf("%d\n",P[call(u,v)]);
    }
    return 0;
}
