//Language: GNU C++


#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REP1(i, n) for (int i = 1; i <= (n); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define ROF(i, b, a) for (int i = (b); i >= (a); --i)
#define CLR(x, n) memset(x, n, sizeof(x))
#define INF 0x7fffffff
#define maxN 10000
#define maxM 1000000
using namespace std;
typedef pair<int, int> pii;

void setIO(string name) {
	string in_f = name + ".in";
	string out_f = name + ".out";
	freopen(in_f.c_str(), "r", stdin);
	freopen(out_f.c_str(), "w", stdout);
}

struct Edge {
	int v, w;
	Edge *next;
} *head[maxN], map[maxM], *pool = map;

#define Opt(x) (((x - map) ^ 1) + map)

void add_value(int u, int v, int w) {
	pool->v = v, pool->w = w, pool->next = head[u], head[u] = pool++;
	pool->v = u, pool->w = 0, pool->next = head[v], head[v] = pool++;
}

const int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int n, T;
char man[20][20], cap[20][20];
int st, en;
int tag[maxN];
int dis[20][20];

void get_source(int &sx, int &sy) {
	sx = sy = 0;
	REP1(i, n) REP1(j, n) if (man[i][j] == 'Z') {
		sx = i, sy = j;
		return;
	}
}

bool exist(int x, int y) {
	if (x == 0 || x == n + 1 || y == 0 || y == n + 1) return false;
	return true;
}
	
void get_dis() {
	int sx, sy;
	get_source(sx, sy);
	CLR(dis, 0x7f), dis[sx][sy] = 0;
	queue<pii> que;
	que.push(pii(sx, sy));
	while (!que.empty()) {
		pii u = que.front(); que.pop();
		int x = u.first, y = u.second;
		REP(i, 4) {
			int nx = x + dir[i][0], ny = y + dir[i][1];
			if (exist(nx, ny) && man[nx][ny] != 'Y' && dis[nx][ny] == 0x7f7f7f7f) {
				dis[nx][ny] = dis[x][y] + 1;
				que.push(pii(nx, ny));
			}
		}
	}
}

int trans(int x, int y) {
	return n * (x - 1) + y;
}

void set_map() {
	get_dis();
	//REP1(i, n) REP1(j, n) printf("%d%c", dis[i][j], j == n ? '\n' : ' ');
	st = 0, en = maxN - 1;
	REP1(i, n) REP1(j, n) {
		if ('1' <= man[i][j] && man[i][j] <= '9') add_value(st, trans(i, j), man[i][j] - '0');
		if ('1' <= cap[i][j] && cap[i][j] <= '9') {
			add_value(en - trans(i, j), en, cap[i][j] - '0');
			add_value(trans(i, j), en - trans(i, j), INF);
		}
	}
	REP(k, T) {
		REP1(x, n) REP1(y, n) if (dis[x][y] > k && man[x][y] != 'Y') {
			REP(i, 4) {
				int nx = x + dir[i][0], ny = y + dir[i][1];
				if (exist(nx, ny) && man[nx][ny] != 'Y' && (dis[nx][ny] > k + 1 || (dis[nx][ny] == k + 1 && '1' <= cap[nx][ny] && cap[nx][ny] <= '9'))) {
					add_value(k * n * n + trans(x, y), (k + 1) * n * n + trans(nx, ny), INF);
				}
				if (exist(nx, ny) && '1' <= cap[nx][ny] && cap[nx][ny] <= '9') {
					add_value((k + 1) * n * n + trans(nx, ny), en - trans(nx, ny), INF);
				}
			}
		}
	}
}

void init() {
	scanf("%d %d", &n, &T);
	REP1(i, n) scanf("%s", man[i] + 1);
	REP1(i, n) scanf("%s", cap[i] + 1);
	set_map();
}

bool build() {
	queue<int> que;
	CLR(tag, -1), tag[st] = 0;
	que.push(st);
	while (!que.empty()) {
		int u = que.front(); que.pop();
		for (Edge *p = head[u]; p; p = p->next) if (p->w) {
			int v = p->v;
			if (tag[v] == -1) {
				tag[v] = tag[u] + 1;
				if (v == en) return true;
				que.push(v);
			}
		}
	}
	return false;
}

int extend(int u, int flow) {
	if (u == en) return flow;
	int ret = 0;
	for (Edge *p = head[u]; p && ret < flow; p = p->next) {
		int v = p->v;
		if (tag[v] == tag[u] + 1 && p->w) {
			int t = extend(v, min(p->w, flow - ret));
			p->w -= t, Opt(p)->w += t, ret += t;
		}
	}
	if (!ret) tag[u] = 0;
	return ret;
}

int dinic() {
	int ret = 0, p;
	while (build()) while (p = extend(st, INF)) ret += p;
	return ret;
}

void solve() {
/*	REP1(i, n) REP1(j, n) {
		printf("%d %d ", i, j);
		int u = trans(i, j);
		for (Edge *p = head[u]; p; p = p->next) {
			printf("%5d", p->v - n * n);
		}
		puts("");
	}
*/
	printf("%d\n", dinic());
}

int main() {
	//setIO("E");
	init();
	solve();
	return 0;
}
