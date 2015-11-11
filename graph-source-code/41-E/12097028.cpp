//Language: GNU C++11


#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  int u[105][105];
  vector< pair<int, int> > v;
  scanf("%d", &n);
  memset(u, 0, sizeof u);
  for (int i = 1; i <= n; i += 2)
    for (int j = i+1; j <= n; j += 2)
      v.push_back(make_pair(i, j));
  for (int i = 2; i <= n; i += 2)
    for (int j = i+1; j <= n; j += 2)
      v.push_back(make_pair(i, j));
  printf("%d\n", n = v.size());
  for (int i = 0; i < n; ++i)
    printf("%d %d\n", v[i].first, v[i].second);
}