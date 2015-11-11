//Language: GNU C++11


#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20005;

int qu[MAXN];
int d[MAXN];
int n, m;

int solve() {
   int fr = 1, re = 1;
   qu[1] = n;
   d[n] = 1;
   while (fr <= re) {
      int u = qu[fr++];
      int v = u - 1;
      if (v > 0 && !d[v]) {
         d[v] = d[u] + 1;
         qu[++re] = v;
         if (v == m) return d[v] - 1;
      }
      v = u * 2;
      if (v < MAXN && !d[v]) {
         d[v] = d[u] + 1;
         qu[++re] = v;
         if (v == m) return d[v] - 1;
      }
   }
   return -1;
}

int main() {
//   freopen("input.txt", "r", stdin);

   ios::sync_with_stdio(false);
   cin >> n >> m;
   cout << solve() << endl;

   return 0;
}
