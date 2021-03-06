//Language: GNU C++


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define DEBUG 0
using namespace std;

const int	MAX_N	= 100 + 10;
const int	MAX_V	= 200 + 10;
const int	MAX_S	= 1 << 7;
const int	INF		= 1000000;
const int	dx[]	= {-1, 0, 1, 0};
const int	dy[]	= {0, 1, 0, -1};
int			N, M, K, S;
int			w		[MAX_N][MAX_N];
int			f		[MAX_N][MAX_N][MAX_S];
int			pre		[MAX_N][MAX_N][MAX_S];
int			qx		[MAX_V];
int			qy		[MAX_V];
int			in		[MAX_N][MAX_N];
int			cov		[MAX_N][MAX_N];

void Init()
{
	int x, y;
	scanf("%d%d%d", &N, &M, &K);
	S = 1 << K;
	for(int i = 1; i <= N; ++ i) 
		for(int j = 1; j <= M; ++ j)
			scanf("%d", &w[i][j]);
	for(int i = 1; i <= N; ++ i)
		for(int j = 1; j <= M; ++ j)
			for(int k = 1; k < S; ++ k) {
				f[i][j][k] = INF;
				pre[i][j][k] = INF;
			}
	for(int i = 0; i < K; ++ i) {
		scanf("%d%d", &x, &y);
		f[x][y][1 << i] = w[x][y];
	}
}

void SPFA(int s)
{
	int qh = 0, qt = 0;
	for(int i = 1; i <= N; ++ i)
		for(int j = 1; j <= M; ++ j) {
			qx[qt] = i; qy[qt ++] = j;
			in[i][j] = true;
		}
	int nx, ny, px, py;
	for( ; qh < qt; ) {
		px = qx[qh]; py = qy[qh ++];
		for(int i = 0; i < 4; ++ i) {
			nx = px + dx[i]; ny = py + dy[i];
			if (nx > 0 && nx <= N && ny > 0 && ny <= M && f[nx][ny][s] > f[px][py][s] + w[nx][ny]) {
				f[nx][ny][s] = f[px][py][s] + w[nx][ny];
				pre[nx][ny][s] = - i;
				if (! in[nx][ny]) {
					in[nx][ny] = true;
					qx[qt] = nx; qy[qt ++] = ny;
				}
			}
		}
		in[px][py] = false;
	}
}

void DFS(int x, int y, int s)
{
	cov[x][y] = true;
	int tmp = pre[x][y][s];
	if (tmp == INF) return;
	if (tmp <= 0) DFS(x - dx[- tmp], y - dy[- tmp], s);
	else DFS(x, y, tmp), DFS(x, y, s - tmp);
}

void Solve()
{
	for(int s = 1; s < S; ++ s) {
		for(int i = 1; i <= N; ++ i)
			for(int j = 1; j <= M; ++ j)
				for(int ns = (s - 1) & s; ns; ns = (ns - 1) & s) 
					if (f[i][j][s] > f[i][j][ns] + f[i][j][s - ns] - w[i][j]) { 
						f[i][j][s] = f[i][j][ns] + f[i][j][s - ns] - w[i][j];
						pre[i][j][s] = ns;
					}
		SPFA(s);
		if (DEBUG) {
			printf("Now is state %d\n", s);
			for(int i = 1; i <= N; ++ i) {
				for(int j = 1; j <= M; ++ j)
					printf("%d ", f[i][j][s]);
				printf("\n");
			}
		}
	}
	int ax, ay, ans = INF;
	for(int i = 1; i <= N; ++ i)
		for(int j = 1; j <= M; ++ j)
			if (f[i][j][S - 1] < ans) {
				ans = f[i][j][S - 1];
				ax = i, ay = j;
			}
	printf("%d\n", ans);
	DFS(ax, ay, S - 1);
	for(int i = 1; i <= N; ++ i) {
		for(int j = 1; j <= M; ++ j)
			putchar(cov[i][j] ? 'X' : '.');
		putchar('\n');
	}
}

int main()
{
	Init();
	Solve();
	return 0;
}
