//Language: GNU C++


#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>

using namespace std;

vector <int> g[50000];
int p[50000];

void dfs(int x, int parent = -1) {
  p[x] = parent;
  int sz = g[x].size();
  for (int i = 0; i < sz; ++i) {
    int y = g[x][i];
    if (y != parent) {
      dfs(y, x);
    }
  }
}

int main() {
  int n, r1, r2; scanf("%d %d %d", &n, &r1, &r2); --r1; --r2;
  for (int i = 0; i < n; ++i) {
    g[i].clear();
  }
  for (int i = 0; i < n; ++i) {
    if (i == r1) {
      continue;
    }
    int p; scanf("%d", &p); --p;
    g[i].push_back(p);
    g[p].push_back(i);
  }
  dfs(r2);
  for (int i = 0; i < n; ++i) {
    if (i == r2) {
      continue;
    }
    printf("%d ", p[i] + 1);
  }
  return 0;
}