//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <iostream>

using namespace std;

#define INF 0x3f3f3f3f

typedef pair<int,int> ii;

int flag,cont;
char mat[12][12],mapa[12][12][12];

void update() {
	for (int i=7; i>=0; i--)
		for (int j=0; j<8; j++)
			if (mat[i][j] == 'S') {
				mat[i][j] = '.';	mat[i+1][j] = 'S';
			}
	return;
}

void dfs(int k, int i, int j) {
	if (i<0 || j<0 || i>7 || j>7) return;
	if (mapa[k][i][j] == 'S') return;
	if (k == 8) {	flag=1;	return;	}

	if (mapa[k+1][i][j] != 'S') dfs(k+1,i,j);
	if (i<7 && mapa[k][i+1][j] != 'S') dfs(k+1,i+1,j);
	if (i<7 && j<7 && mapa[k][i+1][j+1] != 'S') dfs(k+1,i+1,j+1);
	if (i<7 && j && mapa[k][i+1][j-1] != 'S') dfs(k+1,i+1,j-1);
	
	if (i && mapa[k][i-1][j] != 'S') dfs(k+1,i-1,j);
	if (i && j<7 && mapa[k][i-1][j+1] != 'S') dfs(k+1,i-1,j+1);
	if (i && j && mapa[k][i-1][j-1] != 'S') dfs(k+1,i-1,j-1);

	if (j<7 && mapa[k][i][j+1] != 'S') dfs(k+1,i,j+1);
	if (j && mapa[k][i][j-1] != 'S') dfs(k+1,i,j-1);


	return;
}

int main() {
	for (int i=0; i<8; i++)
		scanf(" %s",mat[i]);

	for (int k=0; k<9; k++) {
		for (int i=0; i<8; i++)
			for (int j=0; j<8; j++) mapa[k][i][j] = mat[i][j];

		update();
	}

	flag=0;
	dfs(0,7,0);

	if (flag) printf("WIN\n");
	else printf("LOSE\n");
	
}
