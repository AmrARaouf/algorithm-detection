//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include <queue>
#include <vector>
  
#define scaf2(x,y) scaf(x);scaf(y);
#define mkp make_pair
#define fst first
#define scd second
  
using namespace std;
template<typename T>inline void scaf(T&v)
{
    char ch = getchar();
    for(; ch < '0' || ch > '9'; ch = getchar());
    for(v = 0; ch >= '0' && ch <= '9'; ch = getchar()) v = (v << 1) +(v << 3) + ch - '0';
}

typedef pair<int, int>PII;
typedef long long LL;
const int MV = 3e5 + 5;
const LL mod = 1e9 + 7;

int ROOT[MV];
int cnt[MV];
int maxLen[MV];
int vis[MV];
int dis[MV];
int __path[MV];
vector<int>edge[MV];
int beg;
int Len;

int findSet(int x) { return ROOT[x] = ROOT[x] == x ? x : findSet(ROOT[x]);}
int bfs(int u, int len)
{
    queue<int> dq;
    dq.push(u);
    __path[u] = -2;
    dis[u] = 0;
    while (!dq.empty())
    {
        u = dq.front(); dq.pop();
        if (dis[u] == len) return u;
        for (int i = 0; i < edge[u].size(); ++ i)
        {
            int v = edge[u][i];
            if (v != __path[u])
            {
                dis[v] = dis[u] + 1;
                __path[v] = u;
                dq.push(v);
            }
        }
    }
    return u;
}
int GETLEN(int u, int now)
{
    queue<int> dq;
    dq.push(u);
    dis[u] = now;
    __path[u] = -1;
    beg = u;
    int ret = 0;
    while (!dq.empty())
    {
        u = dq.front(); dq.pop();
        vis[u] = true;
        if (dis[u] - now > ret)
        {
            ret = dis[u] - now;
            beg = u;
        }
        for (int i = 0; i < edge[u].size(); ++ i)
        {
            int v = edge[u][i];
            if (v != __path[u])
            {
                dis[v] = dis[u] + 1;
                __path[v] = u;
                dq.push(v);
            }
        }
    }
    return ret;
}

void solve(int node)
{
    int len = GETLEN(node, 0);
    len = GETLEN(beg, MV << 1);
    int mlen = len;
    len = (len + 1) / 2;
    int _node = bfs(node, len);
    int ru = findSet(node);
    ROOT[ru] = _node;
    ROOT[_node] = _node;
    cnt[_node] = len;
    maxLen[_node] = mlen;
}

int main()
{
    int i, j, k, n, m, u, v;
    scanf("%d%d%d", &n, &m, &k);
    for (i = 1; i <= n; ++ i)
    {
        ROOT[i] = i, cnt[i] = 0, maxLen[i] = 0;
        vis[i] = 0;
        dis[i] = -1;
        __path[i] = -1;
        edge[i].clear();
    }
    for (i = 0; i < m; ++ i)
    {
        scanf("%d%d", &u, &v);
        edge[v].push_back(u);
        edge[u].push_back(v);
        u = findSet(u); v = findSet(v);
        ROOT[v] = u;
    }
    for (i = 1; i <= n; ++ i)
        if (!vis[i])
        {
            solve(i);
        }
    int op;
    while(k -- )
    {
        scanf("%d", &op);
        if (1 == op)
        {
            scanf("%d", &u);
            u = findSet(u);
            printf("%d\n", maxLen[u]);
        }else
        {
            scanf("%d%d", &u, &v);
            u = findSet(u); v = findSet(v);
            if (u != v)
            {
                if (cnt[u] < cnt[v]) swap(u, v);
                ROOT[v] = u;
                maxLen[u] = max(maxLen[u], cnt[u] + cnt[v] + 1);
                if (cnt[u] == cnt[v]) cnt[u] ++;
            }
        }
    }
    return 0;
}
