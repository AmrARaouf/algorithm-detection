//Language: GNU C++


#include <bits/stdc++.h>

#define MAXN 3005
#define NameTask "B"

using namespace std;

int n, m;
int s1, t1, l1;
int s2, t2, l2;
int c[MAXN][MAXN];
int mark[MAXN];
vector<int> a[MAXN];

int BFS(int s, int c[]) {
  memset(mark, 0, sizeof mark);
  for (int i = 1; i <= n; i++) {
    c[i] = n + 1;
  }
  c[s] = 0;
  mark[s] = 1;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < a[u].size(); i++) {
      if (mark[a[u][i]] == 0) {
        q.push(a[u][i]);
        mark[a[u][i]] = 1;
        c[a[u][i]] = c[u] + 1;
      }
    }
  }
}

int main() {
  //freopen(NameTask".inp", "r", stdin);
  //freopen(NameTask".out", "w", stdout);
  //ios_base :: sync_with_stdio(0);
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    a[u].push_back(v);
    a[v].push_back(u);
  }
  scanf("%d%d%d", &s1, &t1, &l1);
  scanf("%d%d%d", &s2, &t2, &l2);

  //BFS(s1, cs1);
  for (int s = 1; s <= n; s++) {
    BFS(s, c[s]);
  }

  if (c[s1][t1] > l1 || c[s2][t2] > l2) {
    printf("-1");
    return 0;
  }

  int res = m - c[s1][t1] - c[s2][t2];
  for (int u = 1; u <= n; u++) {
    for (int v = 1; v <= n; v++) {
      int f1 = c[s1][u] + c[u][v] + c[v][t1];
      int f2 = c[s2][u] + c[u][v] + c[v][t2];
      if (f1 <= l1 && f2 <= l2) {
        res = max(res, m - f1 - f2 + c[u][v]);
      }
      f2 = c[t2][u] + c[u][v] + c[v][s2];
      if (f1 <= l1 && f2 <= l2) {
        res = max(res, m - f1 - f2 + c[u][v]);
      }
    }
  }

  printf("%d", res);
  //cout << res;
}
