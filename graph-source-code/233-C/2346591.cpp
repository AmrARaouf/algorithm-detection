//Language: GNU C++


#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>
#include <stack>
using namespace std;

typedef long long int int64;

#define EPS 10e-9
#define INF 0x3f3f3f3f
#define REP(i,n) for(int i=0; i<(n); i++)

int matriz[120][120];
int vert;

pair<int64, int64> calcula(int64 x) {
	int64 y = 3;
	pair<int64, int64> res;
	int64 ant;
	while (1) {
		int64 a = (y * (y-1) * (y-2)) / 6;
		if (a <= x) {
			res.first = y;
			res.second = x - a;
		}
		else {
			break;	
		}
		y++; 	
	}
	return res;	
}

pair<int64, int64> calcula2(int64 x) {
	int64 y = 3;
	pair<int64, int64> res;
	int64 ant = 0;
	int64 aux;
	while (1) {
		int64 a = (y * (y-1) * (y-2)) / 6;
		aux = a;
		a = a-ant;
		if (a <= x) {
			res.first = y;
			res.second = x - a;	
		}
		else {
			break;	
		}
		ant = aux;
		y++;
	}
	return res;	
}

int main()
{	
	int64 n;
	cin >> n;
	pair<int64, int64> a = calcula(n);
	vert = a.first;
	memset(matriz, 0, sizeof(matriz));
	for (int i = 0; i < vert; i++) {
		for (int j = 0; j < vert; j++) {
			if (i == j) continue;
			matriz[i][j] = 1;	
		}	
	}
	int64 x = a.second;
	while (1) {
		if (x == 0) break;
		//printf("%lld\n", x);
		a = calcula2(x);
		for (int i = 0; i < a.first-1; i++) {
			matriz[vert][i] = 1;
			matriz[i][vert] = 1;	
		}
		vert++;
		x = a.second;
	}
	printf("%d\n", vert);
	REP(i, vert) {
		REP(j, vert) {
			printf("%d", matriz[i][j]);	
		}
		printf("\n");
	}
	return 0;
}