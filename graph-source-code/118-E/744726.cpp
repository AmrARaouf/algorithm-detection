//Language: GNU C++


#include <set>
#include <map>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <algorithm>
#define LL long long
#define pi 3.1415926535897932384626433 
#define sqr(a) ((a)*(a))

using namespace std;

const int maxn = 301010;

vector<int> adj[maxn];
int d[maxn], low[maxn], u[maxn];
int n, m, Yes = 0;
set<pair<int, int> > edge;

void dfs(int x)
{
    u[x] = 1;
    low[x] = d[x];
    for (int i = 0; i < adj[x].size(); i ++)
    {
        int j = adj[x][i];
        if (! u[j])
        {
            edge.insert(make_pair(x, j));
            d[j] = d[x] + 1;
            dfs(j);
            low[x] = min(low[x], low[j]);
        }
        else if (d[j] != d[x] - 1)
            if (d[j] > d[x])
            {
                edge.insert(make_pair(j, x));
                low[x] = min(low[x], low[j]);
            }
            else
            {
                edge.insert(make_pair(x, j));
                low[x] = min(low[x], d[j]);
            }
    }
    if (low[x] >= d[x] && x != 1)
        Yes = 1;
}
                         
int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++)
        adj[i].clear();
    for (int i = 1; i <= m; i ++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    //dfs
    memset(u, 0, sizeof(u));
    edge.clear(); d[1] = 0;
    dfs(1);
    if (Yes)
    {
        cout << 0 << endl;
        return 0;
    }
    for (set<pair<int, int> >::iterator i = edge.begin(); i != edge.end(); i ++)
        cout << i->first << " " << i->second << endl;
    return 0;
}
