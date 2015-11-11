//Language: GNU C++


#include <queue>
#include <string>
#include <vector>
#include <memory.h>
#include <iostream>
#include <algorithm>
using namespace std;
string b[51];
int cv, dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int lev[51][51], low[51][51], mark[51][51], n, m, C, fx, fy;
void dfs(int x, int y){
	mark[x][y] = true;
	lev[x][y] = C++;
	low[x][y] = lev[x][y] - 1;
	int br = 0;
	for (int i = 0;i < 4;++i){
		int nx = x + dir[i][0], 
			ny = y + dir[i][1];
		if (nx >= n || ny >= m || nx < 0 || ny < 0 || b[nx][ny] != '#')
			continue;
		if (mark[nx][ny]){
			low[x][y] = min(lev[nx][ny], low[x][y]);
		}
		else {
			++br;
			dfs(nx, ny);
			if (low[nx][ny] <= low[x][y])
				low[x][y] = low[nx][ny];
			if (low[nx][ny] == lev[x][y] && (x != fx || y != fy))
				cv = true;
		}
	}
	if (x == fx && y == fy && br > 1) cv = true;
	//cout << x << " " << y << "low: " << low[x][y] <<" br: " << br << endl;
}
int main(){
	int tmp = 0;
	cin >> n >> m;
	for (int i = 0;i < n;++i)
		cin >> b[i];
	for (int i = 0;i < n;++i)
		for (int j = 0;j < m;++j){
			if (b[i][j] == '#') ++tmp;
			fx = i, fy = j;
			if (!mark[i][j] && b[i][j] == '#')
				dfs(i, j);
		}
	//cout << tmp << " cv : " << cv << endl;
	if (tmp <= 2) cout << -1 << endl;
	else if (cv) cout << 1 << endl;
	else cout << 2 << endl;
	return 0;
}