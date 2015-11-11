//Language: GNU C++0x



#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <cassert>

#ifdef LOCAL 
#define ATHFILE(f) freopen(f ".in", "r", stdin), freopen(f ".my", "w", stdout)
#else
#define ATHFILE(f)
#endif
#define DEBUGT(t) if (_t == t) _asm int 3
typedef long long LL;
typedef long double LD;
inline int RD() { int x; scanf("%d", &x); return x; }
inline char RDA() { char ch; while ((ch = getchar()) && !isalpha(ch)); return ch; }
#define Rush for (int tests = RD(), _t = 1; _t <= tests; ++_t)
#define ZMV(x, v) memset((x), (v), sizeof(x))
#define ZM(x) memset((x), 0, sizeof(x))
#define SZ(v) (int)(v.size())
#define ALL(v) v.begin(), v.end()
const int maxint = 0x7f7f7f7f;
const int mod = 1000000007;
const double eps = 1e-10, pi = acos(-1.0);

using namespace std;

const int maxn = 100001;
int n, m, dfn[maxn], low[maxn], ind, color, block[maxn], size[maxn];
vector<int> edge[maxn], tree[maxn];
stack<int> sk;

void tarjan(int u, int pa = -1) {
	int v;
	dfn[u] = low[u] = ++ind;
	sk.push(u);
	for (auto it = edge[u].begin(); it != edge[u].end(); ++it) {
		v = *it;
		if (v == pa) continue;
		if (!dfn[v]) {
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
		} else low[u] = min(low[u], dfn[v]);
	}
	if (dfn[u] == low[u]) {
		++color;
		do {
			v = sk.top();
			block[v] = color; ++size[color];
			sk.pop();
		} while (u != v);
	}
}

const int logn = 26;
int parent[maxn], lca[logn][maxn], depth[maxn], cnt[maxn];

void dfs(int u, int pa = -1) {
	cnt[u] = (pa == -1 ? 0 : cnt[pa]) + (size[u] > 1 ? 1 : 0);
	for (auto it = tree[u].begin(); it != tree[u].end(); ++it) {
		if (*it != pa) {
			parent[*it] = u;
			depth[*it] = depth[u] + 1;
			dfs(*it, u);
		}
	}
}

void initLCA(int n) {
	dfs(1);
	for (int i = 1; i <= n; ++i) lca[0][i] = parent[i];
	for (int j = 1; j < logn; ++j) {
		for (int i = 1; i <= n; ++i) {
			lca[j][i] = lca[j - 1][lca[j - 1][i]];
		}
	}
}

int LCA(int x, int y) {
	if (depth[x] < depth[y]) swap(x, y);
	for (int i = logn - 1; i >= 0; --i) {
		if (depth[x] - (1 << i) >= depth[y]) x = lca[i][x];
	}
	if (x == y) return x;
	for (int i = logn - 1; i >= 0; --i) {
		if (lca[i][x] != lca[i][y]) {
			x = lca[i][x], y = lca[i][y];
		}
	}
	return lca[0][x];
}

int two[maxn];

int main() {
	two[0] = 1;
	for (int i = 1; i < maxn; ++i) two[i] = two[i - 1] * 2 % mod;
	n = RD(); m = RD();
	while (m--) {
		int u = RD(), v = RD();
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	tarjan(1);
	for (int i = 1; i <= n; ++i) {
		for (auto it = edge[i].begin(); it != edge[i].end(); ++it) {
			int j = *it;
			if (block[i] != block[j]) tree[block[i]].push_back(block[j]);
		}
	}
	for (int i = 1; i <= color; ++i) {
		sort(ALL(tree[i]));
		tree[i].erase(unique(ALL(tree[i])), tree[i].end());
	}
	initLCA(color);
	int q = RD();
	while (q--) {
		int u = RD(), v = RD(), l;
		u = block[u], v = block[v];
		l = LCA(u, v);
		int ans = cnt[u] + cnt[v] - 2 * cnt[l];
		if (size[l] > 1) ++ans;
		printf("%d\n", two[ans]);
	}
	return 0;
}
