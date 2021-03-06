//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std; 
#define INF 1000000000
//typedef __int64 LL; 
#define N 1111
double eps = 0.0000001; 
int n, a, b; 
struct node {
	int x, y; 
}; 
node A, B, s[N], f[N]; 
int vis[N]; 
double Dis(node a, node b, node c) {
	double ret = 1e100;
	double gg = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    ret = min(ret, sqrt(gg));
    gg = (a.x - c.x) * (a.x - c.x) + (a.y - c.y) * (a.y - c.y);
    ret = min(ret, sqrt(gg));
    if (b.x == c.x && a.y <= max(b.y, c.y) && a.y >= min(b.y, c.y)) 
    	ret = min(ret, (double)abs(a.x - b.x));
    if (b.y == c.y && a.x <= max(b.x, c.x) && a.x >= min(b.x, c.x)) 
    	ret = min(ret, (double)abs(a.y - b.y));
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	scanf("%d%d", &a, &b); 
	scanf("%d%d%d%d", &A.x, &A.y, &B.x, &B.y); 
	scanf("%d", &n); 
	for(int i = 1;i <= n; i++) {
		scanf("%d%d%d%d", &s[i].x, &s[i].y, &f[i].x, &f[i].y); 
	}	
	memset(vis, -1, sizeof(vis)); 
	int dd = (A.x - B.x) * (A.x - B.x) + (A.y - B.y) *(A.y - B.y) ; 
	if(dd <= a*a) {
		printf("%.13lf\n", sqrt((double)dd)); 
		return 0; 
	}
	queue<int > Q; 
	for(int i = 1; i<= n; i++) {
		if(Dis(A, s[i], f[i]) <= eps + a) {
			Q.push(i); vis[i] = a + b; 
		}
	}
	while(!Q.empty()) {
		int now = Q.front(); Q.pop(); 
		for(int i = 1; i <= n; i++) {
			if(vis[i] != -1) continue; 
			double tmp = 1e20; 
			tmp = min(tmp, Dis(s[now], s[i], f[i])); 
			tmp = min(tmp, Dis(f[now], s[i], f[i])); 
			tmp = min(tmp, Dis(s[i], s[now], f[now])); 
			tmp = min(tmp, Dis(f[i], s[now], f[now])); 
			if(tmp <= eps + a) {
				vis[i] = vis[now] + a + b; Q.push(i); 
			}
		}
	}
	double ans = 1e20; 
	for(int i = 1;i <= n; i++) {
		if(vis[i] != -1) {
			if(Dis(B, s[i], f[i]) <= eps + a) {
				ans = min(ans, vis[i] + Dis(B, s[i], f[i])); 
			} 
		}
	}
	if(ans >= 1e20 - eps) {
		puts("-1"); 
	}
	else {
		printf("%.13lf\n", ans); 
	}

	
	return 0; 
}