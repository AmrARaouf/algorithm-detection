//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;

struct state {
	int u, c;
	state(int u, int c) :
			u(u), c(c) {
	}
	bool operator<(const state&e) const {
		return e.c < c;
	}
};

const int N = 1e5;
vector<state> g[N];
vector<int> in[N];
int n, m, cost[N];
bool vis[N];

int Dijkstra(int src, int tar) {
	for (int i = 0; i < n; ++i)
		cost[i] = 2e9;
	priority_queue<state> qu;
	qu.push(state(src, 0));
	cost[src] = 0;
	while (!qu.empty()) {
		state e = qu.top();
		qu.pop();
		if (e.u == tar)
			return e.c;
		if (vis[e.u])
			continue;
		vis[e.u] = true;
		int k = lower_bound(in[e.u].begin(), in[e.u].end(), e.c) - in[e.u].begin(), add = 0;
		for (size_t i = k; i < in[e.u].size(); ++i) {
			if (e.c + add != in[e.u][i])
				break;
			++add;
		}
		for (size_t i = 0; i < g[e.u].size(); ++i) {
			int u = g[e.u][i].u;
			int c = e.c + add + g[e.u][i].c;
			if (vis[u] || c >= cost[u])
				continue;
			cost[u] = c;
			qu.push(state(u, c));
		}
	}
	return -1;
}

int main() {
//	freopen("a", "r", stdin);
	scanf("%d%d", &n, &m);
	while (m--) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		--u;
		--v;
		g[u].push_back(state(v, c));
		g[v].push_back(state(u, c));
	}
	for (int i = 0, x; i < n; ++i) {
		scanf("%d", &x);
		in[i].resize(x);
		for (int j = 0; j < x; ++j)
			scanf("%d", &in[i][j]);
	}
	printf("%d\n", Dijkstra(0, n - 1));
	return 0;
}