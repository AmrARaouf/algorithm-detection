//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
const int N = 100000 + 10;
int n, m, k;
vector<int> tree[N];
set<int> neb[N];
int path[N], inPath[N], cnt;
void dfs(int x) {
  inPath[x] = 1;
  path[cnt ++] = x;
  for(size_t i = 0; i < tree[x].size(); ++ i) {
    if (inPath[tree[x][i]] == 0) {
      dfs(tree[x][i]);
      return ;
    }
  }
}
int main()
{
  cin >> n >> m >> k;
  for(int i = 1; i <= m; ++ i) {
    int u, v;
    cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
    neb[u].insert(v);
    neb[v].insert(u);
  }
  dfs(1);
  int beginIndex = 0;
  for(int i = 0; i < cnt; i ++) {
    if (neb[path[cnt - 1]].find(path[i]) != neb[path[cnt - 1]].end()) {
      beginIndex = i;
      break;
    }
  }
  cout << cnt - beginIndex << endl;
  for(int i = beginIndex; i < cnt; ++ i) {
    cout << path[i] << " ";
  }
  cout << endl;
}
