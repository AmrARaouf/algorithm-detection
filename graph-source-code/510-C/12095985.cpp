//Language: GNU C++11


#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
#define rrep(i, m, n) for(int (i)=(m); (i)<(n);  (i)++)
#define erep(i, m, n) for(int (i)=(m); (i)<=(n); (i)++)
#define  rep(i, n)    for(int (i)=0; (i)<(n);  (i)++)
#define rrev(i, m, n) for(int (i)=(n)-1; (i)>=(m); (i)--)
#define erev(i, m, n) for(int (i)=(n); (i)>=(m); (i)--)
#define  rev(i, n)    for(int (i)=(n)-1; (i)>=0; (i)--)
#define vrep(i, c)    for(__typeof((c).begin())i=(c).begin(); i!=(c).end(); i++)
#define  ALL(v)       (v).begin(), (v).end()
#define pb            push_back
#define mp            make_pair
template<class T, class S> inline bool minup(T& m, const S x){ return m>(T)x ? (m=(T)x, true) : false; }
template<class T, class S> inline bool maxup(T& m, const S x){ return m<(T)x ? (m=(T)x, true) : false; }

static const int    INF = 1000000000;
static const ll     MOD = 1000000007LL;
static const double EPS = 1E-10;

typedef int Weight;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(int src, int dst, Weight weight) : src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

bool visit(const Graph& g, int v, vi& order, vi& color)
{
  color[v] = 1;
  vrep(e, g[v]) {
    if (color[e->dst] == 2) continue;
    if (color[e->dst] == 1) return false;
    if (!visit(g, e->dst, order, color)) return false;
  }
  order.push_back(v); color[v] = 2;
  return true;
}

bool TopologicalSort(const Graph& g, vi& order)
{
  int n = g.size();
  vi color(n);
  rep(u, n) if (!color[u] && !visit(g, u, order, color)) return false;
  reverse(ALL(order));
  return true;
}

int n;
string s[111];
Graph g(26);
bool used[26];

int main(int argc, char *argv[])
{
  scanf("%d", &n);
  rep(i, n) cin >> s[i];

  rep(i, n - 1){
    int len = min(s[i].length(), s[i + 1].length());
    rep(j, len){
      if(s[i][j] != s[i + 1][j]){
        g[s[i][j] - 'a'].pb(Edge(s[i][j] - 'a', s[i + 1][j] - 'a', 1));
        used[s[i][j] - 'a'] = true;
        used[s[i + 1][j] - 'a'] = true;
        break;
      }
      else if(j + 1 == s[i + 1].length()){
        puts("Impossible");
        return 0;
      }
    }
  }
  
  rep(i, 26) if(!used[i]) rep(j, 26) if(used[j]) g[j].pb(Edge(j, i, 1));

  vi order;
  if(TopologicalSort(g, order)){
    vrep(v, order) putchar(*v + 'a');
    putchar('\n');
  }
  else puts("Impossible");
  
  return 0;
}
