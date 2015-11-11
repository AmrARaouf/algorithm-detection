//Language: GNU C++


#include <algorithm>
#include <bitset>
#include <cctype>
#include <cfloat>
#include <climits>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unistd.h>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;
typedef long long ll;

#define gc getchar
int getint() { unsigned int c; int x = 0; while (((c = gc()) - '0') >= 10) { if (c == '-') return -getint(); if (!~c) exit(0); } do { x = (x << 3) + (x << 1) + (c - '0'); } while (((c = gc()) - '0') < 10); return x; }

const int MOD = 1000000007;
struct modint {
    int v;
    modint() : v(0) {}
    modint(int v) : v(v >= MOD ? v - MOD : v) {}
    modint(ll v) : v(v >= MOD ? v % MOD : v) {}
    void clear() { v = ~0; }
    bool is() { return ~v; }
    int to_int() { return v; }
    typedef modint M;
    M& operator+=(M x) { return *this = v + x.v; }
    M& operator-=(M x) { return *this = MOD + v - x.v; }
    M& operator*=(M x) { return *this = (ll)v * x.v; }
    M operator+(M x) const { return M(v) += x; }
    M operator-(M x) const { return M(v) -= x; }
    M operator*(M x) const { return M(v) *= x; }
    M operator-() { return M(0) - *this; }
};
ostream& operator<<(ostream& os, modint x) { os << x.v; return os; }
modint mod_pow(modint x, ll n) { modint y = 1; for (; n; x *= x, n >>= 1) if (n & 1) y *= x; return y; }
modint mod_inv(modint x) { modint y = 1; for (int n = MOD - 2; n; x *= x, n >>= 1) if (n & 1) y *= x; return y; }
modint& operator/= (modint& x, modint y) { return x *= mod_inv(y); }
modint operator/(modint x, modint y) { return x /= y; }

const int N = 100011;


struct StronglyConnectedComponent {
    static const int MAX_V = N;
    int nv, sv;
    vector<int> gr[MAX_V], rg[MAX_V];
    vector<int> cmpMap, vOrder, sccSet[MAX_V];
    bool vis[MAX_V];
    void init(int v = MAX_V) {
        nv = v, cmpMap.resize(nv), vOrder.clear();
        for (v = 0; v < nv; v++) gr[v].clear(), rg[v].clear(), sccSet[v].clear(), sgr[v].clear();
    }
    void add_edge(int fr, int to) { gr[fr].push_back(to), rg[to].push_back(fr); }
    void dfs(int v) {
        vis[v] = 1;
        for (int i = 0; i < (int)gr[v].size(); i++) if (!vis[gr[v][i]]) dfs(gr[v][i]);
        vOrder.push_back(v);
    }
    void rdfs(int v, int k) {
        vis[v] = 1, cmpMap[v] = k, sccSet[k].push_back(v);
        for (int i = 0; i < (int)rg[v].size(); i++) if (!vis[rg[v][i]]) rdfs(rg[v][i], k);
    }
    int scc() {
        memset(vis, 0, sizeof(vis));
        for (int v = 0; v < nv; v++) if (!vis[v]) dfs(v);
        memset(vis, 0, sizeof(vis)), sv = 0;
        reverse(vOrder.begin(), vOrder.end());
        for (int i = 0; i < nv; i++) if (!vis[vOrder[i]]) rdfs(vOrder[i], sv++);
        return sv;
    }
    //
    vector<int> sgr[MAX_V];
    void scc_graph() {
        for (int i = 0; i < sv; i++) sgr[i].clear();
        for (int u = 0; u < nv; u++) for (int i = 0; i < (int)gr[u].size(); i++) if (cmpMap[u] != cmpMap[gr[u][i]]) {
            sgr[cmpMap[u]].push_back(cmpMap[gr[u][i]]);
        }
        for (int s = 0; s < sv; s++) {
            sort(sgr[s].begin(), sgr[s].end());
            sgr[s].erase(unique(sgr[s].begin(), sgr[s].end()), sgr[s].end());
        }
    }
};

int n;
ll cost[N];
int vis[N];
int ng;
vector<int> group[N];
StronglyConnectedComponent scc;

int main () {
    int i, j, tcc, tc = 1 << 28;
    for (tcc = 0; tcc < tc; tcc++) {
        n = getint();
        scc.init(n);
        for (i = 0; i < n; i++) cost[i] = getint();
        int m = getint();
        for (i = 0; i < m; i++) {
            int u = getint() - 1, v = getint() - 1;
            scc.add_edge(u, v);
        }
        scc.scc();
        scc.scc_graph();

        ll minCost = 0;
        modint minNum = 1;
        for (i = 0; i < scc.sv; i++) {
            vector<int> & vec = scc.sccSet[i];
            ll mn = 1LL << 38;
            int cnt = 0;
            for (j = 0; j < vec.size(); j++) {
                if (mn > cost[vec[j]]) {
                    mn = cost[vec[j]], cnt = 1;
                } else if (mn == cost[vec[j]]) {
                    cnt++;
                }
            }
            minCost += mn;
            minNum *= modint(cnt);
        }
        cout << minCost;
        printf(" %d\n", minNum.to_int());
    }
    return 0;
}
