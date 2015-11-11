//Language: GNU C++


#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

struct sEdge {
    int u, prev;
} e[1000009];
int ee;
int first[1001];
void AddEdge(int u, int v)
{
    ee++;
    e[ee].u = v;
    e[ee].prev = first[u];
    first[u] = ee;
}

int ans;
int maxLen[1001];
bool visited[1001];

void DFS(int v)
{
    maxLen[v] = 1;
    visited[v] = true;
    for (int i = first[v]; i; i = e[i].prev) {
        int u = e[i].u;

        if (!visited[u]) DFS(u);
        maxLen[v] = max(maxLen[v], maxLen[u]+1);
    }
    ans = max(ans, maxLen[v]);
}

int Inv[1000][5];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    for (int j = 0; j < k; j++) {
        for (int i = 0; i < n; i++) {
            int t; scanf("%d", &t);
            Inv[t-1][j] = i;
        }
    }

    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
            if (a == b) continue;

            bool ok = true;
            for (int j = 0; j < k; j++) {
                if (Inv[a][j] > Inv[b][j]) ok = false;
            }

            if (ok) AddEdge(a, b);
        }
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) DFS(i);
    }

    printf("%d", ans);
}
