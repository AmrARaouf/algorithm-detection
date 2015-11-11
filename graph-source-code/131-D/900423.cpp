//Language: GNU C++0x


#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <iterator>
#include <functional>
#include <limits>
#include <algorithm>
#include <numeric>

#include <cmath>
#include <cassert>

using namespace std;

bool run_tests();

typedef vector<set<size_t>> graph_t;

typedef vector<size_t> dsu_t;

void dsu_init(dsu_t &dsu)
{
	for (size_t i = 0; i<dsu.size(); ++i)
		dsu[i] = i;
}

size_t dsu_get(dsu_t &dsu, size_t n)
{
	return dsu[n] = (dsu[n]==n?n:dsu_get(dsu, dsu[n]));
}

size_t dsu_unite(dsu_t &dsu, size_t a, size_t b)
{
	a = dsu_get(dsu, a);
	b = dsu_get(dsu, b);
	if (rand()&1)
		swap(a, b);
	dsu[a] = b;
	return dsu_get(dsu, a);
}

#define USE_DSU 0

int main()
{
	std::ios_base::sync_with_stdio(false);
	assert(run_tests());
	size_t n;
	cin>>n;
	graph_t g(n);
#if USE_DSU
	dsu_t dsu(n);
	dsu_init(dsu);
	bool found = false;
	size_t first, second;
#endif
	for (size_t i = 0; i<n; ++i)
	{
		size_t x, y;
		cin>>x>>y;
		--x; --y;
		g[x].insert(y);
		g[y].insert(x);
#if USE_DSU
		size_t a = dsu_get(dsu, x);
		size_t b = dsu_get(dsu, y);
		if (a==b)
		{// cycle was found, it contains both a and b vertices
			assert(!found);
			first = x;
			second = y;
		}
		else
			dsu_unite(dsu, a, b);
#endif
	}
	graph_t cp = g;
	bool changed;
	do
	{
		changed = false;
		for (size_t i = 0; i<n; ++i)
			if (cp[i].size()==1)
			{
				size_t x = *cp[i].begin();
				cp[i].erase(cp[i].begin());
				cp[x].erase(i);
				changed = true;
			}
	}
	while (changed);
	constexpr size_t inf = 1e9;
	vector<size_t> path(n, inf);
	queue<size_t> q;
	vector<bool> used(n, false);
	for (size_t i = 0; i<n; ++i)
		if (!cp[i].empty())
		{
			path[i] = 0;
			q.push(i);
			used[i] = true;
		}
	while (!q.empty())
	{
		size_t cur = q.front();
		q.pop();
		for (const auto &i: g[cur])
		{
			if (!used[i])
			{
				used[i] = true;
				q.push(i);
				path[i] = path[cur]+1;
			}
		}
	}
	for (size_t i = 0; i<n; ++i)
	{
		if (i)
			cout<<' ';
		cout<<path[i];
	}
	cout<<endl;
}

bool run_tests()
{
	return true;
}

