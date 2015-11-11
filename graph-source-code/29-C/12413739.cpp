//Language: GNU C++11


	//	. .. ... .... ..... be name khoda ..... .... ... .. . 	\\

#include <bits/stdc++.h>
using namespace std;

int in() { int x; scanf("%d", &x); return x; }
const int N = 200002;

int a[N], b[N];
vector <int> g[N], xs;

int main()
{
	int n = in();
	for(int i = 0; i < n; i++)
	{
		xs.push_back(a[i] = in());
		xs.push_back(b[i] = in());
	}
	sort(xs.begin(), xs.end());
	xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
	for(int i = 0; i < n; i++)
	{
		a[i] = lower_bound(xs.begin(), xs.end(), a[i]) - xs.begin();
		b[i] = lower_bound(xs.begin(), xs.end(), b[i]) - xs.begin();
		g[a[i]].push_back(b[i]);
		g[b[i]].push_back(a[i]);
	}
	vector <int> path;
	for(int i = 0; i < xs.size(); i++)
		if(g[i].size() % 2)
		{
			int v = i;
			while(1)
			{
				path.push_back(v);
				if(!g[v].size())
					break;
				assert(g[v].size() == 1);
				int u = g[v][0];
				if(g[u].back() != v)
					swap(g[u][0], g[u][1]);
				g[u].pop_back();
				v = u;
			}
			break;
		}
	for(int x : path)
		cout << xs[x] << " ";
	cout << endl;
}
