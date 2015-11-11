//Language: GNU C++


#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <bitset>
#include <vector>
using namespace std;

#define PB push_back
const int N = 300005;
vector<int> head[N];
int col[N];
int n, m;

int main() {
	scanf("%d%d", &n, &m);
	int u, v;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &u, &v);
		--u, --v;
		head[u].PB(v);
		head[v].PB(u);
	}
	vector<int> Q(n);
	for (int i = 0; i < n; i++)
		Q[i] = i;
	while (!Q.empty()) {
		int u = Q.back();
		Q.pop_back();
		int c = 0;
		for (int j = 0; j < head[u].size(); j++)
			c += col[head[u][j]];
		if (c < 2 && col[u] == 0) {
			col[u] = 1;
			for (int j = 0; j < head[u].size(); j++)
				Q.PB(head[u][j]);
		}
		else if (c >= 2 && col[u] == 1) {
			col[u] = 0;
			for (int j = 0; j < head[u].size(); j++)
				Q.PB(head[u][j]);
		}
	}
	for (int i = 0; i < n; i++)
		if (col[i])
			putchar('1');
		else
			putchar('0');
	puts("");	
	return 0;
}
