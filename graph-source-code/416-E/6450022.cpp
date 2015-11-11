//Language: GNU C++


#include<iostream>
#include<algorithm>
#include<cstring>
#include<ctime>
#include<cmath>
#include<string>
#include<cstdio>
#include<vector>
using namespace std;

const int N = 505;
const int INF = 0x07ffffff;
int cnt[N], ans[N][N];
int mat[N][N];

struct Edge {
    int from, to, dis;
}edges[N*N];

void init(int n) {
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            if(i == j) mat[i][j] = 0;
            else mat[i][j] = INF;
}

void floyd(int n) {
    for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
}

int main() {
    int n, m, a, b, d;
    scanf("%d%d", &n, &m);
    init(n);
    for(int i = 0; i < m; ++i) {
        scanf("%d%d%d", &a, &b, &d);
        mat[a][b] = mat[b][a] = min(mat[a][b], d);
        edges[i] = (Edge){a, b, d};
    }
    floyd(n);
    for(int u = 1; u <= n; ++u) { //起点
        memset(cnt, 0, sizeof(cnt)); //记录从起点到终点的最短路径条数（只计算与终点直接相连的边）
        for(int i = 0; i < m; ++i) { //枚举边
            int from = edges[i].from, to = edges[i].to, d = edges[i].dis;
            if(mat[u][from] + d == mat[u][to]) cnt[to]++;
            if(mat[u][to] + d == mat[u][from]) cnt[from]++;
        }

        for(int v = u + 1; v <= n; ++v)//终点
            for(int k = 1; k <= n; ++k) //终点
                if(mat[u][k] + mat[k][v] == mat[u][v])
                    ans[u][v] += cnt[k];//起点到终点的最短路的条数
    }

    for(int i = 1; i <= n; ++i)
        for(int j = i + 1; j <= n; ++j)
            printf("%d ", ans[i][j]);

    return 0;
}

			 		 			 		 	   	 					