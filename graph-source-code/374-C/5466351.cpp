//Language: GNU C++


#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

typedef long long ll;

using namespace std;

const int MaxN = 1000;

char a[MaxN][MaxN];
int down[MaxN][MaxN];
int maxRes = 0;
int n, m;

char next (char now) {
	switch (now) {
		case 'D' : return 'I';
		case 'I' : return 'M';
		case 'M' : return 'A';
		case 'A' : return 'D';
	}
}

bool ok (int row, int col) {
	return (row >= 0 && row < n && col >= 0 && col < m);
}

void dfs (int row, int col, char CUR = 'D') {
	down[row][col] = -2;
	int res = 0;
	int add = 0;
	if (CUR == 'A') add++, res = 1;
	if (ok(row - 1, col) && a[row - 1][col] == next(CUR)) {
		if (down[row - 1][col] == -2) {
			printf ("Poor Inna!");
			exit(0);
		}
		if (down[row - 1][col] >= 0)
			res = max(res, add + down[row - 1][col]);
		else {
			dfs(row - 1, col, next(CUR));
			res = max(res, add + down[row - 1][col]);
		}
	}
	if (ok(row + 1, col) && a[row + 1][col] == next(CUR)) {
		if (down[row + 1][col] == -2) {
			printf ("Poor Inna!");
			exit(0);
		}
		if (down[row + 1][col] >= 0)
			res = max(res, add + down[row + 1][col]);
		else {
			dfs(row + 1, col, next(CUR));
			res = max(res, add + down[row + 1][col]);
		}
	}
	if (ok(row, col - 1) && a[row][col - 1] == next(CUR)) {
		if (down[row][col - 1] == -2) {
			printf ("Poor Inna!");
			exit(0);
		}
		if (down[row][col - 1] >= 0)
			res = max(res, add + down[row][col - 1]);
		else {
			dfs(row, col - 1, next(CUR));
			res = max(res, add + down[row][col - 1]);
		}
	}
	if (ok(row, col + 1) && a[row][col + 1] == next(CUR)) {
		if (down[row][col + 1] == -2) {
			printf ("Poor Inna!");
			exit(0);
		}
		if (down[row][col + 1] >= 0)
			res = max(res, add + down[row][col + 1]);
		else {
			dfs(row, col + 1, next(CUR));
			res = max(res, add + down[row][col + 1]);
		}
	}
	down[row][col] = res;
}

int main () {
	scanf ("%d %d\n", &n, &m);
	for (int i = 0; i < n; i++)
		scanf ("%s", a[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			down[i][j] = -1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] == 'D' && down[i][j] == -1) {
				dfs(i, j);
				maxRes = max(maxRes, down[i][j]);
			}
	if (maxRes == 0) 
		printf ("Poor Dima!");
	else
		printf ("%d", maxRes);
}
