//Language: GNU C++


#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char next[500];
char Map[1005][1005];
bool vis[1005][1005];
int dp[1005][1005];
int dir[4][2] = {{ -1, 0} , {1, 0} , {0, -1} , {0, 1}};
int n , m , cnt;
#define INF 60000000
int dfs(int x, int y, char str)
{
	if (dp[x][y] != -1)
	{
		return dp[x][y];
	}
	int xx , yy , t;
	int cnt = 0;

	for (int i = 0; i < 4; ++i)
	{
		xx = x + dir[i][0];
		yy = y + dir[i][1];
		if (xx < 0 || yy < 0 || xx >= n || yy >= m || Map[xx][yy] != next[str])
		{
			continue;
		}
		if (vis[xx][yy])
		{
			cnt = INF;
		}
		else
		{
			vis[xx][yy] = 1;
			t = dfs(xx , yy , Map[xx][yy]);
			vis[xx][yy] = 0;
			cnt = max(cnt , t);
		}
	}
	dp[x][y] = cnt + 1;
	return dp[x][y];
}
int main()
{
	int ans , t;
	next['D'] = 'I';
	next['I'] = 'M';
	next['M'] = 'A';
	next['A'] = 'D';
	while (scanf("%d%d", &n, &m) != EOF)
	{
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", Map[i]);
		}
		memset(dp, -1, sizeof(dp));
		memset(vis, 0, sizeof(vis));
		cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (Map[i][j] == 'D' && dp[i][j] == -1)
				{
					vis[i][j] = 1;
					t = dfs(i , j , 'D');
					cnt = max(cnt , t / 4);
					vis[i][j] = 0;
				}
			}
		}
		if (cnt == 0)
		{
			cout << "Poor Dima!" << endl;
		}
		else
			if (cnt >= INF / 4)
			{
				cout << "Poor Inna!" << endl;
			}
			else
			{
				printf("%d\n", cnt);
			}
	}
	return 0;
}

 		 			 			    					 		      	