//Language: GNU C++


#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 500, MAXM = MAXN * MAXN;;
int color[MAXN];
struct eglist {
	int other[MAXM], succ[MAXM], last[MAXM], sum;
	void clear(int n) {
		for(int i = 0; i <= n; i++)
			last[i] = 0;
		sum = 0;
	}
	void AddEdge(int a, int b) {
		other[++sum] = b, succ[sum] = last[a], last[a] = sum;
		other[++sum] = a, succ[sum] = last[b], last[b] = sum;
	}
}e;

int n, m, a[MAXN], b[MAXN];

int inside(int a, int l, int r) {
	if (l < r) {
		return l < a && a < r;
	} else {
		return (a <= n && a > l || a >= 1 && a < r);
	}
}

int intersec(int a, int b, int c, int d) {
	if (a == c || a == d || b == c || b == d)
		return 0;
	if (inside(b, c, d) ^ inside(a, c, d))
		return 1;
	return 0;
}

void dfs(int x, int c) {
	color[x] = c;
	for(int i = e.last[x]; i; i = e.succ[i]) {
		int y = e.other[i];
		if (!color[y])
			dfs(y, c * -1);
		else {
			if (color[y] != c * -1) {
				printf("Impossible\n");
				exit(0);
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++) {
		scanf("%d %d", &a[i], &b[i]);
	}
	for(int i = 1; i <= m; i++)
		for(int j = i + 1; j <= m; j++)
			if (intersec(a[i], b[i], a[j], b[j]))
				e.AddEdge(i, j);
	for(int i = 1; i <= m; i++) {
		if (!color[i])
			dfs(i, -1);
	}
	for(int i = 1; i <= m; i++) {
		printf("%c", color[i] == 1 ? 'o' : 'i');
	}
	printf("\n");
	return 0;
}

 	 		 	   			 					 	  	 	