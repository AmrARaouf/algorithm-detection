//Language: GNU C++


// In the name of Allah

#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << (x) << endl;
#define FOR(i,a,b) for ( int i = a; i < b; i ++ )
#define rep(i,n) for ( int i = 0; i < n; i ++ )
#define repd(i,n) for ( int i = n; i >= 0; i -- )
#define PI 3.14159265358979323846
#define pb push_back
#define mp make_pair
#define Y first
#define Z second
#define MP(a,b) mp ( min(a, b), max(a, b))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int max_n = 1e5+10;
int x [max_n], y [max_n];
bool z [max_n];
vector < pair<int, bool> > adj[max_n];
int vis [max_n];
int best [max_n];
vector <int> par, child;
int perv [max_n];
set <pii> Set;
int ans [max_n];

int main()
{
	int n, m;
	scanf ("%d%d", &n, &m);
	rep (i, m)
	{	
		int b;
		scanf ("%d%d%d", &x[i], &y[i], &b);
		x[i] --, y[i] --;
		z[i] = b;
		adj [x[i]].pb(mp(y[i], z[i]));
		adj [y[i]].pb(mp(x[i], z[i]));
	}
	
	memset (vis, 0, sizeof vis);
	memset (best, -1, sizeof best);
	vis[0] = 2;
	best [0] = 0;
	perv[0] = 0;
	par.pb (0);
	while ( par.size() && vis[n-1] < 2 )
	{	
		child.clear();
		rep (i, par.size())
		{
			int at = par[i];
			rep (j, adj[at].size())
			{
				int to = adj[at][j].Y;
				if ( vis[to] == 0 )
				{
					vis [to] = 1;
					child.pb (to);
				}
				if ( vis[to] == 1 && best[to] < best[at]+adj[at][j].Z )
				{
					best [to] = best[at]+adj[at][j].Z;
					perv [to] = at;
				}
			}
		}
		
		par.clear();
		rep (i, child.size())
		{
			par.pb (child[i]);
			vis [child[i]] = 2;
		}
	}
	
	for ( int u = n-1, v = perv[n-1]; u; u = v, v = perv[v] )
		Set.insert (MP(u, v));
	
	int k = 0;	
	rep (i, m)
		if ( Set.count(MP(x[i], y[i])) != z[i] )
			ans [k++] = i;
	
	printf ("%d\n", k);
	rep (i, k)
		printf ("%d %d %d\n", x[ans[i]]+1, y[ans[i]]+1, int(!z[ans[i]]));
	
	return 0;
}
