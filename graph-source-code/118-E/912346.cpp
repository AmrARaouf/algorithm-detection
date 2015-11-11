//Language: GNU C++


#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <cstdio>

using namespace std;

#define mp make_pair
const int N = 100005;
const int MM = N * 6;

int n, m;
int e;
int cnt;
int low[N];
int DFN[N];
int degree[N];
bool visit[N];

struct Edge {
    int v;
    bool msk;
    Edge *next, *op;
} *head[N], ebuf[MM];
int ne = 0;
inline void addEdge(int u, int v) {
    Edge *e1 = ebuf + ne++;
    Edge *e2 = ebuf + ne++;
    e1->msk = false, e1->v = v, e1->next = head[u], e1->op = e2, head[u] = e1;
    e2->msk = false, e2->v = u, e2->next = head[v], e2->op = e1, head[v] = e2;
}

inline void Min(int & a, int b) {
    if(a > b) a = b;
}

void dfs(int u, int pre) {
    low[u] = ++ cnt;
    visit[u] = true;
    for (Edge *p = head[u]; p; p = p->next) {
        int v = p->v;
        if (v == pre) continue;
        if (!visit[v]) {
            dfs(v, u);          
        }
        Min(low[u], low[v]);
    }
}

map<pair<int, int>, bool> M;
bool vis[N];
vector<pair<int, int> > vi;

void dfs2(int u) {
    vis[u] = true;
    for (Edge *p = head[u]; p; p = p->next) {
        int v = p->v;
        if (!p->msk && !p->op->msk) {
            p->msk = p->op->msk = true;
            printf("%d %d\n", u, v);
            if (!vis[v]) {
                dfs2(v);
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    memset(head, 0, sizeof(head));
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        addEdge(u, v);
    }
    dfs(1, -1);
    for (int u = 1; u <= n; u++) {
        for (Edge *p = head[u]; p; p = p->next) {
            int v = p->v;
            if (low[u] != low[v])
                degree[low[u]] ++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 1) {
            ans ++;
        }
    }
    if (ans) {
        cout << "0" << endl;
        return 0;
    }
    dfs2(1);    
}