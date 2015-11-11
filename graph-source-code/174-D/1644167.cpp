//Language: GNU C++


/*
 * Author : Yang Zhang
 */
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

#define MAXN 100005
int n, m;
vector<int> adj[MAXN], radj[MAXN];
int f[MAXN], h[MAXN], g[MAXN];

void bfs1(int u) {
    queue<int> Q;
    Q.push(u);
    h[u] = true;
    while (!Q.empty()) {
        u = Q.front();
        Q.pop();
        for (int i = 0; i < adj[u].size(); i++)
            if (!h[adj[u][i]]) {
                h[adj[u][i]] = true;
                Q.push(adj[u][i]);
            }
    }
}

void bfs2(int u) {
    queue<int> Q;
    Q.push(u);
    g[u] = true;
    while (!Q.empty()) {
        u = Q.front();
        Q.pop();
        if (f[u] == 1) continue;
        for (int i = 0; i < radj[u].size(); i++) {
            if (!g[radj[u][i]]) {
                g[radj[u][i]] = true;
                Q.push(radj[u][i]);
            }
        }
    }
}

int main() {
//    freopen("in", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &f[i]);
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].PB(b);
        radj[b].PB(a);
    }
    for (int i = 1; i <= n; i++) {
        if (f[i] == 1) bfs1(i);
        if (f[i] == 2) bfs2(i);
    }
    for (int i = 1; i <= n; i++) {
        if (h[i] && g[i]) puts("1");
        else puts("0");
    }
    return 0;
}
