//Language: GNU C++


#include <cstdio>
#include <vector>
#include <queue>

const int INFIN = 1000000000;
using namespace std;

int main() {

	int n, m, s, l;
	scanf("%d %d %d", &n, &m, &s);

	vector < vector < pair<int,int> > > g(n);
	int a, b, c;
	for (int i=0; i<m; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		g[--a].push_back(make_pair(--b, c));
		g[b].push_back(make_pair(a, c));
	}
	scanf("%d", &l);

	priority_queue < pair<int,int> > q;
	vector<int> d(n, INFIN);
	d[--s] = 0;

	q.push(make_pair(0, s));
	while (!q.empty()) {
		pair<int,int> v = q.top();
		q.pop();
		if (v.first != -d[v.second])
			continue;
		for (int i = 0; i < (int)g[v.second].size(); i++) {
			int to = g[v.second][i].first;
			if (d[to] > d[v.second] + g[v.second][i].second) {
				d[to] = d[v.second] + g[v.second][i].second;
				q.push(make_pair(-d[to], to));
			}
		}
	}

	int count = 0;
	for (int i = 0; i < n; ++i) {
		if (d[i] == l)
			++count;
		for (int j = 0; j < (int)g[i].size(); ++j) {
			int v = g[i][j].first;
			if (i > v)
				continue;
			int w = g[i][j].second;
			if (d[i] < l && d[v] < l) {
				int tmp1 = l - d[i];
				int tmp2 = l - d[v];
				if (tmp1 + tmp2 < w)
					count += 2;
				else if (tmp1 + tmp2 == w)
					count++;
			} else if (d[i] < l && d[i] + w > l)
				count++;
			else if (d[v] < l && d[v] + w > l)
				count++;
		}
	}
	printf("%d", count);
	return 0;
}