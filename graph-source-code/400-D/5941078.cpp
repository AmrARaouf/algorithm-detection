//Language: GNU C++


//{
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
#define LIN(i, u) for (i = head[u]; ~i; i = nxt[i])
#define MP make_pair
#define PB push_back
#define MAX(a, b, c) max(a, max(b, c))
#define MIN(a, b, c) min(a, min(b, c))
#define all(x) (x).begin(), (x).end()
#define ls(i) (i << 1)
#define rs(i) (i << 1 | 1)
#define pi (atan(1.0) * 4)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

template <class T> void CIN(T &a) { cin >> a; }
template <class T> void CIN(T &a, T &b) { cin >> a >> b; }
template <class T> void CIN(T &a, T &b, T &c) { cin >> a >> b >> c; }
template <class T> void CIN(T &a, T &b, T &c, T &d) { cin >> a >> b >> c >> d; }
template <class T> void PI(T a) { cout << a << endl; }
template <class T> void PI(T a, T b) { cout << a << " " << b << endl; }
template <class T> void PIS(T a) { cout << a << " "; }
template <class T> T abs(T a) { return a < 0 ? -a : a; }

//}

const int inf = 0x3f3f3f3f;
const int MOD = 1000000007;
const int N = 100010;

int n, m, k, c[510], sum[510], be[N];
int f[N];
int u[N], v[N], x[N];
int d[510][510];

void makeSet(int i) {
    f[i] = i;
}

int findSet(int i) {
    if (f[i] != i)
        f[i] = findSet(f[i]);
    return f[i];
}

void unionSet(int x, int y) {
    x = findSet(x);
    y = findSet(y);
    f[y] = x;
}

bool judge() {
    int i;
    FOR(i, k) {
        int fa = findSet(sum[i]);
        for (int j = sum[i - 1] + 1; j <= sum[i]; ++j)
            if (findSet(j) != fa) return false;
    }
    return true;
}

int main() {
//    freopen("in", "r", stdin);

    cin >> n >> m >> k;

    int i;
    FOR(i, k) cin >> c[i];
    FOR(i, k) sum[i] = sum[i - 1] + c[i];

    int j = 1;
    FOR(i, n) {
        if (i > sum[j]) ++j;
        be[i] = j;
    }

    FOR(i, n) makeSet(i);

    REP(i, m) {
        cin >> u[i] >> v[i] >> x[i];
        if (x[i] == 0) unionSet(u[i], v[i]);
    }

    if (!judge()) puts("No");
    else {
        puts("Yes");
        clr(d, 0x3f);
        FOR(i, k) d[i][i] = 0;

        REP(i, m) {
            int a = be[u[i]], b = be[v[i]];
            d[a][b] = min(d[a][b], x[i]);
            d[b][a] = min(d[b][a], x[i]);
        }

        for (i = 1; i <= k; ++i)
            for (j = 1; j <= k; ++j)
                for (int z = 1; z <= k; ++z)
                    d[j][z] = min(d[j][z], d[j][i] + d[i][z]);

        for (i = 1; i <= k; ++i)
            for (j = 1; j <= k; ++j) if (d[i][j] == inf)
                d[i][j] = -1;

        for (i = 1; i <= k; ++i) {
            for (j = 1; j <= k; ++j)
                PIS(d[i][j]);
            puts("");
        }
    }

    return 0;
}
