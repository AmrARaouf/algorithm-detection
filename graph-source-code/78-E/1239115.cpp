//Language: GNU C++


#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

const double pi = 3.1415926535;
const double eps = 1e-6;

const int fx[4] = {-1, 1, 0, 0};
const int fy[4] = {0, 0, -1, 1};
int n, t, sx, sy, dis[20][20], die[20][20], la[500], ro[500000], pr[500000], up[500000], now, bl[500], S, T, del, ans, rec[20][20], save[20][20], ma[20][20];
char c;
int index(int a, int b, int c)
{
	return (a * n + b) * 2 + c + 1;
}
bool dfs(int a, int b)
{
	if (a == T) {
		del = b;
		ans += b;
		return 1;
	}
	bl[a] = ans;
	for (int tmp = la[a]; tmp; tmp = pr[tmp])
		if (bl[ro[tmp]] != ans && up[tmp] && dfs(ro[tmp], min(up[tmp], b))) {
			up[tmp] -= del;
			up[tmp ^ 1] += del;
			return 1;
		}
	return 0;
}
void bfs(int sx, int sy)
{
	queue<int> Q;
	Q.push(sx * n + sy);
	memset(dis, -1, sizeof(dis));
	dis[sx][sy] = 0;
	while (!Q.empty()) {
		int x = Q.front() / n, y = Q.front() % n; Q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = x + fx[i], ty = y + fy[i];
			if (0 <= tx && tx < n && 0 <= ty && ty < n && ma[tx][ty] != -1 && dis[tx][ty] == -1 && (die[tx][ty] == -1 || die[tx][ty] > dis[x][y] + 1 || die[tx][ty] == dis[x][y] + 1 && save[tx][ty])) {
				if (!(die[tx][ty] == dis[x][y] + 1 && save[tx][ty]))
					Q.push(tx * n + ty);
				dis[tx][ty] = dis[x][y] + 1;
			}
		}
	}
}
void ins(int a, int b, int c) {
	now++;
	pr[now] = la[a];
	la[a] = now;
	ro[now] = b;
	up[now] = c;
	
	now++;
	pr[now] = la[b];
	la[b] = now;
	ro[now] = a;
	up[now] = 0;
}
int main()
{
	now = 1;
	scanf("%d%d", &n, &t);
	S = 0, T = 300;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf(" %c", &c);
			if (isdigit(c)) {
				ins(index(i, j, 1), T, c - '0');
				rec[i][j] = c - '0';
			} else if (c == 'Z') {
				sx = i, sy = j;
			} else ma[i][j] = -1;
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf(" %c", &c);
			if (isdigit(c)) {
				ins(S, index(i, j, 0), c - '0');
				save[i][j] = c - '0';
			}
		}
	memset(die, -1, sizeof(die));
	bfs(sx, sy);
	memcpy(die, dis, sizeof(die));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) if (ma[i][j] != -1 && rec[i][j]) {
			bfs(i, j);
			for (int x = 0; x < n; x++)
			for (int y = 0; y < n; y++)
				if (save[x][y] && dis[x][y] != -1 && t >= dis[x][y]) {
//					cout << x << ' ' << y << " to " << i << ' ' << j << endl;
					ins(index(x, y, 0), index(i, j, 1), 192837465);
				}
		}
	memset(bl, -1, sizeof(bl));
	ans = 0;
	while (dfs(S, 192837465));
	printf("%d\n", ans);
}
