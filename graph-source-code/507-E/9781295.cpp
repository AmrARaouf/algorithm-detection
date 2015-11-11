//Language: MS C++


#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>

typedef long long lli;

#define forn(i, n) for (int i = 0; i < n; i++)
#define ford(i, n) for (int i = (n - 1); i >= 0; i--)
#define fore(i, a, b) for (int i = a; i < b; i++)
#define foreach(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define rforeach(it, a) for (auto it = a.rbegin(); it != a.rend(); it++)
#define all(a) a.begin(), a.end()
#define scani(a) scanf("%d", &(a))
#define scanii(a, b) scanf("%d%d", &(a), &(b))
#define scaniii(a, b, c) scanf("%d%d%d", &(a), &(b), &(c))
#define sqr(x) (x) * (x)

using namespace std;

struct edge
{
	int to;
	bool act;

	edge() {}
	edge(int a, bool b) : to(a), act(b) {}
};

vector<vector<edge>> g;

int main()
{
	int n, m, t1, t2, t3, cact = 0, cunact = 0;

	scanii(n, m);
	g = vector<vector<edge>>(n);

	forn(i, m)
	{
		scaniii(t1, t2, t3);

		t1--, t2--;

		g[t1].push_back(edge(t2, t3));
		g[t2].push_back(edge(t1, t3));

		if (t3) cact++;
		else cunact++;
	}

	queue<int> q;
	vector<int> d(n, 1000000);
	vector<int> act(n, -1);
	vector<int> prev(n, -1);
	d[0] = 0;
	act[0] = 0;
	q.push(0);

	while (!q.empty())
	{
		int v = q.front();
		q.pop();

		foreach(it, g[v])
		{
			int to = it->to;

			if (d[v] + 1 == d[to])
			{
				if (act[v] + it->act > act[to])
				{
					act[to] = act[v] + it->act;
					prev[to] = v;
				}
			}

			else if (d[v] + 1 < d[to])
			{
				d[to] = d[v] + 1;
				act[to] = act[v] + it->act;
				prev[to] = v;
				q.push(to);
			}
		}
	}

	printf("%d\n", cact - 2 * act[n - 1] + d[n - 1]);

	vector<char> marked(n, false);

	int x = n - 1;
	marked[x] = true;

	while (prev[x] != -1)
	{
		marked[prev[x]] = true;
		x = prev[x];
	}

	q.push(0);
	vector<char> used(n, 0);
	vector<char> addedToQueue(n, 0);

	while (!q.empty())
	{
		int v = q.front();
		q.pop();

		used[v] = true;

		foreach(it, g[v])
		{
			int to = it->to;

			if (used[to]) continue;

			if (marked[v] && marked[to])
			{
				if (!it->act) printf("%d %d 1\n", v + 1, to + 1);
			}

			else if (it->act)
			{
				printf("%d %d 0\n", v + 1, to + 1);
			}

			if (!addedToQueue[to])
			{
				q.push(to);
				addedToQueue[to] = true;
			}
		}
	}

	return 0;
}