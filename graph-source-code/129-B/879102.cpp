//Language: MS C++


#include <iostream>
#include <vector>

using namespace std;

bool G[110][110];

int main(){
	int n, m; cin >> n >> m;
	int a, b;
	memset(G, false, sizeof(G));
	for ( int i = 0; i < m; i++ ){
		cin >> a >> b;
		G[a][b] = G[b][a] = true;
	}
	int ans = 0;
	while ( true ){
		vector<int> targets;
		for ( int i = 1; i <= n; i++ ){
			int cnt = 0;
			for ( int j = 1; j <= n; j++ ) if ( G[i][j] ) {
				cnt++;
			}
			if ( cnt == 1 ) targets.push_back(i);
		}
		if ( targets.empty() ){
			break;
		} else {
			for ( int i = 0; i < (int)targets.size(); i++ ){
				for ( int row = 1; row <= n; row++ )
					G[row][targets[i]] = 0;
				for ( int col = 1; col <= n; col++ )
					G[targets[i]][col] = 0;
			}
			ans++;
		}
	}
	
	cout << ans << endl;
}