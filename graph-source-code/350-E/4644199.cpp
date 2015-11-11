//Language: GNU C++


#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define abs(a) (((a)>0)?(a):(-(a)))
#define max(a, b) (((a)>(b))?(a):(b))
#define min(a, b) (((a)<(b))?(a):(b))

#define N 303
#define oo int(1e9)
#define eps 1e-8

using namespace std;

bool g[N][N], cl[N];

int main()
{
//    freopen("input.txt", "r", stdin);

    int n, m, k, i, j, c, u, v, v1, v2;

    cin >> n >> m >> k;

    for(i=0; i<N; ++i)
        cl[i] = 0;

    for(i=0; i<N; ++i)
        for(j=0; j<N; ++j)
            g[i][j] = 0;

    v1 = v2 = -1;
    for(i=0; i<k; ++i)
    {
        cin >> c;
        cl[--c] = 1;

        if(v1 == -1)
            v1 = c;
        else if(v2 == -1)
            v2 = c;
    }

    v = 0;
    while(v<n && cl[v])
        ++v;

    if(v == n)
    {
        cout << -1 << endl;
        return 0;
    }


    g[v][v2] = g[v2][v] = 1;
    --m;

    for(i=0; i<n; ++i)
    {
        if((i == v1) || (i == v2)) continue;

        g[v1][i] = g[i][v1] = 1;
        --m;
    }

    if(m<0)
    {
        cout << -1 << endl;
        return 0;
    }

    for(i=0; (i<n) && m; ++i)
        for(j=i+1; (j<n) && m; ++j)
        {
            if(cl[i] && cl[j] && ( (v2 == i) || (v2 == j)))
                continue;

            if(g[i][j])
                continue;

            g[i][j] = 1;
            --m;
        }

    if(m)
    {
        cout << -1 << endl;
        return 0;
    }

    for(i=0; i<n; ++i)
        for(j=i+1; j<n; ++j)
            if(g[i][j])
                cout << i+1 << " " << j+1 << endl;
    return 0;
}
