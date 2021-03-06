//Language: GNU C++


#include <cstdio>
#include <algorithm>

using namespace std;

const int INF = 1 << 29;
const int N = 200;
const int M = 7;
int a[N], c[N];
int dp[1 << M][N];
int g[N][N];
int path[N][N];
int n, m;
char ans[110][110];

void pave_path(int i, int j) {
  for (; j != i; j = path[i][j]) {
    ans[j / m][j % m] = 'X';
  }
}

void construct(int S, int v) {
  int best = INF;
  int u = -1;
  for (int i = 0; i < n; ++i) {
    if (dp[S][v] == dp[S][i] + g[i][v] && dp[S][i] < best) {
      best = dp[S][i];
      u = i;
    }
  }
  pave_path(u, v);
  if (c[u] >= 0 && (1 << c[u]) == S) {
    ans[u / m][u % m] = 'X';
    return;
  }
  for (int T = (S - 1) & S; T; T = (T - 1) & S) {
    if (dp[S][u] == dp[T][u] + dp[S ^ T][u] - a[u]) {
      construct(T, u);
      construct(S ^ T, u);
      return;
    }
  }
}

int main() {
  int L;
  scanf("%d %d %d", &n, &m, &L);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &a[i * m + j]);
      ans[i][j] = '.';
    }
  }
  n *= m;
  fill(c, c + n, -1);
  for (int i = 0; i < L; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x; --y;
    c[x * m + y] = i;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      path[i][j] = -1;
      if (abs(i / m - j / m) + abs(i % m - j % m) == 1) {
        g[i][j] = a[j];
        path[i][j] = i;
      } else if (i == j) {
        g[i][j] = 0;
      } else {
        g[i][j] = INF;
      }
    }
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (g[i][j] > g[i][k] + g[k][j]) {
          g[i][j] = g[i][k] + g[k][j];
          path[i][j] = path[k][j];
        }
      }
    }
  }
  for (int S = 1; S < (1 << L); ++S) {
    for (int v = 0; v < n; ++v) {
      if (c[v] >= 0 && (1 << c[v]) == S) dp[S][v] = a[v];
      else dp[S][v] = INF;
      for (int T = (S - 1) & S; T; T = (T - 1) & S) {
        dp[S][v] = min(dp[S][v], dp[T][v] + dp[S ^ T][v] - a[v]);
      }
    }
    for (int v = 0; v < n; ++v) {
      for (int u = 0; u < n; ++u) {
        dp[S][v] = min(dp[S][v], dp[S][u] + g[u][v]);
      }
    }
  }
  int ret = INF;
  for (int v = 0; v < n; ++v) {
    ret = min(ret, dp[(1 << L) - 1][v]);
  }
  printf("%d\n", ret);
  for (int v = 0; v < n; ++v) {
    if (ret == dp[(1 << L) - 1][v]) {
      construct((1 << L) - 1, v);
      break;
    }
  }
  for (int i = 0; i < n / m; ++i) {
    puts(ans[i]);
  }
  return 0;
}
