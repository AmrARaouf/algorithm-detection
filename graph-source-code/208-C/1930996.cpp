//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

const int maxn = 107, maxnum = 100000000;
      int n, m;
      int len[maxn][maxn], ru[maxn];
      long double L[maxn], R[maxn];

vector<int> edg[maxn];
vector<int> zz;

void work()
{
    for (int i = 1; i <= n; i++) edg[i].clear();
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++)
            if (i != j) len[i][j] = maxnum;
            else        len[i][j] = 0;
    for (int i = 1; i <= m; i++)
    {
        int fir, lst;
        scanf("%d%d", &fir, &lst);
        edg[fir].push_back(lst);
        edg[lst].push_back(fir);
        len[fir][lst] = 1;
        len[lst][fir] = 1;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != k && k != j && j != i) len[i][j] = min(len[i][j], len[i][k]+len[k][j]);
    for (int i = 1; i <= n; i++) L[i] = R[i] = 0;
    L[1] = 1, R[n] = 1;
    memset(ru, 0, sizeof(ru));
    for (int x = 1; x <= n; x++)
        for (int i = 0; i < edg[x].size(); i++)
        {
            int xx = edg[x][i];
            if (len[1][x]+len[x][xx]+len[xx][n] == len[1][n]) ru[xx]++;
        }
    zz.clear();
    for (int i = 1; i <= n; i++)
        if (ru[i] == 0) zz.push_back(i);
    for (int i = 0; i < zz.size(); i++)
    {
        int x = zz[i];
        for (int j = 0; j < edg[x].size(); j++)
        {
            int xx = edg[x][j];
            if (len[1][x]+len[x][xx]+len[xx][n] == len[1][n]) 
            {
                L[xx] += L[x];
                if (--ru[xx] == 0) zz.push_back(xx);
            }
        }
    }
    
    memset(ru, 0, sizeof(ru));
    for (int x = 1; x <= n; x++)
        for (int i = 0; i < edg[x].size(); i++)
        {
            int xx = edg[x][i];
            if (len[n][x]+len[x][xx]+len[xx][1] == len[n][1]) ru[xx]++;
        }
    zz.clear();
    for (int i = 1; i <= n; i++)
        if (ru[i] == 0) zz.push_back(i);
    for (int i = 0; i < zz.size(); i++)
    {
        int x = zz[i];
        for (int j = 0; j < edg[x].size(); j++)
        {
            int xx = edg[x][j];
            if (len[n][x]+len[x][xx]+len[xx][1] == len[n][1]) 
            {
                R[xx] += R[x];
                if (--ru[xx] == 0) zz.push_back(xx);
            }
        }
    }
    long double res = 1;
    for (int i = 2; i < n; i++) res = max(res, L[i]*R[i]*2/L[n]);
    printf("%.12f\n", (double)res);
}

int main()
{
    while (scanf("%d%d", &n, &m) != EOF) work();
}
