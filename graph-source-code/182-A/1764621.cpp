//Language: MS C++


#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define inf 1000000000
#define ll long long
#define eps 1e-9
#define VI vector<int>
#define pb push_back
#define L(s) (int)((s).size())
#define all(s) (s).begin(), (s).end()
#define pii pair<int, int>
#define mp make_pair
#define x first
#define y second
pii s[1111], f[1111];
int n, a, b;
pii st, fn;
int fnd[1111];
inline double min_dst(pii a, pii p, pii q) {
	double ans = 1e100;
	ans = min(ans, sqrt((double)(a.x - p.x) * (a.x - p.x) + (a.y - p.y) * (a.y - p.y)));
	ans = min(ans, sqrt((double)(a.x - q.x) * (a.x - q.x) + (a.y - q.y) * (a.y - q.y)));
	if (p.x == q.x && a.y <= max(p.y, q.y) && a.y >= min(p.y, q.y)) ans = min(ans, (double)abs(a.x - p.x));
	if (p.y == q.y && a.x <= max(p.x, q.x) && a.x >= min(p.x, q.x)) ans = min(ans, (double)abs(a.y - p.y));
	return ans;
}
int main() {
	cin >> a >> b;
	cin >> st.x >> st.y >> fn.x >> fn.y;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> s[i].x >> s[i].y >> f[i].x >> f[i].y;
	}
	memset(fnd, -1, sizeof(fnd));
	if ((st.x - fn.x) * (st.x - fn.x) + (st.y - fn.y) * (st.y - fn.y) <= a * a) {
		printf("%0.15lf\n",sqrt((double)(st.x - fn.x) * (st.x - fn.x) + (st.y - fn.y) * (st.y - fn.y)));
		return 0;
	}
	queue<int> q;
	for(int i = 0; i < n; ++i) if (min_dst(st, s[i], f[i]) <= a + 1e-9) {
		q.push(i); fnd[i] = a + b;
	}
	while(!q.empty()) {
		int cur = q.front(); q.pop();
		for(int j = 0; j < n; ++j) if (fnd[j] == -1) {
			double d = 1e100;
			d = min(d, min_dst(s[cur], s[j], f[j]));
			d = min(d, min_dst(f[cur], s[j], f[j]));
			d = min(d, min_dst(s[j], s[cur], f[cur]));
			d = min(d, min_dst(f[j], s[cur], f[cur]));
			if (d <= a + 1e-9) {
				fnd[j] = fnd[cur] + a + b;
				q.push(j);
			}
		}
	}
	double ans = 1e100;
	for(int i = 0; i < n; ++i) if (fnd[i] != -1 && min_dst(fn, s[i], f[i]) <= a + 1e-9) {
		ans = min(ans, fnd[i] + min_dst(fn, s[i], f[i]));
	}
	if (ans > 1e99) cout << "-1\n"; else printf("%0.15lf\n", ans);
}