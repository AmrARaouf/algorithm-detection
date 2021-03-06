//Language: GNU C++


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <queue>
using namespace std;
const int dx[4] = {0, 1, -1, 0};
const int dy[4] = {1, 0, 0, -1};
char a[20][20];
int destx, desty, sx, sy;
struct NODE {
	NODE(int xx, int yy, int ssta, int mm) : x(xx), y(yy), sta(ssta), m(mm) {}
	int x, y, sta, m;
};
bool used[15][15][65536];
int r, c;
int mk[15][15];
int bfs() {
	memset(used, 0, sizeof(used));
	int len = 1, nx = sx, ny = sy, tx, ty, sta = 0;
	for (len = 1; ;len++) {
		int k;
		for (k = 0; k < 4; k++) {
			tx = nx + dx[k], ty = ny + dy[k];
			if (tx >= 0 && ty >= 0 && tx < r && ty < c && a[tx][ty] == len + '1') {
				sta |= k << (2 * (len - 1));
				nx = tx, ny = ty;
				break;
			}
		}
		if (k < 4) continue;
		else break;
	}
	int mask = (1 << (2 * (len - 1))) - 1;
	NODE np(sx, sy, sta, 0);
	queue<NODE> qu;
	qu.push(np);
	used[sx][sy][sta] = 1;
	while (!qu.empty()) {
		np = qu.front();
		qu.pop();
		memset(mk, 0, sizeof(mk));
		sta = np.sta;
		nx = np.x, ny = np.y;
		for (int i = 1; i < len; i++) {
			int k = sta % 4;
			sta >>= 2;
			nx = nx + dx[k], ny = ny + dy[k];
			mk[nx][ny] = i + 1;
		}
		for (int k = 0; k < 4; k++) {
			tx = np.x + dx[k], ty = np.y + dy[k];
			sta = ((np.sta << 2) + (3 - k)) & mask;
			if (tx >= 0 && ty >= 0 && tx < r && ty < c && !used[tx][ty][sta]) {
				if (a[tx][ty] == '@') {
					return np.m + 1;
				}
				if (a[tx][ty] != '#' && (mk[tx][ty] == len || mk[tx][ty] == 0)) {
					used[tx][ty][sta] = 1;
					qu.push(NODE(tx, ty, sta, np.m + 1));
				}
			}
		}
	}
	return -1;
}
int main() {
	while (scanf("%d%d", &r, &c) != EOF) {
		for (int i = 0; i < r; i++) {
			scanf("%s", a[i]);
			for (int j = 0; j < c; j++) {
				if (a[i][j] == '@') {
					destx = i, desty = j;
				} else if (a[i][j] == '1') {
					sx = i, sy = j;
				}
			}
		}
		printf("%d\n", bfs());
	}
	return 0;
}
