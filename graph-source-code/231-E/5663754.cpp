//Language: GNU C++


#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; i++)
#define REP(i, n) FOR(i, 0, n)
#define ll long long 
#define pb push_back
#define N 100005
#define M 100005
#define MOD 1000000007

int n, m, cyc[N], mark[N], par[N], markup[N], lev[N];
vector<int> a[N], g[N];
bool vis[N];
int p[N][17];

void cycmark(int u = 0, int pre = -1)
{
    vis[u] = 1;
    REP(i, a[u].size())
    {
        int v = a[u][i];
        if(v == pre) continue;
        if(!vis[v])
        {
            par[v] = u;
            cycmark(v, u);
        }
        else if(cyc[u] != v)
        {
            for(int i = u; i != par[v]; i = par[i])
            {
                cyc[i] = u;
                mark[i] = 1;
            }
        }
    }
}

void findmarkup(int u = cyc[0], int pre = -1, int s = 0, int l = 0)
{
    p[u][0] = pre;
    lev[u] = l;
    markup[u] = s + mark[u];
    REP(i, g[u].size())
    {
        int v = g[u][i];
        if(v == pre) continue;
        findmarkup(v, u, markup[u], l+1);
    }
}

void process()
{
    par[0] = -1;
    REP(i, n) cyc[i] = i;
    cycmark();
    REP(u, n) REP(i, a[u].size())
    {
        int v = a[u][i]; if(v > u) continue;
        if(cyc[u] == cyc[v]) continue;
        g[cyc[u]].pb(cyc[v]);
        g[cyc[v]].pb(cyc[u]);
    }
    REP(i, n) REP(j, 17) p[i][j] = -1;
    findmarkup();
    FOR(j, 1, 17) REP(i, n) if(p[i][j-1] != -1) p[i][j] = p[p[i][j-1]][j-1];
    //REP(i, n) cout << lev[i] << ' ';
    //cout << endl;
    return;
}

int p2(int z)
{
    if(z == 0) return 1;
    if(z == 1) return 2;
    if(z & 1) return ((ll)2*p2(z-1))%MOD;
    int k = p2(z/2);
    return ((ll)k*k)%MOD;
}

int lca(int u, int v)
{
    if(u == v) return u;
    if(lev[u] < lev[v]) swap(u, v);
    int d = lev[u] - lev[v];
    REP(j, 17) if(d & (1<<j)) u = p[u][j];
    if(u == v) return u;
    for(int j = 16; j >= 0; j--) if(p[u][j] != p[v][j])
    {
        u = p[u][j];
        v = p[v][j];
    }
    return p[u][0];
}

int query(int u, int v)
{
    u = cyc[u]; v = cyc[v];
    if(u == v) return 2;
    int L = lca(u, v);
    return p2(markup[u] + markup[v] - 2*markup[L] + mark[L]);
}

int main()
{
    cin >> n >> m;
    REP(i, m)
    {
        int u, v; cin >> u >> v; u--, v--;
        a[u].pb(v); a[v].pb(u);
    }
    process();
    int q; cin >> q;
    while(q--)
    {
        int u, v;
        cin >> u >> v; u--, v--;
        cout << "                  " << query(u, v) << endl;
    }
    return 0;
}
