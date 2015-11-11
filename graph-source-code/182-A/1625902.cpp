//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

const int MaxN = 2005;
const double eps = 1e-8;

inline int sgn(double x) {
	return x < -eps ? -1 : x > eps;
}

struct P {
	double x, y;
	P() {
	}
	P(double x, double y) :
			x(x), y(y) {
	}
	P operator+(const P& p) const {
		return P(x + p.x, y + p.y);
	}
	P operator-(const P& p) const {
		return P(x - p.x, y - p.y);
	}
	double operator*(const P& p) const {
		return x * p.y - y * p.x;
	}
	double operator&(const P& p) const {
		return x * p.x + y * p.y;
	}
	double norm() const {
		return hypot(x, y);
	}
	double norm2() const {
		return x * x + y * y;
	}
	void init() {
		scanf("%lf%lf", &x, &y);
	}
} p[MaxN][2];
int adj[MaxN][MaxN];
int d[MaxN], q[MaxN];
double dist[MaxN];
double a, b;
int N, M;

inline double minDist(const P& p, const P& a, const P& b) {
	double fd = ((p - a) & (b - a)) / (b - a).norm2();
	if (sgn(fd) >= 0 && sgn(fd - 1) <= 0)
		return fabs((p - a) * (b - a)) / (b - a).norm();
	else
		return min((p - a).norm(), (p - b).norm());
}

inline double minDist(const P& a, const P& b, const P& c, const P& d) {
	double d1 = minDist(c, a, b);
	double d2 = minDist(d, a, b);
	double d3 = minDist(a, c, d);
	double d4 = minDist(b, c, d);
	return min(min(d1, d2), min(d3, d4));
}

inline double BFS() {
	double ret = 1e100;
	int f = 0, b = 0;
	int u, v;

	q[b++] = 0;
	d[0] = 0;
	while (f != b) {
		u = q[f++];
		for (int i = 1; i <= adj[u][0]; i++) {
			v = adj[u][i];
			if (d[v] == -1) {
				d[v] = d[u] + 1;
				q[b++] = v;
			}
		}
	}

	for (int i = 0; i <= N; i++) {
		if (d[i] != -1) //WA #3
			ret = min(ret, d[i] * (a + ::b) + dist[i]);
	}
	return ret;
}

int main() {
#ifdef __FISH__
	freopen("in.txt", "r", stdin);
#endif

	while (scanf("%lf%lf", &a, &b) == 2) {
		p[0][0].init();
		p[0][1].init();
		scanf("%d", &N);
		adj[0][0] = 0;
		for (int i = 1; i <= N; i++) {
			p[i][0].init();
			p[i][1].init();
			adj[i][0] = 0;
		}
		memset(d, -1, sizeof(d));

		dist[0] = (p[0][0] - p[0][1]).norm();
		if (sgn(dist[0] - a) > 0)
			dist[0] = 1e100;
		for (int i = 1; i <= N; i++) {
			if (sgn(minDist(p[0][0], p[i][0], p[i][1]) - a) <= 0)
				adj[0][++adj[0][0]] = i;
			dist[i] = minDist(p[0][1], p[i][0], p[i][1]);
			if (sgn(dist[i] - a) > 0)
				dist[i] = 1e100;
			for (int j = 1; j < i; j++) {
				if (sgn(minDist(p[i][0], p[i][1], p[j][0], p[j][1]) - a) <= 0) {
					adj[i][++adj[i][0]] = j;
					adj[j][++adj[j][0]] = i;
				}
			}
		}

		double ret = BFS();
		if (ret > 1e99)
			puts("-1");
		else
			printf("%.10f\n", ret);
	}

	return 0;
}
