//Language: GNU C++0x


#include <bits/stdc++.h>

using namespace std;

const int N = 100000;
int n, m, k;
vector<int> adj[N];
int stkIdx[N];
vector<int> stk;

bool dfs(int u) {
  if(stkIdx[u] != -1) {
    if(stk.size() - stkIdx[u] > k) {
      cout << stk.size() - stkIdx[u] << endl;
      for(cout << stk.back() + 1; stk.back() != u; stk.pop_back(), cout << " " << stk.back() + 1);
      cout << endl;
      return true;
    }
    return false;
  }
  stkIdx[u] = stk.size();
  stk.push_back(u);
  for(int i = 0; i < (int)adj[u].size(); ++i) {
    if(dfs(adj[u][i])) return true;
  }
  stk.pop_back();
  return false;
}


int main() {
  scanf("%d %d %d", &n, &m, &k);
  while(m--) {
    int a, b; scanf("%d %d", &a, &b); --a; --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  memset(stkIdx, -1, sizeof stkIdx);
  dfs(0);
  return 0;
}
