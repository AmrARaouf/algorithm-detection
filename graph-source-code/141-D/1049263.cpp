//Language: GNU C++


#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;
#define pb         push_back
#define all(a)     (a).begin(),(a).end()
#define sz(a)      (int)((a).size())
#define REP(i,j,k) for(int i=j; i<k; ++i)
#define rep(i,n)   for(int i=0; i<n; ++i)
#define itr(T,v,i) for(T::iterator       i=v.begin(); i!=v.end(); i++)
#define ITR(T,v,i) for(T::const_iterator i=v.begin(); i!=v.end(); i++)

typedef vector<int> Array;
typedef vector<Array> Mat;

struct P {
  int cost, c, pre, prej;
  P(int cost, int c, int pre, int prej) : 
    cost(cost), c(c), pre(pre), prej(prej) { }
  bool operator < (const P &p) const {
    return cost < p.cost;
  }
};

#define M 200002
int uni(vector<int> &v) {
  set<int> s;
  rep (i, sz(v)) s.insert(v[i]);
  v.clear();
  itr(set<int>, s, i) v.pb(*i);
  return sz(v);
}

int main() {
  int n, L; scanf("%d %d", &n, &L);
  Array x(n), d(n), t(n), p(n), v;
  Mat jump(M);
  
  int m = 0;
  rep(i,n) {
    scanf("%d %d %d %d", &x[i], &d[i], &t[i], &p[i]);
    if (x[i]-p[i] >= 0) v.pb(x[i]-p[i]);
    v.pb(x[i]+d[i]);
  }
  v.pb(0); v.pb(L);
	
  sort(all(v));
  m = uni(v);
	
  rep(i,n) if (x[i]-p[i] >= 0) {
    int pos = lower_bound(all(v), x[i]-p[i])-v.begin();
    jump[pos].pb(i);
  }
	
  Array prev(m, -1), prevjump(m, -1);
  priority_queue<P> q;
  q.push(P(0, 0, -1, -1));
  while (!q.empty()) {
    int cost = q.top().cost, c = q.top().c;
    int pre = q.top().pre, prej = q.top().prej;
    q.pop();
    if (prev[c] >= 0) continue;
    prev[c] = pre;
    prevjump[c] = prej;
		
    if (c == m-1) {
      cout<<-cost<<endl;
      break;
    }
		
    rep(i, sz(jump[c])) {
      int id  = jump[c][i], dist = p[id]+t[id];
      int pos = lower_bound(all(v), x[id]+d[id])-v.begin();
      if(prev[pos] < 0) q.push(P(cost-dist, pos, c, id));
    }
    if(c < m-1) q.push(P(cost-(v[c+1]-v[c]), c+1, c, -1));
    if(c && prev[c-1] < 0) q.push(P(cost-(v[c]-v[c-1]), c-1, c, -1));
  }
  int i = m-1;
  Array result;
  while (i) {
    if (prevjump[i] >= 0) result.pb(prevjump[i]+1);
    i = prev[i];
  }
  reverse(all(result));
  cout<<sz(result)<<endl;
  rep(i, sz(result)) cout<<result[i]<<endl;
  return 0;
}
