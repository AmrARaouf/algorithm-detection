//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n;
int g[101][101];
int cx[101][2];
int vis[101];

void dfs(int node) {
  if (vis[node]) {
    return;
  }
  vis[node] = 1;
  for (int i = 0; i < n; i++) {
    if (g[node][i]) {
      dfs(i);
    }
  }
}

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &cx[i][0], &cx[i][1]);
  }
  memset(g, 0, sizeof(int) * 101 * 101);
  for (int i = 0; i < n; i++) {
    int x = cx[i][0];
    int y = cx[i][1];
    for (int j = i + 1; j < n; j++) {
      if (cx[j][0] == x || cx[j][1] == y) {
        g[i][j] = g[j][i] = 1;
      }
    }
  }
  memset(vis, 0, sizeof(int) * 101);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      ans++;
      dfs(i);
    }
  }
  printf ("%d\n", ans - 1);
  return 0;
}
