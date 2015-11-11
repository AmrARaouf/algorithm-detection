//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 100010;
const int MAXM = 200010;

struct Edge
{
  int x, y; 
  int val, res, pos;
} E[MAXN];

int head[MAXN], next[MAXM], node[MAXM], idx[MAXM], tt;
int vis[MAXN], vtt;
int lab[MAXN], ltt;
int high[MAXN], num[MAXN];
int fa[MAXN];
int dfsn;
int n, m;

bool cmp_val(const Edge &p1, const Edge &p2) {
  return p1.val < p2.val;
}

bool cmp_pos(const Edge &p1, const Edge &p2) {
  return p1.pos < p2.pos;
}

void add(int x, int y, int id)
{
  node[++tt] = y; next[tt] = head[x]; head[x] = tt;
  idx[tt] = id;
}

void init()
{
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &E[i].x, &E[i].y, &E[i].val);
    --E[i].x;
    --E[i].y;
    E[i].pos = i;
    E[i].res = -1;
  }
}

int renew(int x)
{
  if (fa[x] != x) return fa[x] = renew(fa[x]);
  return x;
}

void dfs(int x, int fa)
{
  high[x] = num[x] = dfsn--;
  int fatt = 0;
  for (int i = head[x]; i; i = next[i]) {
    if (fatt == 0 && node[i] == fa) { ++fatt; continue; }
    if (num[node[i]] == 0) {
      dfs(node[i], x);
      if (high[node[i]] < num[x]) {
	E[idx[i]].res = 1;
      }
      high[x] = max(high[x], high[node[i]]);
    } else
      high[x] = max(high[x], num[node[i]]);
  }
}

void solve()
{
  memset(vis, 0, sizeof(vis));
  vtt = 0;
  for (int i = 0; i < n; ++i) fa[i] = i;
  sort(E, E+m, cmp_val);

  for (int st = 0, ed = 1; st < m; st = ed) {
    for (; ed < m && E[st].val == E[ed].val; ++ed);
    ++vtt;
    ltt = 0;
    tt = 0;
    for (int x, y, i = st; i < ed; ++i) {
      x = E[i].x; 
      y = E[i].y;
      x = renew(x); 
      y = renew(y);
      if (x != y) {
	if (vis[x] != vtt) { vis[x] = vtt; head[ltt] = 0; high[ltt] = num[ltt] = 0; lab[x] = ltt++; }
	if (vis[y] != vtt) { vis[y] = vtt; head[ltt] = 0; high[ltt] = num[ltt] = 0; lab[y] = ltt++; }
	add(lab[x], lab[y], i);
	add(lab[y], lab[x], i);
	E[i].res = 0;
      }
    }

    dfsn = ltt;
    for (int i = 0; i < ltt; ++i) 
      if (num[i] == 0) dfs(i, i);

    for (int x, y, i = st; i < ed; ++i) {
      x = E[i].x;
      y = E[i].y;
      x = renew(x);
      y = renew(y);
      if (x != y) fa[x] = y;
    }
  }

  sort(E, E+m, cmp_pos);
  for (int i = 0; i < m; ++i) {
    switch (E[i].res) {
    case -1 : puts("none"); break;
    case 0  : puts("at least one"); break;
    case 1  : puts("any"); break;
    }
  }
}

int main()
{
  init();
  solve();
  return 0;
}
