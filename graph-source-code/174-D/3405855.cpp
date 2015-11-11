//Language: MS C++


#ifdef NALP_PROJECT
#pragma hdrstop
#else
#define _SECURE_SCL 0
#endif

#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:64000000")

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <utility>

#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <memory.h>

#include <iostream>
#include <sstream>

using namespace std;

typedef long long int64;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define y1 YYYYYYYYYYYY1
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define Abs(x) (((x) >= 0) ? (x) : (-(x)))

const int INF = (int)1E9;
const int64 INF64 = (int64)1E18;
const long double EPS = 1E-9;
const long double PI = 3.1415926535897932384626433832795;

const int MAXN = 100100;

int n, m, type[MAXN];
vector<int> g[MAXN], gt[MAXN];
bool u1[MAXN], u2[MAXN];

void DFS1(int v) {
	u1[v] = true;
	forn(i, g[v].size()) {
		int u = g[v][i];
		if (!u1[u]) DFS1(u);
	}
}

void DFS2(int v) {
	u2[v] = true;
	if (type[v] == 1) return;
	forn(i, gt[v].size()) {
		int u = gt[v][i];
		if (!u2[u]) DFS2(u);
	}
}

int main() {
#ifdef NALP_PROJECT
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#else
#endif

	cin >> n >> m;
	forn(i, n)
		scanf("%d", &type[i]);

	forn(i, m) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--; u--;

		g[v].pb(u);
		gt[u].pb(v);
	}

	forn(i, n) {
		if (type[i] == 1 && !u1[i]) DFS1(i);
		if (type[i] == 2 && !u2[i]) DFS2(i);
	}

	forn(i, n)
		if (u1[i] && u2[i])
			printf("1\n");
		else
			printf("0\n");
	
	return 0;
}
