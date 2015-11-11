//Language: GNU C++


#include <iostream>
#include <cstdio>
using namespace std;
#define MaxN 1000010
__int64 v[MaxN];
int main()
{
    __int64 ans, tp, n;
    int i, m, a, b;
    while (scanf("%I64d%d", &n, &m) != EOF)
    {
        for (i=1; i<=n; i++)
            v[i] = 0;

        while (m--)
        {
            scanf("%d%d", &a, &b);
            v[a]++;
            v[b]++;
        }

        tp = 0;
        for (i=1; i<=n ; i++)
            tp += v[i]*(n-v[i]-1);

        printf("%I64d\n", (n*(n-1)*(n-2)/6)-(tp/2));

    }
}

