//Language: GNU C++0x


#include <string>
#include <algorithm>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <fstream>
#include <cassert>

using namespace std;


                                                                                                                                                              #define int ll
const bool online_judge =
#ifdef ONLINE_JUDGE
  true
#else
  false
#endif
  ;

typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

typedef tuple<int,int> int2;
typedef tuple<int,int,int> int3;
typedef tuple<int,int,int,int> int4;

#define all(v)  (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define eb emplace_back
#define SZ(a) ((int)((a).size()))
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep2(i,n) for(int i = 1; i <= n; i++)
#define rep3(i,n) for(int i = n-1; i >= 0; i--)
#define tag(i,v) rep(i,SZ(v))
#define _trace(x) #x << " = " << (x)
#define trace(x)  { if(!online_judge) cerr << _trace(x) << endl; }
#define trace2(x,y) { if(!online_judge) cerr << _trace(x) << " " << _trace(y) << endl; }
#define trace3(x,y,z) { if(!online_judge) cerr << _trace(x) << " " << _trace(y) << " " << _trace(z) << endl; }
#define tracev(x) { if(!online_judge) { cerr << #x << " = "; tag(__i, x) { cerr << x[__i] << ","; } cerr << endl; } }
#define fst get<0>
#define snd get<1>
#define thd get<2>
#define fth get<3>
#define divup(x,y) ((x)/(y)+(0<((x)%(y))))
#define mp make_tuple
#define range(x,a,b) ((x) >= (a) && (x) <= (b))

ostream& operator<<(ostream& os, int2 x){ os << "(" << fst(x) << ", " << snd(x) << ")"; return os; }

ostream& operator<<(ostream& os, int3 x){ os << "(" << fst(x) << ", " << snd(x) << ", " << thd(x) << ")"; return os; }

ostream& operator<<(ostream& os, int4 x){ os << "(" << fst(x) << ", " << snd(x) << ", " << thd(x) << ", " << fth(x) << ")"; return os; }

const int inf = 1LL << 60;

namespace graph {

  class edge {
  public:
    int src;
    int dst;
    int w;
    bool jump;

    edge(int _src, int _dst, int _w, bool _jump){
      src = _src;
      dst = _dst;
      w = _w;
      jump = _jump;
    }

    const bool operator<(const edge &e) const {
      return make_tuple(w,src,dst) < make_tuple(e.w, e.src, e.dst);
    }
    const bool operator>(const edge &e) const {
      return make_tuple(w,src,dst) > make_tuple(e.w, e.src, e.dst);
    }

  };
  
  class t {
  public:
    vector<vector<edge>> p;

    t(int n){
      p = vector<vector<edge>>(n, vector<edge>());
    }

    const int size() const {
      return p.size();
    }

    const vector<edge> get_edges(int i) const {
      return p[i];
    }

    void add_edge(int src, int dst, int w, bool jump){
      p[src].pb(edge(src, dst, w, jump));
    }

  };

  void dijkstra(const t &graph, int start, vector<int> &ans, vector<int> & prev, vector<bool> &jump){
    const int n = graph.size();
    ans = vi(n, inf); ans[start] = 0;
    prev = vi(n, -1);
    jump = vector<bool>(n, false);
    priority_queue<edge, vector<edge>, greater<edge>> q;
    
    for(q.push(edge(-2, start, 0, false)); !q.empty(); ){
      const edge e = q.top(); q.pop();
      if(prev[e.dst] != -1)
	continue;
      prev[e.dst] = e.src;
      jump[e.dst] = e.jump;
      const vector<edge> edges = graph.get_edges(e.dst);
      for(int i = 0; i < SZ(edges); i++){
	edge f = edges[i];
	if(e.w + f.w < ans[f.dst]){
	  ans[f.dst] = e.w + f.w;
	  q.push(edge(f.src, f.dst, e.w + f.w, f.jump));
	}
      }
    }
  }

  void visualize(const t &g, ostream &os){
    os << "digraph sample {" << endl;
    const int n = g.size();
    rep(i,n){
      vector<edge> edges = g.get_edges(i);
      for(int j = 0; j < SZ(edges); j++){
	edge e = edges[j];
	os << e.src << " -> " << e.dst << "[label = \"" << e.w << "\"];" << endl;
      }
    }
    os << "}" << endl;
  }

  vi build_path(vi prev, vector<bool> jump, int end){
    vi path;
    while(prev[end] >= 0){
      if(jump[end])
	path.pb(prev[end]);
      end = prev[end];
    }
    reverse(all(path));
    return path;
  }

}

void run() {

  /* entry point */
  int n,L;
  cin >> n >> L;

  vector<int4> ramp;

  rep(i,n) {
    int x,d,t,p;
    cin >> x >> d >> t >> p;
    if(x - p < 0)
      continue;
    ramp.eb(x-p, x+d, t+p,i+1);
  }

  n = SZ(ramp);
  sort(all(ramp));

  tracev(ramp);

  if(n == 0){
    cout << L << endl;
    cout << 0 << endl;
    cout << endl;
    return;
  }

  graph::t g(n+2);

  rep(i,n){
    int4 r = ramp[i];
    int d = snd(r), t = thd(r);
    
    auto it = lower_bound(all(ramp), mp(d,0,0,0));
    int index = it - ramp.begin();

    g.add_edge(i+1, n+1, t+(L-d), true);

    if(snd(*it) != d && range(index-1,0, n-1)){
      int a = t+(d-fst(ramp[index-1]));
      g.add_edge(i+1, index-1+1, a, true);
    }
    if(range(index,0, n-1)){
      int a = t+(fst(ramp[index])-d);
      g.add_edge(i+1, index+1, a, true);
    }
  }

  g.add_edge(0,1,fst(ramp[0]), false);

  rep(i,n-1){
    int w = fst(ramp[i+1]) - fst(ramp[i]);
    g.add_edge(i+1, i+2, w, false);
    g.add_edge(i+2, i+1, w, false);
  }

  g.add_edge(n,n+1, L-fst(ramp[n-1]), false);
  trace(fst(ramp[n-1]));

  ofstream f("graph.dot");
  visualize(g, f);

  vi ans, prev;
  vector<bool> jump;

  graph::dijkstra(g, 0, ans, prev, jump);

  tracev(ans);
  tracev(prev);
  tracev(jump);

  vi history = graph::build_path(prev, jump, n+1);

  cout << ans[n+1] << endl;
  cout << history.size() << endl;
  tag(i, history) {
    cout << fth(ramp[history[i]-1]) << " ";
  }
  cout << endl;

}

#undef int

int main(int argc, char *argv[]) {

  #if 0
  if(online_judge){
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
  }
  #endif

  run();

  return 0;

}
