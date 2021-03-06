//Language: GNU C++


#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> e[100010];
int et[100010][20];
int par[100010][20];
int done[100010];
int dep[100010];
void dfs(int v) {
	for (int i = 1; i < 20; i++) {
		par[v][i] = par[par[v][i-1]][i-1];
		et[v][i] = max(et[v][i-1], et[par[v][i-1]][i-1]);
	}
	for (int i = 0; i < e[v].size(); i++) {
		int w = e[v][i];
		dep[w] = dep[v] + 1;
		dfs(w);
	}
}
int qt[100010];
int qx[100010], qy[100010];
int so[100010], ti[100010];
int main() {
	int n, m, k = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		par[i][0] = i;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &qt[i], &qx[i]);
		qx[i]--;
		if (qt[i] == 1) {
			scanf("%d", &qy[i]);
			qy[i]--;
			e[qy[i]].push_back(qx[i]);
			par[qx[i]][0] = qy[i];
			et[qx[i]][0] = i;
		} else if (qt[i] == 2) {
			ti[k] = i;
			so[k++] = qx[i];
		} else {
			scanf("%d", &qy[i]);
			qy[i]--;
		}
	}
	for (int i = 0; i < n; i++) {
		if (par[i][0] == i) {
			dfs(i);
		}
	}
	for (int i = 0; i < m; i++) {
		if (qt[i] == 3) {
			int w = qx[i], v = so[qy[i]], tt = -1;
			int diff = dep[v] - dep[w];
			if (diff > 0) {
				for (int j = 0; j < 20; j++) {
					if (diff >> j & 1) {
						tt = max(et[v][j], tt);
						v = par[v][j];
					}
				}
			}
			if (tt < ti[qy[i]] && v == w) {
				puts("YES");
			} else {
				puts("NO");
			}
		}
	}
	return 0;
}
