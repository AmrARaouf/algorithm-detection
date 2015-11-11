//Language: GNU C++0x


#include <iostream>
#include <vector>
#include <list>
#include <deque>

using namespace std;

const long long mod = 1000000007;
const long long inf = 1010101010;

vector<list<int>> graph;
vector<bool> visited;
vector<bool> closed;
vector<int> renumber;
vector<int> low_link;
deque<int> stack;
int index = 0;

vector<list<int>> connected_components;

int tarjan( int node ) {
	visited[node]  = true;
	renumber[node] = index;
	low_link[node] = index;
	++index;

	stack.push_back( node );

	for( int child : graph[node] ) {
		if( !visited[child] ) {
			tarjan( child );
		}

		if( visited[child] && !closed[child] ) {
			low_link[node] = min( low_link[node], low_link[child] );
		}
	}

	if( low_link[node] == renumber[node] ) {
		connected_components.emplace_back();
		do {
			node = stack.back();
			stack.pop_back();
			connected_components[connected_components.size()-1].push_back(node);
			closed[node] = true;
		} while( low_link[node] != renumber[node] );
	}
}

int main() {
	int junctions;
	cin >> junctions;

	vector<long long> costs(junctions+1);
	for( int i=0; i<junctions; ++i )
		cin >> costs[i+1];

	graph.resize(junctions+1);

	int roads;
	cin >> roads;
	for( int i=0; i<roads; ++i ) {
		int from, to;
		cin >> from >> to;

		graph[from].push_back( to );
	}

	visited.resize(junctions+1,false);
	closed.resize(junctions+1,false);
	renumber.resize(junctions+1);
	low_link.resize(junctions+1);

	for( int i=1; i<junctions+1; ++i ) {
		if( !closed[i] ) {
			tarjan( i );
		}
	}

	long long cost = 0;
	long long ways = 1;

	for( auto component : connected_components ) {
		long long min_cost = inf;
		long long nodes_with_min_cost = 0;
		for( int node : component ) {
			if( costs[node] < min_cost ) {
				min_cost = costs[node];
				nodes_with_min_cost = 1;
			} else if( costs[node] == min_cost ) {
				nodes_with_min_cost += 1;
			}
		}
		cost += min_cost;
		ways = (ways*nodes_with_min_cost) % mod;
	}

	cout << cost << " " << ways;
}
