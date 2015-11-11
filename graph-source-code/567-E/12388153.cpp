//Language: GNU C++11


#include <bits/stdc++.h>

using namespace std;

typedef long long lol;
typedef pair<lol, int> pli;
typedef pair<int, int> pii;

#define FI "inp.txt"
#define FO "out.txt"
const int MAXN = 1e5 + 5;
const lol oo = 1LL << 60;
const double EPS = 1e-8;
const lol MOD = 479001599;

struct Edge {
	int u, v, w;
};

int n, m, s, t;
vector<pii> adj[MAXN];
vector<pii> radj[MAXN];
Edge e[MAXN];

lol d[MAXN], rd[MAXN];
lol way[MAXN], rway[MAXN];
priority_queue<pli, vector<pli>, greater<pli>> pq;

void dijkstra();
void rdijkstra();

int main() {
#ifndef ONLINE_JUDGE
	freopen(FI, "r", stdin);
	freopen(FO, "w", stdout);
#endif
	scanf("%d%d%d%d", &n, &m, &s, &t);
	--s;
	--t;
	int u, v, w;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &u, &v, &w);		
		--u;
		--v;
		e[i] = {u, v, w};
		adj[u].push_back({v, w});
		radj[v].push_back({u, w});
	}
	dijkstra();
	rdijkstra();
//	cout << d[t] << endl;
//	cout << rd[s] << endl;
	lol minDist = d[t];
	lol total = way[t];
//	cout << minDist << " " << total << endl;
	for (int i = 0; i < m; ++i) {
		u = e[i].u;
		v = e[i].v;
		w = e[i].w;				
		if (d[u] + rd[v] + w == minDist && (way[u] * rway[v]) % MOD == total) {
			printf("YES\n");
		} else {
			if (d[u] == 0 && u != s || d[v] == 0 && v != t) {
				printf("NO\n");
				continue;
			}
			lol temp = minDist - (d[u] + rd[v]) - 1;
			if (temp > 0 && temp <= w) {
				printf("CAN %d\n", w - temp);
			} else {
				printf("NO\n");
			}
		}
	}
	return 0;
}

void dijkstra() {
	while (!pq.empty()) pq.pop();
	pq.push({0, s});
	for (int i = 0; i < n; ++i) d[i] = +oo;
	memset(way, 0, sizeof way);
	d[s] = 0;
	way[s] = 1;
	while (!pq.empty()) {
		pli cur = pq.top();
		pq.pop();
		if (d[cur.second] > cur.first) continue;
		for (int i = 0; i < adj[cur.second].size(); ++i) {
			int v = adj[cur.second][i].first;
			int w = adj[cur.second][i].second;
			if (cur.first + w < d[v]) {
				d[v] = cur.first + w;
				way[v] = way[cur.second];
				pq.push({d[v], v});
			} else if (cur.first + w == d[v]) {
				way[v] = (way[v] + way[cur.second]) % MOD;
			}
		}
	}	
}

void rdijkstra() {
	while (!pq.empty()) pq.pop();
	pq.push({0, t});
	for (int i = 0; i < n; ++i) rd[i] = +oo;
	memset(rway, 0, sizeof rway);
	rd[t] = 0;
	rway[t] = 1;
	while (!pq.empty()) {
		pli cur = pq.top();
		pq.pop();
		if (rd[cur.second] > cur.first) continue;
		for (int i = 0; i < radj[cur.second].size(); ++i) {
			int v = radj[cur.second][i].first;
			int w = radj[cur.second][i].second;
			if (cur.first + w < rd[v]) {
				rd[v] = cur.first + w;
				rway[v] = rway[cur.second];
				pq.push({rd[v], v});
			} else if (cur.first + w == rd[v]) {
				rway[v] = (rway[v] + rway[cur.second]) % MOD;
			}
		}
	}	
}
