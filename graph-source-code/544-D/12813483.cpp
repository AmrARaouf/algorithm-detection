//Language: GNU C++11


#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define f first
#define s second
#define ll long long

using namespace std;

const int MAX = 3e3 + 5;

vector<int> gr[MAX];
int viz[MAX], d[MAX][MAX];
int n, m, s1, s2, t1, t2, l1, l2;
deque <int> q;

void bfs(int source) {

	memset(viz, 0, sizeof(viz));
	viz[source] = 1;
	q.pb(source);

	while (!q.empty()) {
		int node = q.front();
		q.pop_front();

		for (auto it : gr[node])
			if (!viz[it]) {
				d[source][it] = d[source][node] + 1;
				viz[it] = 1;
				q.pb(it);
			}
	}
}

int main() {
	cin.sync_with_stdio(false);
	cin >> n >> m;
	for (int a, b, i = 1; i <= m; i++) {
		cin >> a >> b;
		gr[a].pb(b);
		gr[b].pb(a);
	}

	cin >> s1 >> t1 >> l1
	    >> s2 >> t2 >> l2;

	for (int i = 1; i <= n; i++)
		bfs(i);

	if (d[s1][t1] > l1 || d[s2][t2] > l2) {
		cout << -1;
		return 0;
	}

	int sol = d[s1][t1] + d[s2][t2];

	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++) {
			int len1, len2, len3, len4;
			len1 = d[s1][i] + d[i][j] + d[j][t1];
			len2 = d[t1][i] + d[i][j] + d[j][s1];
			len3 = d[s2][i] + d[i][j] + d[j][t2];
			len4 = d[t2][i] + d[i][j] + d[j][s2];

			int x = min (len1, len2), y = min(len3, len4);

			if (x > l1 || y > l2)
				continue;

			sol = min(sol, x + y - d[i][j]);
		}

	if (sol > m)
		cout << -1;
	else cout << m - sol;
	return 0;
}
