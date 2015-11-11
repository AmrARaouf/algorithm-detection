//Language: GNU C++


#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int a[11][1111];
int dp[1111];

bool p[6][1001][1001];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int i, j;
    for(i = 1; i <= k; i++) for(j = 1; j <= n; j++) scanf("%d", &a[i][j]);
    int j2;
    for(i = 1; i <= k; i++)
    {
        for(j = 1; j <= n; j++) for(j2 = j + 1; j2 <= n; j2++)
        {
            p[i][a[i][j]][a[i][j2]] = true;
        }
    }
    dp[a[1][1]] = 1;
    for(i = 2; i <= n; i++)
    {
        dp[a[1][i]] = 1;
        for(int i2 = 1; i2 < i; i2++)
        {
            for(j = 2; j <= k; j++) if(!p[j][a[1][i2]][a[1][i]]) break;
            if(j > k) dp[a[1][i]] = max(dp[a[1][i]], dp[a[1][i2]] + 1);
        }
    }
    int ans = 0;
    for(i = 1; i <= n; i++) ans = max(dp[i], ans);
    printf("%d\n", ans);
    return 0;
}
