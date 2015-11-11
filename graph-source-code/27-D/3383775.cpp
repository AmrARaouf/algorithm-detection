//Language: MS C++


#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll __int64
#define ls rt<<1
#define rs ls|1
#define lson l,mid,ls
#define rson mid+1,r,rs
#define middle (l+r)>>1
#define clr_all(x,c) memset(x,c,sizeof(x))
#define clr(x,c,n) memset(x,c,sizeof(x[0])*(n+1))
#define eps (1e-8)
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define PI (acos(-1.0))
#pragma comment(linker, "/STACK:102400000,102400000")
template <class T> T _max(T x,T y){return x>y? x:y;}
template <class T> T _min(T x,T y){return x<y? x:y;}
template <class T> T _abs(T x){return (x < 0)? -x:x;}
template <class T> T _mod(T x,T y){return (x > 0)? x%y:((x%y)+y)%y;}
template <class T> void _swap(T &x,T &y){T t=x;x=y;y=t;}
template <class T> void getmax(T& x,T y){x=(y > x)? y:x;}
template <class T> void getmin(T& x,T y){x=(x<0 || y<x)? y:x;}
int TS,cas=1;
const int M=100+5;
int n,m;
struct edge{
    int u,v;
    void read(){
        scanf("%d%d",&u,&v);
        if(u>v) _swap(u,v);
    }
}p[M];
bool isIntersect(int l1,int r1,int l2,int r2){
    if(l1<l2 && l2<r1 && r1<r2) return true;
    if(l2<l1 && l1<r2 && r2<r1) return true;
    return false;
}
vector<int>init[M<<1],now[M<<1];
int pre[M<<1],low[M<<1],idx[M<<1];
int ss[M<<1],top,index,nn;
int deg[M<<1],op[M<<1];
void dfs(int u){
    ss[++top]=u;
    pre[u]=low[u]=++index;
    for(int i=0;i<init[u].size();i++){
        int v=init[u][i];
        if(pre[v]==-1){
            dfs(v);
            getmin(low[u],low[v]);
        }else if(idx[v]==-1){
            getmin(low[u],pre[v]);
        }
    }
    if(pre[u]==low[u]){
        now[++nn].clear();
        int v=-1;
        while(u!=v){
            idx[v=ss[top--]]=nn;
        }
    }
}
void Tarjan(int n){
    ss[top=index=nn=0]=-1;
    clr(pre,-1,n+1),clr(idx,-1,n+1);
    for(int i=1;i<=n;i++){
        if(pre[i]==-1) dfs(i);
    }
}
void shrink(int n){
    clr(deg,0,n+1);
    for(int u=1;u<=n;u++){
        for(int i=0;i<init[u].size();i++){
            int v=init[u][i];
            if(idx[v]!=idx[u]){
                now[idx[u]].push_back(idx[v]);
                deg[idx[v]]++;
            }
        }
    }
}

void run(){
    int i,j;
    for(i=1;i<=m;i++) p[i].read();
    for(i=1;i<=m*2;i++) init[i].clear();
    bool flag=true;
    for(i=1;i<=m;i++){
        for(j=i+1;j<=m;j++){
            if(isIntersect(p[i].u,p[i].v,p[j].u,p[j].v)){
                init[i].push_back(j+m);
                init[j+m].push_back(i);
                init[j].push_back(i+m);
                init[i+m].push_back(j);
            }
        }
    }
    Tarjan(m<<1);
    for(i=1;i<=m;i++){
        if(idx[i]==idx[i+m]){
            puts("Impossible");
            return;
        }
    }
    shrink(nn);
    for(i=1;i<=m;i++){
        op[idx[i]]=idx[i+m];
        op[idx[i+m]]=idx[i];
    }
    ss[top=0]=-1;
    for(i=1;i<=nn;i++) if(!deg[i]){
        ss[++top]=idx[i];
        deg[idx[i]]=-1,deg[op[idx[i]]]=-2;
    }
    while(top){
        int u=ss[top--];
        for(i=0;i<now[u].size();i++){
            int v=now[u][i];
            if(--deg[v]==0) ss[++top]=v,deg[v]=-1,deg[op[v]]=-2;
        }
    }
    for(i=1;i<=m;i++){
        if(deg[idx[i]]==-1) putchar('o');
        else putchar('i');
    }puts("");
}

void preSof(){
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    preSof();
    //run();
    while((~scanf("%d%d",&n,&m))) run();
    //for(scanf("%d",&TS);cas<=TS;cas++) run();
    return 0;
}