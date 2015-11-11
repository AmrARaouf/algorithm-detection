//Language: MS C++


#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:100000000")
#include <stdio.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <fstream>
#include <iostream>
using namespace std;
#define N 100100
vector <int> m[N], c[N], g[N], h[N];
int d[N], p[N], u[N], n;
queue <int> q;
priority_queue <pair <int, int> > pq;
vector <int> a;
set <long long> w;
void push(int i, int v)
{
    if(u[i]==N) { u[i]=v; q.push(i); }
}
void bfs(int b)
{
    int i, j;
    for(i=0; i<n; u[i]=N, i++);
    for(push(b, 0); !q.empty(); )
        for(i=q.front(), q.pop(), j=0; j<m[i].size(); push(m[i][j], u[i]+1), j++);
}
void ppush(int i, int v, int a)
{
    if(v<u[i]) { u[i]=v; pq.push(make_pair(-v, i)); p[i]=a; }
}
void dij(int b)
{
    int i, j, v;
    for(i=0; i<n; u[i]=N, i++);
    for(ppush(b, 0, -1); !pq.empty(); )
    {
        i=pq.top().second; v=-pq.top().first; pq.pop();
        if(v==u[i])
            for(j=0; j<g[i].size(); ppush(g[i][j], v+h[i][j], i), j++);
    }
}
int main()
{
    int i, j, k, l;
    scanf("%d%d", &n, &k);
    for(; k--; scanf("%d%d%d", &i, &j, &l), i--, j--, m[i].push_back(j), m[j].push_back(i), c[i].push_back(l), c[j].push_back(l));
    bfs(0);
    for(i=0; i<n; d[i]=u[i], i++);
    bfs(n-1);
    for(i=0; i<n; p[i]=u[i], i++);
    for(i=0; i<n; i++)
        for(j=0; j<m[i].size(); j++)
            if(d[i]+p[m[i][j]]+1==p[0]) { g[i].push_back(m[i][j]); h[i].push_back(1-c[i][j]); }
            else if(p[i]+d[m[i][j]]+1>p[0] && i<m[i][j] && c[i][j]) { a.push_back(i); a.push_back(m[i][j]); a.push_back(0); }
    dij(0);
    for(i=n-1; i>0; w.insert((long long)p[i]*N+i), i=p[i])
        if(u[i]==u[p[i]]+1) { a.push_back(p[i]); a.push_back(i); a.push_back(1); }
    for(i=0; i<n; i++)
        for(j=0; j<g[i].size(); j++)
            if(w.find((long long)i*N+g[i][j])==w.end() && h[i][j]==0) { a.push_back(i); a.push_back(g[i][j]); a.push_back(0); }
    printf("%d\n", a.size()/3);
    for(i=0; i<a.size(); printf("%d %d %d\n", a[i]+1, a[i+1]+1, a[i+2]), i+=3);
    return 0;
}