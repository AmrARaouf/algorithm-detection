//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 100;

int n, graph[N][N], color[N];
bool valid;

void dfs(int i, int c) {
    if (color[i] != -1 && color[i] != c) {
        valid = false;
    }
    if (valid && color[i] == -1) {
        color[i] = c;
        for (int j = 0; j < n; ++ j) {
            if (graph[i][j] != -1) {
                dfs(j, c ^ graph[i][j]);
            }
        }
    }
}

bool check() {
    valid = true;
    for (int i = 0; i < n; ++ i) {
        if (color[i] == -1) {
            dfs(i, 0);
        }
    }
    return valid;
}

int m;

int main() {
    scanf("%d%d", &n, &m);
    memset(graph, -1, sizeof(graph));
    for (int i = 0; i < m; ++ i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a --;
        b --;
        graph[a][b] = graph[b][a] = c ^ 1;
    }
    memset(color, -1, sizeof(color));
    if (!check()) {
        puts("Impossible");
    } else {
        vector <int> result;
        for (int i = 0; i < n; ++ i) {
            if (color[i]) {
                result.push_back(i + 1);
            }
        }
        printf("%d\n", (int)result.size());
        for (int i = 0; i < (int)result.size(); ++ i) {
            printf("%d%c", result[i], i == (int)result.size() - 1? '\n': ' ');
        }
    }
    return 0;
}