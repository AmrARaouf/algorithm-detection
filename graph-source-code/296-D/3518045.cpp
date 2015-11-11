//Language: GNU C++


#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;

const int N = 510;
const int inf = 0x3f3f3f3f;

int n;
int x[N];
long long ans[N];
int list[N];
long long dis[N][N];

void init() {
    memset(ans, 0, sizeof ans);
}

void dijkstra(int s, int list[], int dep, int min[], int mat[][N]) {
    int i, j, k, vis[N];
    for (i = 0; i < n; i++) vis[i] = 0, min[i] = inf;
    for (min[s] = j = 0; j < dep; j++) {
        for (i = 0, k = -1; i < dep; i++) {
            int v = list[i];
            if (!vis[v] && (k == -1 || min[v] < min[k]))
                k = v;
        }
        for (vis[k] = 1, i = 0; i < dep; i++) {
            int v = list[i];
            if (!vis[v] && min[k] + mat[k][v] < min[v])
                min[v] = min[k] + mat[k][v];
        }
    }
}

long long cal(int s, int min[][N], int list[], int dep) {
    long long ret = 0;
    for (int i = 0; i < dep; i++)
        ret += min[0][list[i]] + min[1][list[i]];
    for (int i = 0; i < dep; i++) {
        int v = list[i];
        dis[s][v] = min[0][v];
        dis[v][s] = min[1][v];
    }
    for (int i = 0; i < dep; i++) {
        for (int j = 0; j < dep; j++) {
            int u = list[i], v = list[j];
            long long tmp = dis[u][v] - min[1][u] - min[0][v];
            if (tmp > 0) {
                ret -= tmp;
                dis[u][v] -= tmp;
            }
        }
    }
    return ret;
}

int mat[N][N], rmat[N][N];

int main() {
    //freopen("in.txt", "r", stdin);
    while (~scanf("%d", &n)) {
        init();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &mat[i][j]);
                rmat[j][i] = mat[i][j];
            }
        }
        for (int i = 0; i < n; i++) scanf("%d", x + i), x[i]--;
        for (int i = n - 1, cnt = 0; i >= 0; i--) {
            list[cnt++] = x[i];
            int min[2][N];
            dijkstra(x[i], list, cnt, min[0], mat);
            dijkstra(x[i], list, cnt, min[1], rmat);
            ans[i] = ans[i + 1] + cal(x[i], min, list, cnt);
        }
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}

