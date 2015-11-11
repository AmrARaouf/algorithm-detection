//Language: GNU C++


#include <iostream>
#include <cstdio>
using namespace std;
const int N = 2000+5;
__int64 n, i, j, k, q, q1, re, res, a[N][N], C[N][N];
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%I64d%I64d", &n, &k);
    for(i = 1; i < n; ++ i)
    {
        for(j = i+1; j <= n; ++ j)
        {
            scanf("%I64d", &a[i][j]);
        }
    }
    for(i = 1; i <= n; ++ i)
    {
        a[i][i] = -1;
    }
    for(i = 1; i < n; ++ i)
    {
        for(j = i+1; j <= n; ++ j)
        {
            a[j][i] = a[i][j];
        }
    }
    C[0][0] = 1;
    for(i = 1; i <= n; ++ i)
    {
        C[i][0] = 1;
        for(j = 1; j <= i; ++ j)
        {
            C[i][j] = C[i-1][j-1]+C[i-1][j];
        }
    }
    for(i = 1; i <= n; ++ i)
    {
        res = 0;
        q = 0;
        for(j = 1; j <= n; ++ j)
        {
            if(a[i][j]!=-1)
            {
                res+=a[i][j];
                ++ q;
            }
        }
        if(q >= k)
        {
            q1+=C[q][k];
            re = re+res*C[q-1][k-1];
        }
    }
    printf("%I64d\n", re/q1);
    return 0;
}
