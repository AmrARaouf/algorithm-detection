//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <sstream>
using namespace std; 

#define f first
#define s second
#define mp make_pair
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define forit(it,v) for(typeof(v.begin()) it = v.begin(); it != v.end(); ++it)

const int inf = int(1e9 + 1);
typedef pair <int, int> pi;
typedef pair <int, pi> pii;

struct tramplin {
	int x, d, t, p;
} a[200000];

int n, L, c[500000], cn;
vector <pii> e[500000];
int with[500000], back[500000], d[500000];
priority_queue <pi, vector <pi>, greater <pi> > pq;
vector <int> res;

inline int find(int x) {
	return lower_bound(c, c + cn, x) - c;
}

int main() {
	scanf("%d%d", &n, &L);
	c[cn++] = 0;
	c[cn++] = L;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d%d", &a[i].x, &a[i].d, &a[i].t, &a[i].p);				
		if (a[i].x >= a[i].p) {
			c[cn++] = a[i].x - a[i].p;					
			c[cn++] = a[i].x + a[i].d;
		}
	}	 
	sort(c, c + cn);
	cn = unique(c, c + cn) - c;

	for (int i = 0; i < n; ++i) {
		if (a[i].x >= a[i].p) {
			int p = find(a[i].x - a[i].p);
			e[p].pb(mp(i, mp(find(a[i].x + a[i].d), a[i].t + a[i].p)));
		}
	}
	
	for (int i = 0; i < cn; ++i)
		d[i] = inf;
	d[0] = 0;
	pq.push(mp(d[0], 0));	
	
	while (!pq.empty()) {
		pi top = pq.top();
		pq.pop();
		if (top.f > d[top.s]) continue;
		int u = top.s;
		if (u > 0) {
			if (d[u - 1] > d[u] + c[u] - c[u - 1]) {
				d[u - 1] = d[u] + c[u] - c[u - 1];
				pq.push(mp(d[u - 1], u - 1));
				back[u - 1] = u;
				with[u - 1] = -1;
			}
		}
		if (u < cn - 1) {
			if (d[u + 1] > d[u] + c[u + 1] - c[u]) {
				d[u + 1] = d[u] + c[u + 1] - c[u];
				pq.push(mp(d[u + 1], u + 1));
				back[u + 1] = u;
				with[u + 1] = -1;
			}		
		}
		forit (it, e[u]) {
			int num = (*it).f;
			int v = (*it).s.f;
			int cost = (*it).s.s;
			if (d[v] > d[u] + cost) {
				d[v] = d[u] + cost;
				pq.push(mp(d[v], v));
				back[v] = u;
				with[v] = num;
			}
		}
	}
	
	printf("%d\n", d[cn - 1]);	
	int i = cn - 1;
	while (i != 0) {
		if (with[i] != -1)
			res.pb(with[i]);
		i = back[i];			
	}
	reverse(res.begin(), res.end());
	cout << res.size() << endl;
	forit (it, res)
		printf("%d ", (*it) + 1);
	return 0;		
}

