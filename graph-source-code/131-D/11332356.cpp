//Language: GNU C++


# include <bits/stdc++.h>

using namespace std;

const int maxn = 5000;
int n;
int mark[maxn];
int dis[maxn];
int hd[maxn] , hb[maxn];
vector <int> c;
vector <int> adj[maxn];

void dfs(int v,int par){
	mark[v] = 1;
	for(int i=0 ; i<adj[v].size() ; i++){
		int u = adj[v][i];
		if(mark[u] && u != par){
			for(int j=1 ; j<=n ; j++)
				if(mark[j] == 1 && hd[j] >= hd[u])
					c.push_back(j);
		}
		if(!mark[u]){
			hd[u] = hd[v] + 1;
			dfs(u , v);
		}
	}
	mark[v] = 2;
}

void bfs(int source){
	queue <int> q;
	q.push(source);
	mark[source] = 1;
	while(q.size()){
		int v = q.front();
		q.pop();
		for(int i=0 ; i<adj[v].size() ; i++){
			int u = adj[v][i];
			if(!mark[u]){
				mark[u] = 1;
				q.push(u);
				hb[u] = hb[v] + 1;
			}
		}
	}
}

int main(){
	cin >> n;
	for(int i=1 ; i<=n ; i++){
		int fi, se;
		cin >> fi >> se;
		adj[fi].push_back(se);
		adj[se].push_back(fi);
	}
	
	dfs(1 , -1);
	memset(mark , 0 , sizeof mark);
	memset(dis , 127 , sizeof dis);

	for(int i=0 ; i<c.size() ; i++){
		hb[c[i]] = 0;
		bfs(c[i]);
		for(int j=1 ; j<=n ; j++)
			dis[j] = min(dis[j] , hb[j]);

		memset(mark , 0 , sizeof mark);
	}

	for(int i=1 ; i<=n ; i++)
		cout << dis[i] <<" ";
	cout << endl;
	return 0;
}
