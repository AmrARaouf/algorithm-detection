//Language: GNU C++


/*
ID: allen.c1
PROG: CFE
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>
#include<cstring>
#include<stack>
#include<queue>
#include<map>
#include<deque>
#include<cmath>
#include<map>

using namespace std;

#define rep(i, n) for(__typeof(n) i = 0; i < (n); i++)
#define pi 3.1415926535897

typedef long long LL;
typedef pair<int, int> pii;
typedef pair<pii, int> edge;


const int maxn = 300003;
/*
Use DSU to handle the 1st query. To handle second query use: d_n = max(d_u, d_v, ceil(d_u / 2) + (d_v / 2) + 1);
 */
int n, m, q;
vector<int> v[maxn];
int par[maxn];
bool vis[maxn][2];
int deprt = 0, mxlen = 0;
int diam[maxn];

int findpar(int a) {
    return par[a] == a ? a : par[a] = findpar(par[a]);
}

void dfs(int cur, int dep, int ix) {
    if (vis[cur][ix]) return;
    vis[cur][ix] = true;
    for (int i = 0; i < v[cur].size(); i++) {
        int nxt = v[cur][i];
        dfs(nxt, dep + 1, ix);
    }
    if (dep > mxlen) {
        mxlen = dep;
        deprt = cur;
    }
}
int main() {
    for (int i = 0; i < maxn; i++) par[i] = i;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--; b--;
        v[a].push_back(b);
        v[b].push_back(a);
        int pa = findpar(a);
        int pb = findpar(b);
        if (pa != pb) par[pb] = pa;
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i][0]) {
            deprt = i; mxlen = 0;
            dfs(i, 0, 0);
            mxlen = 0;
            dfs(deprt, 0, 1);
            deprt = findpar(deprt);
            diam[deprt] = mxlen;
        }
    }
    for (int i = 0; i < q; i++) {
        int q, a, b;
        scanf("%d", &q);
        if (q == 1) {
            scanf("%d", &a);
            a--;
            printf("%d\n", diam[findpar(a)]);
        }
        else {
            scanf("%d%d", &a, &b);
            a--; b--;
            int pa = findpar(a);
            int pb = findpar(b);
            if (pa != pb) {
                par[pb] = pa;
                diam[pa] = max(diam[pa], max(diam[pb], (diam[pa] + 1) / 2 + (diam[pb] + 1) / 2 + 1));
            }
        }
    }
}
