//Language: MS C++


#include <cstdio>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <memory.h>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <complex>

#pragma comment(linker, "/STACK:16777216")

using namespace std;
 
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef long long LL;

const int INF = 1 << 30;
const int N = 1000000;

vvint g;
int n;
vector < pair<int, int> > vp;
int start;
int q[1100000] = {}, qh = 0, qt = 0, parent[1100000] = {};
bool used[1100000] = {};

void Bfs()
{
	q[qt++] = g[start][0];
	parent[0] = start;
	int Count = -1;
	used[start] = true;
	used[q[qh]] = true;
	printf("%d\n", n - 1);
	while (qh != qt)
	{
		Count++;
		int cur = q[qh];
		int par = parent[qh++];
		printf("2 %d %d\n", par + 1, cur + 1);
		for (int i = 0; i < g[cur].size(); i++)
			if (!used[g[cur][i]])
			{
				vp.push_back(make_pair(Count + qt - qh + 1, Count) );
				q[qt] = g[cur][i];
				parent[qt++] = cur;
				used[g[cur][i]] = true;
			}
	}
}

int main()
{
#ifndef _DEBUG
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	g.resize(n + 1);
	int from, to;
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d%d", &from, &to);
		from--;
		to--;
		g[from].push_back(to);
		g[to].push_back(from);
	}
	for (int i = 0; i < n; i++)
		if (g[i].size() == 1)
			start = i;
	Bfs();
	for (int i = 0; i < vp.size(); i++)
		printf("%d %d\n", vp[i].first + 1, vp[i].second + 1);
	return 0;
}