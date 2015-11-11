//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory.h>

using namespace std;

#ifdef _WIN32
#  define I64 "%I64d"
#else
#  define I64 "%lld"
#endif


#define sqr(a) (a)*(a)
#define ll long long
#define vi vector<int>
#define vs vector<string>
#define dbg(x) cerr << #x << " == " << x << " "
#define dbgL(x) cerr << #x << " == " << x << endl

int u[105];
vector<set<int> > g;
int st[105];
int n, m;

int main()
{
	cin >> n >> m;
	g.resize(n);
	for (int i = 0; i < m; ++i) {
		int v, u;
		cin >> v >> u;
		--v, --u;
		g[v].insert(u);
		g[u].insert(v);
	}

	int ans = 0;
	while (1) {
		int col = 0;
		vector<int> tmp;
		for (int i = 0; i < n; ++i) {
//			cerr << g[i].size() << " ";
			if (g[i].size() == 1) {
				++col;
				tmp.push_back(i);
			}
		}
//		cerr << endl;
		if (col == 0)
			break;
		++ans;
		for (int j = 0; j < tmp.size(); ++j) {
			int i = tmp[j];
			if (g[i].size() == 1) {
				int to = *g[i].begin();
				g[to].erase(i);
				g[i].clear();
			}
		}
	}

	cout << ans << endl;
	return 0;
}
