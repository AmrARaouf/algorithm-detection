//Language: MS C++


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> iip;
typedef pair<ll, int> lip;
typedef pair<ll, lip> liip;
typedef pair<int, iip> iiip;


const int NMAX = 300005;
const int MMAX = 300005;
vector<int> a[NMAX];
int w[NMAX];
long long d[NMAX];
iiip e[MMAX];


int main(){
	ios::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int z, x, c;
		cin >> z >> x >> c;
		z--; x--;
		e[i] = make_pair(c, make_pair(z, x));
		a[z].push_back(i);
		a[x].push_back(i);
	}
	int s; cin >> s; s--;

	priority_queue<liip> pq;
	d[s] = 1;
	for (int i = 0; i < a[s].size(); i++)
	{
		int eid = a[s][i];
		int v1 = s;
		int v2 = e[eid].second.first + e[eid].second.second - v1;
		pq.push(make_pair(-e[eid].first, make_pair(v2, eid)));
	}

	while (!pq.empty())
	{
		liip &z = pq.top();
		ll cost = -z.first;
		int v1 = z.second.first;
		if (d[v1] == 0)
		{
			d[v1] = -z.first;
			w[v1] = z.second.second;
			for (int i = 0; i < a[v1].size(); i++)
			{
				int eid = a[v1][i];
				int v2 = e[eid].second.first + e[eid].second.second - v1;
				if (d[v2] == 0)
					pq.push(make_pair(-cost - e[eid].first, make_pair(v2, eid)));
			}
		}
		else if (d[v1] == cost)
		{
			if (e[z.second.second].first < e[w[v1]].first)
				w[v1] = z.second.second;
		}
		pq.pop();
	}
	d[s] = 0;
	w[s] = m;
	long long cost = 0;
	for (int i = 0; i < n; i++)
	{
		cost += e[w[i]].first;
		e[w[i]].first = 0;
	}

	cout << cost << endl;
	for (int i = 0; i < n; i++)
	{
		if (i != s)
			printf("%d ", w[i] + 1);
	}
}