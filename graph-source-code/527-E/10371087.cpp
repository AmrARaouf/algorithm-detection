//Language: GNU C++11


#include <vector>
#include <cstdio>
#include <utility>
using namespace std;

#define all(V) (V).begin(), (V).end()

typedef vector<int> vi;
typedef vector<vi> vvi;

void build(vi& ans, vvi& graph, vector<pair<int, int>>& edges, int node) {
 	while (!graph[node].empty()) {
 		int x = graph[node].back(); graph[node].pop_back();
		if (edges[x].first == -1) continue;
		int other = edges[x].first + edges[x].second - node;
		edges[x].first = -1;
		build(ans, graph, edges, other);
	}
	ans.push_back(node);
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vvi graph(n);
	vector<pair<int, int>> edges(m);
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &edges[i].first, &edges[i].second);
		edges[i].first--; edges[i].second--;
		graph[edges[i].first].push_back(i);
		graph[edges[i].second].push_back(i);
	}
	// fix graph to be eulerian
	int found = -1;
	for (int i = 0; i < n; ++i) {
		if (graph[i].size() % 2 == 0) continue;
		if (found == -1) found = i;
		else {
			edges.emplace_back(found, i);
			graph[found].push_back(edges.size()-1);
			graph[i].push_back(edges.size()-1);
			found = -1;
		}
	}
	// we also need an even number of edges in total
	if (edges.size() % 2 == 1) {
		edges.emplace_back(0, 0);
		graph[0].push_back(edges.size()-1);
		graph[0].push_back(edges.size()-1);
	}
	// find cycle
	vi ans;
	build(ans, graph, edges, 0);
	ans.pop_back();
	// output answer
	printf("%d\n", edges.size());
	for (int i = 0; i < ans.size(); ++i) {
		if (i % 2) printf("%d %d\n", ans[i]+1, ans[(i+1)%ans.size()]+1);
		else printf("%d %d\n", ans[(i+1)%ans.size()]+1, ans[i]+1);
	}
	return 0;
}

