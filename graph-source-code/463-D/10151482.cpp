//Language: GNU C++0x


#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
int n, k, a[N], idx[5][N], memo[N][N];

int solve(int i, int prev) {
  if (i == n)
    return 0;
  int &ret = memo[i][prev];
  if (ret != -1)
    return ret;
  ret = solve(i + 1, prev);
  bool check = 1;
  for (int j = 0; j < k; ++j) {
    if (idx[j][a[i]] <= idx[j][a[prev]]) {
      check = 0;
      break;
    }
  }
  if (check)
    ret = max(ret, 1 + solve(i + 1, i));
  return ret;
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < n; ++j) {
      int x;
      scanf("%d", &x);
      idx[i][x] = j;
      if (i == 0)
        a[j] = x;
    }
  }
  memset(memo, -1, sizeof memo);
  int ans = 0;
  for (int i = 0; i < n; ++i) 
    ans = max(ans, 1 + solve(i + 1, i));
  printf("%d", ans);
}