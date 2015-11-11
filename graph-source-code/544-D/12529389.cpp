//Language: GNU C++11


/*************************************************************************
    > File Name: d.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com
    > Created Time: 2015年08月14日 星期五 18时25分38秒
 ************************************************************************/

#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <complex>
#include <cassert>
// #pragma comment(linker,"/STACK:102400000,102400000")
using namespace std;
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define MAXN 3005
template <typename T> inline void checkMax(T &a, T b) {a = a>b?a:b;}
template <typename T> inline void checkMin(T &a, T b) {a = a<b?a:b;}
typedef pair<int, int> PII;
typedef vector<int> vi;
const int INF = 0x3fffffff;
const double PI = acos(-1.0);
const double eps = 1e-8;
int N, M, dis[MAXN][MAXN];

int head[MAXN], cnt, S1, T1, L1, S2, T2, L2;

bool vis[MAXN], ok1[MAXN], ok2[MAXN];

struct Edge {
    int v, next;
} p[MAXN * 2];

void init() {
    memset(p, 0, sizeof(p));
    memset(ok1, 0, sizeof(ok1));
    memset(ok2, 0, sizeof(ok2));
    fill(head, head + MAXN, -1);
    cnt = 0;
}

void addEdge(int u, int v) {
    p[cnt].v = v;
    p[cnt].next = head[u];
    head[u] = cnt ++;
}

void bfs(int s) {
    memset(vis, 0, sizeof(vis));
    queue < pair<int, int> > Q;
    Q.push(mp(s, 0));
    vis[s] = true;
    while (!Q.empty()) {
        pair<int, int> top = Q.front();
        Q.pop();
        int u = top.x, d = top.y;
        dis[s][u] = d;
        for (int i = head[u]; i != -1; i = p[i].next) {
            int v = p[i].v;
            if (!vis[v]) {
                Q.push(mp(v, d + 1));
                vis[v] = true;
            }
        }
    }
}

void work() {
    init();
    for (int i = 1; i <= N; i ++) {
        fill(dis[i], dis[i] + MAXN, INF);
    }
    for (int i = 1; i <= M; i ++) {
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(a, b);
        addEdge(b, a);
    }
    for (int i = 1; i <= N; i ++) {
        bfs(i);
    }
    scanf("%d %d %d", &S1, &T1, &L1);
    scanf("%d %d %d", &S2, &T2, &L2);

    if (dis[S1][T1] > L1 || dis[S2][T2] > L2) {
        printf("-1\n"); return ;
    }
    int res = M - dis[S1][T1] - dis[S2][T2];
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= N; j ++) {
            if ((dis[S1][i] + dis[i][j] + dis[j][T1] <= L1) && (dis[S2][i] + dis[i][j] + dis[j][T2] <= L2)) {
                res = max(res, M - dis[S1][i] - dis[i][j] - dis[j][T1] - dis[j][T2] - dis[S2][i]);
            }
        }
    }
    swap(S2, T2);
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= N; j ++) {
            if ((dis[S1][i] + dis[i][j] + dis[j][T1] <= L1) && (dis[S2][i] + dis[i][j] + dis[j][T2] <= L2)) {
                res = max(res, M - dis[S1][i] - dis[i][j] - dis[j][T1] - dis[j][T2] - dis[S2][i]);
            }
        }
    }
    swap(S1, T1);
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= N; j ++) {
            if ((dis[S1][i] + dis[i][j] + dis[j][T1] <= L1) && (dis[S2][i] + dis[i][j] + dis[j][T2] <= L2)) {
                res = max(res, M - dis[S1][i] - dis[i][j] - dis[j][T1] - dis[j][T2] - dis[S2][i]);
            }
        }
    }
    swap(S2, T2);
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= N; j ++) {
            if ((dis[S1][i] + dis[i][j] + dis[j][T1] <= L1) && (dis[S2][i] + dis[i][j] + dis[j][T2] <= L2)) {
                res = max(res, M - dis[S1][i] - dis[i][j] - dis[j][T1] - dis[j][T2] - dis[S2][i]);
            }
        }
    }
    cout << res << endl;
}
int main() {
#ifdef __SKT__
    freopen("in", "r", stdin);
#endif
    while (scanf("%d %d", &N, &M) != EOF) {
        work();
    }
    return 0;
}
