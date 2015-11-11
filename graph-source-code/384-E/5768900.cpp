//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 200010;
const int MAXM = 400010;

int n, m;
int a[MAXN];
int H[MAXN], E[MAXM], X[MAXM], co = 0;

inline void add(int x, int y)
{
	E[++co] = y, X[co] = H[x], H[x] = co;
	E[++co] = x, X[co] = H[y], H[y] = co;
}
int dT;
int l[MAXN], r[MAXN], flag[MAXN];
void dfs(int x, int ff)
{
	l[x] = ++dT;
	flag[x] = -flag[ff];
	for (int p = H[x]; p; p = X[p])
		if (E[p] != ff)
			dfs(E[p], x);
	r[x] = dT;
}
int f[MAXN];
inline void ins(int x, int y)
{
	for (int i = x; i; i -= i & -i) f[i] += y;
}
inline int query(int x)
{
	int ret = 0;
	for (int i = x; i <= n; i += i & -i) ret += f[i];
	return ret;
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	int type, x, y;
	for (int i = 1; i < n; ++i)
	{
		scanf("%d %d", &x, &y);
		add(x, y);
	}
	flag[0] = -1;
	dfs(1, 0);
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d %d", &type, &x);
		if (type == 1)
		{
			scanf("%d", &y);
			ins(r[x], y * flag[x]);
			ins(l[x] - 1, -y * flag[x]);
		}
		else
		{
			printf("%d\n", a[x] + query(l[x]) * flag[x]);
		}
	}
	return 0;
}
