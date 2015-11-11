//Language: MS C++


#include <iostream>
#include <cstdio>
#include <cstring>

#define MAXV 5100
#define MAXE 2000010
#define INF 2000000000
#define lld long long

using namespace std;

struct Edge 
{
    int ed, next;
    lld flow, cost;
} 
edge[MAXE];
int k;
int head[MAXV], nEdge;
int pre[MAXV], dis[MAXV], now[MAXV];
lld his[MAXV];
bool vis[MAXV];

int que[MAXV * MAXV * 2], front, tail;

void init() 
{
    memset(head, -1, sizeof(head));
    nEdge = 0;
}

void addEdge(const int a, const int b, const lld f, const lld c)
{
    edge[nEdge].ed = b;
    edge[nEdge].flow = f;
    edge[nEdge].cost = c;
    edge[nEdge].next = head[a];
    head[a] = nEdge++;
    edge[nEdge].ed = a;
    edge[nEdge].flow = 0;
    edge[nEdge].cost = -c;
    edge[nEdge].next = head[b];
    head[b] = nEdge++;
}

int minCostMaxFlow(const int v, const int src, const int dst, lld &netCost) 
{
    int i, x, y, p, totalFlow = 0;

    netCost = 0;
    while (1) {
        for (i = 0; i < v; ++i) dis[i] = INF;
        memset(vis, 0, sizeof(vis));
        front = tail = v;
        dis[src] = 0; his[src] = INF;
        vis[que[tail++] = src] = true;
        while (front < tail) {
            vis[x = que[front++]] = false;
            for (p = head[x]; ~p; p = edge[p].next) {
                if (edge[p].flow && dis[y = edge[p].ed] > dis[x] + edge[p].cost) {
                    dis[y] = dis[x] + edge[p].cost;
                    pre[y] = x; now[y] = p;
                    his[y] = min(his[x], edge[p].flow);
                    if (!vis[y]) {
                        if (front < tail && dis[y] < dis[que[front]]) que[--front] = y;
                        else que[tail++] = y;
                        vis[y] = true;
                    }
                }
            }
        }
        if (dis[dst] == INF) break;
        
        totalFlow += his[dst];
        netCost += dis[dst] * his[dst];
        for (i = dst; i != src; i = pre[i]) {
            edge[now[i]].flow -= his[dst];
            edge[now[i] ^ 1].flow += his[dst];
        }
    }

    return totalFlow;
}

int i, j, c[200][200];
int n;
int check(lld x)
{
    int i, j;
    init();
    addEdge(0, 1, x, 0);
    addEdge(n, n + 1, x, 0);
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++){
            if (c[i][j] == 0) continue;
            addEdge(i, j, c[i][j], 0);
            addEdge(i, j, x, 1);
        }
    lld ret;
    lld f = minCostMaxFlow(n + 2, 0, n + 1, ret);
    if (f == x && ret <= k) return 1;
    return 0;
}
int main()
{
    cin >> n >> k;
    for(i = 1; i <= n;i++)
        for(j = 1; j <= n;j++){
            cin>>c[i][j];
        }
    lld l = 0, r = 1e9;
    lld ans = 0;
    while(l <= r){
        lld mid = (l + r) >> 1;
        if (check(mid)){
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    cout << ans << endl;
}