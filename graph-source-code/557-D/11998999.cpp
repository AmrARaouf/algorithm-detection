//Language: GNU C++


#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 100005;
const int inf = 0x3f3f3f3f;
int degree[maxn], color[maxn];
int sw[maxn], sb[maxn];
vector<int> G[maxn];
int n, m;
int dfs(int u, int t, int x)
{
    if(color[u] && color[u]!=t)
        return -1;
    if(color[u] && color[u]==t)
        return 1;
    if(t == 1)
        sw[x]++;
    else
        sb[x]++;
    color[u] = t;
    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if(dfs(v, -t, x)==-1)
            return -1;
    }
    return 1;
}
int main()
{
    int a, b, Max = 0;
    memset(color, 0, sizeof(color));
    memset(degree, 0, sizeof(degree));
    memset(sw, 0, sizeof(sw));
    memset(sb, 0, sizeof(sb));
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &a, &b);
        degree[a]++;
        degree[b]++;
        Max = max(Max, degree[a]);
        Max = max(Max, degree[b]);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int ans;
    long long sum;
    if(m == 0)
        ans = 3, sum = (long long)n*(n-1)*(n-2)/6;
    else if(Max <= 1)
        ans = 2, sum = (long long)m*(n-2);
    else
    {
        int flag = 0;
        for(int i = 1; i <= n; i++)
            if(!color[i])
            {
                if(dfs(i, 1, i) == -1)
                {
                    flag = 1;
                    break;
                }
            }
        if(flag)
            ans = 0, sum = 1;
        else
        {
            ans = 1, sum = 0;
            for(int i = 1; i <= n; i++)
                sum += (long long)sw[i]*(sw[i]-1)/2+(long long)sb[i]*(sb[i]-1)/2;
        }
    }
    printf("%d %I64d\n", ans, sum);
    return 0;
}
