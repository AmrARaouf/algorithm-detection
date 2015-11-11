//Language: GNU C++


#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cmath>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;

const int N = 1e5 + 7;
const int D = 20;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-6;
const double PI = acos(-1.0);

vector <int> e[N];

vector <PII> ask;

int fa[N], boss[N], occur[N], f[N][D], deep[N];

int find(int x){
    if (fa[x] == 0)
        return x;
    return fa[x] = find(fa[x]);
}

void dfs(int x, int de){
    deep[x] = ++de;
    //printf("DEEP %d : %d\n", x, deep[x]);
    for (int i = 0; i < e[x].size(); ++i){
        int v = e[x][i];
        f[v][0] = x;
        dfs(v, de);
    }
}

int lca(int x, int y){
    //printf("LCA %d %d\n", x, y);
    if (deep[x] < deep[y])
        swap(x, y);
    int d = deep[x] - deep[y], p = 0;
    while (d){
        //printf("-> %d of %d\n", x, d);
        if (d & 1)
            x = f[x][p];
        d >>= 1;
        ++p;
    }
    if (x == y)
        return x;
    for (int i = 0; i < D; ++i){
        if (f[x][i] != f[y][i]){
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];
}

int main(void){
    int n, m, op, a, b, Q = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i){
        scanf("%d", &op);
        if (op == 1){
            scanf("%d%d", &a, &b);
            fa[a] = b;
            e[b].push_back(a);
        }
        if (op == 2){
            ++Q;
            scanf("%d", &occur[Q]);
            boss[Q] = find(occur[Q]);
        }
        if (op == 3){
            scanf("%d%d", &a, &b);
            ask.push_back(make_pair(a, b));
        }
    }
    for (int i = 1; i <= n; ++i)
        if (find(i) == i)
            dfs(i, 0);
    for (int j = 1; j < D; ++j)
        for (int i = 1; i <= n; ++i)
            f[i][j] = f[f[i][j - 1]][j - 1];
    for (int i = 0; i < ask.size(); ++i){
        int doc = ask[i].second, peo = ask[i].first;
//      printf("Deal : %d %d\n", peo, doc);
//      printf("Point : %d %d\n", peo, occur[doc]);
//      printf("Find : %d %d\n", find(peo), find(occur[doc]));
//      printf("Lca : %d\n", lca(peo, occur[doc]));
//      printf("Deep : %d %d\n", deep[peo], deep[occur[doc]]);
        if (find(peo) != find(occur[doc]) || lca(peo, occur[doc]) != peo || deep[peo] > deep[occur[doc]] || deep[peo] < deep[boss[doc]])
            puts("NO");
        else
            puts("YES");
    }
    return 0;
}
