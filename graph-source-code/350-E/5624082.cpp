//Language: GNU C++


#include <cstdio>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
#define MAX 1000

using namespace std;

int n, m, k;
int a[MAX];
bool use[MAX][MAX];
vector <pair <int, int> > ans;

bool construct() {
  if (n == k) return false;
  if (n * (n - 1) / 2 - (k - 1) < m) return false;
  sort (a, a + k);
  memset (use, 0, sizeof(use));
  int b = 1;
  while (b <= k && a[b - 1] == b) b++;
  for (int i = 1; i < k; i++) {
    use[a[0]][a[i]] = true;
    use[a[i]][a[0]] = true;
  }
  for (int i = 1; i <= n; i++) {
    if (i == b) continue;
    ans.push_back(make_pair(b, i));
    use[b][i] = true;
    use[i][b] = true;
  }
  m -= n - 1;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (m > 0 && !use[i][j]) {
	ans.push_back(make_pair(i, j));
	m--;
      }
    }
  }
  return true;
}

int main() {
  scanf ("%d %d %d", &n, &m, &k);
  for (int i = 0; i < k; i++)
    scanf ("%d", &a[i]);
  if (!construct()) {
    printf ("-1\n");
  }
  else {
    for (int i = 0; i < (int) ans.size(); i++) {
      printf ("%d %d\n", ans[i].first, ans[i].second);
    }
  }
}
