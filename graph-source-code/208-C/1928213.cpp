//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

bool g[200][200];
int dist[2][200];
double kind[2][200];
int list[200];
bool can[200];
int n,m;

void compute(int s, int dist[200], double kind[200])
{
    int head = 1;
    int tail = 1;
    list[1] = s;
    dist[s] = 0;
    kind[s] = 1;
    memset(can, 1, sizeof(can));
    memset(kind, 0, sizeof(kind));
    can[s] = false;
    while (head <= tail)
    {
        int x = list[head];
        for (int i=1;i<=n;i++)
            if (g[x][i]) {
                if (can[i]) {
                    list[++tail] = i;
                    can[i] = false;
                    dist[i] = dist[x] + 1;
                    kind[i] = kind[x];
                }
                else
                    if (dist[i] == dist[x] + 1)
                        kind[i] += kind[x];
            }
        head++;
    }
}


int main() {
    memset(g,0,sizeof(g));
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        g[a][b] = 1;
        g[b][a] = 1;
    }
    compute(1,dist[0],kind[0]);
    compute(n,dist[1],kind[1]);
    int sh = dist[0][n];
    double ans = kind[0][n];
    for (int i=2; i<n; i++)
        if (dist[0][i] + dist[1][i] == sh) {
            double t = 2 * kind[0][i] * kind[1][i];
            if (t>ans) ans = t;
        }
    printf("%.9lf\n",ans/kind[0][n]);
    return 0;
}
