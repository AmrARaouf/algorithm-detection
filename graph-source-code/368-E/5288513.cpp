//Language: GNU C++


/**											Be name Khoda											**/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <climits>
using namespace std;

#define ll long long
#define un unsigned
#define pii pair<ll, ll>
#define pb push_back
#define mp make_pair
#define VAL(x) #x << " = " << x << "   "
#define SQR(a) ((a) * (a))
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define CLR(x, a) memset(x, a, sizeof x)
#define FOREACH(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); i ++)
#define X first
#define Y second
#define PI (3.141592654)

//#define cout fout
//#define cin fin

//ifstream fin("problem.in");
//ofstream fout("problem.out");

const int MAXN = 100 * 1000 + 10, INF = INT_MAX, MOD = 1e9 + 7;

ll a[MAXN];

int main ()
{
	ios::sync_with_stdio(false);

	ll n, m;
	cin >> n >> m;
	for (int i = 0, t; i < m; i ++)
		cin >> t >> a[i];
	sort(a, a + m, greater<int>());

	ll ans = 0;
	for (ll i = 0; i < m; i ++)
	{
		if (!(i % 2) && n - 1 < i * (i + 1) / 2) break;
		if ((i % 2) && n < SQR(i + 1) / 2) break;
		ans += a[i];
	}
	cout << ans << endl;
	return 0;
}
