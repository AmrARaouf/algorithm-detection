//Language: GNU C++


#include <iostream>
#include <vector>
#define cin  std::cin
#define cout std::cout
#define maxn 200000 + 5

int n, m, vtime;
int x[maxn], begin[maxn], end[maxn], depth[maxn];
std::vector< std::vector<int> > edges;
int bit[maxn + 1];

void dfs(int v, int dep)
{
	int u, i;
	begin[v] = vtime++;
	depth[v] = dep;
	for(i = 0; i < edges[v].size(); i++) {
		u = edges[v][i];
		if(begin[u] != 0) continue;
		dfs(u, dep + 1);
	}
	end[v] = vtime;
}

int sum(int i)
{
	int s = 0;
	while(i > 0) {
		s += bit[i];
		i -= i & -i;
	}
	return s;
}

void add(int i, int x)
{
	while(i <= n) {
		bit[i] += x;
		i += i & -i;
	}
}

int main()
{
	int u, v, i, op, a, val;
	cin >> n >> m;
	for(i = 1; i <= n; i++)
		cin >> x[i];
	
	edges.resize(maxn);
	for(i = 0; i < n - 1; i++) {
		cin >> u >> v;
		edges[u].push_back(v);
	}
	vtime = 1;
	dfs(1, 1);
	for(i = 0; i < m; i++) {
		cin >> op;
		if(op == 1) {
			cin >> a >> val;
			if(depth[a] % 2 == 0) val = -val;
			add(begin[a], val);
			add(end[a], -val);
		} else {
			cin >> a;
			cout << ( depth[a]%2 == 1 ? ( x[a] + sum(begin[a]) ) : ( x[a] - sum(begin[a]) ) ) << "\n";
		}
	}
	return 0;
}
				 	    		  	 	   	      		