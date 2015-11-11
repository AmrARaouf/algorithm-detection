//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <string>
#include <numeric>
#include <functional>
#include <iterator>
#include <typeinfo>
#include <utility>
#include <memory>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstddef>
#include <complex>
#include <ctime>
#include <cassert>
using namespace std;

typedef long long int64;
const int inf = 2000000000;
static inline int Rint()
{
	struct X{ int dig[256]; X(){
	for(int i = '0'; i <= '9'; ++i) dig[i] = 1; dig['-'] = 1;
	}};
	static 	X fuck;int s = 1, v = 0, c;
	for (;!fuck.dig[c = getchar()];);
	if (c == '-') s = 0; else if (fuck.dig[c]) v = c ^ 48;
	for (;fuck.dig[c = getchar()]; v = v * 10 + (c ^ 48));
	return s ? v : -v;
}
typedef vector<int> vi;
typedef vi::iterator ivi;
typedef map<int, int> mii;
typedef mii::iterator imii;
typedef set<int> si;
typedef si::iterator isi;

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define rep(i, s, e) for (int i = (s); i < (e); ++i)
#define foreach(itr, c) for(__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); ++itr)
template<typename T> static inline void cmax(T& a, const T& b){if(b>a)a=b;}
template<typename T> static inline void cmin(T& a, const T& b){if(b<a)a=b;}

const int maxn = 100005;
vi adj[maxn];
int c[500];

int mark[maxn];
int belong[maxn];
int dist[505][505];
int check(int n, int k)
{
	int scc = 1;
	for (int curr = 1; curr <= n; ++curr)
	if (mark[curr] == 0)
	{
		mark[curr] = scc;
		queue<int> q;
		q.push(curr);
		while (!q.empty())
		{
			const int now = q.front(); q.pop();
			vi& vec = adj[now];
			const int size = sz(vec);
			for (int i = 0; i < size; i += 2)
			if (mark[vec[i]] == 0 && vec[i+1] == 0)
			{
				mark[vec[i]] = scc;
				q.push(vec[i]);
			}
		}
		++scc;
	}
	
	for (int s = 0, i = 1; i <= k; ++i)
	{
		for (int j = s + 1; j <= s + c[i]; ++j)
		{
			belong[j] = i;
			if (mark[j] != mark[s+1])
			{
				return 0;
			}
		}
		s += c[i];
	}
	return 1;
}

int main()
{
	int n = Rint(), m = Rint(), k = Rint();
	for (int i = 1; i <= k; ++i)
	c[i] = Rint();
	while (m--)
	{
		int s = Rint(), t = Rint(), w = Rint();
		adj[s].pb(t), adj[s].pb(w);
		adj[t].pb(s), adj[t].pb(w);
	}
	if (!check(n, k))
	{
		puts("No");
		return 0;
	}

	memset(dist, -1, sizeof dist);
	for (int i = 1; i <= n; ++i)
	{
		vi& vec = adj[i];
		const int size = sz(vec);
		const int from = belong[i];
		for (int j = 0; j < size; j += 2)
		{
			const int to = belong[vec[j]];
			if (dist[from][to] == -1 || vec[j+1] < dist[from][to])
			{
				
				dist[from][to] = dist[to][from] = vec[j+1];
			}
		}
	}

	for (int i = 1; i <= k; ++i)
	dist[i][i] = 0;
	for (int c = 1; c <= k; ++c)
	for (int a = 1; a <= k; ++a) if (dist[a][c] >= 0)
	for (int b = 1; b <= k; ++b) if (dist[c][b] >= 0)
	{
		const int t = dist[a][c] + dist[c][b];
		if (dist[a][b] == -1 || t < dist[a][b])
		dist[a][b] = t;
	}
	puts("Yes");
	for (int i = 1; i <= k; ++i)
	{
		for (int j = 1; j <= k; ++j)
		printf("%d ", dist[i][j]);
		puts("");
	}
	return 0;
}
