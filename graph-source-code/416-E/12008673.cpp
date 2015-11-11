//Language: GNU C++


#include <bits/stdc++.h>

using namespace std;

#define MAX 502
#define INF 1000000000

int dp[MAX][MAX], dp1[MAX][MAX], dp2[MAX][MAX], edge[MAX][MAX];
vector<pair<int, int> > graph;
vector<int> weight;

int main(){
	for(int i=0 ; i<MAX ; i++){
		for(int j=0 ; j<MAX ; j++){
			if(i != j){
				dp[i][j] = INF; 
				dp1[i][j] = INF;
			}
		}
	}

	int n, m, u, v, w;
	scanf("%d %d", &n, &m);

	for(int i=0 ; i<m ; i++){
		scanf("%d %d %d", &u, &v, &w);

		dp[u][v] = w;
		dp[v][u] = w;

		graph.push_back(make_pair(u, v));
		weight.push_back(w);

		dp1[u][v] = dp1[v][u] = 1;
	}

	for(int k=1 ; k<=n ; k++){
		for(int i=1 ; i<=n ; i++){
			for(int j=1 ; j<=n ; j++){
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}

	for(int i=0 ; i<graph.size() ; i++){
		for(int j=1 ; j<=n ; j++){
			if(dp[j][graph[i].first] + weight[i] == dp[j][graph[i].second])
				edge[j][graph[i].second]++;
			if(dp[j][graph[i].second] + weight[i] == dp[j][graph[i].first])
				edge[j][graph[i].first]++;
		}
	}

	for(int i=1 ; i<=n ; i++){
		for(int j=i+1 ; j<=n ; j++){
			int count = 0;
			for(int k=1 ; k<=n ; k++){
				if(dp[i][k] + dp[k][j] == dp[i][j])
					count += edge[i][k];
			}
			printf("%d ", count);
		}
	}

	return 0;
}