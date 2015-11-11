//Language: GNU C++


/*************************************************************************
    > File Name: cf288d.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年01月28日 星期三 21时20分27秒
 ************************************************************************/

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const double pi = acos(-1);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;
typedef long long LL;
const int N = 200010;
char str[5];
char st[N << 2];
bool vis[N];
int father[N];
int in[N];
int out[N];
vector <int> edge[N];

int get_N (char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return c - 'a';
	}
	else if (c >= 'A' && c <= 'Z')
	{
		return c - 'A' + 26;
	}
	else if (c >= '0' && c <= '9')
	{
		return c - '0' + 52;
	}
}

char n_c (int x)
{
	if (x >= 0 && x <= 25)
	{
		return 'a' + x;
	}
	else if (x >= 26 && x <= 51)
	{
		return 'A' + x - 26;
	}
	else
	{
		return '0' + x - 52;
	}
}

int ans[N << 1];
int cnt;

int find (int x)
{
	if (father[x] == -1)
	{
		return x;
	}
	return father[x] = find (father[x]);
}

void dfs (int u)
{
	while (!edge[u].empty())
	{
		int v = edge[u].back();
		edge[u].pop_back();
		dfs (v);
		ans[++cnt] = v % 62;
	}
}

void init ()
{
	memset (father, -1, sizeof(father));
	memset (vis, 0, sizeof(vis));
	memset (in, 0, sizeof (in));
	memset (out, 0, sizeof (out));
	cnt = 1;

}
int main ()
{
	int n;
	while (~scanf("%d", &n))
	{
		init ();
		for (int i = 0; i < 62 * 62; ++i)
		{
			edge[i].clear();
		}
		for (int i = 1; i <= n; ++i)
		{
			scanf("%s", str);
			int u = get_N (str[0]) * 62 + get_N (str[1]);
			int v = get_N (str[1]) * 62 + get_N (str[2]);
			vis[u] = 1;
			vis[v] = 1;
			edge[u].push_back(v);
//			printf("%d --> %d\n", u, v);
			++in[v];
			++out[u];
			int fu = find (u);
			int fv = find (v);
			if (fu != fv)
			{
				father[fu] = fv;
			}
		}
		int num = 0;
		for (int i = 0; i < 62 * 62; ++i)
		{
			if (!vis[i])
			{
				continue;
			}
			if (father[i] == -1)
			{
				++num;
			}
		}
		if (num > 1)
		{
			printf("NO\n");
			continue;
		}
		int s = -1;
		int c1 = 0;
		int c2 = 0;
		bool flag = false;
		for (int i = 0; i < 62 * 62; ++i)
		{
			if (!vis[i])
			{
				continue;
			}
			if (out[i] - in[i] == 1)
			{
				++c1;
				s = i;
			}
			else if (out[i] - in[i] == -1)
			{
				++c2;
			}
			else if (out[i] != in[i])
			{
				flag = true;
				break;
			}
		}
//		printf("%d %d\n", c1, c2);
		if (flag || !((c1 == 0 && c2 == 0) || (c1 == 1 && c2 == 1)))
		{
			printf("NO\n");
			continue;
		}
		if (s == -1)
		{
			for (int i = 0; i < 62 * 62; ++i)
			{
				if (vis[i])
				{
					s = i;
					break;
				}
			}
		}
		printf("YES\n");
		dfs (s);
		ans[0] = s / 62;
		ans[1] = s % 62;
		printf("%c%c", n_c(ans[0]), n_c(ans[1]));
		for (int i = cnt; i >= 2; --i)
		{
			printf("%c", n_c(ans[i]));
		}
		printf("\n");
	}
	return 0;
}