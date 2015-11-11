//Language: GNU C++


#include <stdio.h>
#include <map>

using namespace std;

#define U 1234567890
#define maxn 444444

map<int, int> u, f;
int t[maxn], p[maxn], x, i, ai, aj, n, ii, ans[maxn], sv;
pair<int, int> pp;

void addedge(int x, int y){
	++ii;
	t[ii] = y;
	p[ii] = f[x];
	f[x] = ii;
	++u[x];
}

void dfs(int x){
	ans[++ans[0]] = x;
	u[x] = U;
	int q = f[x];
	while (q) {
		if (u[t[q]] != U){
			dfs(t[q]);
			break;
		}
		q = p[q];
	}
}

int main(){
	scanf("%d", &n);
	for(i = 0; i<n; i++){
		scanf("%d %d", &ai, &aj);
		addedge(ai, aj);
		addedge(aj, ai);
	}
	for(map<int, int> :: iterator it = u.begin(); it != u.end(); it++){
		pp = *it;
		if (pp.second == 1){
			sv = pp.first;
			break;
		}
	}
	while (!sv) ; 
	dfs(sv);
	for(i = 1; i<ans[0]; i++) printf("%d ", ans[i]);
	printf("%d\n", ans[ans[0]]);
	return 0;
}