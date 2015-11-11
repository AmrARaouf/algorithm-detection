//Language: GNU C++


#include <iostream>
#include <fstream>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
#include <functional>




using namespace std;

typedef long long LL;

typedef pair<LL, LL> pll;

const LL INF = LLONG_MAX;



LL mat[1100][1100];
LL aMat[1100][1100];
LL N, M;
LL array[1100][2];
LL g[1100][1100];
int len[1100];
LL s, t;
LL d[1100];
bool inq[1100];




int main()
{
//    freopen("input.txt", "r", stdin);

    scanf("%I64d %I64d", &N, &M);

    scanf("%I64d %I64d", &s, &t);

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            mat[i][j] = INF;
        }
        mat[i][i] = 0;
    }
    LL a, b, l;
    for(int i = 0; i < M; i++)
    {
        scanf("%I64d %I64d %I64d", &a, &b, &l);
        if(l < mat[a][b])
        {
            mat[a][b] = mat[b][a] = l;
        }
    }
    for(int i = 1; i <= N; i++)
    {
        scanf("%I64d %I64d", &array[i][0], &array[i][1]);
    }

    if(s == t)
    {
        puts("0");
        return  0;
    }
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(mat[i][j] < INF && j != i)
            {
                g[i][len[i]++] = j;
            }
        }
    }


    for(int i = 1; i <= N; i++)
    {
        priority_queue<pll, vector<pll>, greater<pll> > q;
        for(int j = 1; j <= N; j++)
        d[j] = INF;
        d[i] = 0;
        q.push(make_pair(d[i], i));
        while(!q.empty())
        {
            int x = q.top().second;
            q.pop();
            for(int j = 0; j < len[x]; j++)
            {
                int y = g[x][j];
                if(d[y] > d[x] + mat[x][y])
                {
                    d[y] = d[x] + mat[x][y];
                    q.push(make_pair(d[y], y));
                }
            }
        }
        for(int j = 1; j <= N; j++)
        aMat[i][j] = d[j];
    }
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            mat[i][j] = aMat[i][j];
        }
    }
//    for(int i = 1; i <= N; i++)
//    {
//        for(int j = 1; j <= N; j++)
//        {
//            printf("%I64d ", mat[i][j]);
//        }
//        puts("");
//    }

    for(int i = 1; i <= N; i++)
    len[i] = 0;

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(mat[i][j] <= array[i][0] && j != i)
            {
                g[i][len[i]++] = j;
            }
        }
    }




    for(int i = 1; i <= N; i++)
    d[i] = INF;

    d[s] = 0;

    priority_queue<pll, vector<pll>, greater<pll> > q;
    q.push(make_pair(d[s], s));

    while(!q.empty())
    {
        int x = q.top().second;
        q.pop();



        for(int i = 0; i < len[x]; i++)
        {
            int y = g[x][i];
            if(d[y] > d[x] + array[x][1])
            {
                d[y] = d[x] + array[x][1];
                q.push(make_pair(d[y], y));
            }
        }
    }

    if(INF == d[t])
    {
        puts("-1");
    }
    else
    {
        printf("%I64d\n", d[t]);
    }




    return 0;
}
