//Language: GNU C++





#include <cstdio>
#include <cstring>
using namespace std;

#define INF 1000000000
#define MAXN 205
#define MAXM 1000
#define MAXK 7

int dp[MAXN][1<<MAXK], f[MAXN][1<<MAXK][2], q[MAXN], qr, qw;  bool v[MAXN];
void trace(int z, int s, bool sol[]) {
	if (f[z][s][0] == -1) sol[z] = true;
	else if (f[z][s][0] == z) trace(f[z][s][0], s^f[z][s][1], sol), trace(f[z][s][0], f[z][s][1], sol);
	else sol[z] = true, trace(f[z][s][0], f[z][s][1], sol);
}
int SMST(int n, int w[], int h[], int t[][2], int l[], int k, bool sol[]) {
	int state = 1<<k;
	for (int i=0; i<n; ++i)
		for (int j=0; j<state; ++j)
			dp[i][j] = (j==0 ? 0 : INF);
	for (int i=0; i<k; ++i) {
		dp[l[i]][1<<i] = w[l[i]];
		f[l[i]][1<<i][0] = f[l[i]][1<<i][1] = -1;
	}
	qr = qw = 0;
	memset(v, true, sizeof(v));
	for (int i=0; i<state; ++i) {
		for (int j=0; j<n; ++j) {
			for (int o=(i-1)&i; o>0; o=(o-1)&i) {		// (o|i)==i AND 0<o<i
				int tmp = dp[j][i^o] + dp[j][o] - w[j];
				if (tmp < dp[j][i]) {
					dp[j][i] = tmp;
					f[j][i][0] = j;
					f[j][i][1] = o;
				}
			}
			if (dp[j][i] != INF) {
				q[qw++] = j;
				if (qw == MAXN) qw = 0;
				v[j] = false;
			}
		}
		while (qr != qw) {
			int x = q[qr++];
			if (qr == MAXN) qr = 0;
			v[x] = true;
			for (int j=h[x]; j!=-1; j=t[j][1]) {
				int y = t[j][0];
				if (dp[x][i] + w[y] < dp[y][i]) {
					dp[y][i] = dp[x][i] + w[y];
					f[y][i][0] = x;
					f[y][i][1] = i;
					if (v[y]) {
						q[qw++] = y;
						if (qw == MAXN) qw = 0;
						v[y] = false;
					}
				}
			}
		}
	}
	int mi = INF, mii = -1;
	for (int i=0; i<n; ++i)
		if (dp[i][state-1] < mi)
			mi = dp[i][state-1], mii = i;
	for (int i=0; i<n; ++i) sol[i] = false;		// memset fail
	trace(mii, state-1, sol);
	return mi;
}







int m, n, k, w[MAXN], h[MAXN], t[MAXM][2], tw, l[MAXK];

void adde(int x, int y) {
	t[tw][0] = y;
	t[tw][1] = h[x];
	h[x] = tw++;
}

int main() {
	scanf("%d%d%d", &m, &n, &k);
	memset(h, -1, sizeof(h));
	tw = 0;
	for (int i=0; i<m; ++i) {
		for (int j=0; j<n; ++j) {
			scanf("%d", &w[i*n+j]);
			if (i) adde((i-1)*n+j, i*n+j), adde(i*n+j, (i-1)*n+j);
			if (j) adde(i*n+(j-1), i*n+j), adde(i*n+j, i*n+(j-1));
		}
	}
	for (int i=0; i<k; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		l[i] = x*n+y;
	}
	bool sol[MAXN];
	int ans = SMST(m*n, w, h, t, l, k, sol);
	printf("%d\n", ans);
	for (int i=0; i<m; ++i) {
		for(int j=0; j<n; ++j) {
			printf("%c", sol[i*n+j] ? 'X' : '.');
		}
		printf("\n");
	}
	return 0;
}
