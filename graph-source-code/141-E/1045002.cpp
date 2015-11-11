//Language: GNU C++


#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 1010, M = 100010;

int n, m;
struct edge { int u, v, t; } ed[M];

int pnt[N];
int eid[N];

int find(int x) {
  while (pnt[x] != -1)
    x = pnt[x];
  return x;
}

int join(int x, int y, int ee) {
  static int a[N], an;
  if (rand() % 2)
    swap(x, y);
  int rx = find(x);
  int ry = find(y);
  if (rx != ry) {
    an = 0;
    for (int u = y; u != -1; u = pnt[u])
      a[an++] = u;
    for (int i = an - 1; i > 0; i--) {
      int v = a[i];
      int u = a[i - 1];
      int e = eid[u];
      pnt[v] = u;
      eid[v] = e;
    }
    pnt[y] = x;
    eid[y] = ee;
    return 1;
  }
  return 0;
}

int lca(int x, int y) {
  static int vt[N], ts;
  ts++;
  for (int u = x; u != -1; u = pnt[u])
    vt[u] = ts;
  for (int u = y; u != -1; u = pnt[u])
    if (vt[u] == ts)
      return u;
  return -1;
}

int cycle(int x, int y, int ee) {
  static int a[N], an;
  if (rand() % 2)
    swap(x, y);
  int l = lca(x, y);
  int z = -1, s;
  for (int u = x; u != l; u = pnt[u]) {
    int e = eid[u];
    if (ed[e].t == 0) z = u, s = x;
  }
  for (int u = y; u != l; u = pnt[u]) {
    int e = eid[u];
    if (ed[e].t == 0) z = u, s = y;
  }
  if (z == -1)
    return 0;

  an = 0;
  for (int u = s; u != pnt[z]; u = pnt[u])
    a[an++] = u;
  for (int i = an - 1; i > 0; i--) {
    int y = a[i];
    int x = a[i - 1];
    int e = eid[x];
    pnt[y] = x;
    eid[y] = e;
  }
  pnt[s] = (s == x) ? y : x;
  eid[s] = ee;
  return 1;
}

int main() {
  while (scanf("%d %d", &n, &m) != EOF) {
    for (int e = 0; e < m; e++) {
      int u, v, t;
      char c;
      scanf("%d %d %c", &u, &v, &c);
      u--;
      v--;
      t = (c == 'S');
      ed[e].u = u;
      ed[e].v = v;
      ed[e].t = t;
    }
    if (n % 2 == 0) {
      puts("-1");
      continue;
    }
    for (int e = 0; e < m; e++) {
      int u = ed[e].u;
      int v = ed[e].v;
      int t = ed[e].t;
    }
    
    memset(pnt, -1, sizeof pnt);

    int n0 = 0, n1 = 0;
    for (int e = 0; e < m; e++) if (ed[e].t == 0) {
      int u = ed[e].u;
      int v = ed[e].v;
      if (join(u, v, e))
        n0++;
    }
    for (int e = 0; n1 < n / 2 && e < m; e++) if (ed[e].t == 1) {
      int u = ed[e].u;
      int v = ed[e].v;
      if (join(u, v, e)) {
        n1++;
      }
    }
    if (n0 + n1 == n - 1 && n0 >= n / 2)
      for (int e = 0; n1 < n / 2 && e < m; e++) if (ed[e].t == 1) {
        int u = ed[e].u;
        int v = ed[e].v;
        if (cycle(u, v, e))
          n0--, n1++;
      }
    if (n0 == n / 2 && n1 == n / 2) {
      printf("%d\n", n - 1);
      for (int u = 0; u < n; u++) {
        if (pnt[u] != -1)
          printf("%d ", eid[u] + 1);
      }
      puts("");
    } else {
      puts("-1");
    }
  }

  return 0;
}
