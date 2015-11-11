//Language: GNU C++0x


#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 2000 + 10;

int a[maxn][maxn];
vector<int> adjo[maxn];
vector<int> adji[maxn];
bool mark[maxn];
int n;

void dfs1(int v);
void dfs2(int v);

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j]) {
				adjo[i].push_back(j);
				adji[j].push_back(i);
			}
		}

	int ind = 0;
	for (int i = 0; i < n; i++)
		if (a[i][i])
			ind = i;
	dfs1(ind);
	for (int i = 0; i < n; i++)
		if (!mark[i]) {
			cout << "NO\n";
			return 0;
		}
	fill(mark, mark + n, false);
	dfs2(ind);
	for (int i = 0; i < n; i++) 
		if (!mark[i]) {
			cout << "NO\n";
			return 0;
		}

	cout << "YES\n";
	
	return 0;
}

void dfs1(int v) {
	mark[v] = true;
	for (auto u : adjo[v]) 
		if (!mark[u])
			dfs1(u);
}

void dfs2(int v) {
	mark[v] = true;
	for (auto u : adji[v])
		if (!mark[u])
			dfs2(u);
}



