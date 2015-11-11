//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define X first
#define Y second
const int maxk = 500+1;
const int maxn = 1e5+1;
const int INF = 1<<25;
int n, m, k;
int ans[maxk][maxk];
vector<pii> G[maxn];
int c[maxk];
int no[maxn];
int block[maxn], nBlock;

void dfs(int u)
{
    block[u] = nBlock;
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i].first, w = G[u][i].second;
        if (block[v] || w) continue;
        dfs(v);
    }
}
void init()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= k; i++)
    {
        scanf("%d", &c[i]);
        c[i] += c[i-1];
        for (int j = c[i-1]+1; j <= c[i]; j++)
            no[j] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u].pb(mp(v, w));
        G[v].pb(mp(u, w));
    }

    for (int i = 1; i <= n; i++) if (!block[i])
    {
        nBlock++;
        dfs(i);
    }
}

void update(int &x, int y)
{
    if (y < x)
        x = y;
}

void solve()
{
    for (int i = 1; i <= k; i++)
    {
        for (int j = c[i-1]+1; j <= c[i]; j++)
            if (block[j] != block[c[i]])
            {
                puts("No");
                return;
            }
    }

    for (int i = 1; i <= k; i++) for (int j = 1; j <= k; j++)
        ans[i][j] = i==j?0:INF;

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < G[i].size(); j++)
            update(ans[no[i]][no[G[i][j].first]], G[i][j].second);

    for (int x = 1; x <= k; x++)
        for (int y = 1; y <= k; y++)
            for (int z = 1; z <= k; z++)
                update(ans[y][z], ans[y][x]+ans[x][z]);

    puts("Yes");
    for (int i = 1; i <= k; i++) for (int j = 1; j <= k; j++)
        printf("%d%c", ans[i][j]==INF?-1:ans[i][j], j==k?'\n':' ');
}

int main()
{
    init();
    solve();
}
