//Language: GNU C++


// 462D: Appleman and Tree

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define MOD(x) ((x) % 1000000007)

vector<int> children[100005];
int black[100005];

std::pair<int, int> dfs(int v) {
  unsigned long long vb = black[v], vw = 1 - black[v];

  for (int i = 0; i < children[v].size(); i++) {
    std::pair<int, int> result = dfs(children[v][i]);
    unsigned long long ub = result.first, uw = result.second;

    vb = MOD(MOD(vb * uw) + MOD(vw * ub) + MOD(vb * ub));
    vw = MOD(MOD(vw * uw) + MOD(vw * ub));
  }

  return std::make_pair(vb, vw);
}

int main() {
  int n; scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int v; scanf("%d", &v);
    children[v].push_back(i);
  }

  for (int i = 0; i < n; i++) scanf("%d", &black[i]);

  printf("%d\n", dfs(0).first);
}
