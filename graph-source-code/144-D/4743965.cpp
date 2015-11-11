//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <queue>
using namespace std;

#define INF (1 << 30)
#define N 101000
#define M 202000

struct node
{
    int u, v, next, w;
}edge[M];
int last[N], tot;
int n, m, s, k;
int dist[N];
int visit[N];
queue < int > Q;

void addedge(int u, int v, int w)
{
    edge[tot].u = u; edge[tot].v = v; edge[tot].w = w; edge[tot].next = last[u]; last[u] = tot++;
}

void spfa(int s)
{
    while(!Q.empty()) Q.pop();
    for(int i = 0; i <= n; i++) dist[i] = INF;
    dist[s] = 0;
    memset(visit, 0, sizeof(visit));
    visit[s] = 1;
    Q.push(s);
    while(!Q.empty())
    {
        int u = Q.front(), v;
        visit[u] = 0;
        Q.pop();
        for(int j = last[u]; -1 != j; j = edge[j].next)
        {
            v = edge[j].v;
            if(dist[v] > dist[u] + edge[j].w)
            {
                dist[v] = dist[u] + edge[j].w;
                if(!visit[v])
                {
                    Q.push(v);
                    visit[v] = 1;
                }
            }
        }
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &s);
    memset(last, -1, sizeof(last));
    tot = 0;
    for(int i = 0; i < m; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        addedge(x, y, z);
        addedge(y, x, z);
    }
    scanf("%d", &k);
    spfa(s);
    int ans = 0;
    for(int i = 1; i <= n; i++)
        if(dist[i] == k) ans++;
    for(int i = 0; i < m; i++)
    {
        int j = 2 * i;
        int x, y, z, u, v, w;
        u = edge[j].u; v = edge[j].v; w = edge[j].w;
        if(dist[u] < k)
        {
            x = k - dist[u];
            y = w - x;
            if(y != 0 && k < y + dist[v])
                ans++;
        }
        if(dist[v] < k)
        {
            x = k - dist[v];
            y = w - x;
            if(y != 0 && k <= y + dist[u])
                ans++;
        }
        //printf("yy %d %d %d %d\n", i, u, v, ans);
    }
    printf("%d\n", ans);
    return 0;
}

/*
5 6 3
3 1 1
3 2 1
3 4 1
3 5 1
1 2 6
4 5 8
4

4 6 1
1 2 1
1 3 3
2 3 1
2 4 1
3 4 1
1 4 2
2

4 6 1
1 2 2
1 3 3
2 3 1
2 4 1
3 4 1
1 4 2
2


*/

	   		   	 	  	 	 	  	  	