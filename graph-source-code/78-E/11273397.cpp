//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <vector>
#include <bitset>
#include <complex>
#include <cmath>
#include <ctime>
#include <cassert>
using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
#define FAST_IO std::ios::sync_with_stdio(false)
typedef long long LL;
typedef pair<int, int> PII;
int rd() { return RAND_MAX == 32767 ? ((rand() << 15) ^ rand()) : rand(); }

const int maxn = 210;
const int maxe = 1000000;
const int inf = 1000000000;

int tot;
int d[maxn], g[maxn], h[maxn], cur[maxn], pre[maxn], flow[maxn], c[12][12][12][12], f[12][12][12][12], p[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int cap[maxe], nxt[maxe], vec[maxe];
char a[12][12], b[12][12];
queue<int> S;
queue<PII> Q;

int max_flow(int s, int t, int n)
{
	for (int i = 0; i < n; i++) d[i] = n;
	d[t] = 0;
	S.push(t);
	while (! S.empty()) {
		int k = S.front();
		S.pop();
		for (int i = g[k]; i != -1; i = nxt[i])
			if (cap[i ^ 1] && d[k]+1 < d[vec[i]]) {
				d[vec[i]] = d[k]+1;
				S.push(vec[i]);
			}
	}
	for (int i = 0; i <= n; i++) h[i] = 0;
	for (int i = 0; i < n; i++) {
		h[d[i]]++;
		cur[i] = g[i];
	}
	int k = s, res = 0;
	flow[s] = inf;
	while (d[s] < n) {
		int kk = -1;
		for (int i = cur[k]; i != -1; i = nxt[i])
			if (cap[i] && d[k] == d[vec[i]]+1) {
				kk = vec[i];
				pre[kk] = i ^ 1;
				flow[kk] = min(flow[k], cap[i]);
				cur[k] = i;
				k = kk;
				break;
			}
		if (kk == -1) {
			if (--h[d[k]] == 0) break;
			d[k] = n;
			cur[k] = -1;
			for (int i = g[k]; i != -1; i = nxt[i])
				if (cap[i] && d[k] > d[vec[i]]+1) {
					d[k] = d[vec[i]]+1;
					cur[k] = i;
				}
			h[d[k]]++;
			if (k != s) k = vec[pre[k]];
		}
		else if (k == t) {
			res += flow[t];
			for ( ; k != s; k = vec[pre[k]]) {
				cap[pre[k]] += flow[t];
				cap[pre[k] ^ 1] -= flow[t];
			}
		}
	}
	return res;
}
void add_edge(int u, int v, int w)
{
	cap[tot] = w, vec[tot] = v, nxt[tot] = g[u], g[u] = tot++;
	cap[tot] = 0, vec[tot] = u, nxt[tot] = g[v], g[v] = tot++;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, sx, sy;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] == 'Z') {
				sx = i;
				sy = j;
			}
	// c[x0][y0][x1][y1] dis from (x0, y0) to (x1, y1)
	memset(c, -1, sizeof(c));
	for (int x = 0; x < n; x++)
		for (int y = 0; y < n; y++) {
			c[x][y][x][y] = 0;
			Q.push(mp(x, y));
			while (! Q.empty()) {
				int x0 = Q.front().first;
				int y0 = Q.front().second;
				Q.pop();
				for (int i = 0; i < 4; i++) {
					int x1 = x0+p[i][0], y1 = y0+p[i][1];
					if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < n && a[x1][y1] != 'Y' && a[x1][y1] != 'Z' && c[x][y][x1][y1] == -1) {
						c[x][y][x1][y1] = c[x][y][x0][y0]+1;
						Q.push(mp(x1, y1));
					}
				}
			}
		}
	memset(f, -1, sizeof(f));
	for (int x = 0; x < n; x++)
		for (int y = 0; y < n; y++) if (a[x][y] != 'Y' && a[x][y] != 'Z') {
			f[x][y][x][y] = 0;
			Q.push(mp(x, y));
			while (! Q.empty()) {
				int x0 = Q.front().first;
				int y0 = Q.front().second;
				Q.pop();
				for (int i = 0; i < 4; i++) {
					int x1 = x0+p[i][0], y1 = y0+p[i][1];
					if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < n && a[x1][y1] != 'Y' && a[x1][y1] != 'Z' && f[x][y][x1][y1] == -1)
						if (c[sx][sy][x1][y1] == -1 || f[x][y][x0][y0]+1 <= c[sx][sy][x1][y1]) {
							f[x][y][x1][y1] = f[x][y][x0][y0]+1;
							if (c[sx][sy][x1][y1] == -1 || f[x][y][x1][y1] < c[sx][sy][x1][y1])
								Q.push(mp(x1, y1));
						}
				}
			}
		}
	
	int s = n*n*2, t = n*n*2+1;
	tot = 0;
	memset(g, -1, sizeof(g));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (a[i][j] != 'Y' && a[i][j] != 'Z' && a[i][j] != '0') {
				add_edge(s, i*n+j, a[i][j]-'0');
				for (int u = 0; u < n; u++)
					for (int v = 0; v < n; v++)
						if (b[u][v] != 'Y' && b[u][v] != 'Z' && b[u][v] != '0' && f[i][j][u][v] != -1 && f[i][j][u][v] <= m)
							add_edge(i*n+j, u*n+v+n*n, inf);
			}
			if (b[i][j] != 'Y' && b[i][j] != 'Z' && b[i][j] != '0') add_edge(i*n+j+n*n, t, b[i][j]-'0');
		}
	cout << max_flow(s, t, n*n*2+2);
	return 0;
}

