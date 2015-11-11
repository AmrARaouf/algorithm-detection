//Language: GNU C++11


//In The Name Of God

// By I

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll Maxn = 1e5 + 7;
const ll Max = 1e3 + 7;
const ll Mod = 1e9 + 7;
const ll Inf = 2e9 + 7;

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define P_ll pair<ll, ll>
#define P_cl pair<char, ll>
#define P_lc pair<ll, char>
#define Sort( a ) sort ( a.begin(), a.end() )
#define God ios_base::sync_with_stdio ( false )

vector<ll>V[Maxn], G;
ll depth[Maxn], k, m, n;
bool mark[Maxn], q = false;

void dfs ( ll u )
{
	if ( q )
		return ;
	mark[u]++;
	G.pb ( u );
	ll M = Inf;
	for ( ll i = 0; i < V[u].size(); i++ )
	{
		ll v = V[u][i];
		if ( !mark[v] )
		{
			depth[v] = depth[u] + 1;
			dfs ( v );
		}
		else
		{
			M = min ( M, depth[v] );
		}
	}
	if ( depth[u] - M >= k && !q )
	{
		cout << depth[u] - M + 1 << endl;
		for ( ll i = M - 1; i < depth[u]; i++ )
			cout << G[i] << " ";
		cout << endl;
		q = true;
	}
}

int main()
{
	God;
	ll n, m, k;
	cin >> n >> m >> k;
	for ( ll i = 1; i <= m; i++ )
	{
		ll u, v;
		cin >> u >> v;
		V[u].pb ( v );
		V[v].pb ( u );
	}
	depth[1] = 1;
	dfs ( 1 );
	return 0;
}
