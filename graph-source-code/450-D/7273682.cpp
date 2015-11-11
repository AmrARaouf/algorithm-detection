//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define N 100005
#define LL long long
const LL inf = 1e17;
int n, m, k;
int head[N];
struct no{
    int v, next, x;
}e[N << 3];
struct nod{
    int v, x;
}ee[N];
int num;
void add(int u, int v, int x)
{
    e[num].v = v;
    e[num].x = x;
    e[num].next = head[u];
    head[u] = num++;
}
LL dis[N];
int in[N]; 
struct node{
    LL d;
    int x;
    bool operator < (const node &a) const{
        return d > a.d;
    }
};
bool vis[N];
void dijkstra(int st)
{
    for (int i = 0; i <= n; i++)
        dis[i] = inf, vis[i] = false;
    dis[1] = 0;
    priority_queue<node> Q;
    node now, next;
    now.d = 0, now.x = 1;
    Q.push(now);
    while (!Q.empty())
    {
        now = Q.top();
        Q.pop();
        if (vis[now.x]) continue;
        vis[now.x] = true;
        for (int i = head[now.x]; i != -1; i = e[i].next)
        {
            int d = e[i].x;
            int v = e[i].v;
            if (dis[now.x] + d == dis[v]) in[v]++;
            if (dis[now.x] + d < dis[v])
            {
                dis[v] = dis[now.x] + d;
                next.d = dis[v];
                next.x = v;
                in[v] = 1;
                Q.push(next);
            }
        }
    }
}
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    int u, v, x;
    num = 0;
    memset(head, -1, sizeof(head));
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &x);
        add(u, v, x);
        add(v, u, x);
    }
    for (int i = 0; i < k; i++)
    {
        scanf("%d%d", &ee[i].v, &ee[i].x);
        add(1, ee[i].v, ee[i].x);
        add(ee[i].v, 1, ee[i].x);
    }
    dijkstra(1);
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        if (ee[i].x > dis[ee[i].v]) ans++;
        if (ee[i].x == dis[ee[i].v] && in[ee[i].v] > 1) in[ee[i].v]--, ans++;
    }
    printf("%d\n", ans);
    return 0;
}