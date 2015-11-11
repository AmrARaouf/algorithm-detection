//Language: GNU C++


#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 0x7f7f7f7f
#define MAXN 300010
using namespace std;
int f[MAXN];
int D[MAXN];
int n,m,q; int maximum,K; 

struct edge{
    int v,next;
}e[MAXN*2];
int h[MAXN],tot=0;

void addedge(int x,int y){
    ++tot;e[tot].v=y;e[tot].next=h[x];h[x]=tot;
    ++tot;e[tot].v=x;e[tot].next=h[y];h[y]=tot;
}

void dfs(int u){
    for(int i=h[u];i;i=e[i].next){
        int v=e[i].v;
        if(!f[v]){
            f[v]=f[u];
            dfs(v);
        }
    }
}

void dfsdis(int u,int dist,int fa){
    if(dist>maximum) maximum=dist,K=u;
    for(int i=h[u];i;i=e[i].next)
        if(e[i].v!=fa)
            dfsdis(e[i].v,dist+1,u);
}

int getdis(int u){
    maximum=-1; 
    dfsdis(u,0,0);
    maximum=-1;
    dfsdis(K,0,0);
    return maximum;
}

int getfa(int u){
    if(f[u]==u) return u;
    return(f[u]=getfa(f[u]));
}

int main(){
    scanf("%d%d%d",&n,&m,&q);
    int op,x,y;
    while(m--){
        scanf("%d%d",&x,&y);
        addedge(x,y);
    }
    for(int i=1;i<=n;i++)
        if(!f[i]){
            f[i]=i;
            dfs(i);
            D[i]=getdis(i);
        }
    while(q--){
        scanf("%d",&op);
        if(op==1){
            scanf("%d",&x);
            printf("%d\n",D[getfa(x)]);
        }else{
            scanf("%d%d",&x,&y);
            int fx=getfa(x),fy=getfa(y);
            if(fx==fy) continue;
            D[fx]=max(max(D[fx],D[fy]),(D[fx]+1)/2+(D[fy]+1)/2+1);
            f[fy]=fx;
        }
    }
    return 0;
}
