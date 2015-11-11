//Language: GNU C++


#include<map>
#include<set>
#include<list>
#include<queue>
#include<cmath>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<cstdlib>
#include<sstream>
#include<iostream>
#include<algorithm>
using namespace std;
#define lowbit(x) (x&(-x))
#define INF 99999999
#define LLINF 0x7fffffffffffffffll
#define LL __int64
#define MAXN 110000
#define MAXE 1100000
#define CH 129
#define eps 1e-8
#define PI acos(-1.0)
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
#define CC(m,what) memset(m,what,sizeof(m))
#define fuck puts("<<---------------------");
template<class Z>inline bool checkmax(Z &a,Z b){if(a==-1||a<b){a=b;return true;}return false;}
template<class Z>inline bool checkmin(Z &a,Z b){if(a==-1||a>b){a=b;return true;}return false;}

int n,m;
int net[MAXN],size;
void init(){
    size=0;
    memset(net,-1,sizeof(net));
}
struct EDGE{
    int v,next;
}edge[MAXE];
void add(int u,int v){
    edge[size].v=v;
    edge[size].next=net[u];
    net[u]=size++;
}
int val[MAXN];
int k;
bool vis[MAXN][2];
void dfs(int u){
    vis[u][k]=1;
    //if(k==0 && val[u]==2) return;
    if(k==1 && val[u]==1) return;
    for(int i=net[u]; i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(vis[v][k]) continue;
        dfs(v);
    }
}
struct Road{
    int u,v;
}road[MAXE];
int main(){
    int i,j,h;
    int a,b;
    while(scanf("%d%d",&n,&m)!=EOF){
        init();
        for(i=1;i<=n;i++){
            scanf("%d",&val[i]);
        }
        for(i=1;i<=m;i++){
            scanf("%d%d",&a,&b);
            road[i].u=b; road[i].v=a;
            add(a,b);
        }
        memset(vis,0,sizeof(vis));
        k=0;
        for(i=1;i<=n;i++){
            if(val[i]==1) dfs(i);
        }
        init();
        k=1;
        for(i=1;i<=m;i++){
            add(road[i].u, road[i].v);
        }
        for(i=1;i<=n;i++){
            if(val[i]==2) dfs(i);
        }
        for(i=1;i<=n;i++){
            puts(vis[i][0] && vis[i][1]?"1":"0");
        }
    }
    return 0;
}
/*
*/