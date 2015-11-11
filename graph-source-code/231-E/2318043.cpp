//Language: GNU C++


#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#pragma comment(linker, "/STACK:250000000")
template<typename T> int size(T& a){ return (int) a.size(); }
template<typename T> T sqr(T a){ return a * a; }
 
#define _(a, b) memset((a), (b), sizeof(a))
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define REPD(i, a, b) for(int i = (b) - 1; i >= a; --i)

const int MAXN = 200100;
template<int SIZE> struct Graph {
	int to[SIZE], nxt[SIZE], head[SIZE];
	int edge;
	Graph () {
		_(head, 255);
		edge = 0;
	}
	void addEdge(int u, int v) {
		to[edge] = v;
		nxt[edge]=  head[u];
		head[u] = edge++;
	}
};

Graph<2*100000> g;

bool used[MAXN];
int  prv[MAXN];
int cycleId[MAXN];
int curCycle = 0;
bool work[MAXN];
int costCycle[MAXN];

void dfs(int v, int lastEdge) {
	used[v] = true;
	for(int e=g.head[v];e>=0;e=g.nxt[e]) {
		if (lastEdge != -1 && (e^1) == lastEdge) continue;
		if (used[g.to[e]]) {
			if (work[g.to[e]]) continue;
			for(int j=v; j != g.to[e]; j=prv[j]) {
				cycleId[j] = curCycle;
				work[j] = true;
			}
			cycleId[g.to[e]] = curCycle++;
			work[g.to[e]] = true;
		} else {
			prv[g.to[e]] = v;
			dfs(g.to[e], e);
		}
	}
}
Graph<2*100100> tree;
const int MAXLOG = 20;
int par[100100][MAXLOG+1];
int sum[100100][MAXLOG+1];
int depth[100100];

void dfsTree(int v, int parent, int d) {
	depth[v] = d;
	par[v][0] = parent;
	_(sum[v], 0);
	sum[v][0] = costCycle[v];
	
	for(int i=1; i < MAXLOG; ++i) {
		par[v][i] = par[par[v][i - 1]][i - 1];
		int g = par[v][i - 1];
		sum[v][i] = (g==0? 0 : sum[par[v][i - 1]][i - 1]) + sum[v][i - 1];
	}
	for(int e=tree.head[v];e>=0;e=tree.nxt[e]) {
		if (tree.to[e] == parent) continue;
		dfsTree(tree.to[e], v, d+1);
	}
}
int lca(int x, int y) {
	if (depth[x] > depth[y]) 
		return lca(y, x);
	for(int i=MAXLOG-1; i >=0 && depth[x] != depth[y]; --i) {
		if (depth[par[y][i]] >= depth[x])
			y = par[y][i];
	}
	if (x==y) return x;
	for(int i=MAXLOG-1;i>=0;--i) {
		if(par[x][i]!=par[y][i])
			x = par[x][i],
			y = par[y][i];
	}
	return par[x][0];
}
int getsum(int x, int y) {
	if (x==y)return costCycle[x];
	int res = 0;
	for(int i = MAXLOG-1; i >=0 ; --i) {
		if (depth[par[x][i]] >= depth[y]) {
			res += sum[x][i];
			x = par[x][i];
			if (x==y)return res+costCycle[y];
		}
	}
	return res;
}
int process(int x, int y) {
	x = cycleId[x];
	y = cycleId[y];
	int l = lca(x, y);
	int s1 = getsum(x, l) + getsum(y, l) - costCycle[l];
	return s1;
}
int bp(int a, int n, int mod) {
	int r = 1;
	for(; n; n /=2, a=(ll)a*a%mod)
		if (n%2==1)
			r = (ll)r * a %mod;
return r;
}
int main() {
#ifdef air
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

	int n, m;
	scanf("%d%d", &n, &m);
	REP(i, 0, m) {
		int x, y;
		scanf("%d%d", &x, &y);
		-- x, --y;
		g.addEdge(x, y);
		g.addEdge(y, x);
	}
	_(cycleId, 255);
	REP(i, 0, n)
		if (!used[i])
			dfs(i, -1);
	/*REP(i, 0, n) {
		printf("%d ", cycleId[i]);
	}*/
	//printf("\n\n");
	REP(i, 0, curCycle)
		costCycle[i] = 1;
	REP(i, 0 ,n) if (cycleId[i] == -1) {
		cycleId[i] = curCycle;
		costCycle[curCycle] = 0;
		curCycle++;
	}
	set<pair<int, int> > yet;
	REP(i,0,n) for(int e=g.head[i];e>=0;e=g.nxt[e]) {
		int x = cycleId[i];
		int y = cycleId[g.to[e]];
		if (x==y) continue;
		if (x>y) swap(x, y);
		if (yet.find(mp(x, y)) != yet.end()) continue;
		yet.insert(mp(x, y));
		tree.addEdge(x, y);
		tree.addEdge(y, x);
	}

	dfsTree(0,-1,0);
	int q;
	scanf("%d", &q);
	REP(i, 0, q) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x, --y;
		int r = process(x, y);
		printf("%d\n", bp(2, r, 1000000000 + 7));
	}


	

#ifdef air
    printf("\n\n%.2lf\n", clock() * 1e-3);
#endif
}