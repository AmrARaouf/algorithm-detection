//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 110, cs = 1073741823;
int di[maxn][maxn];
long long way[maxn][maxn];
int N, M;

void read()
{
	scanf("%d%d", & N, & M);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j) if (i == j) di[i][j] = 0, way[i][j] = 1;
		else di[i][j] = cs;
	for (int i = 1; i <= M; ++i)
	{
		int a, b;
		scanf("%d%d", & a, & b);
		di[a][b] = di[b][a] = 1; way[a][b] = way[b][a] = 1;
	}
}

void getans()
{
	for (int k = 1; k <= N; ++k)
		for (int i = 1; i <= N; ++i) if (k != i)
			for (int j = 1; j <= N; ++j) if ((i != j) && (k != j))
			{
				if (di[i][j] > di[i][k] + di[k][j])
				{
					di[i][j] = di[i][k] + di[k][j];
					way[i][j] = way[i][k] * way[k][j];
				}
				else if (di[i][j] == di[i][k] + di[k][j])
					way[i][j] += way[i][k] * way[k][j];
			}
			
	long long ans = 0;
	for (int i = 1; i < N; ++i)
	{
		long long sum = 0;
		for (int j = 1; j <= N; ++j) 
		{
			if ((di[i][j] == 1) && (di[1][i] + 1 + di[j][N] == di[1][N]))
				sum += way[1][i] * way[j][N];
			if ((di[i][j] == 1) && (di[1][j] + 1 + di[i][N] == di[1][N]))
				sum += way[1][j] * way[i][N];
		}
		ans = max(ans, sum);
	}
	
	printf("%.9f\n", (double)ans / way[1][N]);
}

int main()
{
	read();
	getans();
}