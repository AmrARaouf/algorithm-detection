//Language: GNU C++11


#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <sstream>
#include <iomanip>

#include <bitset>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <map>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <ctime>
#include <climits>

using namespace std;

typedef pair<int, int> pii;
#define mkp make_pair

int dp[3001][3001];
int main(int argc, char *argv[])
{

#ifdef TEST_OJ
	if (!freopen("test.txt", "r", stdin)) {
		printf("Can't open test.txt!\n");
	}
#endif

	int n, m;
	while (scanf("%d %d", &n, &m) != -1) {
		vector <int> adj[3001];
		for (int i = 0; i < m; i++) {
			int a, b;
			if (scanf("%d %d", &a, &b)) {}
			adj[a - 1].push_back(b - 1);
			adj[b - 1].push_back(a - 1);
		}
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < n; i++) {
			int src = i;
			dp[src][src] = 0;
			queue <int> Q;
			Q.push(src);
			while (!Q.empty()) {
				int curr = Q.front();
				Q.pop();
				for (auto to : adj[curr]) {
					if (dp[src][to] == -1) {
						dp[src][to] = dp[src][curr] + 1;
						Q.push(to);
					}
				}
			}
		}

		
		int s0, t0, l0, s1, t1, l1;
		scanf("%d %d %d %d %d %d", &s0, &t0, &l0, &s1, &t1, &l1);
		--s0; --t0; --s1; --t1;

		int res = m + 1;
		if (dp[s0][t0] > l0 || dp[s1][t1] > l1) {
			printf("-1\n");
			continue;
		} else {
			res = min(res, dp[s0][t0] + dp[s1][t1]);
		}

		for (int iter = 0; iter < 2; iter++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					int v[] = { dp[s0][i] + dp[i][j] + dp[j][t0], 
								dp[s1][i] + dp[i][j] + dp[j][t1]};
					if (v[0] <= l0 && v[1] <= l1) {
						res = min(res, v[0] + v[1] - dp[i][j]);
					}
				}
			}
			swap(s0, t0);
		}


		if (res > m) {
			res = -1;
		} else {
			res = m - res;
		}
		printf("%d\n", res);
	}

	return 0;
}

