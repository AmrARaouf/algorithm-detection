//Language: GNU C++11


#include <bits/stdc++.h>

typedef long long ll;
const int N = 100000 + 5;
const int mod = 258280327 ;
const long long inf = 1ll << 60;

struct Edge {
    int u, v, w;
}e[N];
int n, m, s, t;
int ways[N], rways[N];
int done[N], answeer[N];
long long dis[N], rdis[N];
std::vector <std::pair <int, int> > edges[N], redges[N];

void dijkstra(ll* dis, int* ways, std::vector <std::pair <int, int> >* edges, int s, int t) {
    std::priority_queue <std::pair <ll, int>, std::vector <std::pair <ll, int> >, 
        std::greater<std::pair<ll, int> > > q;
    std::fill(dis, dis + n, inf);
    std::fill(done, done + n, false);
    dis[s] = 0;
    ways[s] = 1;
    q.push({dis[s], s});
    while (q.size()) {
        int u = q.top().second;
        q.pop();
        if (done[u]) {
            continue;
        }  
        done[u] = true;
        for (int i = 0; i < edges[u].size(); i ++) {
            int v = edges[u][i].first;
            int w = edges[u][i].second;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
                ways[v] = ways[u];
            } else if (dis[v] == dis[u] + w) {
                ways[v] += ways[u];
                if (ways[v] >= mod) {
                    ways[v] -= mod;
                }
            }
        }
    }
}

void work() {
    dijkstra(dis, ways, edges, s, t);
    dijkstra(rdis, rways, redges, t, s);
   // for (int i = 0; i < n; i ++) {
   //     printf("%I64d %I64d\n", dis[i], rdis[i]);
   // }
   // puts("");
   // for (int i = 0; i < n; i ++) {
   //     printf("%d %d\n", ways[i], rways[i]);
   // }
    for (int i = 0; i < m; i ++) {
        int u = e[i].u;
        int v = e[i].v;
        int w = e[i].w;
        if (dis[u] + w + rdis[v] == dis[t] && 
            1ll * ways[u] * rways[v] % mod == ways[t]) {
            puts("YES");
        } else if (w > 1 && dis[u] + 1 + rdis[v] < dis[t]) {
            int x = (int)(dis[t] - 1 - dis[u] - rdis[v]);
            printf("CAN %d\n", w - x);
        } else {
            puts("NO");
        }
    }
}

int main() {
    scanf("%d%d%d%d", &n, &m, &s, &t);
    s --, t --;
    for (int i = 0; i < m; i ++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        u --, v --;
        e[i] = Edge{u, v, w};
        edges[u].push_back({v, w});
        redges[v].push_back({u, w});
    }
    work();
    return 0;
}
