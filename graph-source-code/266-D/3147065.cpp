//Language: GNU C++


#include <stdio.h>

#define INFINITY 420000000
#define MAX_N 205

#define min(x,y) (x<y?x:y)
#define max(x,y) (x>y?x:y)

int N;
long Best[MAX_N][MAX_N], Dist[MAX_N][MAX_N];
long BestDist = INFINITY;

void setUp()
{
    for(int i = 1; i < MAX_N; i++)
    {
        Dist[i][i] = 0;

        for(int j = i + 1; j < MAX_N; j++)
            Dist[i][j] = Dist[j][i] = INFINITY;
    }
}

void in()
{
    long m;
    scanf("%d %ld", &N, &m);

    int a, b;
    long d;

    for(long i = 0; i < m; i++)
    {
        scanf("%d %d %ld", &a, &b, &d);
        Dist[a][b] = Dist[b][a] = d*2;
    }
}

void floyd()
{
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            Best[i][j] = Dist[i][j];

    for(int k = 1; k <= N; k++)
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                Best[i][j] = min(Best[i][j], Best[i][k] + Best[k][j]);
}

long check(int a, int b, long x)
{
    long dist, maxDist = 0;

    for(int i = 1; i <= N; i++)
    {
        dist = min(Best[a][i] + x, Best[b][i] + Dist[a][b] - x);
        maxDist = max(maxDist, dist);
    }

    return maxDist;
}

void search(int p, int q, long a, long b)
{
    long pos = (a + b) / 2;
    long dist = check(p, q, pos);
    BestDist = min(BestDist, dist);

    if(b - a < 2 || dist - (pos - a) >= BestDist)
        return;

    search(p, q, a, pos);
    search(p, q, pos, b);
}

void solve()
{
    long dist;

    for(int i = 1; i <= N; i++)
        for(int j = i; j <= N; j++)
            search(i, j, 0, Dist[i][j]);

    printf("%lf\n", (double) BestDist / (double) 2);
}

int main()
{
    setUp();
    in();
    floyd();
    solve();

    return 0;
}
