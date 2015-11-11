//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 105;
const int INF = 10000005;

int L[maxn], R[maxn];
int G[maxn][maxn], t = 0;

void add(int a, int b){
    if (L[b] < L[a] && L[a] < R[b])G[a][b] = 0;
    if (L[b] < R[a] && R[a] < R[b])G[a][b] = 0;
}

void Floyd(int n){
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
}

int main(){
    int T, t = 0;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        for (int j = 1; j <= T; j++)
        G[i][j] = (i == j ? 0 : INF);
    for (int cas = 1; cas <= T; cas++){
        int op;
        scanf("%d", &op);
        if (op == 1){
            t++;
            scanf("%d%d", &L[t], &R[t]);
            for (int i = 1; i < t; i++){
                add(i, t); add(t, i);
            }
        }else {
            int t1, t2;
            scanf("%d%d", &t1, &t2);
            if (G[t1][t2] == 0)printf("YES\n");
            else {
                Floyd(t);
                if (G[t1][t2] == 0)printf("YES\n");
                else printf("NO\n");
            }
        }
    }
    return 0;
}
