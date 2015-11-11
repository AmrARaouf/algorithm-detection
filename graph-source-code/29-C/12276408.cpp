//Language: GNU C++


#include<bits/stdc++.h>

using namespace std;

int n, x, y, a, b, t, t2, id = 1;
map<int, int> mp;
map<int, int> freq;
map<int, int> mp2;
vector<int> v[100100];
bool vis[100100];

void dfs(int x) {
	vis[x] = 1;
	printf("%d ", mp2[x]);
	for (int i = 0; i < (int) v[x].size(); ++i) {
		if (!vis[v[x][i]])
			dfs(v[x][i]);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &x, &y);
		a = mp[x], b = mp[y];
		if (!a) {
			a = mp[x] = id;
			mp2[id] = x;
			++id;
		}

		if (!b) {
			b = mp[y] = id;
			mp2[id] = y;
			++id;
		}
		++freq[a], ++freq[b];
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int s;
	for (map<int, int>::iterator it = freq.begin(); it != freq.end(); ++it)
		if (it->second == 1) {
			s = it->first;
			break;
		}
	dfs(s);
	return 0;
}
