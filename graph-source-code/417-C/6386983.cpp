//Language: GNU C++0x


#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
bool vst[1010][1010];
int cnt[1010], x[1000000 + 9], y[1000000 + 9];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int len = 0;
  bool flag = true;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j)
      if (i != j && !vst[i][j]) {
        vst[i][j] = 1;
        vst[j][i] = 1;
        ++len;
        x[len] = i;
        y[len] = j;
        ++cnt[i];
        if (cnt[i] == k) break;
      }
    if (cnt[i] != k) {
      flag = false;
      break;
    }
  }
  if (flag) {
    printf("%d\n", n * k);
    for (int i = 1; i <= len; ++i)
      printf("%d %d\n", x[i], y[i]);
  } else {
    printf("-1\n");
  }

  return 0;
}
