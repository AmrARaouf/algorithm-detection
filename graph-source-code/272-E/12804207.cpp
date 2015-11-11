//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > adj;
vector<int> ans;

void dfs(int node){
	int cnt=0;
	for(int i=0;i<(int)adj[node].size();i++)
		cnt += ans[node] == ans[adj[node][i]];
	if(cnt > 1){
		ans[node]^=1;
		for(int i=0;i<(int)adj[node].size();i++){
			int to = adj[node][i];
			if(ans[node] == ans[to])
				dfs(to);
		}
	}
}

int main(){
	int n,m,u,v;
	scanf("%d%d",&n,&m);
	adj.resize(n);
	ans.resize(n,0);
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=0;i<n;i++){
		dfs(i);
	}
	for(int i=0;i<n;i++)
		printf("%d",ans[i]);
}
