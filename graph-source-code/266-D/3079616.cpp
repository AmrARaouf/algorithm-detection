//Language: GNU C++


#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 205;

int n, m;
struct Edge
{
    int u, v, w;
} edge[MAXN * MAXN];
int dist[MAXN][MAXN];

bool judge(int d, int u, int v, int w)
{
    vector<pair<int, int> > list;
    for(int i=1;i<=n;++i)
    {
        int l = d - dist[i][u];
        int r = d - dist[i][v];
        if(l >= w)
        {
            continue;
        }
        if(r >= w)
        {
            continue;
        }
        if(l < 0)
        {
            l = -1;
        }
        if(r < 0)
        {
            r = -1;
        }
        if(l == -1 && r == -1)
        {
            return false;
        }
        if(l + r >= w - 1)
        {
            continue;
        }
        list.push_back(make_pair(l + 1, w - r - 1));
    }
    if(list.empty())
    {
        return true;
    }
    sort(list.begin(), list.end());
    int r = 0;
    for(int i=0;i<list.size();++i)
    {
        if(r < list[i].first)
        {
            return true;
        }
        r = max(r, list[i].second + 1);
    }
    return false;
}

bool judge(int d)
{
    for(int i=0;i<m;++i)
    {
        if(judge(d, edge[i].u, edge[i].v, edge[i].w))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        memset(dist, 0x3f, sizeof(dist));
        for(int i=0;i<m;++i)
        {
            scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
            edge[i].w <<= 1;
            dist[edge[i].u][edge[i].v] = edge[i].w;
            dist[edge[i].v][edge[i].u] = edge[i].w;
        }
        for(int i=1;i<=n;++i)
        {
            dist[i][i] = 0;
        }
        for(int k=1;k<=n;++k)
        {
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=n;++j)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int l = 0, r = 1e8;
        int ans = 1e8;
        while(l <= r)
        {
            int mid = (l + r) * 0.5;
            if(judge(mid))
            {
                ans = min(ans, mid);
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        printf("%lf\n", ans * 0.5);
    }
    return 0;
}
