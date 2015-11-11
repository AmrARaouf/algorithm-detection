//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <int, string> pis;
#define f first
#define s second
#define mp make_pair
#define pb push_back
const int N = 11;
const int INF = 1e9;
const int SIZE = 2 * N * N;

struct edge
{
  int to, c, f, rev;
  edge() {}
  edge(int too, int cc, int ff, int revv)
  {
    to = too;
    c = cc;
    f = ff;
    rev = revv;
  }
};

vector <edge> g[SIZE];
int d[SIZE], ptr[SIZE], s, t, n;
queue <int> q;

void addEdge(int v, int u, int cap)
{
  g[v].pb(edge(u, cap, 0, 0));
  g[u].pb(edge(v, 0, 0, 0));
  g[v].back().rev = g[u].size() - 1;
  g[u].back().rev = g[v].size() - 1;
}
bool buildLevNet()
{
  for (int i = 0; i <= t; ++i)
    d[i] = INF;
  d[s] = 0;
  q.push(s);
  while (!q.empty())
  {
    int v = q.front();
    q.pop();
    for (int i = 0; i < g[v].size(); ++i)
    {
      int to = g[v][i].to;
      int cf = g[v][i].c - g[v][i].f;
      if (d[to] == INF && cf > 0)
      {
        d[to] = d[v] + 1;
        q.push(to);
      }
    }
  }
  return d[t] != INF;
}

int dfs(int v, int curFlow)
{
  if (v == t) return curFlow;
  for (int i = 0; i < g[v].size(); ++i)
  {
    int to = g[v][i].to;
    int cf = g[v][i].c - g[v][i].f, addFlow;
    if (d[to] == d[v] + 1 && cf > 0 && (addFlow = dfs(to, min(curFlow, cf))))
    {
      g[v][i].f += addFlow;
      g[to][g[v][i].rev].f -= addFlow;
      return addFlow;
    }
  }
  return 0;
}

int dinica()
{
  int flow = 0;
  while (buildLevNet())
  {
    memset(ptr, 0, sizeof(ptr));
    int add;
    while ((add = dfs(s, INF)))
      flow += add;
  }
  return flow;
}



queue <pii> go;
const int X[] = {-1, 1, 0, 0};
const int Y[] = {0, 0, -1, 1};
int dst[N][N][N][N], tbad;
char a[N][N], b[N][N];
pii bad;
bool check(pii v)
{
  return v.f >= 0 && v.f < n && v.s >= 0 && v.s < n && a[v.f][v.s] != 'Y' && a[v.f][v.s] != 'Z';
}
void bfs(int xs, int ys)
{
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      dst[xs][ys][i][j] = INF;
  dst[xs][ys][xs][ys] = 0;
  go.push(mp(xs, ys));
  while (!go.empty())
  {
    pii v = go.front();
    go.pop();
    if (dst[xs][ys][v.f][v.s] == dst[bad.f][bad.s][v.f][v.s] && (bad.f != xs || bad.s != ys)) continue;
    for (int i = 0; i < 4; ++i)
    {
      pii nv = mp(v.f + X[i], v.s + Y[i]);
      if (check(nv) && dst[xs][ys][nv.f][nv.s] == INF && dst[xs][ys][v.f][v.s] + 1 <= dst[bad.f][bad.s][nv.f][nv.s])
      {
        dst[xs][ys][nv.f][nv.s] = dst[xs][ys][v.f][v.s] + 1;
        go.push(nv);
      }
    }
  }
}

int main()
{
  cin >> n >> tbad;
  int px, py;
  for (int i = 0; i < n; ++i)
    for (int j  = 0; j < n; ++j)
    {
      cin >> a[i][j];
      if (a[i][j] == 'Z') px = i, py = j;
    }
  for (int i = 0; i < n; ++i)
    for (int j  = 0; j < n; ++j)
      cin >> b[i][j];
  bad = mp(px, py);
  bfs(px, py);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      dst[bad.f][bad.s][i][j] = min(dst[bad.f][bad.s][i][j], tbad);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (check(mp(i, j))) bfs(i, j);
  s = 0;
  t = 2 * n * n + 1;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
    {
      if (a[i][j] != '0') addEdge(s, i * n + j + 1, a[i][j] - '0');
      if (b[i][j] != '0') addEdge(i * n + j + 1 + n * n, t, b[i][j] - '0');
    }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      for (int i1 = 0; i1 < n; ++i1)
        for (int j1 = 0; j1 < n; ++j1)
          if (check(mp(i, j)) && check(mp(i1, j1)) && dst[i][j][i1][j1] <= dst[px][py][i1][j1])
            addEdge(i * n + j + 1, i1 * n + j1 + 1 + n * n, INF);
  cout << dinica();

/*
2 60
00
Z1

00
Z1
*/
  return 0;
}
