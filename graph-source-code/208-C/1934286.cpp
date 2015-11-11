//Language: GNU C++


#include <cstdio>
#include <cstring>

int map[111][111];
int dist[111][111];
int n;
int tot = 0;

typedef long long Long;

double test(int point) {
    static Long safe[111][111]; memset(safe,0,sizeof(safe));
    static Long way[111][111]; memset(way,0,sizeof(safe));
    way[0][0] = 1;
    for (int deep = 0; deep < dist[0][n - 1]; deep ++) {
        for (int i = 0; i < n; i++) {
            if (deep != dist[0][i]) continue;
            for (int j = 0; j < n; j++) {
                if (map[i][j]) {
                    way[j][deep + 1] += way[i][deep];
                    safe[j][deep + 1] += safe[i][deep];
                    if (i == point || j == point) safe[j][deep + 1] += way[i][deep];
                }
            }
        }
    }
    double ret = safe[n - 1][dist[0][n - 1]];
    ret /= way[n - 1][dist[0][n - 1]];
    return ret;
}

int main() {
    int m;
    scanf("%d%d",&n,&m);
    memset(dist,0x3f,sizeof(dist));
    for (int i = 0; i < m; i++) {
        int f,t,v;
        scanf("%d%d",&f,&t);
        f --;
        t --;
        v = 1;
        map[f][t] = map[t][f] = v;
        dist[f][t] = dist[t][f] = v;
    }
    for (int i = 0; i < n; i++) {dist[i][i] = 0;}
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    double ans = 0;
    for (int i = 0; i < n; i++) {
        double tmp = test(i);
        if (tmp > ans) ans = tmp;
    }
    printf("%.12lf\n",ans);
    return 0;
}
