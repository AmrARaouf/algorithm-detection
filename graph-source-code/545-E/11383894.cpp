//Language: GNU C++11


#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ul;

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(false);
  int N, M;
  scanf("%d %d ", &N, &M);
  vector< vector< pair<ll, pair<ll, ll> > > > trs(N);
  vector<ll> hs(M);
  for (ll m = 0; m < M; ++m) {
    int u, v, w;
    scanf("%d %d %d ", &u, &v, &w);
    --u; --v;
    trs[u].push_back(make_pair(v, make_pair(w, m+1)));
    trs[v].push_back(make_pair(u, make_pair(w, m+1)));
    hs[m] = w;
  }
  int U;
  scanf("%d ", &U);
  --U;
  set< pair<ll, pair< ll, pair<ll, ll> > > > fringe;
  fringe.insert(make_pair(0, make_pair(0, make_pair(U, 0))));
  vector< bool > already_done(N, false);
  vector<ll> edges;
  ll sum_w  = 0;
  while (fringe.size()) {
    auto it = fringe.begin();
    ll d = it->first, n = it->second.second.first, e = it->second.second.second, w = it->second.first;
    fringe.erase(fringe.begin());
    if (already_done[n]) continue;
    if (e) { edges.push_back(e); sum_w += w; }
    already_done[n] = true;
    for (auto next : trs[n]) {
      if (!already_done[next.first])
        fringe.insert(make_pair(d+next.second.first, make_pair(next.second.first, make_pair(next.first, next.second.second))));
    }
  }
  cout << sum_w << endl;
  for (ll e : edges) cout << e << " ";
  if (edges.size()) cout << endl;
  return 0;
}
