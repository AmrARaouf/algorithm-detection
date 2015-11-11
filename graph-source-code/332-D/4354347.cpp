//Language: GNU C++


#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<ctime>
#include<set>
#include<string>
using namespace std;
const int MAX = 2005;
#define ll __int64
struct node
{
  int a, b, id, pos;
}x[MAX], y[MAX];
int a[MAX][MAX], deg[MAX];
int main()
{
    int n, k, p;
    while (scanf("%d %d", &n, &k) != EOF) {
      ll res = 0;
      memset(deg, 0, sizeof(deg));
      for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
          scanf("%d", &p);
          a[i][j] = a[j][i] = p;
          if (p != -1) {
            res += p * 2;
            deg[i]++;
            deg[j]++;
          }
        }
      }
      if (k == 2) {
        int center = 1;
        for (int i = 1; i <= n; i++) {
          if (deg[i] > deg[center]) {
            center = i;
          }
        }
      for (int i = 1; i <= n; i++) {
          if (i == center)
            continue;
          res += a[i][center] * (ll)(n - 3);
          /*for (int j = 1; j <= n; j++) {
            if (j != center && a[i][j] > 0)
              res -= a[i][j];
          }*/
        }
        cout<<res/(n*(n-1)/2)<<endl;
    }
    else {
      cout<<res/n<<endl;
    }

    }return 0;
}
