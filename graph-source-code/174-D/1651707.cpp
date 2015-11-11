//Language: MS C++


#pragma comment(linker, "/STACK:66777216")
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <assert.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(a) (int)a.size()
#define fill(a, x) memset(a, x, sizeof(a))

#ifdef _DEBUG
	#define Eo(x) {cout << "# " << #x << " = " << (x) << endl;}
	#define E(x)  {cout << #x << " = " << (x) << "; ";}
#else
	#define Eo(x)
	#define E(x)
#endif

void sIO();

typedef pair<int, int> pii;

int n, m, x, y, a[111111];
vector< vector<int> > g, gr;
bool w1[111111], w2[111111], w[111111];

void dfs1(int v) {
	w1[v] = true;
	w[v] = true;
	int kk = sz(g[v]), tto;
	for (int i = 0; i < kk; ++i) {
		tto = g[v][i];
		if (!w[tto]) dfs1(tto);
	}
}

void dfs2(int v) {
	w2[v] = true;
	w[v] = true;
	if (a[v] == 1) return;
	int kk = sz(gr[v]), tto;
	for (int i = 0; i < kk; ++i) {
		tto = gr[v][i];
		if (!w[tto]) dfs2(tto);
	}
}

int main() {
	sIO();
	scanf("%d %d", &n, &m);
	g.resize(n + 5);
	gr.resize(n + 5);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &x, &y);
		g[x].pb(y);
		gr[y].pb(x);
	}
	fill(w1, 0);
	fill(w2, 0);
	fill(w, 0);
	for (int i = 1; i <= n; ++i)
		if (a[i] == 1) dfs1(i);
	fill(w, 0);
	for (int i = 1; i <= n; ++i)
		if (a[i] == 2) dfs2(i);
	for (int i = 1; i <= n; ++i)
		printf("%d ", w1[i] && w2[i]);
	return 0;
}

void sIO() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}