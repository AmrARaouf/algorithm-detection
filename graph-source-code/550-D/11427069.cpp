//Language: GNU C++11


#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
using i64 = long long;
using Pii = pair<int, int>;

constexpr double eps = 1e-8;
const double pi = acos(-1.0);
constexpr int MAX = 1024;

int deg[MAX], mat[MAX][MAX];

inline void addEdge(int u, int v) {
  mat[u][v] = mat[v][u] = 1;
  ++deg[u]; ++deg[v];
}

void calc(int k, int st) {
  int n = k + 2;
  for (int i = 1; i < n; ++i) addEdge(st + i - 1, st + i);
  addEdge(st, st + n - 1);
  for (int i = 1; i < n; ++i) {
    for (int j = i + 2; j < n && deg[st + i] < k; ++j) {
      if (deg[st + j] == k) continue;
      if (deg[st] < k && !mat[st + i][st] && !mat[st][st + j]) {
        addEdge(st + i, st); addEdge(st, st + j);
      } else {
        addEdge(st + i, st + j);
      }
    }
  }
}

int solve(int k) {
  if (!(k & 1)) return -1;
  memset(mat, 0, sizeof(mat));
  memset(deg, 0, sizeof(deg));
  if (k == 1) {
    addEdge(0, 1);
    return 2;
  }
  addEdge(0, k + 2);
  calc(k, 0);
  calc(k, k + 2);
  return (k + 2) << 1;
}

int main() {
  int k;
  while (~scanf("%d", &k)) {
    int n = solve(k);
    if (n == -1) printf("NO\n");
    else {
      int m = 0;
      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          m += mat[i][j];
        }
      }
      printf("YES\n%d %d\n", n, m);
      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          if (mat[i][j]) printf("%d %d\n", i + 1, j + 1);
        }
      }
    }
  }
  return 0;
}
