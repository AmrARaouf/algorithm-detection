//Language: MS C++


/*
ID: sdj22251
PROG: subset
LANG: C++
*/
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#define LOCA
#define MAXN 100005
#define INF 100000005
#define eps 1e-7
using namespace std;
struct node
{
    int v, w;
    node *next;
} edge[MAXN], temp[3 * MAXN]; 
int d[MAXN], n, m, pos = 0;
int q[MAXN * 4];
bool visited[MAXN]; 
int uu[MAXN], vv[MAXN], ww[MAXN];
void spfa(int src, int *ecost) //src是起点， ecost是边权
{
    int h, t, u, i;
    node *ptr;
    h = 0, t = 1;
    memset(visited, 0, sizeof(visited));
    q[0] = src;
    ecost[src] = 0;
    visited[src] = true;
    while(h < t)
    {
        u = q[h++];
        visited[u] = false;
        ptr = edge[u].next;
        while(ptr)
        {
            if(ecost[ptr -> v] > ecost[u] + ptr -> w)
            {
                ecost[ptr -> v] = ecost[u] + ptr -> w;
                if(!visited[ptr -> v])
                {
                    q[t++] = ptr -> v;
                    visited[ptr -> v] = true;
                }
            }
            ptr = ptr -> next;
        }
    }
}
void insert(const int &x, const int &y, const int &w)
{
    node *ptr = &temp[pos++]; 
    ptr -> v = y;
    ptr -> w = w;
    ptr -> next = edge[x].next;
    edge[x].next = ptr;
}
void init()
{
    for(int i = 0; i <= n; i++)
    {
        edge[i].next = NULL;
        d[i] = INF;
    }
}
int main()
{
    int s, w, len;
    scanf("%d%d%d", &n, &m, &s);
    init();
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &uu[i], &vv[i], &ww[i]);
        insert(uu[i], vv[i], ww[i]);
        insert(vv[i], uu[i], ww[i]);
    }
    scanf("%d", &len);
    spfa(s, d);
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(d[i] == len)
        ans++;
    }
    for(int i = 0; i < m; i++)
    {
        int mi = min(d[uu[i]], d[vv[i]]);
        int mx = max(d[uu[i]], d[vv[i]]);
        if(mi < len && mx < len) //如果两个点到源点的最短距离都小于L，就有可能出现边上有两个位置符合题意
        {
            if(mi + mx + ww[i] < 2 * len)       //由于题目要求是到源点的最短距离为L，那么两点分到源点的最短距离之和加上边权如果小于2*L，显然任何位置的最短距离都是小于L的
            continue;
            if(mi + mx + ww[i] == 2 * len) //去重，当某个位置通过两个结点到到达的源点都是L的时候
            ans++;
            else if(mi + mx + ww[i] > 2 * len)
            ans += 2;
        }
        else if(mi < len)
        {
            if(mi + ww[i] > len)
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}