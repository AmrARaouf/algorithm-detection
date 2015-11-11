//Language: GNU C++0x


#include<iostream>
#include<cstdio>
#include<bitset>
#include<algorithm>
#include<utility>
#include<map>
#include<cassert>
#include<vector>
#include<stack>

using namespace std;

#define mp make_pair
#define pb push_back
#define LL long long
#define VMAX 2000001
#define MOD1 1000000007
#define ALL(V) (V).begin(), (V).end()
#define ALLR(V) (V).rbegin(), (V).rend()

int PASSED_POINT = 0;

void Duxar() {
	#ifndef ONLINE_JUDGE
		printf("\n . . . . . . . . . . . . . Passed point - %d\n", ++PASSED_POINT);
	#endif
}

void read_int(int &value) {
	int sign = 1;
	char ch;
	value = 0;
	while(!isdigit(ch = getchar())) {
		(ch == '-') && (sign = -1);
	}
	do {
		value = value * 10 + (ch - '0');
	} while(isdigit(ch = getchar()));
	value *= sign;
}

int N, K;
char graph[1001][1001];

void add_edge(int x, int y) {
	graph[x][y] = graph[y][x] = 'Y';
}

void add_vertex(int from, int &st, int cnt) {
	while (cnt) {
		++st; --cnt;
		add_edge(from, st);
		from = st;
		assert(st <= 1000);
	}
	add_edge(from, 2);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input", "r", stdin);
#endif
	int i, j, dist = 0, st = 2, n1, n2;
	read_int(K);
	Duxar();
	if (K == 1) {
		add_vertex(1, st, dist);
		st = 2;
		Duxar();
	}
	else {
		st = 2; n1 = n2 = 1; dist = 0;
		for (i = 1; (1 << i) <= K; ++i) {
			++dist;
			st += 2;
			add_edge(n1, st); add_edge(n1, st - 1);
			add_edge(n2, st); add_edge(n2, st - 1);
			n1 = st - 1; n2 = st;
		}
		Duxar();
		add_edge(n1, 2); add_edge(n2, 2);
		for (i = i - 2; i >= 0; --i) {
			if (K & (1 << i)) {
				if (i == 0) {
					add_vertex(1, st, dist);
				}
				else {
					n1 = i * 2 + 1;
					n2 = n1 + 1;
					++st;
					add_edge(n1, st);
					add_edge(n2, st);
					add_vertex(st, st, dist - i - 1);
				}
			}
		}
	}
	N = st;
	printf("%d\n", N);
	for (i = 1; i <= N; ++i) {
		for (j = 1; j <= N; ++j) {
			if (graph[i][j] == 'Y') {
				printf("Y");
			}
			else {
				printf("N");
			}
		}
		printf("\n");
	}
	return 0;
}
