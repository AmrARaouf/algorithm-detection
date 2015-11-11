//Language: GNU C++


#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <sstream>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include <queue>
#include <map>

#define pb push_back
#define mp make_pair
#define f1 first
#define f2 second
#define X first
#define Y second

using namespace std;

typedef long long LL;
typedef pair <int, int> PII; 
typedef vector <int> VINT;

const int maxn = 1000 * 100 + 5;
const int mod = 1000 * 1000 * 1000 + 7;

VINT adj[maxn], adjr[maxn];
int mark[maxn], ans[maxn];
int st[maxn];

void dfs1(int x)
{
	mark[x] = 1;
	ans[x]++;
//	if (st[x] == 2)
//		return;
	for (int i = 0; i < (int)adj[x].size(); i++)
	{
		int u = adj[x][i];
		if (!mark[u])
			dfs1(u);
	}
}
void dfs2(int x)
{
	mark[x] = 1;
	ans[x]++;
	if (st[x] == 1)
		return;
	for (int i = 0; i < (int)adjr[x].size(); i++)
	{
		int u = adjr[x][i];
		if (!mark[u])
			dfs2(u);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> st[i];
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].pb(v);
		adjr[v].pb(u);
	}
	for (int i = 0; i < n; i++)
		if (!mark[i] && st[i] == 1)
			dfs1(i);
	for (int i = 0; i < n; i++)
		mark[i] = 0;
	for (int i = 0; i < n; i++)
		if (!mark[i] && st[i] == 2)
			dfs2(i);
	for (int i = 0; i < n; i++)
		if (ans[i] == 2)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	return 0;
}

