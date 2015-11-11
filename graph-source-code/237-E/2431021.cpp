//Language: GNU C++


#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <functional>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cassert>

using namespace std;

#ifndef LEEWINGS_DEBUG
#define LEEWINGS_DEBUG 0
#endif

#define debug(x) if (LEEWINGS_DEBUG) cerr << #x << " = " << (x) << endl

#define debug_line(a, n) do {                                                \
    if (LEEWINGS_DEBUG) {                                                    \
        cerr << #a << "[" << #n << "]:" << endl;                             \
        for (int i = 0; i < (n); i++) cerr << (a)[i] << " ";                 \
        cerr << endl;                                                        \
    }                                                                        \
} while (0)

#define debug_mat(a, n, m) do {                                              \
    if (LEEWINGS_DEBUG) {                                                    \
        cerr << #a << "[" << #n << "][" << #m "]:" << endl;                  \
        for (int i = 0; i < (n); i++) {                                      \
            for (int j = 0; j < (m); j++) cerr << (a)[i][j] << " ";          \
            cerr << endl;                                                    \
        }                                                                    \
    }                                                                        \
} while(0)

typedef pair<int, int> pii;
typedef vector<int>::const_iterator vci;
typedef map<int, int>::const_iterator mci;

const int INF = 0x3f3f3f3f;
const int NEGINF = 0xc0c0c0c0;
const long long LLINF = 0x3f3f3f3f3f3f3f3fll;
const long long NEGLLINF = 0xc0c0c0c0c0c0c0c0ll;
const double DINF = 1.0/0.0f;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int MOD = 1000000007;

inline int LC(int x) { return x << 1; }
inline int RC(int x) { return (x << 1) | 1; }
inline bool eq0(double x) { return fabs(x) < eps; }
inline bool eq(double x, double y) { return fabs(x - y) < eps; }
inline bool ls(double x, double y) { return x + eps < y; }
inline bool gr(double x, double y) { return x - eps > y; }
inline bool greq(double x, double y) { return x + eps >= y; }
inline bool lseq(double x, double y) { return x - eps <= y; }
inline double fmax(double x, double y) { return gr(x, y) ? x : y; }
inline double fmin(double x, double y) { return ls(x, y) ? x : y; }

template<class T> inline T SQR(T x) { return x * x; }
template<class T> inline int SIZE(const T &x) { return x.size(); }

const int MAXV = 200;
const int MAXE = 100000;
const int orig = 0, dest = MAXV - 1, vdest = MAXV - 2;

struct Edge {
    int v;
    int c, f; // capa, flow
    int cpf; // cost per flow
    Edge *next,
         *rev; // revese edge
};
Edge e_buf[MAXE],
     *e_tail,
     *e_head[MAXV];

struct Rnode {
    Rnode *next;
    Edge *which; // which edge
};
Rnode road[MAXV];
int que[MAXE], dist[MAXV];
bool vis[MAXV];

inline void add_edge(int u, int v, int c, int cpf)
{
    *e_tail = (Edge){v, c, 0, cpf, e_head[u]};
    e_head[u] = e_tail++;

    *e_tail = (Edge){u, 0, 0, -cpf, e_head[v]};
    e_head[v] = e_tail++;

    e_head[u]->rev = e_head[v];
    e_head[v]->rev = e_head[u];
}

bool spfa()
{
    memset(vis, false, sizeof(vis));
    memset(dist, 0x3f, sizeof(dist));

    int *head = que,
        *tail = que;
    *tail++ = orig;
    vis[orig] = true;
    dist[orig] = 0;
    road[orig].next = 0;

    while (head != tail) {
        int u = *head++;
        vis[u] = false;
        for (Edge *e = e_head[u]; e; e = e->next)
            if (e->cpf + dist[u] < dist[e->v] && e->f < e->c) {
                dist[e->v] = e->cpf + dist[u];
                road[e->v].next = &road[u];
                road[e->v].which = e;
                if (vis[e->v] == false) {
                    vis[e->v] = true;
                    *tail++ = e->v;
                }
            }
    }

    return dist[dest] < INF;
}

int flow()
{
    int f = INF;
    for (Rnode *r = &road[dest]; r->next; r = r->next)
        f = min(f, r->which->c - r->which->f);

    int res = 0;
    for (Rnode *r = &road[dest]; r->next; r = r->next) {
        r->which->f += f;
        res += r->which->cpf;
        r->which->rev->f = -r->which->f;
    }
    res *= f;

    return res;
}

int mcmf()
{
    int res = 0;
    while (spfa()) res += flow();

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    e_tail = e_buf;

    string t;
    cin >> t;

    int cnt[26];
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < SIZE(t); i++) {
        cnt[t[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        add_edge(orig, i + 1, cnt[i], 0);
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        int m;
        cin >> s >> m;
        memset(cnt, 0, sizeof cnt);
        for (int j = 0; j < SIZE(s); j++) {
            cnt[s[j] - 'a']++;
        }
        for (int j = 0; j < 26; j++) {
            add_edge(j + 1, i + 30, cnt[j], i + 1);
        }
        add_edge(i + 30, vdest, m, 0);
    }
    add_edge(vdest, dest, INF, 0);

    int res = mcmf();
    if (e_head[dest]->rev->f == SIZE(t)) {
        cout << res << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}

