//Language: GNU C++


// 463D: Gargari and Permutations

#include <cstdio>
#include <algorithm>

using namespace std;

int pos[10][1005], a[10][1005], dp[1005];

int main() {
  int n, k; scanf("%d %d", &n, &k);
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
      pos[i][a[i][j]] = j;
    }
  }

  for (int i = 0; i < n; i++) {
    int maxlen = 1;
    for (int j = 0; j < i; j++) { // for each last prev char in subseq
      int s;
      for (s = 1; s < k && pos[s][a[0][j]] < pos[s][a[0][i]]; s++); // valid?
      if (s == k) maxlen = max(maxlen, dp[j] + 1); // use a[j] as prev
    }
    dp[i] = maxlen;
  }

  printf("%d\n", *max_element(dp, dp + n));
}
