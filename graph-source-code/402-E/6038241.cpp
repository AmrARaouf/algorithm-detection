//Language: GNU C++0x


//Codeforces 236
#include <cmath>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int INF = 1 << 30;
const int MAX_N = 2005;


int N;
vector<int> g[MAX_N], tg[MAX_N];

bool is_scc();
void dfs(int node, vector<int> g[], vector<bool>& visited, vector<int>& st);

int main() {
  ios_base::sync_with_stdio(0);
  cin >> N;

  for (int i = 1, edge; i <= N; i += 1) {
    for (int j = 1; j <= N; j += 1) {
      cin >> edge;
      if (edge) {
        g[i].push_back(j);
        tg[j].push_back(i);
      }
    }
  }

  if (is_scc()) {
    cout << "YES";
  } else  {
    cout << "NO";
  }

  return 0;
}

bool is_scc() {
  vector<int> sorted_nodes;
  vector<bool> visited(N + 1, 0);
 
  for (int i = 1; i <= N; ++i) {
    if (!visited[i]) dfs(i, g, visited, sorted_nodes);
  }
  fill(visited.begin(), visited.end(), 0);
 
  vector<int> scc;
  int node = sorted_nodes.back();

  dfs(node, tg, visited, scc);

  return (int(scc.size()) == N);
}
 
void dfs(int node, vector<int> g[], vector<bool>& visited, vector<int>& st) {
  visited[node] = true;
  for (auto x : g[node]) {
    if (!visited[x]) dfs(x, g, visited, st);
  }
  st.push_back(node);
}
