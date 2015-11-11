//Language: GNU C++


#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <ctime>
#include <cmath>
#include <stdio.h>
#include <set>
#include <map>
#include <stack>
#include <fstream>
#include <deque>
#include <list>
#include <ctime>

#define SZ(a) (int(a.size()))
#define MEM(a, val) memset(a, val, sizeof(a))
#define MP(a, b) make_pair(a, b)
#define PB(a) push_back(a)
#define ALL(a) a.begin(), a.end()
#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); ++(i))
#define SQR(a) ((a) * (a))

using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef long double dbl;
typedef pair<int, int> pii ;
typedef vector<int> vint;
typedef vector<LL> vLL;

const int nmax = 109;


bool f[nmax][nmax];
int c[nmax][nmax];
int n, m;

bool dfs(int v, int C, int col[]) {
  if (col[v] != -1 && col[v] != C)
    return false;
  if (col[v] != -1)
    return true;
  col[v] = C;

  for (int to = 1; to <= n; ++to) {
    if (f[v][to]) {
      if (dfs(to, 1 - (C + c[v][to]) % 2, col) == false )
        return false;
    }
  }
  return true;
}

int main() {
//--------------------------------------------------------------------------
  #ifdef _DEBUG
	freopen("input.txt", "r", stdin);	freopen("output.txt", "w", stdout);
#else
//	freopen("input.txt", "r", stdin);	freopen("output.txt", "w", stdout);
#endif
//--------------------------------------------------------------------------
  int col[nmax];
  MEM(col, -1);

  cin >> n >> m;

  for (int i = 0; i < m ; ++i) {
    int u, v, cc;
    cin >> u >> v >> cc;
    f[u][v] = f[v][u] = 1;
    c[u][v] = c[v][u] = cc;
  }

  int CB[nmax];
  for (int v = 1; v <= n; ++v) {
    if (col[v] == -1) {
      MEM(CB, -1);
      if (dfs(v, 0, CB)) {
        dfs(v, 0, col);
        continue;
      }
      MEM(CB, -1);
      if (dfs(v, 1, CB)) {
        dfs(v, 0, col);
        continue;
      }

      cout << "Impossible" << endl;
      return 0;
    }
  }
  vint ans;
  for (int v = 1; v <= n; ++v) {
    if (col[v] == 1) {
      ans.PB(v);
    }
  }
  cout << SZ(ans) << endl;
  if (SZ(ans) > 0)
    cout << ans[0];
  for (int i = 1; i < SZ(ans); ++i)
    cout << " " << ans[i];
  cout << endl;
  return 0;
}
