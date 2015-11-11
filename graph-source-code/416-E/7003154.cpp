//Language: GNU C++


#include <cstdio>
#include <cstring>
using namespace std;

int n, m, x[124751], y[124751], l[124751];

int doc() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &x[i], &y[i], &l[i]);
}

int xuli() {
    
    int d[501][501];
    memset(d, 63, sizeof(d));
    for (int i = 1; i <= m; i++) {
        d[x[i]][y[i]] = l[i];
        d[y[i]][x[i]] = l[i];
    }
    for (int i = 1; i <= n; i++)
        d[i][i] = 0;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j];

    
    int c[501][501] = {0};
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            if (d[x[i]][j] == l[i] + d[y[i]][j])
                c[x[i]][j]++;
            if (d[y[i]][j] == l[i] + d[x[i]][j])
                c[y[i]][j]++;
        }

    
    for (int i = 1; i <= n-1; i++)
        for (int j = i+1; j <= n; j++) {
            int sum = 0;
            for (int k = 1; k <= n; k++)
                if (d[i][j] == d[i][k] + d[k][j])  
                    sum += c[k][j];
            printf("%d", sum);
            if (i < n-1)
                printf(" ");
            else
                printf("\n");
        }
}

int main () {
    //freopen("test00.in", "r", stdin);
    //freopen("", "w", stdout);

    doc();
    xuli();
    return 0;
}
