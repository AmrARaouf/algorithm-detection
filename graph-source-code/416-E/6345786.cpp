//Language: GNU C++


#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <queue>

#define PB push_back
#define MP make_pair
#pragma comment(linker, "/STACK:16777216")

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

/*
inline int read_int()
{
    register char c;
    while ((c=getchar_unlocked()) < 48 || c > 57);
    int p = c-48;
    while ((c=getchar_unlocked()) >= 48 && c <= 57) p=p*10+c-48;
    return p;
}
*/

/*
struct matrix
{
    int64 a[2][2];
};

matrix mul(matrix A,matrix B)
{
    matrix C;
    memset(C.a,0,sizeof(C.a));
    for (int i = 0; i <= 1;i ++)
        for (int j = 0; j <= 1; j++)
            for (int k = 0; k <= 1; k++)
                C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j]) % md;
    return C;
}

matrix pow(matrix A, int64 p)
{
    if (p == 1) return A;
    if (p & 1) return mul(A,pow(A,p-1));
    matrix X = pow(A,p >> 1);
    return mul(X,X);
}



int64 pow(int64 x, int64 y, int64 z)
{
    if (y == 0) return 1%z;
    if (y == 1) return x%z;
    if (y & 1) return (x*pow(x,y-1,z))%z;
    int64 temp = pow(x,y>>1,z);
    return (temp*temp)%z;
}
*/

int dist[501][501];
int INF = 1000000000;
int s[501][501];
int c[501][501];

int main()
{

   	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

    int n,m;
    cin>>n>>m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            dist[i][j] = INF;
            c[i][j] = INF;
        }

    //for (int i = 1; i <= n; i++) dist[i][i] = 0;

    memset(s,0,sizeof(s));

    for (int i = 1; i <= n; i++)
    {
        dist[i][i] = 0;
        //c[i][i] = 0;
    }

    for (int i = 1; i <= m; i++)
    {
        int x,y,l;
        cin>>x>>y>>l;
        dist[x][y] = l;
        dist[y][x] = l;
        c[x][y] = l;
        c[y][x] = l;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                //if (dist[i][k] < INF && dist[k][j] < INF)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }


    memset(s,0,sizeof(s));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                if (dist[i][k] + c[k][j] == dist[i][j]) s[i][j]++;

    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            int ans = 0;
            for (int k = 1; k <= n; k++)
                if (dist[i][k] < INF && dist[k][j] < INF)
                if (dist[i][k] + dist[k][j] == dist[i][j])
                    ans += s[i][k];
            cout<<ans<<" ";
        }

	return 0;
}
