//Language: GNU C++


//============================================================================
// Name        : .cpp
// Source      :
// Author      : Momen_Saeed
//============================================================================

#include <bits/stdc++.h>
using namespace std;

#define sz(v)			(int)(v.size())
#define mems(a , i)		memset(a , i , sizeof(a))
#define memc(a , b)		memcpy(a , b , sizeof(a));
#define mp(x , y)		make_pair(x , y)
#define pb(x)			push_back(x)
const double EPS = 1e-8;

vector < vector <int> > adj;
vector < vector <int> > edge;
vector < pair <int , int> > v0 , v1;
vector <int> vis;

void dfs(int x){
	if(vis[x])	return;
	vis[x] = 1;
	for(int i = 0 ; i < sz(adj[x]) ; i++){
		dfs(adj[x][i]);
	}
}

void pro(){
	int x0 = v0[0].second , x1 = v1[0].second;
	dfs(x0);
	for(int i = 0 ; i < sz(v1) ; i++){
		if(!vis[v1[i].second]){
			vector <int> vv(3 , 0);
			vv[0] = x0 , vv[1] = v1[i].second;
			edge.pb(vv);
			adj[x0].pb(v1[i].second);
			adj[v1[i].second].pb(x0);
			dfs(v1[i].second);
		}
	}
	dfs(x1);
	for(int i = 0 ; i < sz(v0) ; i++){
		if(!vis[v0[i].second]){
			vector <int> vv(3 , 0);
			vv[0] = x1 , vv[1] = v0[i].second;
			edge.pb(vv);
			adj[x1].pb(v0[i].second);
			adj[v0[i].second].pb(x1);
			dfs(v0[i].second);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	int n;
	scanf("%d\n" , &n);
	adj.resize(n+1);

	for(int i = 0 ; i < n ; i++){
		int j , k;
		scanf("%d %d\n" , &j , &k);
		if(j)	v1.pb(mp(k , i+1));
		else v0.pb(mp(k , i+1));
	}
	sort(v0.begin() , v0.end());
	sort(v1.begin() , v1.end());
	int l = 0 , ll = 0;
	while(l < sz(v0) && ll < sz(v1)){
		vector <int> vv(3);
		vv[0] = v0[l].second , vv[1] = v1[ll].second;
		adj[v0[l].second].pb(v1[ll].second);
		adj[v1[ll].second].pb(v0[l].second);
		if(v0[l].first < v1[ll].first){
			vv[2] = v0[l].first;
			 v1[ll].first -= v0[l++].first;
		}
		else if(v0[l].first > v1[ll].first){
			vv[2] = v1[ll].first;
			v0[l].first -= v1[ll++].first;
		}
		else{
			vv[2] = v1[ll].first;
			l++ , ll++;
		}
		edge.pb(vv);
	}
	vis.resize(n+1 , 0);
	pro();
	for(int i = 0; i < sz(edge) ; i++){
		printf("%d %d %d\n" , edge[i][0] , edge[i][1] , edge[i][2]);
	}
	return 0;
}













