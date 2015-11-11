//Language: GNU C++11


/*************************************************************************
    > File Name: e.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com
    > Created Time: 2015年08月15日 星期六 19时25分31秒
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
#define MAXN 505
template <typename T> inline void checkMax(T &a, T b) {a = a>b?a:b;}
template <typename T> inline void checkMin(T &a, T b) {a = a<b?a:b;}
typedef pair<int, int> PII;
typedef vector<int> vi;
const double PI = acos(-1.0);
const double eps = 1e-8;
const LL INF = 10000000000000000LL;
int N, M;

LL dis[MAXN][MAXN], g[MAXN][MAXN], cnt[MAXN][MAXN], ans[MAXN][MAXN];

void floyd() {
    for (int k = 1; k <= N; k ++) {
        for (int i = 1; i <= N; i ++) {
            for (int j = 1; j <= N; j ++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}

void work() {
    for (int i = 1; i <= N; i ++) {
        fill(dis[i], dis[i] + MAXN, INF);
        fill(g[i], g[i] + MAXN, INF);
    }
    memset(cnt, 0, sizeof(cnt));
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i <= N; i ++) dis[i][i] = 0LL;
    for (int i = 1; i <= M; i ++) {
        int a, b, l;
        scanf("%d %d %d", &a, &b, &l);
        dis[a][b] = dis[b][a] = l;
        g[a][b] = g[b][a] = l;
    }
    floyd();
    for (int from = 1; from <= N; from ++) {
        for (int to = 1; to <= N; to ++) {
            if (dis[from][to] == INF || dis[from][to] == 0) {
                continue;
            }
            for (int mid = 1; mid <= N; mid ++) {
                if (dis[from][to] == dis[from][mid] + g[mid][to]) {
                    cnt[from][to] ++;
                }
            }
        }
        for (int to = from + 1; to <= N; to ++) {
            for (int mid = 1; mid <= N; mid ++) {
                if (dis[from][to] == INF || dis[from][mid] == INF || dis[mid][to] == INF) {
                    continue;
                }
                if (dis[from][to] == dis[from][mid] + dis[mid][to]) {
                    ans[from][to] += cnt[from][mid];
                }
            }
            printf("%d ", (int)ans[from][to]);
        }
    }
    printf("\n");
}
int main() {
    while (scanf("%d %d", &N, &M) != EOF) {
        work();
    }
    return 0;
}
