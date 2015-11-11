//Language: GNU C++11


#include <bits/stdc++.h>

#define For(i, a, b) for(int i=(a); i<(b); ++i)
#define INF 1000000000
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

struct edge
{
	int v, rev, cap, flow, cost;
	edge(int _v, int _rev, int _cap, int _flow, int _cost)
	{
		v = _v;
		rev = _rev;
		cap = _cap;
		flow = _flow;
		cost = _cost;
	}
	edge(){}
};

vector <ii> path;
int f = 0, total_cost = 0;
vector <vector <edge> > AdjList;

void addEdge(int u, int v, int cap, int cost)
{
	int k = AdjList[v].size(), l = AdjList[u].size();
	AdjList[u].push_back(edge(v, k, cap, 0, cost));
	AdjList[v].push_back(edge(u, l, 0, 0, -cost));
}

void augment(int s, int v, int min_edge, bool ok)
{
	if (v == s)
	{
		f = ok ? min_edge : 1;
		return;
	}

	int u = path[v].first, i = path[v].second;
	if (u != -1)
	{
		int res = AdjList[u][i].cap - AdjList[u][i].flow;
		augment(s, u, min(res, min_edge), ok);
		AdjList[u][i].flow += f;
		AdjList[v][AdjList[u][i].rev].flow -= f;
		total_cost += AdjList[u][i].cost * f;
		//printf("%d -> %d: %d\n", u, v, AdjList[u][i].cost);
	}
}

int K;

int minCostMaxFlow(int s, int t, int N)
{
	int maxflow = 0;
	path.resize(N);

	while (true)
	{
		f = 0;
		vector <int> dist(N, INF);
		vector <bool> IN(N, false);

		dist[s] = 0;
		path[t] = MP(-1, -1);

		queue <int> cola;
		cola.push(s);
		IN[s] = true;

		while (!cola.empty())
		{
			int u = cola.front(); cola.pop();
			IN[u] = false;

			For(i, 0, (int)AdjList[u].size())
			{
				edge e = AdjList[u][i];
				if (e.cap - e.flow > 0 and dist[e.v] > dist[u] + e.cost)
				{
					dist[e.v] = dist[u] + e.cost;
					path[e.v] = MP(u, i);
					if (!IN[e.v])
						cola.push(e.v), IN[e.v] = true;
				}
			}
		}

		augment(s, t, INF, dist[t] == 0);
		if (!f or total_cost > K)
			break;

		maxflow += f;
	}

	return maxflow;
}

int main()
{
	//std::ios_base::sync_with_stdio(false);

	int n;
	scanf("%d %d", &n, &K);

	AdjList.assign(n, vector <edge>());

	For(u, 0, n)
		For(v, 0, n)
		{
			int cap;
			scanf("%d", &cap);
			
			if (cap)
			{
				addEdge(u, v, cap, 0);
				addEdge(u, v, INF, 1);
			}
		}

	int maxflow = minCostMaxFlow(0, n-1, n);
	//printf("%d\n", total_cost);

	printf("%d\n", maxflow);

	return 0;
}