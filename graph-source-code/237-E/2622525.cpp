//Language: GNU C++


#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
#define REP(i,n) for (int i=0;i<int(n);++i)
#define NN 200
#define pot(u,v) (pi[u]-pi[v])
const ll INF = 1000000000;
typedef pair<ll,int> PLI;
int adj[NN][NN], deg[NN], padre[NN]; 
//cal posar adj, deg, cap, w
ll w[NN][NN], cap[NN][NN], pi[NN], d[NN], f[NN][NN];
int n;
ll flow, cost;
bool dijkstra(int s, int t) {
  memset(padre, -1, sizeof(padre));
  REP(i,n) d[i] = INF;
  d[s] = 0;
  priority_queue<PLI> Q;
  Q.push(PLI(0,s));
  while (not Q.empty()) {
    int u = Q.top().second;
    ll dist = -Q.top().first;
    Q.pop();
    if (dist != d[u]) continue;
    REP(i,deg[u]) {
      int v = adj[u][i];
      if (f[u][v] >= 0 and cap[u][v] - f[u][v] > 0 and 
      d[v] > d[u] + pot(u,v) + w[u][v]) {
        d[v] = d[u] + pot(u,v) + w[u][v];
        Q.push(PLI(-d[v], v));
        padre[v] = u;
      }
      else if (f[u][v] < 0 and d[v] > d[u] + pot(u,v) - w[v][u]) {
        d[v] = d[u] + pot(u,v) - w[v][u];
        Q.push(PLI(-d[v], v));
        padre[v] = u;
      }
    }
  }
  REP(i,n) if (pi[i] < INF) pi[i] += d[i];
  return padre[t] >= 0;
}
void maxmin(int s, int t) {
  memset(f, 0, sizeof(f));
  memset(pi, 0, sizeof(pi));
  flow = cost = 0;
  while (dijkstra(s, t)) {
    ll bot = INF;
    for (int v = t, u = padre[v]; u != -1; v = u, u = padre[u]) {
      if (f[u][v] >= 0) bot = min(cap[u][v] - f[u][v], bot);
      else bot = min(f[v][u], bot);
    }
    for (int v = t, u = padre[v]; u != -1; v = u, u = padre[u]) {
      if (f[u][v] >= 0) cost += w[u][v]*bot;
      else cost -= w[v][u]*bot;
      f[u][v] += bot;
      f[v][u] -= bot;
    }
    flow += bot;
  }
}

int main() {
    string t,s;
    int nn,x;
    cin >> t >> nn;
    int source = nn+26, sink=nn+27;
    n=sink+1;
    REP(i,nn) {
        cin >> s >> cap[source][i];
        vector<int> v(26,0);
        REP(j,s.size()) v[s[j]-'a']++;
        adj[source][deg[source]++]=i;  adj[i][deg[i]++]=source;
        REP(j,26) if (v[j]>0) {
            adj[i][deg[i]++]=nn+j; adj[nn+j][deg[nn+j]++]=i;
            cap[i][nn+j]=v[j];
            w[i][nn+j]=i+1;//cada caracter de la string i costa i+1
        }
    }
    vector<int> v(26,0);
    REP(j,t.size()) v[t[j]-'a']++;
    REP(j,26) if (v[j]>0) {
        adj[nn+j][deg[nn+j]++]=sink; adj[sink][deg[sink]++]=nn+j;
        cap[nn+j][sink]=v[j];
    }
    maxmin(source,sink);
    if (flow==int(t.size())) cout << cost << endl;
    else cout << -1<<endl;
    cin>>t;
}
