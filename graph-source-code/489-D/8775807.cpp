//Language: GNU C++0x


#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
#include <tuple>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long ll;

#ifdef DEBUG
#define dbg(arg) (printf arg)
#define LOG cout << "line:" << __LINE__ << ":" << endl;
#else
#define dbg(arg)
#define LOG
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(15);
    int n, m;
    cin >> n >> m;
	vector<vector<int>> d(n+1);
	vector<vector<bool>> g(n+1, vector<bool>(n+1, false));
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		d[a].push_back(b);
		g[b][a] = true;
	}
	for (auto &v : d) {
		sort(v.begin(), v.end());
		auto it = unique(v.begin(), v.end());
		v.erase(it, v.end());
	}
	ll num = 0;
	for (int i = 1; i < n+1; ++i) {
		if (d[i].size() > 1) {
			for (int j = 1; j < n+1; ++j) {
				if (i == j) continue;
				int count = 0;
				for (auto k : d[i]) {
					if (g[j][k]) {
						++count;
					}
				}
				num += (count * (count - 1) / 2);
			}
		}
	}
	cout << num << "\n";
    return 0;
}

