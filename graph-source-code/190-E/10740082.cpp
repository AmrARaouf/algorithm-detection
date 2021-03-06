//Language: GNU C++11


// In the name of God
#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5; 

vector<int> adj[N], ans[N], st;
bool mark[N];

int main() { 
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v; 
		scanf("%d%d", &u, &v); 
		u--, v--; 
		adj[u].push_back(v); 
		adj[v].push_back(u);
	}
	for(int i = 0; i < n; i++)
		st.push_back(i); 
	int cnt = 0;
	while (!st.empty()) {
		vector<int> &q = ans[cnt], tmp;
		q.push_back(st.back());
		st.pop_back();
		mark[q.back()] = true;
		for (int i = 0; i < (int) q.size(); i++) {
			int v = q[i];
			for (int j = 0; j < (int) adj[v].size(); j++) {
				int u = adj[v][j];
				if (!mark[u]++)
					tmp.push_back(u);
			}
			for (int j = 0; j < (int) st.size(); j++)
				if (!mark[st[j]]++)
					q.push_back(st[j]);
			st.clear();
			tmp.swap(st);
			for (int j = 0; j < (int) st.size(); j++)
				mark[st[j]] = false;
		}
		cnt++;
	}
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++) {
		printf("%d ", (int) ans[i].size());
		for (int j = 0; j < (int) ans[i].size(); j++)
			printf("%d ", ans[i][j] + 1);
		printf("\n");
	}
}
