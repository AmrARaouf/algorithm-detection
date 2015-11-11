//Language: GNU C++


#include <cstdio>
#include <queue>
#include <set>
#include <cstring>
#include <string>
#include <cctype>
#include <climits>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 110;

int cnt[maxn][26];
int a[maxn];
char t[10000000];
int n;
int tc[26];


const int MAX_M = 200000;
const int MAXN = 500;
    
struct Arc {
    int u, v, cost, cap, next;
};
    
int src, sink;
Arc arc[MAX_M];
int narc;
int adj[MAXN];
    
bool Q[MAXN];
int dist[MAXN], pre[MAXN], que[MAXN],front,rear;
int mincost;
int maxflow;
    
void __add_arc(int u, int v, int cap, int cost) {
    arc[narc].u = u;
    arc[narc].v = v;
    arc[narc].cap = cap;
    arc[narc].cost = cost;
    arc[narc].next = adj[u];
    adj[u] = narc;
    narc++;
}
    
void add_edge(int u, int v, int cap, int cost) {
    __add_arc(u, v, cap, cost);
    __add_arc(v, u, 0, -cost);
}
    
bool spfa() {
    std::fill(Q, Q + sink + 1, false);
    std::fill(dist, dist + sink + 1, INT_MAX);
    std::fill(pre, pre + sink + 1, -1);
    front = rear = 0;
    que[rear++] = src;
    dist[src] = 0;
    Q[src] = true;
    while (front < rear) {
        int t = que[--rear];
        Q[t] = false;
        for(int p = adj[t]; p != -1; p = arc[p].next) {
            if (arc[p].cap > 0 && dist[t] + arc[p].cost < dist[arc[p].v]) {
                dist[arc[p].v] = dist[t] + arc[p].cost;
                pre[arc[p].v] = p;
                if (!Q[arc[p].v]) {
                    que[rear++] = arc[p].v;
                    Q[arc[p].v] = true;
                }
            }
        }
    }
    return dist[sink] < INT_MAX;
}
    
void __aug_path() {
    int minFlow = INT_MAX;
    for (int i = pre[sink]; i != -1; i = pre[arc[i].u])
        minFlow = min(minFlow, arc[i].cap);
    for (int i = pre[sink]; i != -1; i = pre[arc[i].u]) {
        arc[i].cap -= minFlow;
        arc[i^1].cap += minFlow;
        mincost += arc[i].cost * minFlow;
    }
    maxflow += minFlow;
}
    
void min_cost_flow() {
    mincost = 0;
    maxflow = 0;
    while (spfa()) {
        __aug_path();
    }
}

int main()
{
    while (scanf("%s", t) != EOF) {
        scanf("%d", &n);
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n;i++) {
            char buf[110];
            scanf("%s%d", buf, &a[i]);
            for (int j = 0; buf[j] != 0; j++)
                cnt[i][buf[j] - 'a']++;
        }
        memset(adj, -1, sizeof(adj));
        memset(tc, 0 ,sizeof(tc));
        narc = 0;
        for (int i = 0; t[i] != 0; i++)
            tc[t[i] - 'a']++;
        for (int i = 1; i<= 26; i++) {
            add_edge(0, i, tc[i -1], 0);
        }
        for (int i = 1; i <= n; i++) {
            add_edge(i + 26, n + 26 + 1, a[i], 0);
        }
        for (int i = 1; i <= 26; i++) {
            for (int j = 1; j <= n; j++) {
                if (tc[i - 1] != 0 && cnt[j][i - 1] != 0) {
                    add_edge(i, 26 + j, cnt[j][i - 1], j);
                }
            }
        }
        
        src = 0;
        sink = n + 26 + 1;
        min_cost_flow();
        if (maxflow != strlen(t))
            mincost = -1;
        printf("%d\n", mincost);
    }
    return 0;
}