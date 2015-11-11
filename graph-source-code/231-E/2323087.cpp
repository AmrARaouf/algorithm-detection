//Language: GNU C++


// =============================================================================
// Author LUONG VAN DO
// Problem
// Algorithm
// Time Limit
// =============================================================================
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <math.h>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

#define rep(i, n) for (int i=0;i<n;i++)
#define repr(i, n) for (int i = n - 1;i>=0;i--)
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i=b;i>=a;i--)
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask ^ (1 << bit); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 111222333
#define N 100010
#define MAX_LOG 17
#define MOD 1000000007

vector <int> adj[N], adjj[N];
ii edge[N];
int n, m, k, cnt, scc;
int parent[N], low[N], num[N], size[N], sc[N], depth[N];
int P[N][MAX_LOG], Sm[N][MAX_LOG];
stack <int> S;
void dfs(int u) {
    num[u] = low[u] = ++cnt;
    S.push(u);
    for (int i = 0;i < adj[u].size();i++) {
        int v = adj[u][i];
        if ( !parent[v] ) {
            parent[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else
        if (parent[u] != v && low[u] > num[v]) low[u] = num[v];
    }
    if (num[u] == low[u]) {
        scc++;
        int x = -1;
        do{
            x = S.top(); S.pop();
            sc[x] = scc;
            size[scc]++;
        }while (x != u);
    }
}
void dfs(int u, int p, int lvl) {
    P[u][0] = p;
    Sm[u][0] = (size[u] > 2);
    depth[u] = lvl;
    for (int i = 0;i < adjj[u].size();i++) {
        int v = adjj[u][i];
        if ( v != p ) dfs(v, u, lvl + 1);
    }
}
void buildLCA() {
    int u, v;
    for (int i = 0;i < m;i++) {
        u = sc[edge[i].ff]; v = sc[edge[i].ss];
        if (u != v) {
            adjj[u].pb(v);
            adjj[v].pb(u);
        }
    }
    //for (int i = 1;i <= scc;i++)
        //cout <<i<<" "<<size[i]<<endl;
    //for (int i = 1;i <= scc;i++)
        //for (int j = 0;j< adjj[i].size();j++)
            //cout << i <<" "<<adjj[i][j]<<endl;
    dfs(1, -1, 0);
    
    for (k = 0;(1<<(k + 1)) <= n;k++);
    for (int j = 1;j <= k;j++)
        for (int i = 1;i <= scc;i++)
            if (P[i][j - 1] == -1) {
                P[i][j] = P[i][j - 1];
                Sm[i][j] = Sm[i][j - 1];
            }
            else {
                P[i][j] = P[P[i][j - 1]][j - 1];
                Sm[i][j] = Sm[i][j - 1] + Sm[P[i][j - 1]][j - 1];
            }
}
int64 power(int x) {
    int64 res = 1, a = 2;
    while ( x ) {
        if (x & 1) res = (res * a) % MOD;
        x>>=1;
        a = (a * a) % MOD;
    }
    return res;
}
int getLCA(int u, int v) {
    int ans = 0, j;
    if (depth[u] < depth[v]) swap(u, v);
    for (int j = k;j >= 0;j--)
        if (P[u][j] != -1 && depth[u] - (1<<j) >= depth[v]) {
            ans += Sm[u][j];
            u = P[u][j];
        }
    if (u == v) return ans + Sm[u][0];
    for (int j = k;j >= 0;j--) {
        if (P[u][j] != -1 && P[u][j] != P[v][j]) {
            ans += Sm[u][j] + Sm[v][j];
            u = P[u][j]; v = P[v][j];
        }
    }
    return ans + Sm[u][1] + Sm[v][0];
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int u, v, x;
    scanf("%d %d", &n, &m);
    fill(low, 0); fill(num, 0);
    fill(parent, 0); fill(size, 0);
    for (int i = 0;i < m;i++) {
        scanf("%d %d",&u, &v);
        edge[i] = ii(u, v);
        adj[u].pb(v); adj[v].pb(u);
    }
    cnt = scc = 0;
    for (int i = 1;i <= n;i++)
        if ( !parent[i] ) {
            parent[i] = -1;
            dfs(i);
        }
    //for (int i = 1;i <= n;i++)
        //cout << i <<" "<<sc[i]<< endl;
    buildLCA();
    scanf("%d", &m);
    while (m--) {
        scanf("%d %d", &u, &v);
        printf("%I64d\n", power(getLCA(sc[u], sc[v])));
    }
}
