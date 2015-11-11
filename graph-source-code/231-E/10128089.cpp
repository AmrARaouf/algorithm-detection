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
int n, m, q;
struct edge
{
	int u, to, next;
};
class G
{
public:
	edge e[2 * NUM];
	int head[NUM];
	int tot;
	G()
	{
		init();
	}
	void init()
	{
		memset(head, -1, sizeof(head));
		tot = 0;
	}
	void add(int u, int v)
	{
		e[tot].u = u;
		e[tot].to = v;
		e[tot].next = head[u];
		head[u] = tot++;
	}
} g, g2, qg;

int id[NUM], dcc;
int dfn[NUM], low[NUM];
int stk[NUM], top;
int ce[NUM], num;
LL cnt[NUM];
void tarjandfs(int u, int &sig, int pree)
{
	stk[top++] = u;
	dfn[u] = low[u] = sig++;
	int v;
	for(int i = g.head[u]; i != -1; i = g.e[i].next)
	{
		v = g.e[i].to;
		if(!dfn[v])
		{
			tarjandfs(v, sig, i);
			if(low[u] > low[v])
				low[u] = low[v];
			if(dfn[u] < low[v])
			{
				ce[num++] = i;
				dcc++;
				cnt[dcc] = 0;
				do
				{
					cnt[dcc]++;
					id[stk[--top]] = dcc;
				}
				while(stk[top] != v);
			}
		}
		else if((i ^ 1) != pree && low[u] > dfn[v])
			low[u] = dfn[v];
	}
}
int tarjan()
{
	int sig = 1;
	dcc = 0;
	//memset(low, 0, sizeof(low));
	//memset(dfn, 0, sizeof(dfn));
	for(int i = 1; i <= n; i++)
		if(!dfn[i])
			tarjandfs(i, sig, -1);
	return dcc;
}

int fa[NUM];
int vis[NUM];
int lca[NUM];
inline int find(int x)
{
	if(x != fa[x])
		fa[x] = find(fa[x]);
	return fa[x];
}

void LCA(int u)
{
	fa[u] = u;
	int k;
	vis[u] = 1;
	for(k = g2.head[u]; k != -1; k = g2.e[k].next)
		if(!vis[g2.e[k].to])
		{
			LCA(g2.e[k].to);
			fa[g2.e[k].to] = u;
		}
	for(k = qg.head[u]; k != -1; k = qg.e[k].next)
		if(vis[qg.e[k].to])
		{
			lca[k / 2] = find(qg.e[k].to);
		}
}

LL ans[NUM];

void dfs(int u, int fa, LL x)
{
	x = x * cnt[u] % INF;
	ans[u] = x;
	for(int i = g2.head[u]; i != -1; i = g2.e[i].next)
		if(g2.e[i].to != fa)
			dfs(g2.e[i].to, u, x);
}
LL qpow(LL x)
{
	LL t = INF - 2;
	LL res = 1;
	while(t)
	{
		if(t & 1) res = res * x % INF;
		x = x * x % INF;
		t >>= 1;
	}
	return res;
}
LL lcares[NUM];
int main()
{
#ifdef ACM_TEST
	freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#endif
	int i, j;
	int u, v;
	scanf("%d%d", &n, &m);
	for(i = 0; i < m; i++)
	{
		scanf("%d%d", &u, &v);
		g.add(u, v);
		g.add(v, u);
	}
	tarjan();
	for(i = 0; i < num; i++)
	{
		j = ce[i];
		u = id[g.e[j].u], v = id[g.e[j].to];
		g2.add(u, v);
		g2.add(v, u);
	}
	scanf("%d", &q);
	for(i = 0; i < q; i++)
	{
		scanf("%d%d", &u, &v);
		qg.add(id[u], id[v]);
		qg.add(id[v], id[u]);
	}
	LCA(0);
	int sum = n;
	for(i = 1; i <= dcc; i++)
	{
		sum -= cnt[i];
		cnt[i] = cnt[i] > 1 ? 2 : 1;
	}
	cnt[0] = sum > 1 ? 2 : 1;
	dfs(0, -1, 1);
	LL res;
	memset(vis, 0, sizeof(vis));
	int w;
	for(i = 0; i < q; i++)
	{
		u = qg.e[2 * i].u;
		v = qg.e[2 * i].to;
		w = lca[i];
		res = ans[u] * ans[v] % INF;
		res = res * cnt[lca[i]] % INF;
		if(!vis[w])
		{
			vis[w] = 1;
			lcares[w] = qpow(ans[w] * ans[w] % INF);
		}
		res = res * lcares[w] % INF;
		printf("%I64d\n", res);
	}
	return 0;
}

  	  	  	 							  			 	  	  		