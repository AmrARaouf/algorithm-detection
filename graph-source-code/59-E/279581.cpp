//Language: GNU C++


#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
using namespace std;

#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)

int N, M, K;
vector<int> adj[3010];

int main() {
  while (3 == scanf("%d%d%d", &N, &M, &K)) {
    for (int i = 1; i <= N; ++i) adj[i].clear();

    rep (i, M) {
      int a, b;
      scanf("%d%d", &a, &b);
      adj[a].pb(b);
      adj[b].pb(a);
    }

    map<pair<int, int>, set<int> > ng;
    rep (i, K) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      ng[mp(a, b)].insert(c);
    }

    set<int> empty_set;

    queue<pair<int, int> > que;
    map<pair<int, int>, pair<int, int> > prv;
    que.push(mp(1, 0));
    prv.insert(mp(mp(1, 0), mp(0, 0)));
    while (!que.empty()) {
      int v = que.front().first;
      int p = que.front().second;
      que.pop();

      if (v == N) {
        vector<int> res;
        for (pair<int, int> t = mp(v, p); t.first != 1; t = prv[t]) res.pb(t.first);
        reverse(all(res));
        printf("%d\n1", (int)res.size());
        rep (i, res.size()) printf(" %d", res[i]);
        puts("");
        goto done;
      }

      set<int> *se;
      if (!ng.count(mp(p, v))) se = &empty_set;
      else se = &ng[mp(p, v)];

      rep (i, adj[v].size()) {
        int w = adj[v][i];
        if (se->count(w)) continue;

        // printf("%d -> %d -> %d\n", p, v, w);

        int tv = w, tp = ng.count(mp(v, w)) == 0 ? 0 : v;
        if (prv.count(mp(tv, tp))) continue;
        prv.insert(mp(mp(tv, tp), mp(v, p)));
        que.push(mp(tv, tp));
      }
    }

    puts("-1");
 done:
    ;
  }

  return 0;
}

