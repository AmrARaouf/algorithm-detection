//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Rep(i, n) for (int i = 1; i <= (n); ++i)
#define clr(x, a) memset(x, (a), sizeof x)
using namespace std;
typedef long long ll;
int const N = 1010;
char const ch[5] = "DIMA";
int const dir[4][2] = { 0, 1, 0, -1, 1, 0, -1, 0 };
char mp[N][N];
int n, m;
int dp[N][N];
int sx, sy;
int q[N][N];
int dfs(int x, int y, int d) {
    if (q[x][y]) return -2;
    if (~dp[x][y]) return dp[x][y];
    q[x][y] = 1;
    int td = (d + 1) % 4, tx, ty;
    int tr = (d == 3), t, mt = 0;
    rep(i, 4) {
        tx = x + dir[i][0], ty = y + dir[i][1];
        if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
            if (mp[tx][ty] == ch[td]) {
                t = dfs(tx, ty, td);
                if (t == -2) return dp[x][y] = -2;
                mt = max(mt, t);
            }
        }
    }
    q[x][y] = 0;
    if (mt < 0 || tr < 0) while (1);
    return dp[x][y] = tr + mt;
}
int main() {
    scanf("%d%d", &n, &m); rep(i, n) scanf(" %s", mp[i]);
    clr(dp, 0xff);
    int ret = 0; 
    rep(i, n) rep(j, m) if (mp[i][j] == 'D' && dp[i][j] == -1) {
        int tr = dfs(i, j, 0);
        if (tr == -2) {
            puts("Poor Inna!");
            return 0;
        }
        ret = max(ret, tr);
    }
    if (ret == 0) puts("Poor Dima!");
    else printf("%d\n", ret);
    return 0;
}
