//Language: GNU C++


#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>

using namespace std;

#define MAXN 12
#define INF 1000000

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int N, T;
char grid1[MAXN][MAXN], grid2[MAXN][MAXN];
int A[MAXN][MAXN];
int B[MAXN][MAXN][MAXN][MAXN];
int depth[MAXN][MAXN];

#define MAX_NETWORK_NODES 205

struct edge {
	int a, b, cap, flow;
};

int n, s, t, d[MAX_NETWORK_NODES], ptr[MAX_NETWORK_NODES], q[MAX_NETWORK_NODES];
vector<edge> e;
vector<int> g[MAX_NETWORK_NODES];

void add_edge (int a, int b, int cap)
{
	edge e1 = { a, b, cap, 0 };
	edge e2 = { b, a, 0, 0 };
	g[a].push_back ((int) e.size());
	e.push_back (e1);
	g[b].push_back ((int) e.size());
	e.push_back (e2);
}
 
bool bfs()
{
	int qh=0, qt=0;
	q[qt++] = s;
	memset (d, -1, n * sizeof d[0]);
	d[s] = 0;
	while (qh < qt && d[t] == -1) {
		int v = q[qh++];
		for (size_t i=0; i<g[v].size(); ++i) {
			int id = g[v][i],
				to = e[id].b;
			if (d[to] == -1 && e[id].flow < e[id].cap) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[t] != -1;
}
 
int dfs (int v, int flow)
{
	if (!flow)  return 0;
	if (v == t)  return flow;
	for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
		int id = g[v][ptr[v]],
			to = e[id].b;
		if (d[to] != d[v] + 1)  continue;
		int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
		if (pushed) {
			e[id].flow += pushed;
			e[id^1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}
 
int dinic()
{
	int flow = 0;
	for (;;) {
		if (!bfs())  break;
		memset (ptr, 0, n * sizeof ptr[0]);
		while (int pushed = dfs (s, INF))
			flow += pushed;
	}
	return flow;
}

int get_id(int x, int y)
{
	return x*N+y;
}

void build_network()
{
	s = 0, t = 2*N*N+1;
	n = 2*N*N+2;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			if( grid1[i][j] > '0' && grid1[i][j] <= '9' )
				add_edge(s,1+get_id(i,j),grid1[i][j]-'0');
			if( grid2[i][j] > '0' && grid2[i][j] <= '9' )
				add_edge(N*N+1+get_id(i,j),t,grid2[i][j]-'0');
		}
	for(int x1=0;x1<N;x1++)
		for(int y1=0;y1<N;y1++)
			for(int x2=0;x2<N;x2++)
				for(int y2=0;y2<N;y2++)
					if( B[x1][y1][x2][y2] )
					{
						add_edge(1+get_id(x1,y1),N*N+1+get_id(x2,y2),INF);
					}
}

int main()
{
	// freopen("input.txt","r",stdin);
	scanf("%d%d",&N,&T);
	for(int i=0;i<N;i++)
		scanf("%s",grid1[i]);
	getchar();
	for(int i=0;i<N;i++)
		scanf("%s",grid2[i]);
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			A[i][j] = INF;
	queue< pair<int,int> > Q;
	for(int x=0;x<N;x++)
		for(int y=0;y<N;y++)
			if( grid1[x][y] == 'Z' )
			{
				for(int i=0;i<4;i++)
					if( x+dx[i] >= 0 && x+dx[i] < N && y+dy[i] >= 0 && y+dy[i] < N && grid1[x+dx[i]][y+dy[i]] != 'Y' )
					{
						A[x+dx[i]][y+dy[i]] = 1;
						Q.push(make_pair(x+dx[i],y+dy[i]));
					}
			}
	while( !Q.empty() )
	{
		int x = Q.front().first, y = Q.front().second;
		Q.pop();
		for(int i=0;i<4;i++)
			if( x+dx[i] >= 0 && x+dx[i] < N && y+dy[i] >= 0 && y+dy[i] < N && grid1[x+dx[i]][y+dy[i]] != 'Y' && grid1[x+dx[i]][y+dy[i]] != 'Z' && A[x+dx[i]][y+dy[i]] == INF )
			{
				A[x+dx[i]][y+dy[i]] = A[x][y] + 1;
				Q.push(make_pair(x+dx[i],y+dy[i]));
			}
	}
	for(int x1=0;x1<N;x1++)
		for(int y1=0;y1<N;y1++)
			for(int x2=0;x2<N;x2++)
				for(int y2=0;y2<N;y2++)
				{
					if( grid1[x1][y1] == 'Y' || grid1[x1][y1] == 'Z' || grid1[x2][y2] == 'Y' || grid1[x2][y2] == 'Z' )
					{
						B[x1][y1][x2][y2] = 0;
						continue;
					}
					for(int i=0;i<N;i++)
						for(int j=0;j<N;j++)
							depth[i][j] = INF;
					queue< pair<int,int> > Q2;
					depth[x1][y1] = 0;
					Q2.push(make_pair(x1,y1));
					int c = 0;
					while( !Q2.empty() )
					{
						int x = Q2.front().first, y = Q2.front().second;
						Q2.pop();
						if( x == x2 && y == y2 )
						{
							c = 1;
							break;
						}
						if( depth[x][y] >= T || depth[x][y] >= A[x][y] )
							continue;
						for(int i=0;i<4;i++)
						{
							int x3 = x+dx[i], y3 = y+dy[i];
							if( x3 >= 0 && x3 < N && y3 >= 0 && y3 < N && grid1[x3][y3] != 'Y' && grid1[x3][y3] != 'Z' && depth[x3][y3] == INF && depth[x][y]+1 <= A[x3][y3] )
							{
								depth[x3][y3] = depth[x][y]+1;
								Q2.push(make_pair(x3,y3));
							}
						}
					}
					if( c )
						B[x1][y1][x2][y2] = 1;
					else
						B[x1][y1][x2][y2] = 0;
				}
	build_network();
	printf("%d\n",dinic());
	return 0;
}
