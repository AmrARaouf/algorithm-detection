//Language: GNU C++11


#include <bits/stdc++.h>

#define PB push_back 

typedef long long LL;

using namespace std;

const int inf=~0U >> 1, maxN=4010;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  static bool b[maxN][maxN];
  static vector<int> a[maxN];
  static int deg[maxN];
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (u > v) swap(u, v);
    a[u].PB(v);
    b[u][v] = b[v][u] = true;
    ++deg[u]; ++deg[v];
  }
  int ans = inf;
  for (int i = 0; i < n; ++i)
    for (size_t j = 0; j + 1 < a[i].size(); ++j)
      for (size_t k = 1; k < a[i].size(); ++k)
        if (b[a[i][j]][a[i][k]])
          ans = min(ans, deg[i] + deg[a[i][j]] + deg[a[i][k]] - 6);
  printf("%d\n", ans == inf ? -1 : ans);
  return 0;
}