//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
struct node
{
    int x, step;
};
int bfs (int n, int m)
{
    node p, q;
    queue <node> Q;
    int vis[maxn];
    memset (vis, 0, sizeof(vis));
    vis[n] = 1;
    p.x = n;
    p.step = 0;
    Q.push (p);
    while (!Q.empty())
    {
        p = Q.front();
        Q.pop();
        if (p.x == m)
            return p.step;
        q.step = p.step + 1;
        int x = p.x - 1;
        int y = p.x * 2;
        if (x > 0 && !vis[x])
        {
            q.x = x;
            Q.push (q);
            vis[x] = 1;
        }
        if (p.x<m && y<maxn && !vis[y])
        {
            q.x = y;
            Q.push (q);
            vis[y] = 1;
        }
    }
}
int main ()
{
    int n, m;
    while (scanf ("%d %d", &n, &m) != EOF)
        printf ("%d\n", bfs(n, m));
    return 0;
}
