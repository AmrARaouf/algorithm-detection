//Language: MS C++


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAXV 100010
#define MAXE 200010

using namespace std;

const char ans[][20] = {"none", "at least one", "any"};

struct EdgeSet {
    int u, v, w, id;
} est[MAXE];

int pre[MAXV];

struct Edge {
    int ed, id, next;
} edge[MAXE];

int head[MAXV], nEdge;
int dfn[MAXV], low[MAXV], idx;
int tag[MAXE];

void init() {
    memset(head, -1, sizeof(head));
    nEdge = 0;
}

void addEdge(int a, int b, int id) {
    edge[nEdge].ed = b;
    edge[nEdge].id = id;
    edge[nEdge].next = head[a];
    head[a] = nEdge++;
    edge[nEdge].ed = a;
    edge[nEdge].id = id;
    edge[nEdge].next = head[b];
    head[b] = nEdge++;
}

void tarjan(int x, int p) {
    int i, y;

    dfn[x] = low[x] = idx++;
    for (i = head[x]; ~i; i = edge[i].next) {
        if ((i | 1) != (p | 1)) {
            if (~dfn[y = edge[i].ed]) low[x] = min(low[x], dfn[y]);
            else {
                tarjan(y, i);
                low[x] = min(low[x], low[y]);
                if (dfn[x] < low[y]) tag[edge[i].id] = 2;
            }
        }
    }
}

bool cmp(const EdgeSet &a, const EdgeSet &b) {
    return a.w < b.w;
}

int root(int x) {
    int r, i, nxt;

    for (r = x; ~pre[r]; r = pre[r]);
    for (i = x; i != r; i = nxt) {
        nxt = pre[i]; pre[i] = r;
    }

    return r;
}

int kruskal(int n, int m) {
    int i, j, ra, rb, cnt = 0, ret = 0;

    init();
    memset(tag, 0, sizeof(tag));
    memset(dfn, -1, sizeof(dfn));
    memset(pre, -1, sizeof(pre));
    sort(est, est + m, cmp);
    for (i = 0; i < m && cnt < n - 1; i = j) {
        for (j = i; est[j].w == est[i].w; ++j) {
            ra = root(est[j].u); rb = root(est[j].v);
            if (ra == rb) tag[est[j].id] = 0;
            if (ra != rb) {
                tag[est[j].id] = 1;
                addEdge(ra, rb, est[j].id);
            }
        }
        for (j = i; est[j].w == est[i].w; ++j) {
            ra = root(est[j].u); rb = root(est[j].v);
            if (ra != rb) {
                if (dfn[ra] == -1) tarjan(ra, -1);
                head[ra] = dfn[ra] = head[rb] = dfn[rb] = -1;
            }
        }
        for (j = i; est[j].w == est[i].w; ++j) {
            ra = root(est[j].u); rb = root(est[j].v);
            if (ra != rb) {
                pre[ra] = rb; ret += est[j].w; ++cnt;
            }
        }
    }

    return ret;
}

int main() {
    int n, m, i;

    while (~scanf("%d %d", &n, &m)) {
        for (i = 0; i < m; ++i) {
            scanf("%d %d %d", &est[i].u, &est[i].v, &est[i].w);
            --est[i].u; --est[i].v; est[i].id = i;
        }
        kruskal(n, m);
        for (i = 0; i < m; ++i) printf("%s\n", ans[tag[i]]);
    }

    return 0;
}
