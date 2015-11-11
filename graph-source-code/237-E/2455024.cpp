//Language: GNU C++0x


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

#define SZ(x) (int)(x.size())

const int N = 150;
char str[1000];
int cnt[26], all;

struct Edge {
  int v, c, f, w, dual;
  Edge(int v, int c, int w, int dual): v(v), c(c), w(w), dual(dual) { f = 0; }
};
vector<Edge> a[N];
vector<Edge>::iterator idx[N];
int d[N], dp[N], pre[N];
bool flag[N];
int q[N];

void add_edge(int x, int y, int c, int w) {
  a[x].push_back(Edge(y, c, w, SZ(a[y])));
  a[y].push_back(Edge(x, 0, -w, SZ(a[x]) - 1));
}

int mincost_maxflow(int s, int t, int n) {
  int cost = 0, sum = 0;
  while (true) {
    fill(pre, pre + n, -1);
    fill(d, d + n, INT_MAX);
    fill(flag, flag + n, false);
    d[s] = 0;
    flag[s] = true;
    dp[s] = INT_MAX;
    q[0] = s;
    int head = 0, tail = 1;
    while (head != tail) {
      int i = q[head];
      flag[i] = false;
      for (vector<Edge>::iterator it = a[i].begin(); it != a[i].end(); ++it) {
        if (it->c > it->f && d[it->v] > d[i] + it->w) {
          d[it->v] = d[i] + it->w;
          if (!flag[it->v]) {
            flag[it->v] = true;
            q[tail++] = it->v;
            if (tail == N) tail = 0;
            pre[it->v] = i;
            idx[it->v] = it;
            dp[it->v] = min(dp[i], it->c - it->f);
          }
        }
      }
      if (++head == N) head = 0;
    }
    if (pre[t] == -1) break;
    int aug = dp[t];
    sum += aug;
    for (int i = t; pre[i] != -1; i = pre[i]) {
      idx[i]->f += aug;
      a[idx[i]->v][idx[i]->dual].f -= aug;
      cost += aug * idx[i]->w;
    }
  }
  return sum == all ? cost : -1;
}

int main() {
  scanf("%s", str);
  fill(cnt, cnt + 26, 0);
  for (int i = 0; str[i]; ++i) {
    cnt[str[i] - 'a']++;
    all++;
  }
  int n;
  scanf("%d", &n);
  int s = n + 26, t = s + 1;
  for (int i = 0; i < 26; ++i) {
    add_edge(n + i, t, cnt[i], 0);
  }
  for (int i = 0; i < n; ++i) {
    int k;
    scanf("%s %d", str, &k);
    add_edge(s, i, k, 0);
    fill(cnt, cnt + 26, 0);
    for (int j = 0; str[j]; ++j) {
      cnt[str[j] - 'a']++;
    }
    for (int j = 0; j < 26; ++j) {
      add_edge(i, n + j, cnt[j], i + 1);
    }
  }
  printf("%d\n", mincost_maxflow(s, t, t + 1));
  return 0;
}
