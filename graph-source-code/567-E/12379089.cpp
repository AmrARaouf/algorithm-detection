//Language: GNU C++


#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <climits>
using namespace std;

#define wh while
#define FOR(i, n) for(int i = 0; i < n; i++)
#define REP(i,n) for(int i = 1; i <= n; i++)
#define sf scanf
#define pf printf
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
#define clr(abc,z) memset(abc,z,sizeof(abc))


typedef long long LL;
typedef long double LD;
typedef pair<int, long long> pii;

const int maxn = 1e5 + 100;

int n, m, s, t;
vector<pii> G[maxn];

struct NODE{
    LL d; int u;
    bool operator < (const NODE& rhs) const {
        return d > rhs.d;
    }
};
LL dis[maxn];
bool vis[maxn];
const LL inf = 1LL << 60;
void Dijkstra(int s){
    priority_queue<NODE> Q;
    FOR(i, n + 1){
        dis[i] = inf; vis[i] = 0;
    }
    dis[s] = 0;
    Q.push((NODE){0, s});
    wh(!Q.empty()) {
        NODE c = Q.top(); Q.pop();
        if(vis[c.u]) continue;
        vis[c.u] = true;
        FOR(i, (int)G[c.u].size()) {
            int v = G[c.u][i].first;
            LL w = G[c.u][i].second;
            if(dis[v] > dis[c.u] + w){
                dis[v] = dis[c.u] + w;
                Q.push((NODE){dis[v], v});
            }
        }
    }
}

int dfn[maxn], low[maxn], dfs_clock;
void Tarjan(int u, int fa){
    dfn[u] = low[u] = ++dfs_clock;
    FOR(i, (int)G[u].size()) {
        int v = G[u][i].first;
        if(!dfn[v]){
            Tarjan(v, G[u][i].second);
            low[u] = min(low[u], low[v]);
            if(low[v] > dfn[u]){
                vis[G[u][i].second] = true;
            }
        }
        else if(G[u][i].second != fa && dfn[v] != dfn[u])
            low[u] = min(dfn[v], low[u]);
    }
}

struct EDGE{
    int u, v;
    LL w;
}edge[maxn];
LL dis1[maxn], dis2[maxn];

int main() {
    sf("%d%d%d%d", &n, &m, &s, &t);
    FOR(i, m){
        sf("%d%d%I64d", &edge[i].u, &edge[i].v, &edge[i].w);
        G[edge[i].u].PB(MP(edge[i].v, edge[i].w));
    }
    Dijkstra(s);
    REP(i, n){
        dis1[i] = dis[i]; G[i].clear();
    }
    FOR(i, m)
        G[edge[i].v].PB(MP(edge[i].u, edge[i].w));
    Dijkstra(t);
    REP(i, n){
        dis2[i] = dis[i]; G[i].clear();
    }
    FOR(i, m){
        int u = edge[i].u, v = edge[i].v;
        LL w = edge[i].w; vis[i] = false;
        if(dis1[u] + w == dis1[v] && dis2[v] + w == dis2[u]){
            G[u].PB(MP(v, i)); G[v].PB(MP(u, i));
        }
    }
    dfs_clock = 0;
    Tarjan(s, -1);
    FOR(i, m){
        int u = edge[i].u, v = edge[i].v; LL w = edge[i].w;
        if(vis[i]) puts("YES");
        else if(w - (dis1[t] - dis1[u] - dis2[v] - 1) < w)
            pf("CAN %I64d\n", w - (dis1[t] - dis1[u] - dis2[v] - 1));
        else puts("NO");
    }
}
