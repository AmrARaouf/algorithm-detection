//Language: GNU C++0x


#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

#ifndef ONLINE_JUDGE
#define DEBUG
#endif

#define oo 0x3F3F3F3F
#ifdef DEBUG
#define cvar(x) cerr << "[" << #x << ": " << x << "]" << endl
template<class T> void DISP (const char *s, T x, int n) {cerr << "[" << s << ": "; for (typename T::iterator it = x.begin (); it != x.end (); ++it) cerr << *it << " "; cerr << "]" << endl;}
#define disp(x,n) DISP (#x " to " #n, x, n)
#else
#define cvar(...) ({})
#define disp(...) ({})
#endif
#ifdef WIN32
#define fmt64 "%I64d"
#else
#define fmt64 "%lld"
#endif
#define foreach(i, x) for (__typeof__((x).begin ()) i = (x).begin (); i != (x).end (); ++i)
#define MKP make_pair
#define Px first
#define Py second
#define PB push_back

typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;
typedef vector<int> VI;
typedef map<int, int> MII;
typedef set<int> SI;
typedef pair<int, int> PII;

int64 fpm (int64 b, int64 e, int64 m) { int64 t = 1; for (; e; e >>= 1, b = b * b % m) e & 1 ? t = t * b % m : 0; return t; }
template<class T> inline bool chkmin (T &a, T b) {return a < b ? a = b, true : false;}
template<class T> inline bool chkmax (T &a, T b) {return a > b ? a = b, true : false;}
template<class T> inline T sqr (T x) {return x * x;}

const int maxn = 110000, maxm = 110000;

struct edge {int t; edge *n;} ;
typedef int arr32[maxn];

edge graph[maxm << 1], *eptr = graph, *adj[maxn];
int top, tms, tail;
arr32 stk, rep, low, dfn, Q, size, ways, tid, aux, root, fth, depth;
const int mod = 1000000007;

void adde (int s, int t)
{
  *(++eptr) = (edge){t, adj[s]}, adj[s] = eptr;
}

void dfs (int v, int f)
{
  edge *e; low[v] = dfn[v] = ++tms, rep[v] = v, stk[++top] = v;
  // cerr << "dfs " << v << " " << f << endl;
  for (e = adj[v]; e; e = e->n)
    if (e->t != f && !dfn[e->t]) // tree
      dfs (e->t, v), low[v] = min (low[v], low[e->t]);
    else if (e->t != f)
      low[v] = min (low[v], dfn[e->t]);
  int u;
  if (low[v] == dfn[v])
    for (rep[v] = v; (u = stk[top--]) != v; )
      rep[u] = v;
}

void dfs2 (int v, int f)
{
  Q[++tail] = v, size[v] = 1, tid[v] = tid[f] + ways[v], fth[v] = f, depth[v] = depth[f] + 1;
  for (edge *e = adj[v]; e; e = e->n)
    if (e->t != f)
      dfs2 (e->t, v), size[v] += size[e->t], size[aux[v]] < size[e->t] ? aux[v] = e->t : 0;
}

int LCA (int s, int t)
{
  for (; root[s] != root[t]; s = fth[root[s]])
    if (depth[root[s]] < depth[root[t]])
       swap (s, t);
  return depth[s] < depth[t] ? s : t;
}

int main ()
{
#ifndef ONLINE_JUDGE
  freopen ("E.in" , "r", stdin);
  freopen ("E.out", "w", stdout);
#endif
  ios_base::sync_with_stdio (false);

  int n, m;
  
  cin >> n >> m;
  for (int i = 1, s, t; i <= m; ++i)
    cin >> s >> t, adde (s, t), adde (t, s);
  dfs (1, 0);
  for (int i = 1; i <= n; ++i)
    if (rep[i] != i)
      ways[rep[i]] = 1;
  // for (int i = 1; i <= n; ++i)
  //   cerr << i << ": " << rep[i] << " " << ways[i] << endl;

  set<PII> E;
  for (int v = 1; v <= n; ++v)
    for (edge *e = adj[v]; e; e = e->n)
      if (rep[v] < rep[e->t])
        E.insert (MKP (rep[v], rep[e->t]));
  memset (adj, 0, sizeof (adj)), eptr = graph;
  for_each (E.begin (), E.end (), [](PII e) {
      adde (e.Px, e.Py); adde (e.Py, e.Px); // cerr << "newe: " << e.Px << " " << e.Py << endl;
    });

  dfs2 (1, 1); assert (tail == E.size () + 1);
  for (int i = 1, v; v = Q[i], i <= tail; ++i)
    if (!root[v])
      for (int u = v; u; u = aux[u])
        root[u] = v;

  int K, s, t;
  for (cin >> K; K--; )
    {
      cin >> s >> t, s = rep[s], t = rep[t];
      int x = LCA (s, t);
      cout << fpm (2, tid[s] + tid[t] - tid[x] * 2 + ways[x], mod) << endl;
    }
  
  return 0; 
}
