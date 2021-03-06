//Language: GNU C++


#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int nmax = 100000;

int n, m, a, b, t;
vector<int> e[nmax+1];
int num[nmax+1], low[nmax+1];
vector< pair<int, int> > ans;
bool flag;

void dfs(int u, int from) {
	num[u] = low[u] = ++t;
	int s = e[u].size();
	for (int i = 0; i < s; i++) {
		int v = e[u][i];
		if (num[v] == 0) {
			ans.push_back(make_pair(u, v));
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] > num[u]) 
				flag = true;
		} else {
			if (v != from) {
				low[u] = min(low[u], num[v]);
				if (num[v] < num[u])
					ans.push_back(make_pair(u, v));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	
	dfs(1, -1);
	if (flag)
		cout << "0\n";
	else {
		int size = ans.size();
		for (int i = 0; i < size; i++)
			cout << ans[i].first << " " << ans[i].second << "\n";
	}
	
	return 0;
}