//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

typedef unsigned long long ll;
typedef pair<int, int> pii;

const int MAXN = 100100;

int n, m;
int was[MAXN];
vector<int> g[MAXN];
bool was2[3][MAXN];

bool dfs(int v, int col = 1) {
  was[v] = col;
  for (int i = 0; i < (int)g[v].size(); ++i) {
    if (!was[g[v][i]]) {
      if (dfs(g[v][i], 3 - col)) {
	return true;
      }
    } else if (was[v] == was[g[v][i]])
      return true;
  }
  return false;
}

int dfs2(int v, int col) {
  was2[col][v] = true;
  int res = was[v] == col;
  for (int i = 0; i < (int)g[v].size(); ++i) {
    if (!was2[col][g[v][i]]) {
      res += dfs2(g[v][i], col);
    }
  }
  return res;
}

ll C(int n, int k) {
  if (k > n) return 0;
  ll res = 1;
  for (int i = 0; i < k; ++i)
    res *= n - i;
  for (int i = 2; i <= k; ++i)
    res /= i;
  return res;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0, a, b; i < m; ++i) {
    scanf("%d%d", &a, &b);
    g[a].pb(b);
    g[b].pb(a);
  }
  for (int i = 1; i <= n; ++i) {
    if (!was[i] && dfs(i)) {
      puts("0 1");
      return 0;
    }
  }
  ll one = 0;
  for (int i = 1; i <= n; ++i) {
    if (!was2[1][i]) {
      one += C(dfs2(i, 1), 2);
      one += C(dfs2(i, 2), 2);
    }
  }
  if (one) {
    cout << 1 << ' ' << one << endl;
    return 0;
  }
  if (m) {
    cout << 2 << ' ' << m * 1ll * (n - 2) << '\n';
    return 0;
  }
  cout << 3 << ' ' << C(n, 3) << '\n';
  return 0;
}
