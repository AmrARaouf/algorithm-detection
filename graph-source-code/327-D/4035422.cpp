//Language: GNU C++


/**
Calvin Xiao
calvin.xiao at scaurugby.com
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std ;

#define REP(i,n) for (int i = 0; i < (int)(n); ++i)
#define REPN(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
#define REPI(c,itr) for(__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); itr++)

#define N 505

int n, m;
char g[N][N];
int vis[N][N];
vector<string> cmd;
vector<int> x, y;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

void put(string CMD, int X, int Y) {
    cmd.push_back(CMD);
    x.push_back(X);
    y.push_back(Y);
    g[X][Y] = CMD[0];
}

void dfs(int i, int j) {
    vis[i][j] = 1;
    REP(k, 4) {
        int nx = i + dx[k], ny = j + dy[k];
        if (!vis[nx][ny] && g[nx][ny] == 'R' || g[nx][ny] == '.') {
            if (g[nx][ny] == 'R')
                put("D", nx, ny);
            put("B", nx, ny);
            dfs(nx, ny);
            put("D", nx, ny);
            put("R", nx, ny);
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif
    scanf("%d%d", &n, &m);
    REPN(i, 1, n) {
        REPN(j, 1, m) {
            scanf(" %c", &g[i][j]);
        }
    }
    REPN(i, 1, n) {
        REPN(j, 1, m) {
            if (g[i][j] == '.') {
                put("B", i, j);
                dfs(i, j);
            }
        }
    }


    int R = 0, B = 0;
    int test = 0;
    if (test)
    REPN(i, 1, n) {
        REPN(j, 1, m) {
            if (g[i][j] == 'R')
                R++;
            else if(g[i][j] == 'B')
                B++;
        }
    }
    if (test)
        cout << R << ' ' << B << ' ' << R * 200 + B * 100 << endl;

    printf("%d\n", (int)(cmd.size()));
    REP(i, cmd.size()) {
        printf("%c %d %d\n", cmd[i][0], x[i], y[i]);
        //cout << cmd[i] << ' ' << x[i] << ' ' << y[i] << endl;
    }

    return 0;
}
