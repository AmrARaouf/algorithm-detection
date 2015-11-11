//Language: GNU C++


#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100*1000+10;
int N, u, v, w;
long long ftv[MAXN], ptv[MAXN];
vector <pair<int, int> > g[MAXN];
bool mark[MAXN];

void dfs(int u)
{
	mark[u] = 1;
	vector <pair<int, int> > tmp;
	tmp.resize(0);
	for (int i = 0 ; i < g[u].size() ; i++)
		if (!mark[g[u][i].first])
		{
			int y = g[u][i].first;
			int z = g[u][i].second;
			tmp.push_back(make_pair(y,z));
			dfs(y);
			ftv[u] += ftv[y]+2*z;
		}
	ptv[u] = ftv[u];
	for (int i = 0 ; i < tmp.size() ; i++)
	{
		int y = tmp[i].first;
		int z = tmp[i].second;
		ptv[u] = min(ptv[u], ftv[u]-ftv[y]-z+ptv[y]);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> N;
	for (int i = 0 ; i < N-1 ; i++)
	{
		cin >> u >> v >> w;
		g[u].push_back(make_pair(v, w));
		g[v].push_back(make_pair(u, w));
	}
	dfs(1);
	/*for (int i = 1 ; i <= N ; i++)
		cout << ftv[i] << " " << ptv[i] << endl;*/
	cout << ptv[1] << endl;
	return 0;
}
