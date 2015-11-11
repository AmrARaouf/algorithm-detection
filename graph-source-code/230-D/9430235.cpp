//Language: GNU C++0x


#include <bits/stdc++.h>
#include <ext/algorithm>
#include <ext/hash_map>
#include <ext/hash_set>
#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;

#ifdef HOME
	#define DB(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl;
#else
	#define DB(x)
#endif

#ifndef __GXX_EXPERIMENTAL_CXX0X__
	#define foreach(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#endif

typedef long long i64;
typedef pair<i64,i64> pii;

const i64 oo = 0x3f3f3f3f3f3f3f3f;
const int N = 100000 + 100;

vector<pii> G[N];
vector<pii> trips[N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m; cin >> n >> m;

	for(int i = 0; i < m; ++i)
	{
		int a, b, c; cin >> a >> b >> c;
		G[a].push_back(pii(b,c));
		G[b].push_back(pii(a,c));
	}

	for(int i = 1; i <= n; ++i)
	{
		int k, last = -1;
		cin >> k;

		for(int j = 0; j < k; ++j)
		{
			int t; cin >> t;
			if(last + 1 < t) trips[i].push_back(pii(last+1,t-1));
			last = t;
		}

		trips[i].push_back(pii(last+1,oo));
	}

	vector<i64> dist(n+1,oo);
	priority_queue<pii> PQ;

	dist[1] = 0;
	PQ.push(pii(0,1));

	while(!PQ.empty())
	{
		int s = PQ.top().second;
		i64 d = -PQ.top().first;

		PQ.pop();

		if(dist[s] < d) continue;

		auto p = lower_bound(trips[s].begin(), trips[s].end(), pii(0,d),
				[](pii a, pii b) { return a.second < b.second; });

		if(p != trips[s].end())
		{
			if(p->first > d)
				d = p->first;
		}

		for(auto &e : G[s])
			if(d + e.second < dist[e.first])
			{
				dist[e.first] = d + e.second;
				PQ.push(pii(-dist[e.first],e.first));
			}
	}

	if(dist[n] < oo) cout << dist[n] << endl;
	else cout << -1 << endl;

	return 0;
}
