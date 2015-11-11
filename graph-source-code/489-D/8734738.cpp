//Language: GNU C++0x


#include <algorithm>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>


#define INF 1000000000
#define MOD 1000000007
#define ALL(x) std::begin(x), std::end(x)


long long nck[3333][3333] = {0};

int n, m, a, b;

std::vector<int> g[3333];

bool visit[3333];

long long c[3333];


void dfs(int i, int j)
{
  if (j == 0) {
    c[i] ++;

    return;
  }

  for (const auto& k : g[i])
    if (! visit[k]) {
      visit[k] = true;

      dfs(k, j - 1);

      visit[k] = false;
    }
}


int main(int argc, char** argv)
{
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);


  nck[0][0] = 1;

  for (int i = 1; i < 3333; i ++) {
    nck[i][0] = nck[i][i] = 1;
    
    for (int j = 1; j < 3333; j ++)
      nck[i][j] = nck[i-1][j-1] + nck[i-1][j];
  }


  std::cin >> n >> m;

  for (int i = 0; i < m; i ++) {
    std::cin >> a >> b;

    g[a - 1].push_back(b - 1);
  }

  long long s = 0;

  memset(visit, 0, sizeof(visit));

  for (int i = 0; i < n; i ++) {
    memset(c, 0, sizeof(c));

    visit[i] = true;

    dfs(i, 2);

    visit[i] = false;

    for (int j = 0; j < n; j ++)
      s += nck[c[j]][2];
  }

  std::cout << s << std::endl;

  return 0;
}
