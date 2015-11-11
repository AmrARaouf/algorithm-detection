//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <deque>
using namespace std;

#define pb push_back
#define mp make_pair

const int N = 1e5 + 10;

int n, m, x, y;
int v[N];
vector <int> g[2][N];
int dist[N];
bool used[2][N];
deque <int> q;


void dfs(int u)
{
  used[0][u] = true;
  for(int i = 0; i < (int)g[0][u].size(); i++)
  {
    int to = g[0][u][i];
    if (!used[0][to])
      dfs(to);
  }
}

void bfs()
{
  while(!q.empty())
  {
    int s = q.front(); q.pop_front();
    for(int i = 0; i < (int)g[1][s].size(); i++)
    {
      int to = g[1][s][i], w = (v[to] == 1);
      if (!w && dist[to] > dist[s])
      {
        used[1][to] = true;
        dist[to] = dist[s];
        q.push_front(to);
      }
      else if (w && dist[to] > dist[s] + 1)
      {
        used[1][to] = true;
        dist[to] = dist[s] + 1;
        q.push_back(to);
      }
    }
  }
}

int main()
{
  cin >> n >> m;
  for(int i = 1; i <= n; i++)
    scanf("%d", &v[i]);
  for(int i = 1; i <= n; i++)
    dist[i] = N;
  for(int i = 0; i < m; i++)
  {
    scanf("%d%d", &x, &y);
    g[0][x].pb(y);
    g[1][y].pb(x);
  }
  for(int i = 1; i <= n; i++)
    if (v[i] == 1)
      dfs(i);
    else if (v[i] == 2)
    {
      used[1][i] = true;
      dist[i] = 0;
      q.push_back(i);
    }
  bfs();
  for(int i = 1; i <= n; i++)
    if (used[0][i] && used[1][i])
    {
      if (dist[i] == (v[i] == 1))
        printf("1\n");
      else
        printf("0\n");
    }
    else
      printf("0\n");
  return 0;
}
