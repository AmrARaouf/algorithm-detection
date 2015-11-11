//Language: GNU C++


#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100+10;

bool g[MAXN][MAXN];
int n, m, a, b, ans;

int main()
{
	cin >> n >> m;
	for (int i = 0 ; i < m ; i++)
	{
		cin >> a >> b;
		g[a][b] = 1;
		g[b][a] = 1;
	}
	for (int i = 1 ; i <= n ; i++)
	{
		vector <int> temp;
		for (int j = 1 ; j <= n ; j++)
		{
			int cnt = 0;
			for (int k = 1 ; k <= n ; k++)
				if (g[j][k])
					cnt++;
			if (cnt == 1)
				temp.push_back(j);
		}
		if ((int)temp.size())
			ans++;
		for (int j = 0 ; j < (int)temp.size() ; j++)
			for (int k = 1 ; k <= n ; k++)
			{
				g[temp[j]][k] = 0;
				g[k][temp[j]] = 0;
			}
	}
	cout << ans << endl;
	return 0;
}
