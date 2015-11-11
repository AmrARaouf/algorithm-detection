//Language: MS C++


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <hash_map>
#include <map>
#include <hash_set>
#include <set>
#include <stack>
#include <algorithm>
#include <sstream>
#include <queue>
#include <math.h>
using namespace std;
typedef long long LL;
#define mems(arr, val) memset(arr, val, sizeof(arr));
#define all(A) A.begin(), A.end()
#define forn(it, from, to) for(int it = from; it < to; ++it)
#define INF 2000000000
#define SIZE 1000009
#define mp(a, b) make_pair(a, b)
bool A[100000];

int dijkstra(vector<vector<pair<int, int>>> &G, int s, int l)
{
	vector<int> d(G.size(), INT_MAX);
	vector<int> p(G.size());
	vector<char> used(G.size(), 0);
	set<pair<int, int>> S;
	S.insert(mp(0, s));
	d[s] = 0;
	p[s] = s;
	while(S.size() > 0)
	{
		int val = S.begin()->first;
		int v = S.begin()->second;
		used[v] = 1;
		S.erase(*S.begin());
		for(int i = 0; i < G[v].size(); ++i)
		{
			int to = G[v][i].first;
			int len = G[v][i].second;
			if (!used[to] && d[v] + len < d[to])
			{
				S.erase(mp(d[v] +len, to));
				d[to] = d[v] + len;
				p[to] = v;
				S.insert(mp(d[to], to));
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < G.size(); ++i)
	{
		if (d[i] == l) ans++;
		for(int j = 0; j < G[i].size(); ++j)
		{
			int len = G[i][j].second;
			int to = G[i][j].first;
			int fr = i;
			if (to > fr) continue;
			if (d[fr] > l && d[to] > l) continue;
			if (l > d[fr] && l < d[fr] + len && l < d[to] + len - (l - d[fr])) ans++;
			if (l > d[to] && l < d[to] + len && l < d[fr] + len - (l - d[to])) ans++;
			if (d[fr] + d[to] + len == 2 * l && l > d[fr] && l > d[to]) ans++;
			//if (d[fr] == l) ans++;
			//if (d[to] == l) ans++;
		}
	}

	return ans;
}

int main()
{
#ifdef MY_SOL
	freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#endif
	int n,m,s;
	cin>>n>>m>>s;
	s--;
	vector<vector<pair<int, int> > > G(n);
	forn(i, 0, m)
	{
		int from, to, len;
		cin>>from>>to>>len;
		from--;
		to--;
		G[from].push_back(mp(to, len));
		G[to].push_back(mp(from, len));
	}
	int l;
	cin>>l;
	if (l == 0)
	{
		cout<<1;
		return 0;
	}
	cout<<dijkstra(G, s, l);
	return 0;
}

