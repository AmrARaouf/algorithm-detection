//Language: GNU C++11


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <unordered_map>
#include <set>
#include <list>
#include <unordered_set>
#include <queue>
#include <stack>
#include <utility>
#include <string.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cctype>

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef long lint;

#define MP make_pair
#define PB push_back
#define EPS 0.0000001
#define ALL(a) a.begin(), a.end()

const int INF = 1000 * 1000 * 1000;
const int MOD = 1000 * 1000 * 1000 + 7;
const lint INF_L = 1000 * 1000 * 1000;
const ll INF_LL = 1LL * INF_L * INF_L;
const ll MOD_LL = 1000000000007LL;


ll gcd(ll a, ll b)
{
	while (b)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}

ll lcm(ll a, ll b)
{
	return (a / gcd(a, b)) * b;
}

vector < set <int> > g;
int n;

int d[3001][3001];

void bfs(int start)
{
	queue <pair <int, int>> q;
	q.push(MP(start, 0));
	vector <bool> u(n, false);
	while (q.size())
	{
		auto p = q.front();
		u[p.first] = true;
		if (d[start][p.first] == -1 || d[start][p.first] > p.second)
		{
			d[start][p.first] = d[p.first][start] = p.second;
		}
		q.pop();
		for (auto v : g[p.first])
		{
			if (!u[v])
			{
				q.push(MP(v, p.second + 1));
			}
		}
	}
}

#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int m, a, b, s1, t1, l1, s2, t2, l2;
	cin >> n >> m;
	g.resize(n);
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		--a, --b;
		g[a].insert(b);
		g[b].insert(a);
		//g[a][b] = g[b][a] = true;
	}
	cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
	--s1, --t1, --s2, --t2;
	memset(d, 255, sizeof(d));
	for (int i = 0; i < n; ++i)
		bfs(i);

	int ans = -1;
	if (d[s1][t1] <= l1 && d[s2][t2] <= l2)
	{
		ans = m - d[s1][t1] - d[s2][t2];
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (d[s1][i] != -1 && d[t1][j] != -1 && d[s2][i] != -1 && d[t2][j] != -1 && d[i][j] != -1
				&& d[s1][i] + d[t1][j] + d[i][j] <= l1 && d[s2][i] + d[t2][j] + d[i][j] <= l2)
			{
				int cur = d[s1][i] + d[t1][j] + d[s2][i] + d[t2][j] + d[i][j];
				if (ans == -1 || ans < m - cur)
				{
					ans = m - cur;
				}
			}
			swap(t1, s1);
			if (d[s1][i] != -1 && d[t1][j] != -1 && d[s2][i] != -1 && d[t2][j] != -1 && d[i][j] != -1
				&& d[s1][i] + d[t1][j] + d[i][j] <= l1 && d[s2][i] + d[t2][j] + d[i][j] <= l2)
			{
				int cur = d[s1][i] + d[t1][j] + d[s2][i] + d[t2][j] + d[i][j];
				if (ans == -1 || ans < m - cur)
				{
					ans = m - cur;
				}
			}
			swap(t1, s1);
		}
	}
	cout << ans << endl;

	return 0;
}