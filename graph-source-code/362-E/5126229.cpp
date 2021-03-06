//Language: GNU C++


#include <cstdio>
const int inf = -1u/4;
struct edge {
    int u, v, cap, cost;
}e[50*50*4];
int n, k, ne;
int maxflow, mincost;
int sol[55];
int dp[55];
int main() {
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int x;
            scanf("%d", &x);
            if(x) {
                e[ne++] = {i, j, x, 0};
                e[ne++] = {j, i, 0, 0};
                e[ne++] = {i, j, inf, 1};
                e[ne++] = {j, i, 0, -1};
            }
        }
    }
    for(; ; ) {
        for(int i = 1; i < n; i++) {
            dp[i] = inf;
        }
        for(int yes = 1; yes; ) {
            yes = 0;
            for(int i = 0; i < ne; i++) {
                if(e[i].cap and dp[e[i].v] > dp[e[i].u] + e[i].cost) {
                    dp[e[i].v] = dp[e[i].u] + e[i].cost;
                    sol[e[i].v] = i;
                    yes = 1;
                }
            }       
        } 
        mincost += dp[n-1];
        if(mincost > k) {
            break;
        }
        int flow;
        if(dp[n-1] == 0) {
            flow = inf;
            for(int v = n-1; v; ) {
                int i = sol[v];
                if(e[i].cap < flow) {
                    flow = e[i].cap;   
                }
                v = e[i].u;
            } 
        } else {
            flow = 1;
        }
        maxflow += flow;
        for(int v = n-1; v; ) {
            int i = sol[v];
            e[i].cap -= flow;
            e[i^1].cap += flow;
            v = e[i].u;
        }
    }
    printf("%d\n", maxflow);
}