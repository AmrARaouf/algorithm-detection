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

const LL N = 1000;
typedef LL arr[N + 10];

arr f, rank[6], s[6];
LL n, K, ans;

LL main() {
#ifndef ONLINE_JUDGE
	freopen("per.in", "r", stdin);
	freopen("per.out", "w", stdout);
#endif

	scanf(R R "\n", &n, &K);
	FOR (i, 1, K) {
		FOR (j, 1, n) scanf(R, s[i] + j), rank[i][s[i][j]] = j;
	}

	f[1] = ans = 1;
	FOR (i, 2, n) {
		f[i] = 1;
		FOR (j, 1, i - 1) {
			bool can = 1;
			FOR (k, 2, K) if (rank[k][s[1][j]] > rank[k][s[1][i]]) { can = 0; break; }
			if (can) f[i] = max(f[i], f[j] + 1);
		}
		ans = max(ans, f[i]);
	}
	printf(R "\n", ans);
	
	return 0;
}
