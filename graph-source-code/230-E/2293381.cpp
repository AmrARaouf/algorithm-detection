//Language: GNU C++


#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <sstream>
#include <stack>
#include <cassert>

#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626433832795
#define sqr(x) (x)*(x)
#define forn(i, n) for(int i = 0; i < n; ++i)
#define ALL(x) x.begin(), x.end()
#define F first
#define S second
#define m0(x) memset(x,0,sizeof(x))
#define CC(x) cout << (x) << "\n"
#define pw(x) (1ull<<(x)).

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 2147483647;
const ll LLINF = 9223372036854775807LL;

int n, m, d[1000010];

int main() {
	cin >> n >> m;
	forn(i,m) {
		int a, b;
    scanf("%d %d", &a, &b);
		d[a]++;
		d[b]++;
	}
	
	ll res = 0;
	for(int v = 1; v <= n; v++) {
		ll a = d[v], b = n-1-a;
		res += a*(a-1)+b*(b-1)-a*b;
	}

	CC(res/6);
  return 0;
}
