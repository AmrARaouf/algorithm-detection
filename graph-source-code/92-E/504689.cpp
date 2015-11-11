//Language: GNU C++


#include <algorithm>
#include <cctype>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>

#define REP(i,a,b) for((i)=(a);(i)<(int)(b);(i)++)
#define rep(i,b) REP(i,0,b)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

using namespace std;
typedef long long ll;
const double eps = 1e-10;
const int inf = 1<<28;

int in() { int x; scanf("%d", &x); return x; }
ll In() { ll x; cin >> x; return x; }
double inreal() { double x; scanf("%lf", &x); return x; }
string instr() { char buf[1001]; scanf("%s", buf); return (string)buf; }

struct UF {
  vector<int> p, r;
  UF(int n) { n++; p.resize(n, ~0), r.resize(n, 0); }
  int root(int x) { return ~p[x] ? p[x] = root(p[x]) : x; }
  bool conn(int x, int y) {
    x = root(x), y = root(y); if (x == y) return 0;
    if (r[x] < r[y]) p[x] = y; else { p[y] = x; if (r[x] == r[y]) r[x]++; }
    return 1;
  }
  bool same(int x, int y) { return root(x) == root(y); }
};

const ll M = 1000000009LL;
ll resget(ll x) { x = x - 1; if (x < 0) return M - 1; return x; }

int main() {  
  int i, j, k, n = in(), m = in(), u, v;
  UF uf(n);
  ll res = 1;
  rep(i, m) {
    u = in() - 1, v = in() - 1;
    if (uf.conn(u, v)) {
      cout << resget(res) << endl;
    } else {
      res = res * 2 % M;
      cout << resget(res) << endl;
    }
  }


  return 0;
}














