//Language: GNU C++11


#include<iostream>
#include<algorithm>
#include<cstdio>
#include<set>
#include<string.h>
#include<string>
using namespace std;
#define MAX 4000
#define INF MAX*3
int adj[MAX][MAX], deg[MAX];
int main()
{
	ios::sync_with_stdio(0);
	int n, m;
	while (cin >> n >> m)
	{		
		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v; v--; u--;
			adj[u][v] = adj[v][u] = 1;
			deg[u]++, deg[v]++;
		}
		int ans = INF;
		for (int i = 0; i < n - 2; i++)
			for (int j = i + 1; j < n - 1; j++)
				if (adj[i][j])
					for (int k = j + 1; k < n; k++)
						if (adj[i][k] && adj[j][k])
							ans = min(ans, deg[i] + deg[j] + deg[k]);
		if (ans == INF)
			cout << "-1\n\n";
		else
			cout << ans - 6 << "\n\n";
	}
}