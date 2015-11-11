//Language: GNU C++


#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>

using namespace std;

const int maxN = 200;

int mat[maxN][maxN];
int N, M;

int main() {
	int i, j;
	#ifndef ONLINE_JUDGE
		freopen("E.in", "r", stdin);
		freopen("E.out", "w", stdout);
	#endif

	scanf("%d", &N);
	for (i = 1; i <= N; i++)
		for (j = i - 1; j > 0; j -= 2) {
			mat[i][j] = 1;
			M++;
		}

	printf("%d\n", M);
	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++)
			if (mat[i][j])
				printf("%d %d\n", i, j);

//	printf("\n");

	return 0;
}
