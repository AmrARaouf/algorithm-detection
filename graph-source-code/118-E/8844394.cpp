//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<vector<int> > v;
int n, m;
typedef pair<int, int> pr;
vector<pr> ans;
map<pr,int> mp;
int vis[100009];
int best[100009];
int dfs(int u, int p, int d) {

	if (vis[u])
		return best[u];

	//cout << u << endl;
	int ret = d;
	vis[u] = d;
	best[u]=d;
	for (int i = 0; i < (int)v[u].size(); i++) {
		int nu = v[u][i];
		if (nu == p)
			continue;
		if(mp.count(pr(min(nu,u),max(nu,u)))==0)
		{
			mp[pr(min(nu,u),max(nu,u))]=1;
				ans.push_back(pr(u, nu));
		}
		ret = min(ret, dfs(nu, u, d + 1));
	}
	return best[u] = ret;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("2.in", "r", stdin);

#endif // ONLINE_JUDGE
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	v.resize(n + 2);
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, 0, 1);
	int fg = 1;

	//for(int i=1;i<=n;i++)
		//cout<<i<<" "<<vis[i]<<" "<<best[i]<<endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			int f = i;
			int t = v[i][j];
			if(vis[t]<vis[f])
				swap(f,t);
			if (vis[f] < best[t] )
				fg = 0;
		}
	}
	if (!fg)
		cout << 0 << endl;
	else {
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i].first << " " << ans[i].second << endl;
	}
	return 0;
}
