//Language: GNU C++


#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <sstream>
#include <stack>
#include <cassert>
#include <ctime>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define pb push_back
#define sz(x) ((x).size())

const int N = 100009;
const int inf = 0x3f3f3f3f;
const ll oo = 0x3f3f3f3f3f3f3f3fll;

int n, m, k, a[N], vis[N];

struct Edge{
	int a, b;
	Edge(int a, int b) : a(a), b(b) {}
};

int p[N];

int find(int x){
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < k; i++){
		scanf("%d", &a[i]);
		vis[a[i]] = 1;
	}
	if(m == n * (n - 1) / 2 || k == n){
		cout << -1 << endl;
		return 0;
	}
	vector<Edge> vt, ans;
	for(int i = 1; i <= n; i++)
		p[i] = i;
	for(int i = 1; i <= n; i++){
		if(i == a[0] || i == a[1]) continue;
		for(int j = i + 1; j <= n; j++){
			if(j == a[0] || j == a[1]) continue;
			if(find(i) == find(j)) vt.pb(Edge(i, j));
			else ans.pb(Edge(i, j)), p[find(i)] = find(j);
		}
	}
	for(int i = 1; i <= n; i++){
		if(i == a[0] || i == a[1]) continue;
		if(vis[i]) {
			vt.pb(Edge(i, a[1]));
		}
		else {
			if(find(i) == find(a[1])) vt.pb(Edge(i, a[1]));
			else ans.pb(Edge(i, a[1])), p[find(i)] = find(a[1]);
			if(find(i) == find(a[0])) vt.pb(Edge(i, a[0]));
			else ans.pb(Edge(i, a[0])), p[find(i)] = find(a[0]);
		}
	}
	int t = 0;
	while(ans.size() < m){
		if(t == vt.size()) break;
		ans.pb(vt[t++]);
	}
	if(ans.size() != m) cout << -1 << endl;
	else{
		for(int i = 0; i < ans.size(); i++)
			cout << ans[i].a << " " << ans[i].b << endl;
	}
	return 0;
}
