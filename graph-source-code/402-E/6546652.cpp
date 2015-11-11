//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define N 2010
using namespace std;
int n;
int m[N][N],low[N],stk[N],dfn[N];
bool instk[N];
int stkid,cnt,bcnt;
void init(){
    stkid=cnt=bcnt=0;
    memset(dfn,-1,sizeof(dfn));
    memset(instk,0,sizeof(instk));
}
void tarjan(int u){
    int i,v;
    dfn[u]=low[u]=++cnt;
    instk[u]=1;
    stk[++stkid]=u;
    for(int i=1;i<=n;++i){
        if(!m[u][i])continue;
        v=i;
        if(dfn[v]==-1){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }else if(instk[v])low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]){
        ++bcnt;
        do{
            v=stk[stkid--];
            instk[v]=0;
        }while(u!=v);
    }
}
void solve(){
    for(int i=1;i<=n;++i)if(dfn[i]==-1)tarjan(i);
}
using namespace std;
int main(){
    int tmp;
    while(~scanf("%d",&n)){
        init();
        memset(m,0,sizeof(m));
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                scanf("%d",&tmp);
                m[i][j]= tmp>0?1:0;
            }
        }
        solve();
        if(bcnt==1)puts("YES");else puts("NO");
    }
    return 0;
}
