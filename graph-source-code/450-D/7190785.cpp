//Language: GNU C++0x


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <utility>
#include <set>
#include <map>

#define INF 0x3f3f3f3f

using namespace std;

typedef long long LL;

struct State {
	int node, train;
	LL val;
	State (const int& n, const LL& v) : node(n), val(v), train(0) {}
	State (const int& n, const LL& v, const int& del) : node(n), val(v), train(del) {}
};

bool operator<(const State& a, const State& b) {
	if (a.val == b.val) return a.train > b.train;
	return a.val > b.val;
}

const int N = 100005;
bool visited[N];
vector<State> graph[N];

int n, m, k, ans = 0;

void dijkstra () {
	memset(visited, false, sizeof(visited));
	priority_queue<State> pq;

	for (int i = 0; i < k; ++i) {
		int s; LL y;
		cin >> s >> y;
		--s;
		State ss(s, y, 1);
		pq.push(ss);
	}

	State s(0, 0);
	pq.push(s);

	while (!pq.empty()) {
		State t = pq.top();
		pq.pop();

		if (visited[t.node]) {
			if (t.train == 1)
				++ans;
			continue;
		}

		visited[t.node] = true;
		for (const auto& e : graph[t.node]) {
			if (!visited[e.node]) {
				State ss(e.node, t.val+e.val, e.train);
				pq.push(ss);
			}
		}
	}
}


int main() {
	cin >> n >> m >> k;
	
	int u, v; LL x;
	for (int i = 0; i < m; ++i) {
		cin >> u >> v >> x;
		--u;
		--v;
		State s1(v, x);
		State s2(u, x);
		graph[u].push_back(s1);
		graph[v].push_back(s2);
	}

	dijkstra();
	cout << ans << endl;
	return 0;
}
