//Language: MS C++


#include <iostream>
#include <cstdio>
using namespace std;
const int N = 305;
int n, m, k, a[N], go[N], mark[N];
int res1[N*N], res2[N*N];
int solve(int n,int m,int k)
{
    int qan = 0;
    if(m==0 || k==n)
    return 0;

   /* if(n-k >= 2)
    {
        qan = 0;
        for(int i = n; i >= 1; -- i)
        {
            for(int j = n-1; j >= 1; -- j)
            {
                if(qan+1 <= m)
                {
                    ++ qan;
                    res1[ qan ] = i;
                    res2[ qan ] = j;
                }
            }
        }
        return 1;
    }
    else
    {*/
        if(m > k*(n-k)+(((k-1)*(k-2))/2)+(( (n-k)*(n-k-1) )/2) )
           return 0;
        for(int j = k+1; j <= n; ++ j)
        {
            for(int i = 1; i <= k; ++ i)
            {

                    if(qan+1 <= m)
                    {
                        ++ qan;
                        res1[qan] = i;
                        res2[qan] = j;
                    }
            }
            for(int i = j+1; i <= n; ++ i)
            {
                    if(qan+1 <= m)
                    {
                        ++ qan;
                        res1[qan] = i;
                        res2[qan] = j;
                    }
            }
        }
        for(int i = 2; i <= k; ++ i)
        {
            for(int j = i+1; j <= k; ++ j)
            {
                    if(qan+1 <= m)
                    {
                        ++ qan;
                        res1[qan] = i;
                        res2[qan] = j;
                    }
            }
        }
        return 1;
   // }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= k; ++ i)
        scanf("%d", &a[i]);
    int qa = 0;
    for(int i = 1; i <= k; ++ i)
    {
        ++ qa;
        go[qa] = a[i];
        mark[ a[i] ] = 1;
    }
    for(int i = 1; i <= n; ++ i)
    if(mark[i]==0)
    {
        ++ qa;
        go[qa] = i;
    }
    if(solve(n, m, k))
    {
        for(int i = 1; i <= m; ++ i)
        {
            printf("%d %d\n", go[ res1[ i ] ], go[ res2[ i ] ]);
        }
    }
    else
    {
        printf("-1\n");
    }
    return 0;
}
