//Language: GNU C++11


#include <bits/stdc++.h>
#include <ext/algorithm>
#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;

const int N = 100000 + 100;
vector<int> g[N];
int tin[N], tout[N], timer;

void dfs(int u)
{
    tin[u] = ++timer;

    for (auto v : g[u])
        if (!tin[v]) dfs(v);

    tout[u] = ++timer;
}

bool anc(int u, int v)
{
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int p[N];

int root(int u)
{
    return p[u] < 0 ? u : p[u] = root(p[u]);
}

void join(int u, int v)
{
    if ((u = root(u)) != (v = root(v)))
    {
        if (p[u] > p[v]) swap(u, v);
        p[u] += p[v];
        p[v] = u;
    }
}

vector<pair<int,int>> queries[N];
int ans[N];

struct query
{
    int t, x, y;
};

int dad[N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i)
        p[i] = -1;

    vector<query> q(m);
    int id = 0;
    for (auto &qr : q)
    {
        scanf("%d%d", &qr.t, &qr.x);
        if (qr.t != 2) scanf("%d", &qr.y);
        if (qr.t == 3) queries[qr.y].push_back({id++, qr.x});
        if (qr.t == 1) g[qr.y].push_back(qr.x), dad[qr.x] = qr.y;
    }

    for (int i = 1; i <= n; ++i)
        if (dad[i] == 0)
            dfs(i);

    int doc = 1;
    for (auto qr : q)
    {
        if (qr.t == 1)
            join(qr.x, qr.y);
        else if (qr.t == 2)
        {
            for (auto p : queries[doc])
                ans[p.first] = root(p.second) == root(qr.x) && anc(p.second, qr.x);
            doc += 1;
        }
    }

    for (int i = 0; i < id; ++i)
        printf("%s\n", ans[i] ? "YES" : "NO");

    return 0;
}
