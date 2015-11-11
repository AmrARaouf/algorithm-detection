//Language: MS C++


#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 200
#define Red 1
#define Blue 2

int n, m, N;
struct Edge
{
	int u, v;
	int index;
	char ch;
}edge[MAX];
bool map[MAX][MAX];
bool mat[MAX][MAX];

bool Cmp(Edge a, Edge b)
{
	return a.u < b.u;
}
int len;
void init()
{
	int i;
	len = 0;
	memset(map, 0, sizeof(map));
	for(i = 0; i < m; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		if(u > v)
			swap(u, v);
		edge[len].u = u;
		edge[len].v = v;
		edge[len++].index = i;
	}
	sort(edge, edge + len, Cmp);
	m = len;
}
void Build()	
{
	memset(map, 0, sizeof(map));
	int i, j;
	for(i = 0; i < m; i++)
		for(j = i + 1; j < m; j++)
		{
			if(edge[i].v > edge[j].u && edge[j].v > edge[i].v && edge[j].u > edge[i].u)
			{
				map[i][j+m] = true;
				map[j][i+m] = true;
				map[j+m][i] = true;
				map[i+m][j] = true;
			}
		}
}
int deep[MAX], low[MAX], torp[MAX], stack[MAX], vis[MAX], cnt[MAX];
int time, top, seq, sig;
void dfs(int u)
{
	deep[u] = low[u] = ++time;
	stack[top++] = u;
	vis[u] = 1;
    int v;
	for(v = 0; v < N; v++)
		if(map[u][v] == true)
		{
			if(vis[v] == 0)
			{
				dfs(v);
				if(low[u] > low[v])
					low[u] = low[v];
			}
			else if(vis[v] == 1 && low[u] > deep[v])
				low[u] = deep[v];
		}
	if(deep[u] == low[u])
	{
		++seq;
		do
		{
			int tar = stack[top-1];
			vis[tar] = 2;
			torp[tar] = seq;
		}while(stack[--top] != u);
	}
}
void tarjan()
{
	memset(vis, 0, sizeof(vis));
	time = top = seq = sig = 0;
	int i;
	N = 2 * m;
	for(i = 0; i < N; i++)
		if(vis[i] == 0)
			dfs(i);
}
bool Check()
{
	int flag = 0;
	int i;
	for(i = 0; i < m; i++)
		if(torp[i] == torp[i+m])
		{
			flag = 1;
			break;
		}
	if(flag == 1)
		return false;
	else return true;
}
void dfs2(int u)
{
	vis[u] = 1;
	int v;
	for(v = 1; v <= seq; v++)
		if(mat[u][v] == true && vis[v] == 0)
			dfs2(v);
	cnt[sig++] = u;
}
bool Cmp1(Edge a, Edge b)
{
	return a.index < b.index;
}
void out()
{
	memset(vis, 0, sizeof(vis));
	memset(mat, 0, sizeof(mat));
	int i, j;
	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
		{
			int u = torp[i];
			int v = torp[j];
			if(u == v)
				continue;
			if(map[i][j] == true)
				mat[u][v] = true;
			if(map[j][i] == true)
				mat[v][u] = true;
		}
    sig = 0;
	for(i = 1; i <= seq; i++)
		if(vis[i] == 0)
			dfs2(i);
	memset(vis, 0, sizeof(vis));
	for(i = 0; i < sig; i++)
	{
		int u = cnt[i];
		int op = -1;
		int v;
		for(v = 0; v < N; v++)
			if(vis[v] == 0 && torp[v] == u)
			{
				vis[v] = Red;
				if(op == -1)
					op = v;
			}
		if(op >= m)
			op = op - m;
		else op = op + m;
		for(v = 0; v < N; v++)
		{
			if(vis[v] == 0 && torp[v] == torp[op])
				vis[v] = Blue;
		}
		for(v = 0; v < N; v++)
			if(vis[v] == 0 && mat[torp[v]][torp[op]] == true)
				vis[v] = Blue;
	}
	for(i = 0; i < m; i++)
		if(vis[i] == Red)
			edge[i].ch = 'i';
		else edge[i].ch = 'o';
	sort(edge, edge + m, Cmp1);
	for(i = 0; i < m; i++)
		printf("%c", edge[i].ch);
	printf("\n");
}
int main(void)
{
	while(scanf("%d %d", &n, &m) != EOF)
	{
		init();
		Build();
		tarjan();
		if(!Check())
			printf("Impossible\n");
		else out();
	}
	return 0;
}