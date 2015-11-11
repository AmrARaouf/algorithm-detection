//Language: GNU C++


#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
struct Pos{
	int x;
	int y;
	int second;
};
char map[10][10]; 
int addx[9] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 };
int addy[9] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };
bool flag;
void dfs(int x, int y, int step)
{
	if (step >= 7)
	{
		flag = true;
		return;
	}
	int nx;
	int ny;
	for (int i = 0; i < 9; i++)
	{
		nx = addx[i] + x;
		ny = addy[i] + y;
		//下一步没有雕像	无法通行			ny-step
		//下一步的同列 上一格没有雕像 安全性	ny-step-1
		if (nx >= 1 && nx <= 8 && ny >= 1 && ny <= 8 )
		{//范围合法
			if (nx - step >= 1 && map[nx-step][ny] != 'S')
			{//可行
				if (nx == 1 || nx - step >= 2 && map[nx-step-1][ny] != 'S')
					dfs(nx, ny, step + 1);
			}
		}
	}
}



int main()
{
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 8; j++)
			cin >> map[i][j];
		cin.get();
	}
	flag = false;
	dfs(8, 1, 0);
	if (flag)
		cout << "WIN" << endl;
	else
		cout << "LOSE" << endl;
	return 0;
}

   		 		 		  	  				   	  				