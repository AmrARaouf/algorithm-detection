//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <memory.h>

using namespace std;

#ifdef _WIN32
#  define I64 "%I64d"
#else
#  define I64 "%lld"
#endif


#define sqr(a) (a)*(a)
#define ll long long
#define vi vector<int>
#define vs vector<string>
#define dbg(x) cerr << #x << " == " << x << " "
#define dbgL(x) cerr << #x << " == " << x << endl

const int maxn = 1e5 + 15;
const int inf = 1e9 + 7;

set<pair<int, int> > d;
int dist[maxn];
int n, m, s;
vector<int> g[maxn], c[maxn], num[maxn];
vector<pair<int, int> > edges;
set<int> where[maxn];
int ans;
int L;

void find() {
	for (int i = 0; i < n; ++i)
		if (i != s)
			d.insert(make_pair(inf, i)), dist[i] = inf;
	d.insert(make_pair(0, s));
	for (int i = 0; i < n; ++i) {
		int v = d.begin()->second;
		d.erase(make_pair(dist[v], v));
		for (int j = 0; j < g[v].size(); ++j) {
			int to = g[v][j], cost = c[v][j];
			if (dist[to] > dist[v] + cost) {
				d.erase(make_pair(dist[to], to));
				dist[to] = dist[v] + cost;
				d.insert(make_pair(dist[to], to));
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		if (dist[i] == L)
			++ans;
		if (dist[i] < L) {
			for (int j = 0; j < g[i].size(); ++j)
				if (dist[i] + c[i][j] > L) {
					int wh;
					if (i < g[i][j]) {
						wh = L - dist[i];
						if (dist[i] + (L - dist[i]) > dist[g[i][j]] + (c[i][j] - wh))
							continue;
					}
					else {
						wh = c[i][j] - (L - dist[i]);
						if (dist[i] + (L - dist[i]) > dist[g[i][j]] + wh)
							continue;
					}
					if (where[num[i][j]].find(wh) == where[num[i][j]].end())
						where[num[i][j]].insert(wh), ++ans;
				}
		}
	}
	cout << ans << endl;
}

int main()
{
//	freopen("in","r",stdin);
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 0; i < m; ++i) {
		int v, u, w;
		scanf("%d%d%d", &v, &u, &w);
		--v, --u;
		g[v].push_back(u);
		c[v].push_back(w);
		g[u].push_back(v);
		c[u].push_back(w);
		num[v].push_back(i);
		num[u].push_back(i);
		edges.push_back(make_pair(min(v, u), max(v, u)));
	}
	--s;
	scanf("%d", &L);

	find();

	return 0;
}
