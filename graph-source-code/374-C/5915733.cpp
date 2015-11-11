//Language: GNU C++


#include <iostream>

using namespace std;

bool f;
char num[1100][1100];
int ans[1100][1100];
bool cycle[1100][1100];
const int dx[] = {1,0,-1,0};
const int dy[] = {0,-1,0,1};
const char dima[] = {'D','I','M','A'};
int cnt=0;

int dfs(int x, int y)
{
	cnt ++;
	int cont = cnt;
	if(cycle[x][y])
	{
		f = true;
		return 0;
	}
	if(f) return 0;
	if(ans[x][y] != 0) return ans[x][y];

	int dim;
	if(num[x][y] == 'D') dim = 0;
	if(num[x][y] == 'I') dim = 1;
	if(num[x][y] == 'M') dim = 2;
	if(num[x][y] == 'A') dim = 3;

	int maxi=0;
	cycle[x][y]=true;
	for(int i = 0; i < 4; i++)
	{
		if(num[x+dx[i]][y+dy[i]] == dima[(dim + 1)%4])
		{
			maxi = max(maxi,dfs(x+dx[i],y+dy[i]));
		}
	}
	cycle[x][y]=false;

/*	ans[x][y] = maxi + 1;
	if(cont == 1)
	{
		for(int i = 0; i < 5;i++)
		{
			for(int j = 0; j < 5; j++)
			{
				cout << ans[i][j] << "\t";
			}
			cout << endl;
		}
	}*/

	ans[x][y] = maxi +1;
	return maxi+1;

}

int main()
{
	int n,m;
	cin >> n >> m;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> num[i][j];
		}
	}

	int maxi=0, d=0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if (num[i][j] == 'D')
			{
				 d = dfs(i,j);
				 if(f)
				 {
					 cout << "Poor Inna!";
					 return 0;
				 }
		//		 cout << "d: " << d << endl;
			}
			if(d > maxi)
			{
				maxi = d;
			}
		}
	}
	if(maxi < 4)
	{
		cout << "Poor Dima!";
		return 0;
	}
	cout << maxi / 4;
}
