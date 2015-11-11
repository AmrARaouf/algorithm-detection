//Language: MS C++


#include <stdio.h>

int n, m;
const int maxint = 1000000000;

int a[501][501];
int dis[501][501];
int t[501][501]; // t[i][j] 表示从i到j的最短路的第一个节点，有多少种可能性？
int c[501][501]; 

void compute(int i, int j){
	if (a[i][j] == dis[i][j]) t[i][j] = c[i][j] = 1;
	else t[i][j] = c[i][j] = 0;
	for (int k = 1; k <= n; k++)
		if (k != i && k != j && a[i][k] > 0 && a[i][k] + dis[k][j] == dis[i][j]){
			t[i][j]++; c[i][j] ++;
		}
	for (int k = 1; k <= n; k++)
		if (k != i && k != j && dis[i][k] + dis[k][j] == dis[i][j]){
			if (t[k][j] == -1) compute(k, j);
			c[i][j] += t[k][j];
		}
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i == j) {
				t[i][j] = dis[i][j] = 0;
			}
			else{
				t[i][j] = -1; dis[i][j] = maxint;
			}
	for (int i = 0; i < m; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		scanf("%d", &a[x][y]);
		dis[x][y] = dis[y][x] = a[y][x] = a[x][y];
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (dis[i][k] + dis[k][j] < dis[i][j]) dis[i][j] = dis[i][k] + dis[k][j];
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++){
			if (dis[i][j] < maxint) compute(i, j);
			printf("%d ", c[i][j]);
		}
}
