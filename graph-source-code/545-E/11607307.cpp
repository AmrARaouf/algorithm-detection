//Language: GNU C++


#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <set>

using namespace std;

typedef unsigned long long int ull;


const int MAXN = 300000 + 5; // число вершин
const ull INF = (ull)1E15; // константа-бесконечность
 
struct edge {
	int a, b, cost, num;
};
 
int n, m;
ull dist[MAXN];
int prev_cost[MAXN];
int prev_num[MAXN];
vector<edge> edges[MAXN];
 
void add_edge (int a, int b, int cost, int num) {
	edge e1 = { a, b, cost, num};
	edge e2 = { b, a, cost, num};
	edges[a].push_back (e1);
	edges[b].push_back (e2);
}


void Dijkstra(int v)
{
    dist[v] = 0;
	prev_cost[v] = 0;
	prev_num[v] = -1;
    set<pair<ull, int> > q;
    for (int i = 1; i <= n; ++i)
    {
        q.insert(make_pair(dist[i], i));
    }
    while (!q.empty())
    {
        pair<ull, int> cur = *q.begin();
        q.erase(q.begin());
        for (int i = 0; i < (int)edges[cur.second].size(); ++i)
        {
			if (dist[edges[cur.second][i].b] == cur.first + edges[cur.second][i].cost) {
				if (prev_cost[edges[cur.second][i].b] > edges[cur.second][i].cost) {
					prev_cost[edges[cur.second][i].b] = edges[cur.second][i].cost;
					prev_num[edges[cur.second][i].b] = edges[cur.second][i].num;
				}
            }
			if (dist[edges[cur.second][i].b] > cur.first + edges[cur.second][i].cost) {
				prev_cost[edges[cur.second][i].b] = edges[cur.second][i].cost;
				prev_num[edges[cur.second][i].b] = edges[cur.second][i].num;
				q.erase(make_pair(dist[edges[cur.second][i].b], edges[cur.second][i].b));
				dist[edges[cur.second][i].b] = cur.first + edges[cur.second][i].cost;
				q.insert(make_pair(dist[edges[cur.second][i].b], edges[cur.second][i].b));
            }
        }
    }
}



int main(){
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		dist[i] = INF;
	}
	for (int i = 1; i <= m; ++i) {
		int a, b, cost;
		scanf("%d %d %d", &a, &b, &cost);
		add_edge(a, b, cost, i);
	}
	int v;
	scanf("%d", &v);
	Dijkstra(v);
	ull sum = 0;
	for (int i = 1; i <= n; ++i) {
		sum += prev_cost[i];
	}
	cout << sum << endl;
	for (int i = 1; i <= n; ++i) {
		if (i != v) {
			printf("%d ", prev_num[i]);
		}
	}
	cout << endl;
}
