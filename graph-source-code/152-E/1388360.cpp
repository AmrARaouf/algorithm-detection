//Language: GNU C++


#include <algorithm>
#include <ctime>
#include <iostream>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
const int inf = (1<<29);
const int N = 105, M = 105, NM = 205, K = 8;
int n, m, k, a[N][M], x[NM], y[NM], dp[1<<K][NM], dist[NM][NM], dist_parent[NM][NM];
pair<int,bool> dp_parent[1<<K][NM];

char result[N][M];

void construct_path(int i, int j) {
	//cout << i << " " << j << endl;
	if (dist_parent[i][j] == -1) {
		result[x[i]][y[i]] = 'X';
		result[x[j]][y[j]] = 'X';
	} else {
		int p = dist_parent[i][j];
		construct_path(i, p);
		construct_path(p, j);
	}
}
void construct_set(int i, int j) {
	if (dp_parent[i][j].first == -1) {
		REP(h, k) if (i & (1<<h)) {
			construct_path(h, j);
		}
	} else {
		pair<int,bool> p = dp_parent[i][j];
		if (p.second) {
			//merging
			construct_set(p.first, j);
			construct_set(i & ~p.first, j);
		} else {
			//tails
			construct_set(i, p.first);
			construct_path(p.first, j);
		}
	}
}

int main() {
	cin >> n >> m >> k;
	REP(i, n) REP(j, m) cin >> a[i][j];
	REP(i, k) { cin >> x[i] >> y[i]; x[i]--; y[i]--; }
	
	//do all pairs shortest path
	int c = k;
	REP(i, n) REP(j, m) {
		bool flag = true;
		REP(a, k) if (i == x[a] && j == y[a]) flag = false;
		if (flag) {
			x[c] = i; y[c] = j;
			c++;
		}
	}
	
	REP(i, c) REP(j, c) {
		if (i != j && ((abs(x[i] - x[j]) + abs(y[i] - y[j]) == 1))) {
			dist[i][j] = a[ x[j] ][ y[j] ];
		} else {
			dist[i][j] = inf;
		}
		dist_parent[i][j] = -1;
	}
	REP(i, c) dist[i][i] = 0;
	
	REP(i, c) REP(j, c) REP(k, c) {
		int new_dist = dist[j][i] + dist[i][k];
		if (new_dist < dist[j][k]) {
			dist[j][k] = new_dist;
			dist_parent[j][k] = i;
		}
	}
		
	REP(i, c) REP(j, c) if (i != j) dist[i][j] -= a[ x[j] ][ y[j] ];
	
	//now dist[j][k] gives the length of the (...) path (i.e. not start or end square)
	
	/*REP(i, c) {
		REP(j, c) cout << dist[i][j] << " ";
		cout << endl;
	}*/
	
	//dp!
	REP(i, 1<<k) {
		if (i) {
			REP(j, c) {
				//min cost to connect the subset i and point j
				REP(h, k) if (i & (1<<h)) dp[i][j] += a[x[h]][y[h]] + dist[h][j];
				if (!( j < k && (i & (1<<j)) )) dp[i][j] += a[ x[j] ][ y[j] ];
				dp_parent[i][j].first = -1;
			
				for (int g = i; g; g = (g - 1) & i) if (g && (i & ~g)) {
					int new_v = dp[g][j] + dp[i & ~g][j] - a[x[j]][y[j]];
					if (new_v < dp[i][j]) {
						dp[i][j] = new_v; 
						dp_parent[i][j] = make_pair(g, true);
					}
				}
				
				/*REP(h, k) if (i & (1<<h)) cout << a[x[h]][y[h]] << " ";
				cout << a[x[j]][y[j]] << " -- " << dp[i][j] << endl;*/
			}
			
			//tails
			REP(j, c) {
				REP(k, c) {
					int new_v = dp[i][j] + dist[j][k] + a[x[k]][y[k]];
					if (new_v < dp[i][k]) {
						dp[i][k] = new_v;
						dp_parent[i][k] = make_pair(j, false);
					}
				}
			}
		} else {
			REP(j, c) dp[i][j] = 0;
		}
	}
	
	//cout << dist[0][1]+dist[0][0] << endl;
	
	int best = 0;
	REP(j, c) if (dp[(1<<k)-1][j] < dp[(1<<k)-1][best]) best = j;
	
	REP(i, n) REP(j, m) result[i][j] = '.';
	
	cout << dp[(1<<k)-1][best] << endl;	
	construct_set((1<<k)-1,best);
	REP(i, n) {
		REP(j, m) cout << result[i][j];
		cout << endl;
	}	
}