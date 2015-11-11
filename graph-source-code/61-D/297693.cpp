//Language: GNU C++


//

#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <complex>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <set>

#define int long long
#define eps 10e-8
#define sqr(x) ((x) * (x))
#define prec(x) fixed << setprecision (x)
#define equal(a,b) ((bool) (abs ((a) - (b) < eps))) 
#define dis(x1,y1,x2,y2) (sqrt ((sqr ((x1) - (x2)))+(sqr ((y1) - (y2)))))
#define fur(i,s,e) for (int i = s; i < e; i++)
#define furm(n,m) for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
#define fure(n) for (int i = 0; i < n; i++)
#define furv(i,n) for (int i = 0; i < n; i++)
#define furev(i,s,e) for (int i = e - 1; i >= s; i--)
#define dbgm(a) for (int i = 0; i < n; i++, cerr << endl) for (int j = 0; j < n; j++) cerr << a[i][j] << ' ';
#define finish(x) { cout << x << endl; return 0; }
#define dbg(a) for (int i = 0; i < n; i++) cerr << a[i] << ' '
#define point pair <int, int>
#define X first
#define Y second
//#define point complex <double>
//#define X real
//#define Y imag
#define first(v) (v[0])
#define last(v) (v[v.size() - 1])

using namespace std;

int adj[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
int coradj[4][2] = { {1, 1}, {-1, 1}, {-1, -1}, {1, -1} };
int alladj[8][2] = { {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0} };
int gcd (int a, int b) { return ((b)? gcd (b, a % b) : a); }
int rem (int a, int n) { return (a % n + n) % n; }

#define maxN (100 * 1000 + 10000)

int n;
vector <int> a[maxN];
vector <int> c[maxN];

int d[maxN], f[maxN];
int mark[maxN];

void dfs (int v)
{
	mark[v] = 1;

	for (int i = 0; i < a[v].size(); i++)
		if (!mark[a[v][i]])
			dfs (a[v][i]);

	int max = 0, el = 0;
	int count = 0;
	for (int i = 0; i < a[v].size(); i++)
		if (mark[a[v][i]] == 2)
		{
			count++;
			if (d[a[v][i]] + 2 * c[v][i] - f[a[v][i]] - c[v][i] > max)
				max = d[a[v][i]] + 2 * c[v][i] - f[a[v][i]] - c[v][i],
				el = i;
			d[v] += d[a[v][i]] + 2 * c[v][i],
			f[v] += d[a[v][i]] + 2 * c[v][i];
		}

	if (count)
	{
		f[v] -= d[a[v][el]] + 2 * c[v][el];
		f[v] += f[a[v][el]] + c[v][el];
	}
 
	//cerr << v << ' ' << d[v] << ' ' << f[v] << endl;

	mark[v] = 2;
}

main()
{
	cin >> n;

	fure (n - 1)
	{
		int x, y, w;
		cin >> x >> y >> w;
		x--; y--;

		a[x].push_back (y); a[y].push_back (x);
		c[x].push_back (w); c[y].push_back (w);
	}

	dfs (0);

	cout << f[0] << endl;

	return 0;
}

