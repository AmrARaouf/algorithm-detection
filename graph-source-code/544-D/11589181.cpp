//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;

const int nmax = 505;

typedef vector< int > vi;

vector< vi > al;
int n, m, s[2], t[2], l[2], dist[3003][3003], ans;

int main() {
	scanf("%d%d", &n, &m);
	al.assign(n, vi());
	int a, b;
	for(int i = 0; i<m; i++) {
		scanf("%d%d", &a, &b);
		a--; b--;
		al[a].push_back(b);
		al[b].push_back(a);
	}
	for(int i = 0; i<2; i++) {
		scanf("%d%d%d", &s[i], &t[i], &l[i]);
		s[i]--; t[i]--;
	}
	memset(dist, -1, sizeof dist);
	for(int i = 0; i<n; i++) {
		queue<int> q;
		q.push(i);
		dist[i][i] = 0;
		while(!q.empty()) {
			int v = q.front(); q.pop();
			for(int j = 0; j<al[v].size(); j++) {
				int u = al[v][j];
				if(dist[i][u] == -1) {
					dist[i][u] = dist[i][v] + 1;
					q.push(u);
				}
			}
		}
	}
	ans = m+1;
	for(int k = 0; k<2; k++) {
		if((dist[s[0]][t[0]]) <= l[0] && (dist[s[1]][t[1]]) <= l[1]) {
			ans = min(ans, dist[s[0]][t[0]] + dist[s[1]][t[1]]);
		}
		for(int i = 0; i<n; i++)
			for(int j = 0; j<n; j++)
				if((dist[s[0]][i]+dist[i][j]+dist[j][t[0]])<=l[0] && (dist[s[1]][i]+dist[i][j]+dist[j][t[1]])<=l[1])
					ans = min(ans, dist[s[0]][i]+dist[i][j]+dist[j][t[0]] + dist[s[1]][i]+dist[j][t[1]]);
		swap(t[1], s[1]);
	}
	printf("%d\n", m-ans);
	return 0;
}