//Language: GNU C++


#include <bits/stdc++.h>
#define fr(i,a,b) for (int i = (a), __ = (b); i < __; ++i)
#define st first
#define nd second
#define dbg(x) cout << #x << " " << x << endl
using namespace std;

const double eps = 1e-7;
const int inf = 0x3f3f3f3f;
typedef pair<int,int> ii;
typedef long long ll;
typedef vector<int> vi;

const int N = 100005;
const int E = 300005;
int custo[N], to[E], ant[E], adj[N], z = 0;
int dfs_num[N], dfs_low[N], S[N], visited[N];
int numSCC, dfsNmb, ind;
vector<int> scc[N];

inline void add(int a, int b) {
    to[z] = b; ant[z] = adj[a]; adj[a] = z++;
}

void tarjan(int u) {
    dfs_low[u] = dfs_num[u] = dfsNmb++;
    S[ind++] = u;
    visited[u] = 1;
    for (int i = adj[u]; ~i; i = ant[i]) {
        int v = to[i];
        if (dfs_num[v] == -1) tarjan(v);
        if (visited[v]) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    if (dfs_low[u] == dfs_num[u]) {
        while (1) {
            int v = S[--ind]; visited[v] = 0;
            scc[numSCC].push_back(v);
            if (u == v) break;
        } 
        ++numSCC;
    }
}

int mini[N];

const int mod = 1000000007;

int main() {
    int n; scanf("%d", &n);
    numSCC = dfsNmb = ind = 0;
    fr(i,0,n) {
        scanf("%d", &custo[i]);
        adj[i] = -1;
        dfs_low[i] = visited[i] = 0;
        dfs_num[i] = -1;
        mini[i] = inf;
    }
    int m; scanf("%d", &m);
    while (m--) {
        int a, b; scanf("%d %d", &a, &b); --a; --b;
        add(a,b);
    }
    fr(i,0,n) if (dfs_num[i] == -1) tarjan(i);
    ll soma = 0, total = 1;
    fr(i,0,numSCC) {
        ll qnt = 0;
        fr(j,0,scc[i].size()) {
            int x = custo[scc[i][j]];
            if (x < mini[i]) {
                qnt = 1; mini[i] = x;
            } else if (x == mini[i]) ++qnt;
        }
        soma += mini[i];
        total = (qnt*total)%mod;
    }
    cout << soma << " " << total << endl;
	return 0;
}

