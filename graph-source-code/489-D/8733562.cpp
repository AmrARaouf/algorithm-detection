//Language: GNU C++0x


#include <algorithm>
#include <functional>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <map>
#include <set>
#include <queue>

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

#include <cassert>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " <<  x << endl
#define mp make_pair
#define pb push_back
#define sz(s) (int)((s).size())
#define eps 10e-7

typedef long long ll;
typedef pair<int, int> pint;

#define MAX 3030
vector<int> r[MAX], c[MAX]; 
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, m) {
    int a, b;
    scanf("%d %d", &a, &b);
    r[a].pb(b);
    c[b].pb(a);
  }

  FOR(i, 1, n + 1) {
    sort(r[i].begin(), r[i].end());
    sort(c[i].begin(), c[i].end());
  }

  ll ret = 0;
  FOR(i, 1, n + 1) {
    if(r[i].empty()) continue;
    FOR(j, 1, n + 1) {
      if(c[j].empty()) continue;
      if(i == j) continue;
      int cur = 0;
      int k1 = 0;
      int k2 = 0;
      int n1 = sz(r[i]);
      int n2 = sz(c[j]);
      while((k1 < n1) && (k2 < n2)) {
        if(r[i][k1] == c[j][k2]) {
          cur++;
          k1++;
          k2++;
        } else if(r[i][k1] < c[j][k2]) {
          k1++;
        } else k2++;
      }

      if(cur >= 2)
        ret += ((ll) cur) * (cur - 1) / 2;
    }
  }

  printf("%lld\n", ret);
  return 0;
}
