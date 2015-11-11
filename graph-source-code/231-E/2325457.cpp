//Language: GNU C++


#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 100005;
const int MAXS = 20;
const __int64 MOD = 1000000007ll;

int n, m;
vector<int> adj[MAXN];

inline unsigned int LOG2(unsigned int x){
    unsigned int ret;
    __asm__ __volatile__ ("bsrl %1, %%eax":"=a"(ret):"m"(x));
    return ret;
}

__int64 pow2(int x){
    if (x == 0) return 1;
    __int64 r = pow2(x >> 1);
    r *= r;
    if (x & 1) r *= 2ll;
    r %= MOD;
    return r;
}

void init(){
    for (int i = 1;i <= n;i++) adj[i].clear();
    for (int i = 0;i < m;i++){
        int x, y;
        scanf("%d%d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

int num[MAXN], low[MAXN], stamp;
int stk[MAXN], stkTop;
int dccCnt;
vector<int> dcc[MAXN];
void dfs1(int x, int fa = -1){
//    printf("dfs1 %d from %d %d\n", x, fa, stamp);
    num[x] = low[x] = stamp++;
    stk[stkTop++] = x;
    for (int i = 0;i < (int)adj[x].size();i++){
        int nx = adj[x][i];
        if (num[nx] < 0){
            dfs1(nx, x);
            low[x] = min(low[x], low[nx]);
        }
        else if (nx != fa){
            low[x] = min(low[x], num[nx]);
        }
    }
    if (low[x] == num[x]){
//        printf("got %d\n", x);
        dcc[dccCnt].clear();
        while (1){
            int y = stk[--stkTop];
            dcc[dccCnt].push_back(y);
            if (y == x) break;
        }
        dccCnt += 1;
//        for (int j = 0;j < stkTop;j++) printf("%d ", stk[j]);
//        printf("\n");
    }
}
int fa[MAXN << 1];
vector<int> adj1[MAXN << 1];
int ms;
void buildNew(){
    stamp = 0;
    stkTop = 0;
    dccCnt = 0;
    for (int i = 1;i <= n;i++) num[i] = -1;
    dfs1(1);
    int id = n + 1;
    for (int i = 1;i <= n;i++) fa[i] = i;
    for (int i = 0;i < dccCnt;i++){
        if ((int)dcc[i].size() <= 2) continue;
        fa[id] = id;
        for (int j = 0;j < (int)dcc[i].size();j++){
//            printf("%d ", dcc[i][j]);
            fa[dcc[i][j]] = id;
        }
//        printf("\n");
        id += 1;
    }
    for (int i = 1;i < id;i++){
        adj1[i].clear();
    }
    for (int i = 1;i <= n;i++){
        for (int j = 0;j < (int)adj[i].size();j++){
            int k = adj[i][j];
//            printf("original %d %d\n", i, k);
            if (i < k){
                if (fa[i] != fa[k]){
                    adj1[fa[i]].push_back(fa[k]);
                    adj1[fa[k]].push_back(fa[i]);
//                    printf("link %d %d\n", i, k);
                }
            }
        }
    }
//    for (int i = 1;i <= n;i++){
//        if (i != fa[i]){
//            adj1[i].push_back(fa[i]);
//            adj1[fa[i]].push_back(i);
////            printf("link %d %d\n", i, fa[i]);
//        }
//    }
    ms = LOG2(n + dccCnt);
}

int up[MAXN << 1][MAXS];
int s[MAXN << 1][MAXS];
int ht[MAXN << 1];
void dfs(int x, int y, int fa = -1){
//    printf("dfs %d %d\n", x, y);
//    if (y > 1000000) exit(0);
    ht[x] = y;
    up[x][0] = fa;
    for (int i = 0;i < ms;i++){
        if (up[x][i] > 0) up[x][i + 1] = up[up[x][i]][i];
        else up[x][i + 1] = -1;
    }
    s[x][0] = (x > n);
    for (int i = 0;i < ms;i++){
        if (up[x][i] > 0) s[x][i + 1] = s[x][i] + s[up[x][i]][i];
        else s[x][i + 1] = s[x][i];
    }
    for (int i = 0;i < (int)adj1[x].size();i++){
        int nx = adj1[x][i];
        if (nx != fa){
            dfs(nx, y + 1, x);
        }
    }
}

int getUp(int x, int y){
}

int lca(int x, int y){
    if (ht[x] > ht[y]) swap(x, y);
    for (int i = ms;i >= 0;i--){
        if (up[y][i] > 0 && ht[up[y][i]] >= ht[x]){
            y = up[y][i];
        }
    }
//    printf("lca1 %d %d\n", x, up[2][1]);
    for (int i = ms;i >= 0;i--){
        if (up[x][i] != up[y][i]){
            x = up[x][i];
            y = up[y][i];
        }
    }
    while (x != y){
        x = up[x][0];
        y = up[y][0];
    }
    return x;
}

//from x up to y
int acc(int x, int y){
//    printf("acc %d %d\n", x, y);
    int r = 0;
    for (int i = ms;i >= 0;i--){
        if ((1 << i) & (ht[x] - ht[y] + 1)){
            r += s[x][i];
            x = up[x][i];
        }
    }
//    printf("r = %d\n", r);
    return r;
}

void query(){
    int q;
    scanf("%d", &q);
    while (q--){
        int x, y;
        scanf("%d%d", &x, &y);
//        printf("ox %d %d\n", x, y);
        x = fa[x];
        y = fa[y];
        int fa = lca(x, y);
//        printf("query %d %d %d\n", x, y, fa);
        printf("%I64d\n", pow2(acc(x, fa) + acc(y, fa) - (fa > n)));
    }
}

void work(){
    buildNew();
    dfs(fa[1], 0);
    query();
}

int main(){
#ifdef ATTIIX
    freopen("e.in", "r", stdin);
#endif
    while (~scanf("%d%d", &n, &m)){
        init();
        work();
    }
    return 0;
}
