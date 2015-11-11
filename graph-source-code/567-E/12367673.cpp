//Language: GNU C++11


		//	   - -- --- ---- -----be name khoda----- ---- --- -- -		\\

#include <bits/stdc++.h>
using namespace std;

inline int in() { int x; scanf("%d", &x); return x; }
typedef long long ll;
const int N = 200002, MOD1 = 1e9 + 7, MOD2 = 1e9 + 9, MOD3 = 101;

struct Edge
{
	int u, v, l;
};

int n, m;
ll d[N], dR[N], ted1[N], tedR1[N], ted2[N], tedR2[N], ted3[N], tedR3[N];
vector <Edge> es, g[N], gR[N];

void dj(int st, vector <Edge> g[], ll d[])
{
	set <pair<ll, int>> s;
	fill(d, d + n + 1, 1e17);
	d[st] = 0;
	for(int v = 1; v <= n; v++)
		s.insert({d[v], v});
	while(s.size())
	{
		int v = s.begin()->second;
		s.erase(s.begin());
		for(Edge e : g[v])
			if(d[e.u] > d[v] + e.l)
			{
				s.erase({d[e.u], e.u});
				d[e.u] = d[v] + e.l;
				s.insert({d[e.u], e.u});
			}
	}
}

ll add(ll &x, ll &y, ll mod) { return (x + y) % mod; }
ll zrb(ll &x, ll &y, ll mod) { return (x * y) % mod; }

void cnt(int s, int t)
{
	vector <pair<ll, int>> vs;
	for(int v = 1; v <= n; v++)
		if(d[v] + dR[v] == d[t])
			vs.push_back({d[v], v});

	ted1[s] = ted2[s] = ted3[s] = 1;
	tedR1[t] = tedR2[t] = tedR3[t] = 1;
	sort(vs.begin(), vs.end());
	for(auto chi : vs)
	{
		int v = chi.second;
		for(Edge e : gR[v])
			if(d[e.u] + dR[e.v] + e.l == d[t])
			{
				ted1[v] = add(ted1[v], ted1[e.u], MOD1);
				ted2[v] = add(ted2[v], ted2[e.u], MOD2);
				ted3[v] = add(ted3[v], ted3[e.u], MOD3);
			}
	}
	reverse(vs.begin(), vs.end());
	for(auto chi : vs)
	{
		int v = chi.second;
		for(Edge e : g[v])
			if(d[e.v] + dR[e.u] + e.l == d[t])
			{
				tedR1[v] = add(tedR1[v], tedR1[e.u], MOD1);
				tedR2[v] = add(tedR2[v], tedR2[e.u], MOD2);
				tedR3[v] = add(tedR3[v], tedR3[e.u], MOD3);
			}
	}
}

int s, t;

bool ok(int u, int v)
{
	return zrb(ted1[u], tedR1[v], MOD1) == ted1[t] &&
		   zrb(ted2[u], tedR2[v], MOD2) == ted2[t] &&
		   zrb(ted3[u], tedR3[v], MOD3) == ted3[t];
}

int main()
{
	cin >> n >> m >> s >> t;
	for(int i = 0; i < m; i++)
	{
		int u = in(), v = in(), l = in();
		es.push_back({u, v, l});
		g[u].push_back({v, u, l});
		gR[v].push_back({u, v, l});
	}
	
	dj(s, g, d);
	dj(t, gR, dR);
	assert(d[t] == dR[s]);

	cnt(s, t);

	for(Edge e : es)
	{
		ll len = d[e.u] + dR[e.v] + e.l;
		ll need = len - d[t];
		assert(need >= 0);
		if(!need && ok(e.u, e.v))
			cout << "YES\n";
		else if(e.l - need - 1 > 0)
			cout << "CAN " << need + 1 << "\n";
		else
			cout << "NO\n";
	}
}
