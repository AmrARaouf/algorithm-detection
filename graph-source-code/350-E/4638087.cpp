//Language: GNU C++0x


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>

#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define clr(a, b) memset(a, b, sizeof(a))
#define sz(a) ((int)(a).size())
#define pb push_back

#define N 300

int i,j,k,m,n,l;
vi a;
bool v[N+10];

void solve(){
	if (l==n || m>(n-1)*(n-2)/2+(n-l)){
		puts("-1"); return;
	}

	repf(i, 1, n) if (!v[i]) a.pb(i);

	swap(a[1], a[n-1]);

	rep(i, n-1) printf("%d %d\n", a[i], a[i+1]), m--;

	repf(i, 2, n-1){
		repf(j, 1, i-2){
			if (m)
				m--, printf("%d %d\n", a[j], a[i]);
		}
		if (!v[a[i]] && m)
			m--, printf("%d %d\n", a[0], a[i]);
	}
}

int main(){
	while (~scanf("%d%d%d", &n, &m, &l)){
		clr(v, 0);
		a.clear();
		rep(i, l) scanf("%d", &k), a.pb(k), v[k]=1;
		solve();
	}
	return 0;
}

