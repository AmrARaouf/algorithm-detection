//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define FOR(i,a,b) for(int i = (a), _b = (b); i <= _b; ++i)
#define pb push_back
#define fi first
#define se second
const int N = 1E5 + 10;
typedef long long ll;
typedef pair<ll, int> ele;
typedef pair<int, int> pii;
struct Edge {
    int u, v, w;
    Edge() {}
    Edge(int _u, int _v, int _w) { u = _u;  v = _v; w = _w; }
};

struct edge{
    int v, w, id;
    edge() {}
    edge(int _v, int _w, int _id) { v = _v; w = _w; id = _id; }
};

int n, m, s, t, pt[N], par[N], num[N], low[N];
bool del[N];
ll d1[N], d2[N];
Edge e[N];
vector<pii> b[N];
vector<edge> a[N];

void enter() {
    scanf("%d%d%d%d", &n, &m, &s, &t);
    FOR(i,1,m) {
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
        a[e[i].u].pb( edge(e[i].v, e[i].w, 0) );
        a[e[i].v].pb( edge(e[i].u, e[i].w, 1) );
    }
}

void dijkstra(ll d[], int kind) {
    priority_queue<ele, vector<ele>, greater<ele> > q;
    FOR(i,1,n) d[i] = 1E18;
    int x = (kind)? t: s;
    d[x] = 0;
    q.push(ele(0, x));
    while (!q.empty()) {
        ll du = q.top().fi; int u = q.top().se; q.pop();
        if (du != d[u]) continue;
        FOR(i,0,a[u].size()-1)
        if (a[u][i].id == kind) {
            int v = a[u][i].v, w = a[u][i].w;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.push(ele(d[v], v));
            }
        }
    }
}

void init() {
    FOR(i,1,m) {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if (d1[u] + w + d2[v] == d1[t]) {
            b[u].pb(pii(v,i)); b[v].pb(pii(u,i));
        }
    }
    vector<int> stk;
    stk.pb(s); par[s] = -1;
    int cnt = 0; num[s] = ++cnt; low[s] = n+1;
    stk.pb(s);
    while (!stk.empty()) {
        int u = stk.back();

        if (pt[u] == b[u].size()) {
            stk.pop_back();
            if (stk.empty()) break;
            int pu = stk.back();
            low[pu] = min(low[pu], low[u]);
            continue;
        }

        while (pt[u] < b[u].size()) {
            int v = b[u][pt[u]].fi, id = b[u][pt[u]++].se;
            if (!del[id]) {
                del[id] = true;
                if (!par[v]) {
                    par[v] = u;
                    num[v] = ++cnt; low[v] = n+1;
                    stk.pb(v);
                    break;
                } else low[u] = min(low[u], num[v]);
            }
        }
    }
}

bool bridge(int u, int v) {
    if (par[u] == v) swap(u, v);
    if (par[v] != u) return false;
    return low[v] >= num[v];
}

void solve() {
    FOR(i,1,m) {
        int u = e[i].u, v = e[i].v, w = e[i].w;

        if (d1[u] == 1E18 || d2[v] == 1E18) {
            puts("NO"); continue;
        }

        if (d1[u] + d2[v] + w == d1[t] && bridge(u,v)) {
            puts("YES"); continue;
        }

        ll delta = d1[u] + w + d2[v] - d1[t] + 1;
        if (w > delta) printf("CAN %I64d\n", delta);
        else puts("NO");
    }
}

int main() {
    //freopen("test.inp", "r", stdin);
    enter();
    dijkstra(d1,0);
    dijkstra(d2,1);
    init();
    solve();
}
