//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <complex>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 411111;
const int mod = (int)(1e9+7);
struct node{
    int v,next;
}edge[maxn<<2];
int head[maxn],e;
int belong[maxn],scc;
int cost[maxn];
int dfn[maxn],low[maxn],dep;
int stk[maxn],top;
int res[maxn];
int num[maxn];
bool ins[maxn];
void add_edge(int u,int v){
    edge[e].v=v;
    edge[e].next=head[u];
    head[u]=e++;
}
void tarjan(int u){
    ins[u]=true;
    stk[top++]=u;
    dfn[u]=low[u]=++dep;
    int i,v;
    for(i=head[u];~i;i=edge[i].next){
        v=edge[i].v;
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }else if(ins[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(low[u]==dfn[u]){
        ++scc;
        do{
            v=stk[--top];
            belong[v]=scc;
            ins[v]=false;
            res[scc]=min(res[scc],cost[v]);
        }while(u^v);
    }
}
int main() {
    int n,m,i,u,v;
    memset(res,0x7f,sizeof(res));
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d",&cost[i]);
    }
    cin>>m;
    memset(head,-1,sizeof(head));
    for(i=1;i<=m;++i){
        scanf("%d%d",&u,&v);
        add_edge(u,v);
    }
    for(i=1;i<=n;++i){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    LL x=0,y=1;
    for(i=1;i<=scc;++i){
        x += res[i];
    }
    for(i=1;i<=n;++i){
        if(cost[i]==res[belong[i]]){
            num[belong[i]]++;
        }
    }
    for(i=1;i<=scc;++i){
        y=y*num[i]%mod;
    }
    printf("%lld %lld\n",x,y);
    return 0;
}
  			  			  				     	