//Language: GNU C++


#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn = 100010;

struct EDGE{
    int st, to, id, w, next;
}edge[2*maxn];
struct Edge{
    int st, to, id, w;
    bool operator<(const Edge&a)const{
        return w < a.w;
    }
}e[maxn];

typedef int arr[maxn];
arr head, vis, low, dfn, f, g, h;
int tot;

void add(int a, int b, int edgeid){
    edge[tot].to = b;
    edge[tot].id = edgeid;
    edge[tot].next = head[a];
    head[a] = tot++;
}

void dfs(int u, int fa, int depth){
    low[u] = dfn[u] = depth;
    vis[u] = 1;
    for(int i = head[u]; i != -1; i = edge[i].next){
        int v = edge[i].to;
        if(vis[v]==1 && edge[i].id != fa)
            low[u] = min(low[u], dfn[v]);
        else if(!vis[v]){
            dfs(v, edge[i].id, depth + 1);
            low[u] = min(low[u], low[v]);
            if(low[v] > dfn[u]){
                h[edge[i].id] = 2;
            }
        }
    }
    vis[u] = 2;
}
int find(int x){
    return x==f[x] ? x : (f[x] = find(f[x]));
}

int main(){
    //freopen("test.in", "r", stdin);
    for(int n, m; scanf("%d%d", &n, &m)!=EOF;){
        for(int i = 1; i <= n; i ++) f[i] = i, h[i] = 0;
        for(int i = 0; i < m; i ++){
            scanf("%d%d%d", &e[i].st, &e[i].to, &e[i].w);
            h[i] = 0;
            e[i].id = i;
        }
        sort(e, e + m);
        memset(head, -1, sizeof(head));
        tot = 0;
        for(int i = 0; i < m; ){
            int s = i, j, fx, fy;
            for(j = i; j < m && e[j].w == e[i].w; j ++){
                fx = find(e[j].st), fy = find(e[j].to);
                if(fx==fy) continue;
                h[e[j].id] = 1;
                add(fx, fy, e[j].id);
                add(fy, fx, e[j].id);
                g[j] = fx;
            }
            i = j;
            for(j = s; j < i; j ++){
                if(g[j] && !vis[g[j]]){
                    dfs(g[j], -1, 1);
                }
            }
            for(j = s; j < i; j ++){
                fx = find(e[j].st), fy = find(e[j].to);
                if(fx!=fy){

                    vis[fx] = vis[fy] = 0;
                    head[fx] = head[fy] = -1;
                    f[fx] = fy;
                }
            }
            tot = 0;
        }
        for(int i = 0; i < m; i ++){
            if(h[i]==0) printf("none\n");
            else if(h[i]==1) printf("at least one\n");
            else printf("any\n");
        }
    }
    return 0;
}

     	  										 					