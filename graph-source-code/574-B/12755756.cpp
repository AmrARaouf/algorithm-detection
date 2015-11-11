//Language: GNU C++11


#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
vector<int> vet[4005];
int du[4005];
bool line[4005][4005];
int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        int u, v;
        int ans = -1;
        memset(line, 0, sizeof(line));
        for (int i = 1; i <= n; i++) vet[i].clear(), du[i] = 0;
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &u, &v);
            vet[u].push_back(v);
            vet[v].push_back(u);
            line[u][v] = line[v][u] = true;
            du[u]++, du[v]++;
        }
        for (int i = 1; i <= n; i++) {
            if (du[i] >= 2) {
                for (int j = 0; j < vet[i].size(); j++) {
                    int v = vet[i][j];
                    if (v != i && du[v] >= 2) {
                        for (int k = 0; k < vet[v].size(); k++) {
                            int vv = vet[v][k];
                            if (vv != i && vv != v && line[vv][i]) {
                                if (ans == -1)
                                    ans = du[i] + du[v] + du[vv] - 6;
                                else
                                    ans = min(ans, du[i] + du[v] + du[vv] - 6);
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
}
