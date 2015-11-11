//Language: GNU C++


#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 15;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int d[1 << 16][MAX][MAX], mark[MAX * 2][MAX * 2], col;
pair<int, pair<int, int> > q[MAX * MAX * (1 << 16) + 5];
char t[MAX][MAX];
int n, m, len;
bool isav(int x, int y)
{
	return (0 <= x && x < n && 0 <= y && y < m && t[x][y] != '#');
}
void bfs(int smask, int sx, int sy)
{
	memset(d, 63, sizeof(d));
	d[smask][sx][sy] = 0;
	int h = 0, t = 0;
	q[t++] = make_pair(smask, make_pair(sx, sy));
	while (h < t)
	{
		int mask = q[h].first, x = q[h].second.first, y = q[h].second.second;
		h++;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!isav(nx, ny))
				continue;
			int nmask = mask;
			nmask >>= 2;
			nmask |= ((i ^ 2) << (2 * len - 4));
			col++;
			int tmask = mask;
			int xx = 15, yy = 15;
			bool valid = true;
			for (int j = 0; j < len; j++)
			{
				if (mark[xx][yy] == col)
				{
					valid = false;
					break;
				}
				mark[xx][yy] = col;
				xx += dx[tmask & 3];
				yy += dy[tmask & 3];
				tmask >>= 2;
			}
			if (valid && d[nmask][nx][ny] > d[mask][x][y] + 1)
			{
				d[nmask][nx][ny] = d[mask][x][y] + 1;
				q[t++] = make_pair(nmask, make_pair(nx, ny));
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int x, y, gx, gy;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> t[i][j];
			if (t[i][j] == '1')
			{
				x = i;
				y = j;
			}
			if (t[i][j] == '@')
			{
				gx = i;
				gy = j;
			}
			if ('1' <= t[i][j] && t[i][j] <= '9')
				len = max(len, t[i][j] - '0');
		}
	int mask = 0;
	int tx = x, ty = y;
	for (int i = 2; i <= len; i++)
		for (int j = 0; j < 4; j++)
		{
			int nx = tx + dx[j];
			int ny = ty + dy[j];
			if (isav(nx, ny) && t[nx][ny] == '0' + i)
			{
				mask <<= 2;
				mask |= j;
				tx = nx;
				ty = ny;
				break;
			}
		}
	bfs(mask, x, y);
	int ans = 1000000000;
	for (int i = 0; i < (1 << (2 * len - 2)); i++)
		ans = min(ans, d[i][gx][gy]);
	if (ans == 1000000000)
		ans = -1;
	cout << ans << endl;
	return 0;
}
