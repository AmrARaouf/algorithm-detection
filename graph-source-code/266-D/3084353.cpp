//Language: GNU C++


#include <algorithm>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

const int MAXN = 201;
const int MAXM = 20001;
const int INF = 1012345678;

int n, m, dist[MAXN][MAXN];
int a[MAXM], b[MAXM], w[MAXM];

int calc(int a, int b, int w) {
	vector< pair<int, int> > s(n);
	for (int i = 0; i < n; i++) {
		s[i] = make_pair(dist[a][i] << 1, (dist[b][i] + w) << 1);
	}
	sort(s.begin(), s.end());
	int lower = s.back().first, upper = s.back().second, res = lower;
	s.pop_back();
	do {
		while (!s.empty()) {
			int nxtlower = s.back().first, nxtupper = s.back().second;
			s.pop_back();
			if (upper <= nxtupper) {
				res = min(res, (nxtlower + upper) / 2);
				lower = nxtlower;
				upper = nxtupper;
				break;
			}
		}
	} while (!s.empty());
	return res;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dist[i][j] = INF;
		}
		dist[i][i] = 0;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &a[i], &b[i], &w[i]);
		a[i]--;
		b[i]--;
		dist[a[i]][b[i]] = dist[b[i]][a[i]] = w[i];
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	int res = INF;
	for (int i = 0; i < m; i++) {
		res = min(res, min(calc(a[i], b[i], w[i]), calc(b[i], a[i], w[i])));
	}
	printf("%.2lf\n", res / 2.0);
	return 0;
}