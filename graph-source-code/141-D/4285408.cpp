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
using namespace std;

#define ll long long
#define un unsigned
#define pii pair<int, int>
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

const int MAXN = 300 * 1000 + 10, INF = 1e9 + 7;

set<pii> heap;
bool mark[MAXN];
vector<pair<pii, int> > adj[MAXN];
int d[MAXN], n = 0;
pii par[MAXN];

void dij()
{
	int x = 0;
	for (int k = 0; k < n; k ++)
	{
		mark[x] = true;
		for (int i = 0; i < SZ(adj[x]); i ++)
		{
			int v = adj[x][i].X.X, w = adj[x][i].X.Y, idx = adj[x][i].Y;
			if (!mark[v] && d[v] > d[x] + w)
			{
				par[v] = mp(x, idx);
				heap.erase(mp(d[v], v));
				d[v] = d[x] + w;
				heap.insert(mp(d[v], v));
			}
		}
		x = heap.begin()->Y;
		heap.erase(*heap.begin());
	}
}

pair<pii, pii> e[MAXN];
set<int> s;
map<int, int> idx;
map<pii, int> edge;

int main ()
{
	ios::sync_with_stdio(false);

	int m, L;
	cin >> m >> L;
	s.insert(0);
	s.insert(L);
	for (int i = 0; i < m; i ++)
	{
		cin >> e[i].X.X >> e[i].X.Y >> e[i].Y.X >> e[i].Y.Y;
		if (e[i].X.X - e[i].Y.Y >= 0 && e[i].X.Y >= e[i].Y.X)
		{
			s.insert(e[i].X.X - e[i].Y.Y);
			s.insert(e[i].X.X + e[i].X.Y);
		}
	}
	vector<int> v;
	FOREACH(i, s)
	{
		idx[*i] = n;
		v.pb(*i);
		n ++;
	}
	for (int i = 0; i < m; i ++)
	{
		int x = e[i].X.X - e[i].Y.Y, y = e[i].X.X + e[i].X.Y, w = e[i].Y.X + e[i].Y.Y;
		if (x >= 0 && e[i].X.Y >= e[i].Y.X)
			adj[idx[x]].pb(mp(mp(idx[y], w), i + 1));
	}
	for (int i = 1; i < SZ(v); i ++)
	{
		adj[i].pb(mp(mp(i - 1, v[i] - v[i - 1]), 0));
		adj[i - 1].pb(mp(mp(i, v[i] - v[i - 1]), 0));
	}

	CLR(par, -1);
	for (int i = 1; i < n; i ++)
	{
		d[i] = INF;
		heap.insert(mp(d[i], i));
	}
	dij();
	cout << d[n - 1] << endl;

	vector<int> ans;
	int x = n - 1;
	while (x != -1)
	{
		if (par[x].Y > 0) ans.pb(par[x].Y);
		x = par[x].X;

	}
	reverse(ALL(ans));
	cout << SZ(ans) << endl;
	FOREACH(i, ans) cout << *i << ' ';

	return 0;
}

	 	 		 			     									