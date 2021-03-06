//Language: GNU C++


#include <bits/extc++.h>

using namespace std;

//#define NDEBUG
#ifdef NDEBUG
#define DEBUG if (false)
#else
#define DEBUG if (true)
#endif
#define WRITE(x) DEBUG { cout << (x) << endl; }
#define WATCH(x) DEBUG { cout << #x << " = " << (x) << endl; }
#define ALL(x) (x).begin(), (x).end()
#define FORN(i, a, b) for(typeof(b) i = (a); i < (b); ++i)
#define FOREACH(i, c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)

typedef long long ll;

#define INF 0x3f3f3f3f

struct Edge{
	int v, rev, cap, cost, orig_cost;
	bool orig;
	Edge(int v_, int cap_, int cost_, int rev_, bool orig_) : v(v_),
		rev(rev_), cap(cap_), cost(cost_), orig_cost(cost_), orig(orig_) {}
};

struct MinCostMaxFlow{
	vector<vector<Edge> > g;
	vector<int> p, pe, dist;
	int flow, cost, n;

	MinCostMaxFlow(int n_) : g(n_), p(n_), pe(n_), dist(n_), n(n_) {}

	void addEdge(int u, int v, int cap, int cost){
		if(u == v) return;
		Edge e(v, cap, cost, int(g[v].size()), true);
		Edge r(u, 0, 0, int(g[u].size()), false);
		g[u].push_back(e);
		g[v].push_back(r);
	}

	bool findPath(int src, int sink){
		set<pair<int, int> > q;
		fill(ALL(dist), INF);
		dist[src] = 0;
		p[src] = src;
		q.insert(make_pair(dist[src], src));
		while(not q.empty()){
			int u = q.begin()->second;
			q.erase(q.begin());

			FOREACH(e, g[u]){
				if(not e->cap) continue;
				int newdist = dist[u] + e->cost;
				if(newdist < dist[e->v]){
					if(dist[e->v] == INF) q.erase(make_pair(dist[e->v], e->v));
					dist[e->v] = newdist;
					q.insert(make_pair(newdist, e->v));
					p[e->v] = u;
					pe[e->v] = int(distance(g[u].begin(), e));
				}
			}
		}
		return dist[sink] < INF;
	}

	void fixCosts(){
		FORN(u, 0, n)
			FOREACH(e, g[u]){
				if(e->cap){
					if(e->cap) e->cost = min(INF, e->cost + dist[u] - dist[e->v]);
				}else{
					e->cost = 0;
				}
				assert(e->cost >= 0);
			}
	}

	void augmentFlow(int sink){
		int mincap = numeric_limits<int>::max();
		for(int v = sink; p[v] != v; v = p[v])
			mincap = min(mincap, g[p[v]][pe[v]].cap);
		for(int v = sink; p[v] != v; v = p[v]){
			Edge& e = g[p[v]][pe[v]];
			Edge& r = g[v][g[p[v]][pe[v]].rev];
			e.cap -= mincap;
			r.cap += mincap;
			cost += (e.orig ? e.orig_cost : -r.orig_cost) * mincap;

		}
		flow += mincap;
	}

	void fixInitialCosts(int src)
	{
		fill(ALL(dist), INF);
		dist[src] = 0;
		FORN(i, 0, n){
			FORN(u, 0, n){
				FOREACH(e, g[u]){
					if(e->orig) dist[e->v] = min(dist[e->v], dist[u] + e->cost);
				}
			}
		}
		fixCosts();
	}

	pair<int, int> maxFlow(int src, int sink){
		flow = 0;
		cost = 0;
		fixInitialCosts(src);
		while(findPath(src, sink)){
			fixCosts();
			augmentFlow(sink);
		}
		return make_pair(flow, cost);
	}

};

vector<int> getFreq(string& str)
{
	vector<int> freq('z' - 'a' + 1);
	FOREACH(c, str) freq[*c - 'a']++;
	return freq;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string t;
	cin >> t;
	int n;
	cin >> n;
	vector<string> s(n);
	vector<int> a(n);
	FORN(i, 0, n) cin >> s[i] >> a[i];
	MinCostMaxFlow g(n + 28);
	FORN(i, 0, n){
		if(a[i] % 2){
			g.addEdge(0, i + 1, a[i], i + 1);
		}else{
			g.addEdge(0, i + 1, a[i] / 2, i + 1);
			g.addEdge(0, i + 1, a[i] / 2, i + 1);
		}
		vector<int> freq = getFreq(s[i]);
		FORN(j, 0, 26){
			g.addEdge(i + 1, n + j + 1, freq[j], 0);
		}
	}
	vector<int> freq = getFreq(t);
	FORN(j, 0, 26){
		g.addEdge(n + j + 1, n + 27, freq[j], 0);
	}
	pair<int, int> sol = g.maxFlow(0, n + 27);
	if(sol.first != int(t.size())){	
		cout << -1 << endl;
	}else{
		cout << sol.second << endl;
	}
}
