//Language: GNU C++


#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;
int const nMax=160;
int map[nMax][nMax];
int co[nMax];
int vis[nMax];
int n,m;

bool dfs(int u,int color)
{
    vis[u]=1;int col;
    co[u]=color;
    for(int v=1;v<=n;v++)if(map[u][v]!=-1){
        col=color+1-map[u][v];
        col%=2;
        if(vis[v]){
            if(co[v]!=col)return false;
        }else {
            if(!dfs(v,col))return false;
        }
    }
    return true;
}

vector<int> Q;
void dfs(int u){
    vis[u]=1;
    for(int v=1;v<=n;v++)if(map[u][v]==0){
        for(int k=1;k<=n;k++)if(map[v][k]!=-1){
            map[v][k]=map[v][k]^1;
            map[k][v]=map[v][k];
        }
        Q.push_back(v);
        dfs(v);
    }else if(!vis[v]&&map[u][v]==1)dfs(v);
    return ;
}

int main()
{
    memset(map,-1,sizeof(map));
    scanf("%d%d",&n,&m);
    int u,v,w;
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&u,&v,&w);
        map[u][v]=map[v][u]=w;
    }
    memset(vis,0,sizeof(vis));
    for(int u=1;u<=n;u++)if(!vis[u])
    if(!dfs(u,0)){
        puts("Impossible");
        return 0;
    }else {
        Q.clear();
        memset(vis,0,sizeof(vis));
        for(int u=1;u<=n;u++)if(!vis[u])
        dfs(u);
        if(Q.size()>n)return puts("Impossible"),0;
        printf("%d\n",Q.size());
        for(int i=0;i<Q.size();i++)printf("%d ",Q[i]);
        puts("");
    }
    return 0;
}
