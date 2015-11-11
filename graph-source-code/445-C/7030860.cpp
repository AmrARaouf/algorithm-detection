//Language: GNU C++


#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;
const int INF = 1<<30;

int con[501][501];

int main() {
	memset( con, 0, sizeof(con) );
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> vx;
	vx.push_back(0);
	rep(i, n) {
		int v;
		scanf("%d", &v);
		vx.push_back(v);
	}
	rep(i, m) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		con[a][b] = con[b][a] = c;
	}
	if(n==1) {
		printf("0\n");
		return 0;
	}
	double mx = 0;
	int mi=-1, mj=-1;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if( con[i][j] > 0 ) {
				double d = 1. * (vx[i]+vx[j]) / con[i][j];
				if( mx < d ) {
					mx = d;
					mi = i;
					mj = j;
				}
			}
		}
	}
	if( mi==-1 ) {
		printf("0\n");
		return 0;
	}
	bool visit[501] = {};
	visit[mi] = visit[mj] = true;
	int cost[501] = {};
	for(int i=1; i<=n; i++) {
		cost[i] += con[mi][i];
		cost[i] += con[mj][i];
	}
	ll nv=vx[mi]+vx[mj], ne=con[mi][mj];
	while(1) {
		int ni = -1;
		for(int i=1; i<=n; i++) {
			if( !visit[i] && cost[i]>0 && (ni==-1 || 1.*(nv+vx[i])/(ne+cost[i]) > 1.*(nv+vx[ni])/(ne+cost[ni])) ) {
				ni = i;
			}
		}
		if(ni==-1) break;
		if( 1.*nv/ne > 1.*(nv+vx[ni])/(ne+cost[ni]) ) {
			break;
		}
		visit[ni] = true;
		nv += vx[ni];
		ne += cost[ni];
		for(int i=1; i<=n; i++) {
			cost[i] += con[ni][i];
		}
	}
	printf("%.10lf\n", 1.*nv/ne);
	return 0;
}
