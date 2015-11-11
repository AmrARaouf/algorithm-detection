//Language: GNU C++


#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL long long
#define N 3100
struct node{
    int v, next;
    node(int v = 0, int next = 0) :v(v), next(next){}
}e[N * 10];
int head[N], cnt, num[N];
bool vis[N];
void add(int u, int v)
{
    e[cnt] = node(v, head[u]);
    head[u] = cnt++;
}
LL fun(int n)
{
    return n * (n - 1) / 2;
}
int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        cnt = 0;
        memset(head, -1, sizeof head);
        int u, v;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &u, &v);
            add(u, v);
        }
        LL ans = 0;
        for (int i = 1; i <= n; i++)
        {
            memset(num, 0, sizeof num);
            for (int j = head[i]; ~j; j = e[j].next)
                for (int k = head[e[j].v]; ~k; k = e[k].next)
                    if (e[k].v != i) num[e[k].v]++;
            for (int i = 1; i <= n; i++)
                if (num[i] >= 2) ans += fun(num[i]);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}