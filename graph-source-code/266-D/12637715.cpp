//Language: GNU C++


#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 220, inf = 1e9;

int n, m, src, d[N][N], g[N][N], ord[N], ans;

bool cmp(int i, int j) {
	return d[src][i] < d[src][j];
}
void solve(int u, int v, int w) {
	int lmx, rmx = 0;
	for (int ii = n; ii >= 1; --ii) {
		int i = ord[ii];
		lmx = d[i][u];
		int p = w + rmx - lmx;
		if (p < 0) p = 0;
		if (p > w * 2) p = w * 2;
		ans = min(ans, max(p + lmx * 2, w * 2 - p + rmx * 2));
		rmx = max(rmx, d[i][v]);
	}
	ans = min(ans, rmx * 2);
}
int main() {
	
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			if (i != j) g[i][j] = inf;
		}
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		g[u][v] = g[v][u] = w;
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			d[i][j] = g[i][j];
		}
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
	ans = inf;
	for (int i = 1; i <= n; ++i) {
		src = i;
		for (int j = 1; j <= n; ++j) ord[j] = j;
		sort(ord + 1, ord + n + 1, cmp);

		for (int j = i + 1; j <= n; ++j)
			if (g[i][j] != inf) {
				solve(i, j, g[i][j]);
			}
	}
	printf("%.8lf\n", 0.5 * ans);
}
