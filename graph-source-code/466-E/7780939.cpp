//Language: GNU C++


#include <bits/stdc++.h>

#define R "%d"
#define RL "%I64d"
#define RD "%lf"
#define W "%.8lf"

#define Max(x, y) ((x) > (y) ? (x) : (y))
#define Min(x, y) ((x) < (y) ? (x) : (y))
#define Set(x, y) memset(x, y, sizeof(x))
#define Cpy(x, y) memcpy(x, y, sizeof(y))
#define All(x) x.begin(), x.end()
#define Sqr(x) ((x) * (x))
#define Sz(x) ((LL)x.size())

#define Mk make_pair
#define Pb push_back
#define Pk pop_back
#define Fr first
#define Se second

#define FOR(x, l, r) for (LL x = (l), end = (r); x <= end; ++x)
#define ROF(x, l, r) for (LL x = (l), end = (r); x >= end; --x)
#define Edge(x, y) for (LL x = g[y]; x; x = nt[x])

#define Read(x) ((x) = Get())
#define Lowbit(x) ((x) & (-x))
using namespace std;

typedef int LL;
typedef long long ll;
typedef double LD;
typedef long double real;

typedef map <LL, LL> MI;
typedef pair <LL, LL> PI;
typedef set <LL> SI;
typedef vector <LL> VI;

inline LL Get() {
	LL res = 0, q = 1;
	char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	if (ch == '-') q = -1, ch = getchar();
	while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
	return res * q;
}

const LD eps = 1e-12, pi = M_PI;
const LL oo = (LL)2e9, mod = (LL)1e9 + 7;
const ll INF = (ll)1e17;

const LL N = (LL)1e5, LG = 20;
typedef LL arrv[N + 10];
typedef LL arre[2 * N + 10];

arrv f[LG + 1], h[LG + 1], c, bel, d, g, tme;
arre pt, nt;
bool v[N + 10];
LL n, m, j, k, cnt, tot, all;

struct node {
	LL t, x, y;
}q[N + 10];

struct queue {
	arrv v;
	LL f, r;
}Q;

void Link(LL x, LL y) {
	pt[++tot] = y, nt[tot] = g[x], g[x] = tot;
}

void Bfs(LL st) {
	Q.v[1] = st, Q.f = Q.r = 1;
	bel[st] = ++all, d[st] = 1, v[st] = 1;
	while (Q.f <= Q.r) {
		LL x = Q.v[Q.f++];
	    bel[x] = all;
		for (LL c = 1; d[x] - (1 << c) > 0; ++c)
			f[c][x] = f[c - 1][f[c - 1][x]], h[c][x] = max(h[c - 1][x], h[c - 1][f[c - 1][x]]);
		
		Edge (i, x)
			Q.v[++Q.r] = pt[i], d[pt[i]] = d[x] + 1;
	}
}

LL Lca(LL x, LL y) {
	LL c = 0, res = 0;
	while (d[y] > d[x]) {
		for (c = 0; d[y] - (1 << c) >= d[x]; ++c);
		--c, res = max(res, h[c][y]), y = f[c][y];
	}
	if (x == y) return res;
	return -1;
}

LL main() {
#ifndef ONLINE_JUDGE
	freopen("e.in", "r", stdin);
	freopen("e.out", "w", stdout);
#endif

	scanf(R R "\n", &n, &m);
	FOR (i, 1, m) {
		LL tp;
		scanf(R, &tp);
		if (tp == 1) scanf(R R "\n", &j, &k), f[0][j] = k, h[0][j] = i, Link(k, j), v[j] = 1;
		else if (tp == 2) scanf(R "\n", &j), c[++cnt] = j, tme[cnt] = i;
		else scanf(R R "\n", &q[i].x, &q[i].y), q[i].t = i;
	}

	FOR (i, 1, n)
		if (!v[i])
			Bfs(i);
	
	FOR (i, 1, m)
		if (q[i].t) {
			LL qt = c[q[i].y];
			if (bel[qt] != bel[q[i].x]) printf("NO\n");
			else {
				LL ck = Lca(q[i].x, qt);
				if (ck < 0 || ck > tme[q[i].y]) printf("NO\n");
				else printf("YES\n");
			}
		}

	return 0;
}
