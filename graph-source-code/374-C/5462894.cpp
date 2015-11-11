//Language: GNU C++0x


#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e3+10;

char maze[N][N];
int n, m;

int maxLength[N][N], inStack[N][N], hadLoop;
const int shift[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
const char dima[] = "DIMA";
int dfs(int x, int y, int z = 0) {
	if (~maxLength[x][y]) return maxLength[x][y];
	inStack[x][y] = 1;
	int tempMaxLength = 0;
	for (int i = 0; i < 4; i++) {
		int tx = x+shift[i][0], ty = y+shift[i][1];
		if (0 <= tx && tx < n && 0 <= ty && ty < m
			&& maze[tx][ty] == dima[(z+1)%4]) {
			if (inStack[tx][ty]) {
					hadLoop = 1;
					continue;
			}
			tempMaxLength = max(tempMaxLength, dfs(tx, ty, z+1));
		}
	}
	inStack[x][y] = 0;
	return maxLength[x][y] = 1+tempMaxLength;
}

int main() {
	while (~scanf("%d%d", &n, &m)) {
		for (int i = 0; i < n; i++) scanf("%s", maze[i]);
		memset(maxLength, -1, sizeof(maxLength));
		memset(inStack, 0, sizeof(inStack));
		hadLoop = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (maze[i][j] == 'D')
					dfs(i, j);
		int result = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (maze[i][j] == 'D')
					result = max(result, maxLength[i][j]);
		if (hadLoop) puts("Poor Inna!");
		else if (result/4) printf("%d\n", result/4);
		else puts("Poor Dima!");
	}
	return 0;
}