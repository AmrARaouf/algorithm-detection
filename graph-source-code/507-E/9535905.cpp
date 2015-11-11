//Language: GNU C++


#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
const int maxm = 2 * maxn;
const int inf = (1<<28);

int fir[maxn], d[maxn], st[maxn], cnt, yy, aa, bb;
struct Edge {
    int v, nxt, id, z;
    Edge(int v = 0, int n = 0, int i = 0, int z = 0) : v(v), nxt(n), id(i), z(z) {}
}edges[maxm];
struct List{
    int u, v, z;
    List(int u = 0, int v = 0, int z = 0) : u(u), v(v), z(z) {}
}list[maxm];

void init() {
    cnt = 0;
    yy = aa = bb = 0;
    memset(fir, -1, sizeof(fir));
}
void add_edge(int u, int v, int id, int z)
{
    edges[cnt] = Edge(v, fir[u], id, z);
    fir[u] = cnt++;
}
struct node {
    int u, step, road;
    node(int u = 0, int s = 0, int r = 0) : u(u), step(s), road(r) {}
    bool operator < (const node& t) const {
        return step > t.step || (step == t.step && road < t.road);
    }
};
priority_queue<node> Q;
bool vis[maxn], tag[maxn];
struct FA {
    int u, id;
    FA(int u = 0, int i = 0) : u(u), id(i) {}
}fa[maxn];

void bfs(int n)
{
    Q.push(node(1, 0, 0));
    
    while (!Q.empty())
    {
        node now = Q.top(); Q.pop();
        int u = now.u;
        if (u == n) break;
        if (vis[u]) continue;
        vis[u] = true;
    
        for (int e = fir[u]; e != -1; e = edges[e].nxt) if (!vis[edges[e].v]) {
            int v = edges[e].v, z = edges[e].z, id = edges[e].id;
            node nxt = node(v, now.step+1, now.road + z);
            if (d[v] <= d[u] + z && (st[u] != st[v] || u == 1)) {
                d[v] = d[u] + z;
                fa[v] = FA(u, id);
                st[v] = now.step+1;
                Q.push(nxt);
            }
        }
    }
    FA pre = fa[n];
    while (pre.u) {
        tag[pre.id] = true;
        if (list[pre.id].z) bb++;
        else aa++;
        pre = fa[pre.u];
    }
}
int main()
{
    int n, m; scanf("%d%d", &n, &m);
    
    init();
    for (int i = 0; i < m; i++) {
        int u, v, z; scanf("%d%d%d", &u, &v, &z);
        yy += z;
        add_edge(u, v, i, z);
        add_edge(v, u, i, z);
        list[i] = List(u, v, z);
    }
    bfs(n);
    printf("%d\n", yy+aa-bb);
    for (int i = 0; i < m; i++) {
        if (list[i].z && !tag[i]) {
            printf("%d %d %d\n", list[i].u, list[i].v, list[i].z ^ 1);
        }
        else if(!list[i].z && tag[i]) {
            printf("%d %d %d\n", list[i].u, list[i].v, list[i].z ^ 1);
        }
    }
    
    return 0;
}
































