//Language: GNU C++


#include <iostream>

using namespace std;

long long now[505][505], past[505][505];
long long w[505][505], x[505], ans[505];
bool mark[505];

int main()
{
	int n;
	cin >> n;
	for (int j = 0; j < n; j++)
		for (int i = 0; i < n; i++)
			 cin >> w[i][j];
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
		x[i]--;
		mark[i] = true;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			past[i][j] = w[i][j];
	for (int k = 1; k <= n; k++)
	{
		mark[x[n - k]] = false;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				now[i][j] = min(past[i][j], past[i][x[n - k]] + past[x[n - k]][j]);
				if (!mark[i] && !mark[j])
					ans[n - k] += now[i][j];
			}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				past[i][j] = now[i][j];
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
	cout << endl;
}

