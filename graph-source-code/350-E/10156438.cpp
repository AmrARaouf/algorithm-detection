//Language: GNU C++


#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>
#define INF 1000000007
#define MP make_pair
const int NUM = 100010;
const double eps = 1e-10, pi = acos(-1.0);
using namespace std;
typedef pair <int, int> P;
typedef long long LL;
typedef unsigned long long uLL;
int n, m, k, a[400];
int g[400][400];
int ans[400][400], res[400][400];
bool verify()
{
	int i, j, l, v;
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			if(i == j)
				ans[i][j] = 0;
			else
				ans[i][j] = INF;
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			if(g[i][j])
				ans[i][j] = g[i][j];
	for(l = 1; l <= n; l++)
		if(a[l])
		{
			for(i = 1; i <= n; i++)
				for(j = 1; j <= n; j++)
					ans[i][j] = min(ans[i][j], ans[i][l] + ans[l][j]);
		}
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			if(i == j)
				res[i][j] = 0;
			else
				res[i][j] = INF;
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			if(g[i][j])
				res[i][j] = g[i][j];
	for(l = 1; l <= n; l++)
		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				res[i][j] = min(res[i][j], res[i][l] + res[l][j]);
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			if(ans[i][j] != res[i][j])
				return true;
	return false;
}
int main()
{
#ifdef ACM_TEST
	freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#endif
	int i, j;
	scanf("%d%d%d", &n, &m, &k);
	for(i = 0; i < k; i++)
	{
		scanf("%d", &j);
		a[j] = 1;
	}
	if(k == n)
	{
		printf("-1\n");
		return 0;
	}
	int s = 0;
	int cnt = 0;
	for(i = 1; i <= n; i++)
		if(a[i])
		{
			s = i;
			break;
		}
	int u = s;
	for(i = 1; i <= n; i++)
		if(!a[i])
		{
			g[u][i] = 1;
			g[i][u] = 1;
			u = i;
			cnt++;
		}
	for(i = 1; i <= n; i++)
		if(a[i] && i != s)
		{
			g[u][i] = 1;
			g[i][u] = 1;
			u = i;
			cnt++;
		}
	for(i = 1; cnt < m && i <= n; i++)
		for(j = i + 1; cnt < m && j <= n; j++)
			if(i != s && j != s)
			{
				if(!g[i][j])
				{
					g[i][j] = 1;
					g[j][i] = 1;
					cnt++;
				}
			}
			else if((i == s && !a[j]) || (!a[i] && j == s))
			{
				if(!g[i][j])
				{
					g[i][j] = g[j][i] = 1;
					cnt++;
				}
			}
	if(cnt == m && verify())
	{
		for(i = 1; i <= n; i++)
			for(j = i + 1; j <= n; j++)
				if(g[i][j])
					printf("%d %d\n", i, j);
	}
	else
		printf("-1\n");
	return 0;
}

		 					 			  	  	 		  	 	  			