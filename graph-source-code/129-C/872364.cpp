//Language: GNU C++


#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

char a[8][8];
int d[9][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}, {0, 0}};
vector< pair<int, int> > statues;
int ds[8][8][32];
int dp[8][8][32];

bool isValid(int x, int y)
{
	return x >= 0 && y >= 0 && x < 8 && y < 8;
}

int go(int x, int y, int move)
{
	if(x == 0 && y == 7)
		return 1;
	if(move >= 32)
		return 0;
	if(dp[x][y][move] != -1)
		return dp[x][y][move];
	int res = 0;
	for(int i = 0; i < 9; i++)
	{
		int nextx = x + d[i][0];
		int nexty = y + d[i][1];
		if(isValid(nextx, nexty) && !ds[nextx][nexty][move] && !ds[nextx][nexty][move + 1])
		{
			res = go(nextx, nexty, move + 1);
			if(res == 1)
				break;
		}
	}
	dp[x][y][move] = res;
	return res;
}

int main()
{
	//freopen("test.txt", "r", stdin);
	memset(ds, 0, sizeof(ds));
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			cin >> a[i][j];
			if(a[i][j] == 'S')
				statues.push_back(make_pair(i, j));
		}
	}
	for(int i = 0; i < statues.size(); i++)
	{
		int x = statues[i].first;
		int y = statues[i].second;
		int move = 0;
		for(int j = x; j < 8; j++)
		{
			ds[j][y][move++] = 1;
		}
	}
	if(go(7, 0, 0))
		cout << "WIN" << endl;
	else
		cout << "LOSE" << endl;
	return 0;
}