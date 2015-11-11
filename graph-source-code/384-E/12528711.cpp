//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define M int m = (l + r) >> 1
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r

const int N = 2e5 + 10;
int val[N];
vector <int> g[N];
int timeLabel;
int ll[N], rr[N], dep[N], sum[2][N << 2], lazy[2][N << 2];

void dfs(int u, int fa, int d) {
    ll[u] = ++timeLabel;
    dep[u] = d;
    int cnt = (int) g[u].size();
    for (int i = 0; i < cnt; ++i) {
        int v = g[u][i];
        if (v == fa) continue;
        dfs(v, u, d + 1);
    }
    rr[u] = timeLabel;
}

void pushUp(int rt, int x) {
    sum[x][rt] = sum[x][ls] + sum[x][rs];
}

void build(int rt, int l, int r, int x) {
    sum[x][rt] = lazy[x][rt] = 0;
    if (l == r) {
        return;
    }
    M;
    build(lson, x);
    build(rson, x);
    pushUp(rt, x);
}

void pushDown(int rt, int len, int x) {
    if (lazy[x][rt]) {
        lazy[x][ls] += lazy[x][rt];
        lazy[x][rs] += lazy[x][rt];
        sum[x][ls] += lazy[x][rt];
        sum[x][rs] += lazy[x][rt];
        lazy[x][rt] = 0;
    }
}

void update(int rt, int l, int r, int L, int R, int data, int x) {
    if (L <= l && r <= R) {
        lazy[x][rt] += data;
        sum[x][rt] += data;
        return;
    }
    pushDown(rt, r - l + 1, x);
    M;
    if (L <= m) {
        update(lson, L, R, data, x);
    }
    if (R > m) {
        update(rson, L, R, data, x);
    }
    pushUp(rt, x);
}

int query(int rt, int l, int r, int L, int R, int x) {
    if (L <= l && r <= R) {
        return sum[x][rt];
    }
    pushDown(rt, r - l + 1, x);
    M;
    int ret = 0;
    if (L <= m) {
        ret += query(lson, L, R, x);
    }
    if (R > m) {
        ret += query(rson, L, R, x);
    }
    return ret;
}

int S() {
    int ret = 0, neg = 0;
    char c = getchar();
    for ( ; c < '0' || c > '9'; c = getchar())
        if (c == '-') neg = 1;
    for ( ; c >= '0' && c <= '9'; c = getchar())
        ret = (ret << 3) + (ret << 1) + c - '0';
    return neg ? -ret : ret;
}

int main() {
    int n = S(), m = S();
    for (int i = 1; i <= n; ++i) val[i] = S();
    for (int i = 1; i < n; ++i) {
        int u = S(), v = S();
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1, 1);
    for (int i = 0; i < 2; ++i) {
        build(1, 1, n, i);
    }
    while (m--) {
        int op = S(), x = S(), data;
        if (op == 1) {
            data = S();
            update(1, 1, n, ll[x], rr[x], data, dep[x] & 1);
            if (ll[x] < rr[x]) {
                update(1, 1, n, ll[x] + 1, rr[x], -data, (dep[x] & 1) ^ 1);
            }
        }
        else {
            int ans = query(1, 1, n, ll[x], ll[x], dep[x] & 1) + val[x];
            printf("%d\n", ans);
        }
    }
    return 0;
}