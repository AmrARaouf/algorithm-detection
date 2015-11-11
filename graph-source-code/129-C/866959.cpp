//Language: GNU C++


//============================================================================
// Author       : LAM PHAN VIET
// Online Judge :
// Problem Name :
// Time Limit   : .000s
// Description  :
//============================================================================
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define inpFile(f) freopen(f, "r", stdin)
#define outFile(f) freopen(f, "w", stdout)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define ff first
#define ss second
#define bit(n) (1<<(n))
#define Last(i) ( i & -i )
#define INF 500000000
#define maxN 10
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef pair<ii, int> iii;

const int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1, 0 };
const int dy[] = { 0, -1, 1, -1, 1, 0, -1, 1, 0 };
const int n = 8;
char s[maxN][maxN];
int d[maxN][maxN][200];

bool inside(int x, int y) {
    return (0 <= x && x < n && 0 <= y && y < n);
}

bool bfs() {
    REP(i, maxN) REP(j, maxN)
        REP(k, 200) d[i][j][k] = false;
    int x, y, dist, xx, yy;
    queue<iii> Q;
    Q.push(iii(ii(7, 0), 0));
    d[7][0][0] = true;
    while (!Q.empty()) {
        x = Q.front().ff.ff;
        y = Q.front().ff.ss;
        dist = Q.front().ss;
     //   printf("%d %d %d\n", x, y, dist);
        Q.pop();
        if (x == 0 && y == 7) return true;
        if (dist + 1 == 200) continue;
        REP(k, 9) {
            xx = x + dx[k];
            yy = y + dy[k];
            if (!inside(xx, yy)) continue;
            if (d[xx][yy][dist + 1]) continue;
            if (xx - dist - 1 >= 0 && s[xx - dist - 1][yy] == 'S') continue;
            if (xx - dist >= 0 && s[xx - dist][yy] == 'S') continue;
            d[xx][yy][dist + 1] = true;
            Q.push(iii(ii(xx, yy), dist + 1));
        }
    }
    return false;
}

int main() {
    #ifndef ONLINE_JUDGE
        inpFile("test.inp"); outFile("test.out");
    #endif
    REP(i, n) gets(s[i]);
    if (bfs()) puts("WIN");
    else puts("LOSE");
    return 0;
}

// lamphanviet@gmail.com - 2011
