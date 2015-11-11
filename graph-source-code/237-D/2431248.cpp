//Language: GNU C++


// AntiFate
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);++i)
#define fab(i,a,b) for(int i=(a);i<=(b);++i)
#define fba(i,b,a) for(int i=(b);i>=(a);--i)
#define clr(a) memset(a,0,sizeof(a))
#define fec(i,a) for(__typeof((a).end())i=(a).begin();i!=(a).end();++i)
#define fpc(i,j,v) for(int i=a[v],j;j=to[i],i;i=nx[i])

#define N 101000

int n;
int x[N], y[N];

int to[N*2], nx[N*2], a[N], id[N];

int cnt = 0;
vector<int> c1,c2,c3,c4;

void dfs(int v, int f)
{
	int last = -1;
	fpc(i, j, v) if (j != f)
	{
		id[j] = ++cnt;
		c1.push_back(v);
		c2.push_back(j);
//cerr<<f<<" "<<last<<"!\n";
		if (f >= 1 && last == -1)
		{
			c3.push_back(id[v]);
			c4.push_back(cnt);
		} else
		if (last >= 0)
		{
			c3.push_back(last);
			c4.push_back(cnt);
		}
		last = cnt;
		dfs(j, v);
	}
}

int main()
{
	scanf("%d", &n);
	rep(i,n-1)
	{
		static int t = 1;
		scanf("%d%d",x+i,y+i);
		nx[++t] = a[x[i]];
		to[a[x[i]] = t] = y[i];
		nx[++t] = a[y[i]];
		to[a[y[i]] = t] = x[i];
	}
	dfs(1,0);

	printf("%d\n", n-1);
	rep(i,n-1)
		printf("2 %d %d\n",c1[i],c2[i]);
	rep(i,n-2)
		printf("%d %d\n",c3[i],c4[i]);
	
}

/* vim:set ts=4 sts=4 sw=4 noet: */
