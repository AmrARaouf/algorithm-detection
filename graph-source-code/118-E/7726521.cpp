//Language: GNU C++0x


#include <cstdio>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

const int MAX_N = 100007;
const int MAX_M = 600007;

typedef pair<int,int> pii;

int n, m;
int head[MAX_N], edgecnt;
struct Edge {
	int v, nxt;
	Edge () {

	}
	Edge(int _v, int _nxt) {
		v = _v, nxt = _nxt;
	}
};
Edge G[MAX_M];
bool bridge, vis[MAX_M];
int low[MAX_N], pre[MAX_N], dfs_clock;
set<pii> ans;

void addedge(int u, int v) {
	G[edgecnt] = Edge(v, head[u]);
	head[u] = edgecnt++;
}

void dfs(int u) {
	low[u] = pre[u] = ++dfs_clock;
	for (int i = head[u]; ~i; i = G[i].nxt) {
		int v = G[i].v;
		if (vis[i]) continue;
		vis[i] = vis[i ^ 1] = true;
		ans.insert(make_pair(u, v));
	//rintf("qqq %d %d\n", u, v);
		if (!pre[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else low[u] = min(low[u], pre[v]);
		if (low[v] > pre[u]) {
			bridge = true;
			return ;
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	memset(head, -1, sizeof head);
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		addedge(u, v);
		addedge(v, u);
	}
	dfs(1);
	if (bridge == 1) puts("0");
	else {
		for (set<pii>::iterator it = ans.begin(); it != ans.end(); ++it) {
			printf("%d %d\n", it->first, it->second);
		}
	}
	return 0;
}