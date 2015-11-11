//Language: MS C++


#pragma comment(linker, "/STACK:268435456")
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <assert.h>
#include <stack>
#include <deque>
#include <limits.h>
#include <memory.h>
#include <ctime>
//#include <unordered_map>
//#include <unordered_set>
using namespace std;
 
void prepare(string s = "") {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	if (s != "") {
		freopen((s + ".in").c_str(), "r", stdin);
		//freopen((s + ".out").c_str(), "w", stdout);
	}
#endif
}

const int NMAX = 100001,
	INF = 1000000000;

int n, m;
int d[NMAX];
vector<bool> used;
vector<int> g[NMAX], gr[NMAX], p, c;

void getData() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> d[i];
	}
	cin >> m;
	int a , b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		g[a].push_back(b);
		gr[b].push_back(a);
	}
}

void dfs1 (int v) {
	used[v] = true;
	for (int i=0; i < g[v].size(); ++i) {
		if (!used[ g[v][i] ])
			dfs1 (g[v][i]);
	}
	p.push_back (v);
}
 
void dfs2 (int v) {
	used[v] = true;
	c.push_back (v);
	for (int i=0; i < gr[v].size(); ++i) {
		if (!used[ gr[v][i] ])
			dfs2 (gr[v][i]);
	}
}
 
void solve() {
	long long s = 0, k = 1;

	used.assign(n+1, false);
	for (int i= 1; i <= n; ++i) {
		if (!used[i]) {
			dfs1(i);
		}
	}
	reverse(p.begin(), p.end());
	used.assign(n+1, false);
	for (int i = 0; i < n; ++i) {
		int v = p[i];
		if (!used[v]) {
			dfs2(v);
			int MIN = INF, cnt = 0;
			for (int j = 0; j < c.size(); ++j) {
				if (MIN > d[c[j]]) {
					MIN = d[c[j]];
					cnt = 1;
				}
				else if (MIN == d[c[j]]) {
					cnt ++;
				}
			}
			s += MIN;
			k = (k * cnt) % 1000000007;
			c.clear();
		}
	}

	cout << s << ' ' << k;
}

int main() {
	prepare();
	
	getData();
	solve();

	return 0;
}