//Language: GNU C++


#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
#define rep(i,l,r) for (int i=l; i<=r; i++)
#define drep(i,r,l) for (int i=r; i>=l; i--)
#define N 508
int n, m, w[N];
double ans;
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n ,&m);
    rep(i, 1, n) scanf("%d", &w[i]);
    rep(i, 1, m)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if (((double)w[x] + (double)w[y]) / (double)z > ans) ans = ((double)w[x] + (double)w[y]) / (double)z;
    }
    printf("%.15lf\n", ans);
    //fclose(stdin); fclose(stdout);
    return 0;
}