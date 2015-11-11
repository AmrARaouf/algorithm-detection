//Language: GNU C++


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define FOREACH(it, c) for(typeof(c.begin()) it = c.begin(); it != c.end(); it ++)

int m, n;
char c[2005][2005];
bool ok[2005 * 2005], fr[2005 * 2005];
int f[2005 * 2005];
bool flag;
vector<int> s[2005 * 2005];
queue<int> q;

void setlink(int i, int j, int u, int v) {
    if (c[i][j] == '#') return;
    s[(i - 1) * n + j].push_back((u - 1) * n + v);
    ok[(u - 1) * n + v] = false;
}
int bfs(int u, int x) {
    int res = 0;
    f[u] = 1;
    q.push(u);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        res = max ( res, f[u] );
        FOREACH(v, s[u]) 
            if (f[*v] == 0) {
                f[*v] = f[u] + 1;
                q.push(*v);
            } 
    }
    return res;
}
int main() {
    //freopen("test.inp", "r", stdin);
    memset(ok, true, sizeof(ok));
    scanf("%d%d\n", &m, &n);
    for (int i = 1; i <= m; i ++) {
        for (int j = 1; j <= n; j ++) 
            scanf("%c", &c[i][j]);
        scanf("\n");
    }
    for (int i = 1; i <= m; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (c[i][j] == '^') setlink(i-1, j, i, j);
             if (c[i][j] == '<') setlink(i, j-1, i, j);
            if (c[i][j] == '>') setlink(i, j+1, i, j);
            if (c[i][j] == 'v') setlink(i+1, j, i, j);
            if (c[i][j] == '#') ok[(i - 1) * n + j] = false;
        }
    }

    int max1 = -1, max2 = -1, res = 0;
    for (int i = 1; i <= m * n; i ++) if (ok[i]) {
        int k = bfs(i, i);
        res = max(res, k * 2 - 1);
        if (k >= max1) max2 = max1, max1 = k;
        else if (k >= max2) max2 = k;
    }
    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++) 
            if (c[i][j] != '#' && f[(i - 1) * n + j] == 0) {
                cout << -1; 
                return 0;
            }

    if (max2 != -1) res = max(res, max1 + max2);
    cout << res << endl;
    return 0;
}