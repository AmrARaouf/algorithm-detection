//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 100005;

int n, m;
int colors[MAXN];
set < int > Q[MAXN];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &colors[i]);
	}

	for(int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (colors[a] != colors[b]) {
			Q[colors[a]].insert(colors[b]);
			Q[colors[b]].insert(colors[a]);
		}
	}

	int maxx = -1, col = MAXN;
	for (int i = 1; i <= n; i++) {
		if (maxx < (int) Q[colors[i]].size() || (maxx == (int) Q[colors[i]].size() && col > colors[i])) {
			maxx = (int) Q[colors[i]].size();
			col = colors[i];
		}
	}

	printf("%d\n", col);
	return 0;
}
