//Language: GNU C++


#if 1
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <sstream>
#include <iostream>
#include <bitset>
#include <ctime>
#include <cassert>
#include <numeric>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair <LL, LL> pii;
typedef vector <LL> veci;
typedef vector <veci> graph;
const LD eps = 1e-9;
const LD pi = acos(-1.0);
const LD inf = 1e+9;

#pragma comment(linker, "/STACK:36777216")
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define iss istringstream
#define oss ostringstream
#define dbg(x) cerr << #x << " = " << x << endl
#define dbgv(x) {cerr << #x << ": {"; for (LL _i = 0; _i < x.size(); _i++) {if (_i) cerr << ", "; cerr << x[_i];} cerr << "}" << endl;}
#define NAME "problem"
LL gcd(LL a, LL b) {return (b == 0) ? a : gcd(b, a % b);}
LL xabs(LL a) {return a > 0 ? a: -a;}

int n, m;
vector <vector <char> > g;
bool check(int x, int y)
{
	return (x >= 0 && y >= 0 && x <= n - 1 && y <= m - 1 && g[x][y] == '#');
}
int sm[4][2] = {{1, 0},{-1, 0},{0, 1},{0,-1}};

const int MAXN = 3000;

bool used[MAXN] ={};
int timer = 0, tin[MAXN], fup[MAXN];
int fll = 0;

void dfs (int x, int y, int p = -1) 
{
	
	int v = m * x + y;
	used[v] = true;
	tin[v] = fup[v] = timer++;
	int children = 0;
	for (size_t i = 0; i < 4; ++i) 
	{
		int nx = x + sm[i][0];
		int ny = y + sm[i][1];
		if (check(nx, ny))
		{
			int to = m * nx + ny;
			if (to == p)  continue;
			if (used[to])
				fup[v] = min (fup[v], tin[to]);
			else 
			{
				dfs (nx, ny, v);
				fup[v] = min (fup[v], fup[to]);
				if (fup[to] >= tin[v] && p != -1)
					fll = 1;
				++children;
			}
		}
	}
	if (p == -1 && children > 1)
		fll = 1;
}
 

int main()
{	
	cin >> n >> m;	
	g.resize(n, vector <char>(m));
	int tmp = 0;
	int x, y;
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < m; k++)
		{
			cin >> g[i][k];
			if (g[i][k] == '#')
			{
				tmp++;
				x = i;
				y = k;
			}
		}
	}
	if (tmp <= 2)
	{
		cout << -1 << endl;
		return 0;
	}
	int ma = 4;
	dfs(x, y);
	if (fll)
		cout << 1 << endl;
	else

		cout << 2 << endl;
	return 0;
}
#endif