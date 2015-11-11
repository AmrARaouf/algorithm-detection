//Language: GNU C++


#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX 300005

int g[MAX], lnk[2*MAX], nxt[2*MAX], e;
int par[MAX], rnk[MAX], depth, far, bst;
int path[MAX], done[MAX];

void edge(int u, int v) {
  nxt[++e] = g[u], g[u] = e, lnk[e] = v;
  nxt[++e] = g[v], g[v] = e, lnk[e] = u;
}

int get(int u) {
  if(u == par[u]) return u;
  par[u] = get(par[u]);
  return par[u];
}

void edge(int u, int v, int update) {
  if(u == v) return;
  int t;
  if(rnk[u] < rnk[v]) t = u, u = v, v = t;
  par[v] = u;
  if(rnk[u] == rnk[v]) rnk[u]++;
  if(update) path[u] = max(max(path[u], path[v]), (path[u]+1)/2+(path[v]+1)/2+1);
}  

void dfs(int u, int p) {
  depth++;
  if(depth > bst) bst = depth, far = u;
  for(int i=g[u]; i; i=nxt[i]) {
    int v = lnk[i];
    if(v == p) continue;
    dfs(v, u);
  }
  depth--;
}

int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  for(int i=1; i<=n; ++i)
    par[i] = i, rnk[i] = 1;
  while(m--) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge(u, v);
    edge(get(u), get(v), 0);
  }
  for(int i=1; i<=n; ++i) {
    if(done[get(i)]) continue;
    depth = bst = -1, far = 0;
    dfs(get(i), 0);
    depth = bst = -1;
    dfs(far, 0);
    path[get(i)] = bst;
    done[get(i)] = 1;
  }
  while(q--) {
    int t, u, v;
    scanf("%d %d", &t, &u);
    if(t-1) {
      scanf("%d", &v);
      edge(get(u), get(v), 1);
    } else printf("%d\n", path[get(u)]);
  }
  return 0;
}
    
  


    
