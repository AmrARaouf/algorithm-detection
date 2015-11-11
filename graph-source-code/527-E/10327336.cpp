//Language: GNU C++0x


#include <bits/stdc++.h>

#define all(c) c.begin(), c.end() 
#define SIZE(A) (int((A).size()))
#define mp make_pair
#define pb push_back

using namespace std;

const int MAXN = 200000;
const int MAXV = 500000*4;

int n, m;
int h[MAXN], cur[MAXN], deg[MAXN], xo[MAXN];
char bad[MAXV];
int ne[MAXV], to[MAXV]; 
int lastEdge;

set< pair<int,int> > d;
vector<int> q, spis;

void AddEdge(int u, int v) {
  to[lastEdge] = v;
  ne[lastEdge] = h[u];
  h[u] = lastEdge++;
}

void Dfs(int u) {
  for (int &j = h[u]; j != -1; j = ne[j]) {
    if (bad[j]) {
      continue;
    }

    int v = to[j];
    bad[j] = bad[j^1] = 1;
    Dfs(v);
    if (j == -1) {
      break;
    }
  }
  q.pb(u);
}

int main() {
  cin >> n >> m;
  memset(h, -1, sizeof(int)*n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u; --v;
    AddEdge(u, v);
    AddEdge(v, u);
    ++deg[u]; ++deg[v];
  }

  for (int i = 0; i < n; ++i) {
    int v = deg[i];
    if (v & 1) {
      ++v;
      ++cur[i];
    }
    if (cur[i]) {
      d.insert(mp(-cur[i], i));
    }
  }

  for (; SIZE(d) > 1;) {
    int u = d.begin()->second;
    d.erase(d.begin());
    int v = d.begin()->second;
    d.erase(d.begin());
    --cur[u]; --cur[v];
    AddEdge(u, v);
    AddEdge(v, u);
    ++deg[u]; ++deg[v];
    if (cur[u]) {
      d.insert(mp(-cur[u], u));
    }
    if (cur[v]) {
      d.insert(mp(-cur[v], v));
    }
  }
  for (int i = 0; i < n; ++i) {
    if ((deg[i]>>1)&1) {
      spis.pb(i);
    }
  }
  if (SIZE(spis)&1) {
    AddEdge(spis.back(), spis.back());
    spis.pop_back();
  }
  for (int i = 0; i < SIZE(spis); ++i) {
    xo[spis[i]] ^= 1;
  }

  Dfs(0);
  printf("%d\n", SIZE(q)-1);
  for (int i = 1, j = xo[q[0]]; i < SIZE(q); ++i) {
    if (j) {
      printf("%d %d\n", q[i]+1, q[i-1]+1);
    } else {
      printf("%d %d\n", q[i-1]+1, q[i]+1);
    }
    j ^= xo[q[i]];
  }

  return 0;
}
