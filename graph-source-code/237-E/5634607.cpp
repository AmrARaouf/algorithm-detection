//Language: GNU C++


#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <limits>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long L;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

const L INF = numeric_limits<L>::max() / 4;

struct MinCostMaxFlow {
  int N;
  VVL cap, flow, cost;
  VI found;
  VL dist, pi, width;
  VPII dad;

  MinCostMaxFlow(int N) : 
    N(N), cap(N, VL(N)), flow(N, VL(N)), cost(N, VL(N)), 
    found(N), dist(N), pi(N), width(N), dad(N) {}
  
  void AddEdge(int from, int to, L cap, L cost) {
    this->cap[from][to] = cap;
    this->cost[from][to] = cost;
  }
  
  void Relax(int s, int k, L cap, L cost, int dir) {
    L val = dist[s] + pi[s] - pi[k] + cost;
    if (cap && val < dist[k]) {
      dist[k] = val;
      dad[k] = make_pair(s, dir);
      width[k] = min(cap, width[s]);
    }
  }

  L Dijkstra(int s, int t) {
    fill(found.begin(), found.end(), false);
    fill(dist.begin(), dist.end(), INF);
    fill(width.begin(), width.end(), 0);
    dist[s] = 0;
    width[s] = INF;
    
    while (s != -1) {
      int best = -1;
      found[s] = true;
      for (int k = 0; k < N; k++) {
        if (found[k]) continue;
        Relax(s, k, cap[s][k] - flow[s][k], cost[s][k], 1);
        Relax(s, k, flow[k][s], -cost[k][s], -1);
        if (best == -1 || dist[k] < dist[best]) best = k;
      }
      s = best;
    }

    for (int k = 0; k < N; k++)
      pi[k] = min(pi[k] + dist[k], INF);
    return width[t];
  }

  pair<L, L> GetMaxFlow(int s, int t) {
    L totflow = 0, totcost = 0;
    while (L amt = Dijkstra(s, t)) {
      totflow += amt;
      for (int x = t; x != s; x = dad[x].first) {
        if (dad[x].second == 1) {
          flow[dad[x].first][x] += amt;
          totcost += amt * cost[dad[x].first][x];
        } else {
          flow[x][dad[x].first] -= amt;
          totcost -= amt * cost[x][dad[x].first];
        }
      }
    }
    return make_pair(totflow, totcost);
  }
};

char target[10001];
int n;
char word[100][101];
int a[100];
int freq[26];

int main()
{
#ifdef local
    freopen("a.in", "r", stdin);
#endif
    scanf("%s %d", target, &n);
    for(int i=0;i<n;i++)
        scanf("%s %d", word[i], a+i);
    MinCostMaxFlow mcmf(n+2+26);
    for(int i=1;i<=n;i++)
        mcmf.AddEdge(0,i,a[i-1],i);
    for(int i=0;i<n;i++)
    {
        memset(freq,0,sizeof(freq));
        for(char *c=word[i];*c;c++) freq[*c-'a']++;
        int u = i+1;
        for(int i=0;i<26;i++)
        {
            if(freq[i])
             mcmf.AddEdge(u,1+n+i,freq[i],0);
        }
    }
    memset(freq,0,sizeof(freq));
    for(char *c=target;*c;c++) freq[*c-'a']++;
    for(int i=0;i<26;i++)
    {
        if(freq[i])
         mcmf.AddEdge(1+n+i,n+27,freq[i],0);
    }
    pair<L, L> ans = mcmf.GetMaxFlow(0,n+27);
    if(ans.first < strlen(target)) printf("-1\n");
    else                           printf("%d\n", ans.second);
    return 0;
}