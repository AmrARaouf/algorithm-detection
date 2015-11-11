//Language: GNU C++


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define ri(X) scanf("%d", &(X))
#define pi(X) printf("%d", (X))
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define lint long long
#define pii pair<int,int>
#define inf 1e7
#define linf 1e18
#define X first
#define Y second
#define all(X) (X).begin(),(X).end()
#define uni(X) X.erase(unique(X.begin(), X.end()), X.end());

int n, m;
const int mn = 3009;
vector<int> g[mn];
int s1, t1, l1;
int s2, t2, l2;

int cost[mn][mn];
bool visit[mn];
void bfs(int ini){
  memset(visit,0,sizeof(visit));
  queue<int> Q;
  int u = ini;
  visit[u] = 1;
  Q.push(u);
  cost[ini][u] = 0;
  int v;
  while(!Q.empty()){
    u = Q.front();
    //cout << u << " ";
    Q.pop();
    for(int i = 0; i < g[u].size(); i++){
      v = g[u][i];
      if(visit[v]) continue;
      cost[ini][v] = cost[ini][u]+1;
      visit[v] = 1;
      Q.push(v);
    }
  }//cout << endl;
}

void solve(){
  for(int i = 0; i < n; i++){
    bfs(i);
  }
  /*for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout << cost[i][j] << " ";
    }cout << endl;
  }*/
  
  if(cost[s1][t1] > l1 || cost[s2][t2] > l2){
    printf("-1\n");
    return;
  }
  int res = cost[s1][t1]+cost[s2][t2];
  int r1,r2;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      r1 = min(cost[s1][j]+cost[j][i]+cost[i][t1],cost[s1][i]+cost[i][j]+cost[j][t1]);
      r2 = min(cost[s2][j]+cost[j][i]+cost[i][t2],cost[s2][i]+cost[i][j]+cost[j][t2]);
      if(r1 > l1 || r2 > l2) continue;
      res = min(res, r1+r2-cost[i][j]);
    }
  }
  printf("%d\n", m-res);
  
}

int main(){
  
  ri(n); ri(m); 
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cost[i][j] = i==j?0:inf;
    }
  }
  int u,v;
  for(int i = 0; i < m; i++){
    ri(u); ri(v);
    u--; v--;
    g[u].pb(v);
    g[v].pb(u);
    
    cost[u][v] = cost[v][u] = 1;
  }
  
  ri(s1); ri(t1); ri(l1);
  ri(s2); ri(t2); ri(l2);
  s1--; t1--;
  s2--; t2--;
  solve();
  return 0;
}

