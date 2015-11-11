//Language: GNU C++


#include <set>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 55;
const int M = N * N << 1;
const int INF = 0x77777777;

struct Dinic {
	struct Edge {
		int u, v, c, f, nx;
		Edge() {}
		Edge(int u, int v, int c, int f, int nx) : u(u), v(v), c(c), f(f), nx(nx) {}
	} edge[M];
	int s, t, eh[N], ec;
	bool vis[N];
	int dis[N], q[M];
	void init(int n = N) {
		memset(eh, -1, sizeof(eh));
		ec = 0;
	}
	void addedge(int u, int v, int c) {
		edge[ec] = Edge(u, v, c, 0, eh[u]);
		eh[u] = ec++;
		edge[ec] = Edge(v, u, 0, 0, eh[v]);
		eh[v] = ec++;
	}
	bool bfs() {
		memset(vis, 0, sizeof(vis));
		int qh, qt;
		qh = qt = 0;
		dis[q[qt++] = s] = 0;
		vis[s] = 1;
		while (qh < qt) {
			int u = q[qh++];
			for (int i = eh[u]; ~i; i = edge[i].nx) {
				Edge &e = edge[i];
				if (vis[e.v]) continue;
				if (e.c - e.f <= 0) continue;
				dis[e.v] = dis[u] + 1;
				vis[q[qt++] = e.v] = 1;
			}
		}
		return vis[t];
	}
	int dfs(int u, int mx) {
		if (mx == 0 || u == t) return mx;
		int ret = 0;
		for (int i = eh[u]; ~i; i = edge[i].nx) {
			Edge &e = edge[i];
			if (dis[e.v] != dis[u] + 1) continue;
			if (e.c - e.f <= 0) continue;
			int f = dfs(e.v, min(mx, e.c - e.f));
			if (f > 0) {
				e.f += f;
				edge[i ^ 1].f -= f;
				ret += f;
				mx -= f;
				if (mx <= 0) break;
			}
		}
		return ret;
	}
	int flow;
	int cal(int S, int T) {
		s = S, t = T;
		int ret = 0;
		while (bfs()) ret += dfs(s, INF);
		return flow = ret;
	}
	int pre[N];
	int expand() {
		int qh, qt;
		qh = qt = 0;
		memset(dis, 0x77, sizeof(dis));
		dis[q[qt++] = s] = 0;
		while (qh < qt) {
			int u = q[qh++];
			for (int i = eh[u]; ~i; i = edge[i].nx) {
				if (i & 1) continue;
				Edge &e = edge[i];
				//cout << u << ' ' << e.v << ' ' << e.c << ' ' << e.f << endl;
				if (e.c <= e.f) {
					if (dis[e.v] > dis[u] + 1) {
						dis[e.v] = dis[u] + 1;
						q[qt++] = e.v;
						pre[e.v] = i;
					}
				} else {
					if (dis[e.v] > dis[u]) {
						dis[e.v] = dis[u];
						q[qt++] = e.v;
						pre[e.v] = i;
					}
				}
			}
		}
		int u = t, tmp = dis[t];
		while (u != s) {
			Edge &e = edge[pre[u]];
			if (e.c <= e.f) e.c++;
			u = e.u;
		}
		cal(s, t);
		return tmp;
	}
} mxf;

int main() {
	int n, k, x;
	while (cin >> n >> k) {
		mxf.init();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> x;
				if (x) mxf.addedge(i, j, x);
			}
		}
		int ans = mxf.cal(0, n - 1);
		//cout << "ans " << ans << endl;
		if (ans) {
			while (k > 0) {
				int t = mxf.expand();
				if (k >= t) ans++;
				else break;
				k -= t;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
