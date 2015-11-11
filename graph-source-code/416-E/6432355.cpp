//Language: GNU C++0x


#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define min(a, b) ((a) < (b) ? (a) : (b))
#define INF 1000000000

int G[510][510], dist[510][510];
int cnt[510], dp[510][510];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		G[i][i] = 0;
		dist[i][i] = 0;
		dp[i][i] = 0;
		for(int j = i + 1; j <= n; j++) {
			G[i][j] = G[j][i] = 0;
			dist[i][j] = dist[j][i] = INF;
			dp[i][j] = dp[j][i] = 0;
		}
	}

	for(int i = 0; i < m; i++) {
		int x, y, l;
		scanf("%d%d%d", &x, &y, &l);
		G[x][y] = G[y][x] = l;
		dist[x][y] = dist[y][x] = l;
	}

	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(dist[i][k] + dist[k][j] < dist[i][j]) 
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	for(int u = 1; u <= n; u++) {
		memset(cnt, 0, (n + 5) * sizeof(int));
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				if(G[i][j] && G[i][j] + dist[j][u] == dist[i][u]) cnt[i]++;
				if(G[j][i] && G[j][i] + dist[i][u] == dist[j][u]) cnt[j]++;
			}
		}
		
		for(int v = 1; v < u; v++) {
			for(int k = 1; k <= n; k++) {
				if(dist[v][k] + dist[k][u] == dist[v][u]) dp[v][u] += cnt[k];
			}
		}
	}

	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) 
			printf("%d ", dp[i][j]);
	}

	return 0;
}
