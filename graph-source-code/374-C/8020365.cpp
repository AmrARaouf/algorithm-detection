//Language: GNU C++


#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair <int,int> pii;
typedef vector <int> vi;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define forn(i, a, b) for(int i = (a); i < (b); ++i)
#define ford(i, a, b) for(int i = (a); i >= (b); --i)
#define fore(i, a, b) forn(i, a, b + 1)

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define fill(a, v) memset(a, v, sizeof(a))
#define sz(a) ((int)a.size())

#define gl(x) cin >> x
#define gi(x) scanf("%d", &x)
#define pls(x) cout << x << " "
#define pln(x) cout << x << "\n"
#define pis(x) printf("%d ", x)
#define pin(x) printf("%d\n", x)
#define pnl printf("\n")
#define dbn cerr << "\n"
#define dbg(x) cerr << #x << " : " << x << " "
#define dbs(x) cerr << x << " "

#define foreach(c, it) for(__typeof(c.begin()) it = c.begin(); it != c.end(); ++it)

const int N = 1010;
const int inf = (int)1e9;

char mat[N][N];
int cnt[N][N], was[N][N];
bool inStack[N][N];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
char need[4] = {'D', 'I', 'M', 'A'};

int dfs(int x, int y, int n, int m, int pos) {
    if(was[x][y]) {
        if(!inStack[x][y]) return cnt[x][y];
        else return inf;
    }
    was[x][y] = true;
    inStack[x][y] = true;
    cnt[x][y] = pos == 3;
    int fromHere = 0;
    rep(i, 4) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 and nx < n and ny >= 0 and ny < m) if(mat[nx][ny] == need[(pos + 1) % 4]) {
            fromHere = max(fromHere, dfs(nx, ny, n, m, (pos + 1) % 4));
        }
    }
    inStack[x][y] = false;
    cnt[x][y] += fromHere;
    return cnt[x][y];
}

int main() {
    int n, m;
    gi(n), gi(m);
    rep(i, n) scanf("%s", mat[i]);
    int can = 0;
    fill(was, 0);
    fill(inStack, 0);

    rep(i, n) {
        rep(j, m) if(!was[i][j] and mat[i][j] == 'D') {
            can = max(can, dfs(i, j, n, m, 0));
        }
    }
    if(can > 0 and can < inf) pin(can);
    else puts(can ? "Poor Inna!" : "Poor Dima!");
    return 0;
}