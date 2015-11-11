//Language: GNU C++


#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define FMT         "%I64d"
#define INF         (1<<30)
#define EPS         (1e-9)
#define l(x)        ((x)<<1)
#define r(x)        ((x)<<1|1)
#define f(x)        ((x)>>1)
#define lson(x)     l(x), (l), (mid)
#define rson(x)     r(x), (mid + 1), (r)
#define max(a,b)    ((a)>(b)?(a):(b))
#define min(a,b)    ((a)<(b)?(a):(b))
#define lowbit(x)   ((x)&-(x))
typedef long long   int64;
#ifdef  unix
#undef  FMT
#define FMT         "%lld"
#endif

using namespace std;
#define maxN 2010
vector<int> e[maxN];
int mark[maxN], n;
int dfs(int u);
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int u;
        scanf("%d", &u);
        mark[i] = 0;
        if (u != -1) e[u].push_back(i);
    }
    for (int i = 1; i <= n; i++) 
        if (!mark[i]) 
            mark[i] = dfs(i);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, mark[i]);
//  for (int i = 1; i <= n; i++)
//      printf("mark[%d] = %d\n", i, mark[i]);
    printf("%d\n", ans);
    return 0;
}
int dfs(int u) {
    int ret = 0;
    for (int i = 0; i < e[u].size(); i++) {
        int v = e[u][i];
        mark[v] = dfs(v);
        ret = max(ret, mark[v]);
    }
    return ++ret;
}