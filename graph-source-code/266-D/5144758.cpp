//Language: GNU C++


#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <utility>
#include <stack>
#include <set>
#include <map>
using namespace std;
#define clr(a, b) memset(a, b, sizeof(a))
#define REP(i, n) for (i = 0; i < (int)(n); ++i)
#define FOR(i, n) for (i = 1; i <= (int)(n); ++i)
#define MP make_pair
#define PB push_back
#define CI(a) scanf("%d", &a)
#define CII(a, b) scanf("%d%d", &a, &b)
#define CIII(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define PI(a) printf("%d\n", a)
#define PIS(a) printf("%d ", a)
#define ABS(x) max((x), -(x))
#define MAX(a, b, c) max(a, max(b, c))
#define MIN(a, b, c) min(a, min(b, c))
#define ls(i) (i << 1)
#define rs(i) (i << 1 | 1)
#define pi (atan(1.0) * 4)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int N = 210, inf = 0x7fffffff;

int n, m, d[N][N], g[N][N], ans;

int calc(int u, int v) {
    vector <pii> vi, vj;
    int i;
    FOR(i, n) vi.PB(MP(d[i][u], d[i][v]));
    sort(vi.begin(), vi.end());
    reverse(vi.begin(), vi.end());

    int maxn = -1;
    REP(i, n) {
        if (vi[i].second <= maxn) continue;
        vj.PB(vi[i]); maxn = vi[i].second;
    }

    int ed = vj.size();
    int ret = min(vj[0].first, vj[ed - 1].second) * 2 + g[u][v];
    REP(i, ed - 1) {
        ret = min(ret, vj[i+1].first + g[u][v] + vj[i].second);
    }

    return ret;
}

int main() {
//    freopen("in", "r", stdin);
    cin >> n >> m;
    int i, j, k;
    int u, v, w;

    clr(d, 0x3f);
    FOR(i, n) d[i][i] = 0;

    while (m--) {
        CIII(u, v, w);
        g[u][v] = g[v][u] = w;
        d[u][v] = d[v][u] = w;
    }

    FOR(i, n) FOR(j, n) FOR(k, n)
        d[j][k] = min(d[j][k], d[j][i] + d[i][k]);

    ans = inf;

    FOR(i, n) for (j = i; j <= n; ++j) if (g[i][j] || i == j) {
        ans = min(ans, calc(i, j));
    }

    printf("%.1lf\n", ans / 2.0);

    return 0;
}
