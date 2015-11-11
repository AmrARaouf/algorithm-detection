//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;

#define FOR(a, b, c) for(int a = (b); a <= (c); a++)
#define REP(a, b) for(int a = 0; a < (b); a++)
#define FORD(a, b, c) for(int a = (b); a >= (c); a--)
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define si size()
#define mp make_pair
#define st first
#define nd second

int n, r1, r2, a, d[100000];
bool k[100000];
vector<int> v[100000];

void dfs(int x, int y) {
	k[x] = true;
	d[x] = y;
	REP(i, v[x].si) {
		if(!k[v[x][i]])
			dfs(v[x][i], x);
	}
}

int main() {
	scanf("%d%d%d", &n, &r1, &r2);
	FOR(i, 1, n) {
		if(i!=r1) {
			scanf("%d", &a);
			v[i].pb(a);
			v[a].pb(i);
		}
	}
	dfs(r2, -1);
	FOR(i, 1, n) {
		if(i!=r2)
			printf("%d ", d[i]);
	}
	printf("\n");
	return 0;
}