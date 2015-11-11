//Language: GNU C++


// Solution by Mukai Yersin
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

#define sz 400000
#define mp make_pair
#define pb push_back                                                   
#define eps 1e-5
#define inf 1<<30
#define INF (long long)(1ll<<62)
#define F first
#define S second

typedef long long ll;

using namespace std;

struct st {
 	int val, next, ves;
} a[sz];
int head[sz], q[sz], c[sz], was[sz], used[sz], x, y, v, n, m, k, s, d[510][510];

void add(int x, int y, int v, int i)
{
 	a[i].val = y;
 	a[i].next = head[x];
 	a[i].ves = v;
 	head[x] = i;
}

void dfs(int v)
{
	was[v] = q[v];
	used[q[v]] = 1;
    for (int i=head[v]; i; i=a[i].next)
    {
    	if (!was[a[i].val] && a[i].ves == 0)
    		dfs(a[i].val);
		if (q[a[i].val]!=q[v])
			d[q[a[i].val]][q[v]]=min(d[q[a[i].val]][q[v]], a[i].ves),
			d[q[v]][q[a[i].val]]=d[q[a[i].val]][q[v]];
    }
}	

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i=1; i<=k; i++)
	{
		scanf("%d", &c[i]);
		for (int j=s+1; j<=s+c[i]; j++)
			q[j]=i;
		s+=c[i];
	}

	for (int i=1; i<=m; i++)
	{
	 	scanf("%d %d %d", &x, &y, &v);
	 	add(x, y, v, i);
	 	add(y, x, v, i+m);
	}
	for (int i=1; i<=k; i++)
		for (int j=i+1; j<=k; j++)
			d[i][j]=d[j][i]=inf;

	for (int i=1; i<=n; i++)
		if (!was[i]&&!used[q[i]]) dfs(i);
	for (int i=1; i<=n; i++)
		if (!was[i]) 
		{
		 	printf("No");
		 	return 0;
		}
	for (int t=1; t<=k; t++)
		for (int i=1; i<=k; i++)
			for (int j=1; j<=k; j++)
				if (d[i][t]<inf && d[t][j]<inf)
					d[i][j]=min(d[i][j], d[i][t]+d[t][j]);
	puts("Yes");
	for (int i=1; i<=k; i++, printf("\n"))
		for (int j=1; j<=k; j++)
		{
			if (d[i][j]==inf) d[i][j]=-1;
			printf("%d ", d[i][j]);
		}
	return 0;
}
