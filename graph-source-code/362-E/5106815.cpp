//Language: GNU C++


#include <iostream>
#include <vector>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <cctype>
#include <queue>
using namespace std;
typedef long long ll;
#define mp make_pair
#define f first
#define s second
#define pb push_back
const int X[] = {-1, 1, 0, 0};
const int Y[] = {0, 0, -1, 1};
const int N = 100 + 10;
const int INF = 1e9;

struct edge
{
  int to, f, rev, c, cst;
  edge() {}
  edge(int too, int cc, int revv, int css)
  {
    to = too;
    c = cc;
    f = 0;
    cst = css;
    rev = revv;
  }
};

vector <edge> g[N];
int d[N], par[N], pared[N], n, k, s, t;
bool use[N];
queue <int> q;

void addEdge(int x, int y, int cap, int cst)
{
  int s1 = g[x].size();
  int s2 = g[y].size();
  g[x].pb(edge(y, cap, s2, cst));
  g[y].pb(edge(x, 0, s1, -cst));
}

int FBellman()
{
  for (int i = 0; i <= t; ++i) d[i] = INF;
  d[s] = 0;
  q.push(s);
  use[s] = true;
  while (!q.empty())
  {
    int v = q.front();
    use[v] = false;
    q.pop();
    for (int i = 0; i < g[v].size(); ++i)
    {
      int to = g[v][i].to;
      if (d[to] > d[v] + g[v][i].cst && g[v][i].c > g[v][i].f)
      {
        d[to] = d[v] + g[v][i].cst;
        if (!use[to]) q.push(to);
        use[to] = true;
        par[to] = v;
        pared[to] = i;
      }
    }
  }
  return d[t];
}

int main()
{
  cin >> n >> k;
  s = 0;
  t = n - 1;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
    {
      int x;
      cin >> x;
      if (x)
      {
        addEdge(i, j, x, 0);
        addEdge(i, j, k, 1);
      }
    }

  int ans = 0;
  while (true)
  {
    int w = FBellman();
    if (w == INF) break;
    int v = t, mn = INF;
    while (v != s)
    {
      mn = min(mn, g[par[v]][pared[v]].c - g[par[v]][pared[v]].f);
      v = par[v];
    }
    if (k >= w * mn)
    {
      ans += mn;
      k -= w * mn;
    } else
    {
      mn = min(mn, k / w);
      ans += mn;
      break;
    }

    v = t;
    while (v != s)
    {
      g[par[v]][pared[v]].f += mn;
      g[v][g[par[v]][pared[v]].rev].f -= mn;
      v = par[v];
    }
  }
  cout << ans;
  return 0;
}
