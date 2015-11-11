//Language: GNU C++


#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define EACH(itr,c) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)  
#define FOR(i,b,e) for (int i=(int)(b); i<(int)(e); i++)
#define MP(x,y) make_pair(x,y)
#define REP(i,n) for(int i=0; i<(int)(n); i++)

#ifdef ONLINE_JUDGE
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

const int INF = 1e9;
int N, M, K;
int a[100][100];
int xs[7], ys[7];
int dp[1<<7][100][100];
int pre[1<<7][100][100][3];    // type 0=end, 1=split, 2=merged
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool vis[100][100];

void shortestPath(int mask) {
    REP (itr, N*M+10) {
        REP (i, N) REP (j, M) REP (k, 4) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x < 0 || x >= N) continue;
            if (y < 0 || y >= M) continue;
            if (dp[mask][i][j] + a[x][y] < dp[mask][x][y]) {
                dp[mask][x][y] = dp[mask][i][j] + a[x][y];
                pre[mask][x][y][0] = 2;
                pre[mask][x][y][1] = i;
                pre[mask][x][y][2] = j;
            }
        }
    }
}

void constructPath(int mask, int x, int y) {
    vis[x][y] = true;

    if (pre[mask][x][y][0] == 1) {
        constructPath(pre[mask][x][y][1], x, y);
        constructPath(pre[mask][x][y][2], x, y);
    } else if (pre[mask][x][y][0] == 2) {
        constructPath(mask, pre[mask][x][y][1], pre[mask][x][y][2]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    
    cin >> N >> M >> K;
    REP (i, N) REP (j, M) cin >> a[i][j];
    REP (i, K) cin >> xs[i] >> ys[i], --xs[i], --ys[i];
    
    REP (i, 1<<K) REP(j, N) REP (k, M) dp[i][j][k] = INF;
    REP (i, K) dp[1<<i][xs[i]][ys[i]] = a[xs[i]][ys[i]];

    REP (mask, 1<<K) {
        REP (i, N) REP (j, M) {
            for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
                int tmp = dp[submask][i][j] + dp[mask^submask][i][j] - a[i][j];
                if (tmp < dp[mask][i][j]) {
                    dp[mask][i][j] = tmp;
                    pre[mask][i][j][0] = 1;
                    pre[mask][i][j][1] = submask;
                    pre[mask][i][j][2] = mask^submask;
                }

            }
        }
        shortestPath(mask);
    }
    
    int ret = INF;
    REP (i, N) REP (j, M) ret = min(ret, dp[(1<<K)-1][i][j]);
    cout << ret << endl;

    REP (i, N) REP (j, M) if (dp[(1<<K)-1][i][j] == ret) { constructPath((1<<K)-1, i, j); goto disp; }

disp:
    REP (i, N) {
        REP (j, M) {
            if (vis[i][j]) cout << "X";
            else cout << ".";
        }
        cout << endl;
    }
    
    return 0;
}
