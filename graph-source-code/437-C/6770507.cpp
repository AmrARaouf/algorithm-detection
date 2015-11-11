//Language: GNU C++


#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cassert>

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)

#define DEBUG if (1)
#define PRINT(x) DEBUG cout << #x << ": " << x << endl;
#define PRINT_VEC(x1999)\
  DEBUG cout << #x1999 << ": ";\
  DEBUG for (int i = 0; i < (x1999).size(); i++) { cout << (x1999)[i] << " "; }\
  DEBUG cout << endl;

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;

int N, M;
int main() {
  cin >> N >> M;

  VI vs;
  for (int i = 0; i < N; i++) {
    int v;
    cin >> v;
    vs.push_back(v);
  }
  
  VVI g(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<bool> removed(N, false);
  int ans = 0;
  for (int n = 0; n < N-1; n++) {
    for (int i = 0; i < N; i++) {
      if (removed[i]) continue;
      int max_cost = 0;
      int total_cost = 0;

      for (VI::iterator it = g[i].begin(); it != g[i].end(); ++it) {
        int c = *it;
        if (removed[c]) continue;
        max_cost = max(max_cost, vs[c]);
        total_cost += vs[c];
      }

      if (max_cost <= vs[i]) {
        ans += total_cost;
        removed[i] = true;

        break;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
