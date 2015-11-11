//Language: GNU C++


#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

const int N = 100010;

struct query3 {
  int u, id;
  query3(int u, int id) : u(u), id(id) { }
};

std::vector<query3> q3[N];

struct query {
  int k, u, v;
} q[N];

std::vector<int> ed[N];

int ans[N], tin[N], tout[N], parent[N], dsu[N];

int find(int x) {
  if (dsu[x] != x) dsu[x] = find(dsu[x]);
  return dsu[x];
}

void dfs(int u, int& tm) {
  tin[u] = ++tm;
  for (int i = 0; i < int(ed[u].size()); ++i) {
    dfs(ed[u][i], tm);
  }
  tout[u] = ++tm;
}

inline bool ancestor(int u, int v) {
  return tin[v] < tin[u] && tout[u] < tout[v];
}

int main() {
  //assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
  //std::ios::sync_with_stdio(0);
  //std::cin.tie(0);
  memset(tin, 0, sizeof(tin));
  memset(tout, 0, sizeof(tout));
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    int k, u, v, p;
    scanf("%d %d", &k, &u);
    q[i].k = k;
    q[i].u = u;
    if (k == 1) {
      scanf("%d", &v);
      q[i].v = v;
      ed[v].push_back(u);
      parent[u] = v;
    } else if (k == 2) {
      //
    } else if (k == 3) {
      scanf("%d", &p);
      q3[p].push_back(query3(u, i));
    }
  }
  int tm = 0;
  for (int u = 1; u <= n; ++u) {
    if (parent[u] == 0) {
      dfs(u, tm);
    }
    dsu[u] = u;
  }
  int packet = 0;
  memset(ans, -1, sizeof(ans));
  for (int i = 1; i <= m; ++i) {
    int k = q[i].k;
    int u = q[i].u;    
    if (k == 1) {
      int v = q[i].v;
      dsu[u] = v;
    } else if (k == 2) {
      int uu = find(u);
      ++packet;
      for (int j = 0; j < int(q3[packet].size()); ++j) {
        query3& z = q3[packet][j];
        if (!ancestor(uu, z.u) && (ancestor(u, z.u) || u == z.u)) {
          ans[z.id] = 1;
        } else {
          ans[z.id] = 0;
        }
      }      
    }
  }  
  for (int i = 1; i <= m; ++i) {
    if (ans[i] != -1) {
      puts(ans[i] ? "YES" : "NO");
    }
  }
}