//Language: GNU C++11


#include <bits/stdc++.h>
#define X first
#define Y second
#define int long long
#define pb push_back

using namespace std;

typedef pair<int, int> pii;

const int maxn = 100 * 1000 + 100;
const int lg = 20;

int n, m;
vector<pii> q;
int par[maxn], sz[maxn], bs[maxn];
int boss[maxn], rc[maxn], cnt = 0;
vector<int> adj[maxn];
int par2[maxn][lg + 5], h[maxn];
vector<int> ver;


void merge(int u, int v);
int find_par(int u);
void dfs(int v);
int lca(int u, int v);

main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	fill(par, par + n, -1);
	fill(sz, sz + n, 1);
	for (int i =0; i < n; i++)
		bs[i] = i;
	for (int i = 0; i < m; i++) {
		int t, x, y;
		cin >> t;
		if (t == 1) {
			cin >> x >> y;
			x--, y--;
			merge(x, y);
			adj[y].pb(x);
		}
		else if (t == 2) {
			cin >> x;
			x--;
			rc[cnt] = x;
			x = find_par(x);
		//	cerr << bs[x] << endl;
			boss[cnt] = bs[x];
			cnt++;
		}
		else {
			cin >> x >> y;
			x--, y--;
			q.pb(pii(x, y));
		}
	}

	for (int i = 0; i < n; i++)
		fill(par2[i], par2[i] + lg, -1);
	for (int i = 0; i < n; i++)
		if (par[i] == -1)
			dfs(i);
	for (int v : ver) {
		for (int i = 1; i <= lg && (1<<i) <= h[v]; i++)
			par2[v][i] = par2[par2[v][i - 1]][i - 1];
	}
	for (pii p : q) {
		int v = p.X, ind = p.Y;
	//	cerr << rc[ind] << endl;
		int v2 = find_par(v);
		if (v2 != find_par(rc[ind])) {
			cout << "NO\n";
			continue;
		}

		if (lca(rc[p.Y], v) == v && lca(boss[p.Y], v) == boss[p.Y]) 
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}
			
void merge(int u, int v) {
	u = find_par(u);
	v = find_par(v);
	if (u == v)
		return;
	int b = bs[v];
	if (sz[v] < sz[u])
		swap(u, v);
	par[u] = v;
	bs[v] = b;
}

int find_par(int u) {
	return (par[u] == -1? u : (par[u] = find_par(par[u])));
}

void dfs(int v) {
	ver.pb(v);
	for (int u : adj[v]) {
		h[u] = h[v] + 1;
		par2[u][0] = v;
		dfs(u);
	}
}

int lca(int u, int v) {
	if (u == v)
		return u;
	if (h[u] > h[v]) 
		swap(u, v);
	for (int i = lg; i >= 0; i--) {
		if (h[v] - (1<<i) >= h[u])
			v = par2[v][i];
	}
	if (u == v)
		return u;
	for (int i = lg; i >= 0; i--) {
		if (h[v] >= (1<<i) && par2[v][i] != par2[u][i]) 
			u = par2[u][i], v = par2[v][i];
	}
	return par2[v][0];
}


