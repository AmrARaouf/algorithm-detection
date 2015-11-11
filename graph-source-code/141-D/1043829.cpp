//Language: GNU C++


#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef long long ll;

struct ramp {
  ll x, d, t, p;
  int id;
};

bool operator<(const ramp &a, const ramp &b) {
  return a.x + a.d < b.x + b.d;
}

const ll INF = 0x3f3f3f3f3f3f3f3fll;
const int N = 100010;

int n, n1;
ll L;
ramp a[N];
ll xx[N];
ll f1[N + N], f2[N + N];
int g1[N + N], g2[N + N];
int prev[N];
ll best[N];
int stack[N], top;

inline int id(int u, int v) { return (u + v - 1) | (u + 1 < v); }
inline int md(int u, int v) { return (u + v + 1) >> 1; }

void build(ll *f, int v) {
  memset(f, 0x3f, sizeof(*f) * (v + v));
}

void update(ll *f, int *g, int u, int v, int x, ll y, int z) {
  int t = id(u, v);
  int d = md(u, v);
  int l = id(u, d);
  int r = id(d, v);
  if (u + 1 == v) {
    if (f[t] > y)
      f[t] = y, g[t] = z;
    return;
  }
  if (x < d)
    update(f, g, u, d, x, y, z);
  else
    update(f, g, d, v, x, y, z);
  if (f[l] < f[r])
    f[t] = f[l], g[t] = g[l];
  else
    f[t] = f[r], g[t] = g[r];
}

ll query(ll *f, int *g, int u, int v, int a, int b, int &z) {
  int t = id(u, v);
  int d = md(u, v);
  int l = id(u, d);
  int r = id(d, v);
  if (a == b)
    return INF;
  if (u == a && v == b)
    return z = g[t], f[t];
  if (b <= d)
    return query(f, g, u, d, a, b, z);
  else if (d <= a)
    return query(f, g, d, v, a, b, z);
  else {
    int z1, z2;
    ll f1 = query(f, g, u, d, a, d, z1);
    ll f2 = query(f, g, d, v, d, b, z2);
    if (f1 < f2)
      return z = z1, f1;
    else
      return z = z2, f2;
  }
}

int main() {
  scanf("%d %d", &n, &L);
  n1 = n;
  for (int i = 0, z = 1; i < n; i++, z++) {
    scanf("%lld %lld %lld %lld", &a[i].x, &a[i].d, &a[i].t, &a[i].p);
    a[i].id = z;
    if (a[i].t >= a[i].d || a[i].x - a[i].p < 0) {
      n--;
      i--;
    }
  }

  sort(a, a + n);

  for (int i = 0; i < n; i++)
    xx[i] = a[i].x + a[i].d;
  n1 = unique(xx, xx + n) - xx;

  ll ans = L;
  int last = -1;
  build(f1, n1);
  build(f2, n1);
  for (int i = 0; i < n; i++) {
    int j = lower_bound(xx, xx + n1, a[i].x - a[i].p) - xx;
    int k = lower_bound(xx, xx + n1, a[i].x + a[i].d) - xx;
    ll x = a[i].x + a[i].d;
    int id1, id2, id3 = -1;
    ll t1 = query(f1, g1, 0, n1, 0, j, id1) + a[i].x - a[i].p + a[i].p + a[i].t;
    ll t2 = query(f2, g2, 0, n1, j, k, id2) - a[i].x + a[i].p + a[i].p + a[i].t;
    ll t3 = a[i].x + a[i].t;
    ll t = t1;
    int id = id1;
    if (t > t2)
      t = t2, id = id2;
    if (t > t3)
      t = t3, id = id3;
    update(f1, g1, 0, n1, k, t - x, i);
    update(f2, g2, 0, n1, k, t + x, i);
    prev[i] = id;
    best[i] = t;
    if (id != -1 && best[id] + abs((a[i].x - a[i].p) - (a[id].x + a[id].d)) + a[i].p + a[i].t != best[i]) {
      printf("shit %d -> %d, %lld -> %lld\n", id, i, best[id], best[i]);
      printf("%lld %lld %lld\n", t1, t2, t3);
    }
    ll tt = t + L - x;
    if (ans > tt) {
      ans = tt;
      last = i;
    }
  }
  int last1 = last;
  while (last1 != -1) {
    stack[top++] = last1;
    last1 = prev[last1];
  }
  int ooops = 0;
  ll x = 0, t = 0;
  while (top) {
    int i = stack[--top];
    t += abs((a[i].x - a[i].p) - x) + a[i].p + a[i].t;
    x = a[i].x + a[i].d;
    if (best[i] != t)
      ooops += 1;
  }
  t += L - x;
  x = L;
  if (t != ans)
    puts("ooops!");
  if (ooops)
    printf("ooops = %d\n", ooops);

  top = 0;
  while (last != -1) {
    stack[top++] = a[last].id;
    last = prev[last];
  }
  printf("%lld\n", ans);
  printf("%d\n", top);
  while (top)
    printf("%d\n", stack[--top]);

  return 0;
}
