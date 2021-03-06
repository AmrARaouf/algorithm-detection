//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1005
#define M 200005
using namespace std;

int n, m, ca, cb, na, nb, x, y, ed, ok;
int l[N], v[N], p[N];
int ax[M], ay[M], az[M], bx[M], by[M], bz[M];
int qd[M], qn[M], qt[M], qz[M];
char s[4];

int find(int x){
	if (p[x] == x) return x;
	return p[x] = find(p[x]);
}

void bd(int x, int y, int t, int z){
	qd[++ed] = y, qt[ed] = t, qz[ed] = z;
	qn[ed] = l[x], l[x] = ed;
}

void rm(int x, int y){
	if (qd[l[x]] == y && !qt[l[x]]){
		l[x] = qn[l[x]];
		return;
	}
	for (int i=l[x], j; i; i=qn[i]){
		j = qn[i];
		if (qd[j] == y && !qt[j]){
			qn[i] = qn[j];
			return;
		}
	}
}

int dfs(int x, int y){
	v[x] = 1;
	if (x == y) return 1;
	for (int i=l[x]; i; i=qn[i]){
		if (v[qd[i]]) continue;
		if (dfs(qd[i], y)){
			if (!ok && !qt[i] && ca>n/2){
				rm(x, qd[i]), rm(qd[i], x);
				ca--;
				ok = 1;
			}
			return 1;
		}
	}
	return 0;
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++){
		scanf("%d%d%s", &x, &y, s);
		if (s[0] == 'S') ax[na] = x, ay[na] = y, az[na++] = i;
		if (s[0] == 'M') bx[nb] = x, by[nb] = y, bz[nb++] = i;
	}
	
	for (int i=1; i<=n; i++) p[i] = i;
	for (int i=0; i<na; i++){
		x = ax[i], y = ay[i];
		if (find(x) == find(y)) continue;
		ca++;
		p[find(x)] = find(y);
		bd(x, y, 0, az[i]), bd(y, x, 0, az[i]);
	}
	
	for (int i=0; i<nb; i++){
		if (cb == n/2) break;
		x = bx[i], y = by[i];
		memset(v, 0, sizeof(v));
		ok = 0;
		if (!dfs(x, y) || ok){
			bd(x, y, 1, bz[i]);
			bd(y, x, 1, bz[i]);
			cb++;
		}
	}
	
	if (n%2 == 1 && ca == n/2 && cb == n/2){
		printf("%d\n", n-1);
		for (int i=1; i<=n; i++)
		for (int j=l[i]; j; j=qn[j])
		if (qd[j] > i) printf("%d ", qz[j]);
	}
	else printf("-1\n");
	return 0;
}
