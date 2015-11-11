//Language: MS C++


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

const int N = 120;
int g[N][N], cnt[N];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    memset(g, 0, sizeof(g));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0;i < m;++i) {
        int s, t;
        scanf("%d%d", &s, &t);
        g[s][t] = g[t][s] = 1;
        ++cnt[s], ++cnt[t];
    }
    int ans = 0;
    for (int tag = 1;tag;) {
        tag = 0;
        for (int i = 1;i <= n;++i) {
            if (cnt[i] == 1)
                cnt[i] = -1, tag = 1;
        }
        for (int i = 1;i <= n;++i) {
            if (cnt[i] == -1) {
                for (int j = 1;j <= n;++j)
                    if (g[i][j])
                        --cnt[j], g[i][j] = 0, g[j][i] = 0;
                cnt[i] = -2;
            }
        }
        if (tag)++ans;
    }
    printf("%d\n", ans);
    return 0;
}