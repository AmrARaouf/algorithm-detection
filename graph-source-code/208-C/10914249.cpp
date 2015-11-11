//Language: GNU C++11


#include <stdio.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
using namespace std;
#define uint long long // unimaginable big int!
#define ctoi(u) ((u) - 'a')
#define mcode(a, b) ((a) * (m) + b + 1)
#define inf 2000000001
#define Inf 20000000000000000LL
#define P pair<int, int>
#define Q pair<int, P>
#define hd first
#define rr second
#define maxInt 2147483647
#define foreach(u, e) for (__typeof(e.begin()) u = e.begin(); u != e.end(); u++)

const int maxn = 100 + 2;

int n, m;
int dis[maxn][maxn], o[maxn];
double f[maxn], g[maxn];
bool vis[maxn];

int main() {
    int a, b;
    scanf("%d%d", &n, &m);
    memset(dis, -1, sizeof(dis));
    for (int i = 1; i <= n; i++) dis[i][i] = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        dis[a][b] = 1;
        dis[b][a] = 1;
    }
    
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) 
                if ((dis[i][k] != -1 && dis[k][j] != -1) && (dis[i][j] == -1 || dis[i][k] + dis[k][j] < dis[i][j])) dis[i][j] = dis[i][k] + dis[k][j];
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (dis[i][j] == 1 && dis[1][i] + dis[j][n] + 1 != dis[1][n]) dis[i][j] = 0;
    
    int h = 0, t = 0;
    o[h] = 1; vis[1] = true; f[1] = 1;
    while (h <= t) {
        int u = o[h++];
        for (int i = 1; i <= n; i++)
            if (dis[u][i] == 1) {
                if (dis[1][u] < dis[1][i]) f[i] += f[u];
                if (!vis[i]) {
                    vis[i] = true;
                    o[++t] = i;
                }
            }
    }
    
    memset(vis, false, sizeof(vis));
    h = 0; t = 0; 
    o[h] = n; vis[n] = true; g[n] = 1;
    while (h <= t) {
        int u = o[h++];
        for (int i = 1; i <= n; i++)
            if (dis[i][u] == 1) {
                if (dis[u][n] < dis[i][n]) g[i] += g[u];
                if (!vis[i]) {
                    vis[i] = true;
                    o[++t] = i;
                }
            }
    }
    
    double best = 0;
    for (int i = 1; i <= n; i++) {
        double cur = 0;
        for (int j = 1; j <= n; j++)
            if (dis[i][j] == 1 || dis[j][i] == 1) {
                if (dis[1][j] < dis[1][i]) cur += f[j] * g[i];
                else cur += f[i] * g[j];
            }
        best = max(best, cur);
    }
    printf("%.12lf\n", best / f[n]);
    return 0;
}


