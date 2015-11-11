//Language: GNU C++


#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<time.h>
using namespace std;
typedef long long ll;

const int MAXN = 207;
const int MAX = 1<<25;
const int T = 100;
int g[MAXN][MAXN];
int x[MAXN*MAXN], y[MAXN*MAXN], W[MAXN*MAXN];

double getv(int n, int u, int v, double x) {
	double ret = 0;
	for(int i = 1; i <= n; i++) ret = max(ret, min(g[i][u] + x, g[i][v] + g[u][v] - x));
	return ret;
}

int main() {
	int n, m;
	while(~scanf("%d%d", &n, &m)) {
		int u, v, w;
		int i, j, k;
		for(i = 1; i <= n; i++) for(j = 1; j <= n; j++) {
			if(i == j) g[i][j] = 0;
			else g[i][j] = MAX;
		}
		for(i = 0; i < m; i++) {
			scanf("%d%d%d", &u, &v, &w);
			g[u][v] = g[v][u] = w;
			x[i] = u, y[i] = v;
		}
		while(true) {
			bool bans = false;
			for(i = 1; i <= n; i++) for(j = 1; j <= n; j++) for(k = 1; k <= n; k++) {
				if(g[i][k] > g[i][j] + g[j][k]) {
					g[i][k] = g[i][j] + g[j][k];
					bans = true;
				}
			}
			if( !bans) break;
		}
		double ans = 1<<25;
		for(j = 0; j < m; j++) {
			u = x[j], v = y[j];
			double l = 0, r = g[u][v], mid, mmid;
			double minw = MAX, w, tl, tr;
			for(i = 0; i < T; i++) {
				tl = g[u][v] * i / T, tr = g[u][v] * (i+1) / T;
				w = getv(n, u, v, (tl + tr) / 2);
				if(w < minw) {
					minw = w;
					l = tl, r = tr;
				}
			}
			while(fabs(l-r) > 1e-6) {
				mid = (l+r) / 2;
				mmid = (mid + r) / 2;
				if(getv(n, u, v, mid) > getv(n, u, v, mmid)) l = mid;
				else r = mmid;
			}
			ans = min(ans, getv(n, u, v, l));		
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}
						
			
					 
		














