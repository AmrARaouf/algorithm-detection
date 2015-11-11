//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;

const int N = 2000, S = N * N;
vector<int> g[S];
int m, n, depth[S], height[S], f[S], dtime[S];
string mat[N];

void enter() {
	cin >> m >> n;
	for(int i = 0; i < m; ++i)
		cin >> mat[i];
}

int conv(int x, int y) {
	return x * n + y;
}

void buildTrees() {
	memset(dtime, -1, sizeof dtime);
	int time = 0;
	for(int sx = 0; sx < m; ++sx)
		for(int sy = 0; sy < n; ++sy) {
			if(dtime[conv(sx, sy)] == -1 && mat[sx][sy] != '#') {
				int x = sx, y = sy; ++time;
				while(mat[x][y] != '#' && dtime[conv(x, y)] == -1) {
					int nx = x, ny = y;
					dtime[conv(x, y)] = time;
					switch(mat[x][y]) {
						case '>': ++ny; break;
						case '<': --ny; break;
						case '^': --nx; break;
						case 'v': ++nx; break;
						default: assert(false);
					}
					g[conv(nx, ny)].push_back(conv(x, y));
					x = nx; y = ny;
				}
				if(dtime[conv(x, y)] == time) {
					cout << -1 << endl;
					exit(EXIT_SUCCESS);
				}
			}
		}
}

void solve() {
	vector<int> roots;
	for(int i = 0; i < m; ++i)
		for(int j = 0; j < n; ++j)
			if(!g[conv(i, j)].empty() && mat[i][j] == '#')
				roots.push_back(conv(i, j));
	vector<int> treeHeight, order;
	queue<int> q;
	int ntree = roots.size(), res = 0;
	for(int i = 0; i < ntree; ++i) q.push(roots[i]);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		order.push_back(u);
		for(unsigned i = 0; i < g[u].size(); ++i) {
			q.push(g[u][i]);
			depth[g[u][i]] = depth[u] + 1;
		}
	}
	reverse(order.begin(), order.end());
	for(unsigned i = 0; i < order.size(); ++i) {
		int u = order[i], high1 = -1, high2 = -1;
		bool isRoot = i + ntree >= order.size();
		for(unsigned i = 0; i < g[u].size(); ++i) {
			int v = g[u][i];
			if(height[v] > high1) high2 = high1, high1 = height[v];
			else if(height[v] > high2 && (isRoot || height[v] != high1)) high2 = height[v];
			f[u] = max(f[u], f[v]);
		}
		if(high1 != -1) {
			height[u] = high1 + 1;
			if(high2 != -1) f[u] = max(f[u], high1 + high2 + 2 * depth[u]);
		} else height[u] = 1;
	}
	for(int i = 0; i < ntree; ++i) {
		treeHeight.push_back(height[roots[i]]);
		res = max(res, f[roots[i]]);
		res = max(res, height[roots[i]] * 2 - 3);
		res = max(res, height[roots[i]] - 1);
	}
	sort(treeHeight.rbegin(), treeHeight.rend());
	if(ntree >= 2) res = max(res, treeHeight[0] + treeHeight[1] - 2);
	cout << res << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	enter();
	buildTrees();
	solve();
	return 0;
}
