//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#define REP(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;

/*
const int MAX_N = (100000 + 100);
int N, cnt, vis[MAX_N << 1], degree[MAX_N << 1];
vector<int > g[MAX_N];
vector<int > ans;
map<int, int > mp, remp;

bool dfs(int u, int fa)
{
	if ((int)ans.size() == N) return true;
	REP(i, 0, (int)g[u].size()) {
		if (g[u][i] != fa && !vis[g[u][i]]) {
			vis[g[u][i]] = 1;
			ans.push_back(remp[g[u][i]]);
			if (dfs(g[u][i], u)) return true;
			vis[g[u][i]] = 0;
			ans.pop_back();
		}
	}
	return false;
}

int main()
{
	cin >> N; cnt = 0;
	FOR(i, 1, N) {
		int u, v; cin >> u >> v;
		if (mp.find(u) == mp.end()) mp[u] = ++cnt;
		if (mp.find(v) == mp.end()) mp[v] = ++cnt;
		remp[mp[u]] = u, remp[mp[v]] = v;
		g[mp[u]].push_back(mp[v]);
		g[mp[v]].push_back(mp[u]);
		++degree[mp[u]], ++degree[mp[v]];
	}
	N = cnt;
	FOR(i, 1, N) if (degree[i] == 1) {
		vis[i] = 1;
		ans.push_back(remp[i]);
		dfs(i, -1);
		break;
	}
	REP(i, 0, (int)ans.size()) cout << ans[i] << ' ';
	return 0;
}
*/


map<int, vector<int > > g;
map<int, bool> vis;
int N, st;

void dfs(int u)
{
	vis[u] = true;
	cout << u << ' ';
	REP(i, 0, (int)g[u].size()) {
		int v = g[u][i];
		if (!vis[v]) dfs(v);
	}
}

int main()
{
	cin >> N;
	FOR(i, 1, N) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (map<int, vector<int> >::const_iterator it = g.begin(); it != g.end(); ++it) {
		if (it->second.size() == 1) st = it->first;
	}
	dfs(st);
	return 0;
}