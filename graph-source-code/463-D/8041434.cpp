//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;

int n, K, t, ans = 1;
vector< vector<int> > hash, AdjList;
vector<int> dis, vis;

void findEdges() {
	for (int i = 0; i < n; i++ ) {
		for (int j = 0; j < n; j++ ) {
			if( i == j ) continue;
			bool ok = true;
			for (int k = 0; k < K; k++ ) {
				if (hash[k][i] >= hash[k][j]) ok = false;
			}
			if(ok) AdjList[i].push_back(j);
		}
	}
}
void dfs( int cur ) {
	if( vis[ cur ] ) return;

	vis[cur] = 1;
	for (int i = 0; i < AdjList[cur].size(); i++ ) {
		int neigh = AdjList[cur][i];
		if( not vis[neigh] )
			dfs(neigh);
		dis[cur] = max( dis[cur], dis[neigh] + 1);
	}
	ans = max( ans, dis[cur] );
}
int main()
{
	int num;
	scanf("%d %d", &n, &K );
	hash.resize( K,  vector<int>(n, 0) );
	AdjList.resize(n), dis.resize(n, 1), vis.resize(n, 0);

	for( int i = 0; i < K ; i++ ) {
		for (int j = 0; j < n; j++ ) {
			scanf("%d", &num );
			num--;
			hash[i][ num ] = j;
		}
	}
	
	findEdges();
	for (int i = 0; i < n ; i++ ) if(not vis[i] ) dfs(i);
	printf("%d\n", ans);
	return 0;
}