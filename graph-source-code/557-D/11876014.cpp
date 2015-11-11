//Language: GNU C++


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <math.h>
using namespace std;
#pragma warning(disable:4996)
typedef long long LL;                   
const int INF = 1<<30;
/*

*/
const int N = 1000000 + 10;
vector<int> g[N];
int d[N];
int color[N];
bool hasOddCycle;
void dfs(int u, int fa,int &cnt, int &black)
{
	
	for (int i = 0; i < g[u].size(); ++i)
	{
		int v = g[u][i];
		if (v == fa) continue;
		if (color[v] == -1)
		{
			color[v] = color[u] ^ 1;
			black += color[v];
			cnt += 1;
			dfs(v, u, cnt, black);
		}
		else if (color[u] == color[v])
		{
			hasOddCycle = true;
		}
		
	}
}
int main()
{
	int n, m, a, b;
	bool flag = false;
	scanf("%d%d", &n, &m);
	if (m == 0)
	{
		printf("%d %I64d\n", 3, (LL)n*(n - 1)*(n-2) / 6);
		return 0;
	}
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
		d[a]++;
		d[b]++;
		if (d[a]>1 || d[b] > 1)
			flag = true;
	}
	if (!flag)
	{
		printf("%d %I64d\n", 2, (LL)(n - 2 * m)*m + (LL)2 * m*(m - 1));
		return 0;
	}
	memset(color, -1, sizeof(color));
	LL ans = 0;
	int cnt, black;
	for (int i = 1; i <= n; ++i)
	{
		if (color[i] == -1)
		{
			cnt = black = 1;
			color[i] = 1;
			dfs(i, -1, cnt, black);
			ans += (LL)black*(black - 1) / 2 + (LL)(cnt - black)*(cnt - black - 1) / 2;
		}
		if (hasOddCycle)
			break;
	}
	if (hasOddCycle)
		printf("%d %d\n", 0, 1);
	else
		printf("%d %I64d\n", 1, ans);

    return 0;
}