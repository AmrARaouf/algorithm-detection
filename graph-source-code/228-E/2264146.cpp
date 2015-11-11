//Language: GNU C++


#include <vector>
#include <numeric>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <limits>
#include <iomanip>

using namespace std;

#define FOR(i,a,b)		for(int i=(a),_b=(b);i<(_b);++i)
#define FORD(i,a,b)		for(int i=(a),_b=(b);i>(_b);--i)
#define pb			push_back
#define mp			make_pair
#define	all(c)			(c).begin(),(c).end()
#define	tr(c,i)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define	present(c,x)		((c).find(x) != (c).end())
#define	cpresent(c,x)		(find(all(c),x) != (c).end())

typedef long long			ll;
typedef unsigned long long	ull;
typedef unsigned char	 	byte;
typedef vector<int>			vi;
typedef pair<int, int>		pii;
typedef pair<ll, ll>		pll;
typedef vector<pii>			vpii;

const int N = 25;

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen(argv[1],"r",stdin);
#endif
#ifndef ONLINE_JUDGE
	ifstream cin(argv[1]);
#endif
#if 0
	ofstream cout(argv[2]);
#endif
	int n,m;
	cin >> n >> m;
	bool roads[m][n+1];
	FOR(i,0,m) FOR(j,0,n+1) roads[i][j] = false;
	int x,y,k;
	FOR(i,0,m) {
		cin >> x >> y >> k;
		--x,--y;
		roads[i][x] = roads[i][y] = true;
		roads[i][n] = (k == 0);
	}
	bool used[m];
	FOR(i,0,m) used[i] = false;
	FOR(i,0,n) {
		int idx = -1;
		FOR(e,0,m) {
			if (!used[e] && roads[e][i]) {
				idx = e;
				break;
			}
		}
		if (idx == -1) continue;
		used[idx] = true;
		FORD(j,n,i-1) {
			if (roads[idx][j]) {
				FOR(e,0,m) {
					if (e != idx && roads[e][i])
						roads[e][j] = !roads[e][j];
				}
			}
		}
	}
	vi ans;
	FOR(i,0,m) {
		if (roads[i][n]) {
			bool ok = false;
			FOR(j,0,n) {
				if (roads[i][j]) {
					ans.pb(j+1);
					ok = true;
					break;
				}
			}
			if (!ok) {
				puts("Impossible");
				return 0;
			}
		}
	}
	cout << ans.size() << endl;
	FOR(i,0,ans.size())
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}
