//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;

int n,m,k,u,v;
vector<vector<int> > adj;
bool vis[110000];
int instak[110000];
vector<int>stk;
void solve(int node,int par=-1){

	if(instak[node] > 0){
		vector<int>ans;
		ans.push_back(node);
		while(stk.size() && stk.back()!=node){
			ans.push_back(stk.back());
			stk.pop_back();
		}
		if((int)ans.size() >= k){
			cout<<ans.size()<<endl;
			for(int i=0;i<(int)ans.size();i++){
				cout<<ans[i]+1<<" ";
			}
			exit(0);
		}
		for(int i=ans.size()-1;i>0;i--){
			stk.push_back(ans[i]);
		}
		return;
	}
	if(vis[node])return;
	vis[node]=1;
	stk.push_back(node);
	instak[node]++;
	for(int i=0;i<(int)adj[node].size();i++){
		int to = adj[node][i];
		if(to != par) solve(to,node);
	}
	instak[node]--;
	stk.pop_back();
}
int main(){
	cin>>n>>m>>k;
	k++;
	adj.resize(n);
	for(int i=0;i<m;i++){
		cin>>u>>v;
		u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(vis,0,sizeof vis);
	memset(instak,0,sizeof instak);
	for(int i=0;i<n;i++){
		if(!vis[i]){
			stk.clear();
			solve(i);
		}
	}
}
