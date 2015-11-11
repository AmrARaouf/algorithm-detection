//Language: GNU C++


#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <cmath>
#include <set>
#define ll long long
using namespace std;
const int INF = 1000000007;
const int MAX = 300001;
vector <int> adj[MAX];
bool p[MAX];
int d(int v)
{
	int ans = 0;
	for (int i = 0; i < adj[v].size(); i++)
	{
		int u = adj[v][i];
		if (p[u] == p[v])
			ans++;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int k = 0; k < 50; k++)
		for (int i = 1; i <= n; i++)
		{
			if (d(i) > 1)
				p[i] = !p[i];
			for (int j = 0; j < adj[i].size(); j++)
				if (d(j) > 1)
					p[j] = !p[j];
		}
	for (int i = 1; i <= n; i++)
		cout << p[i];
 	return 0;
}
