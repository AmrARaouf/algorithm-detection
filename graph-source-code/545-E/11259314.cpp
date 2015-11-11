//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

#define FOR(i,a,b) for (int (i) = (a), _b = (b); (i) <= _b; ++(i) )
#define FORD(i,a,b) for (int (i) = (a), _b = (b); (i) >= _b; --(i) )
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define DEBUG(x) cout << #x << " = " << x << "\n"

const int N = 3e5 + 10;

typedef pair<int, int> ii;
typedef long long ll;

int n, m, s;
vector<ii> a[N];
vector<int> id[N];
long long d[N], tree[N], res;
int trc[N];
bool sel[N];

void enter() {
    scanf("%d%d", &n, &m);
    FOR(i,1,m) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        a[u].pb(mp(v,w));
        id[u].pb(i);
        a[v].pb(mp(u,w));
        id[v].pb(i);
    }
    scanf("%d", &s);
}

struct cmp {
    bool operator() (const pair<ll, int> &a, const pair<ll, int> &b) { return a.X > b.X; }
    bool operator() (const ii &a, const ii &b) { return a.X > b.X; }
};

void dijkstra() {
    FOR(i,1,n) d[i] = 1e18;
    d[s] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int> >, cmp> q;
    q.push(mp(d[s],s));
    while (!q.empty()) {
        long long du = q.top().X;
        int u = q.top().Y;
        q.pop();
        if (du != d[u]) continue;
        FOR(i,0,a[u].size()-1) {
            int v = a[u][i].X;
            if (d[v] > d[u] + a[u][i].Y) {
                d[v] = d[u] + a[u][i].Y;
                q.push(mp(d[v], v));
            }
        }
    }
}

void prim() {
    priority_queue<ii, vector<ii>, cmp> q;
    FOR(i,1,n) tree[i] = 1e18;
    tree[s] = 0;
    FOR(i,0,a[s].size()-1) {
        int v = a[s][i].X;
        if (tree[v] > a[s][i].Y && d[v] == d[s] + a[s][i].Y) {
            tree[v] = a[s][i].Y;
            trc[v] = id[s][i];
            q.push(mp(tree[v], v));
        }
    }

    res = 0;
    while (!q.empty()) {
        int treeu = q.top().X;
        int u = q.top().Y;
        q.pop();
        if (treeu != tree[u]) continue;
        //DEBUG(u); DEBUG(tree[u]);
        //res += tree[u];
        sel[trc[u]] = true;
        FOR(i,0,a[u].size()-1) {
            int v = a[u][i].X;
            if (d[v] == d[u]+a[u][i].Y && tree[v] > a[u][i].Y) {
                tree[v] = a[u][i].Y;
                trc[v] = id[u][i];
                q.push(mp(tree[v], v));
            }
        }
    }
}

int main() {
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    enter();
    dijkstra();
    prim();
    res = 0;
    FOR(i,1,n) if (i!=s) res += tree[i];
    printf("%I64d\n", res);
    FOR(i,1,n) if (i!=s) printf("%d ", trc[i]);
}

