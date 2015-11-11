//Language: MS C++


#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;
#define sz(v) (v).size()
#define Rep(i, num, n) for (int (i) = (num); (i) < (n); ++(i))
#define RepV(i, v) Rep(i, 0, sz(v))
#define LL long long
#define mn(a, b) ((a) < (b)) ? (a) : (b)
#define mx(a, b) ((a) > (b)) ? (a) : (b)
vector<pair<int, int>> g[100010];
int n;
int u[100010];
LL dp1[100010];
LL dp2[100010];
LL go1(int v) {
    if(u[v])
        return 0;
    u[v] = 1;
    if (!sz(g[v]))
        dp1[v] = 0; 
    RepV(i, g[v])
        if (!u[g[v][i].first])
            dp1[v] += 2 * g[v][i].second + go1(g[v][i].first);
    return dp1[v];
}
LL go2(int v) {
    if(u[v])
        return dp2[v];
    u[v] = 1;
    if (!sz(g[v])) {
        return dp2[v] = 0;
    }
    dp2[v] = ((LL)1 << 62);
    RepV(i, g[v])
        if (!u[g[v][i].first])
            dp2[v] = mn(dp2[v], dp1[v] - dp1[g[v][i].first] + go2(g[v][i].first) - g[v][i].second);
    return dp2[v];
}
int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%d", &n);
    Rep(i, 0, n - 1) {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        --x;--y;
        g[mn(x, y)].push_back(make_pair(mx(x, y), w));
        //g[y].push_back(make_pair(x, w));
    }       
    go1(0);
    memset(u, 0, sizeof(u));
    printf("%I64d", go2(0));
    return 0;
}