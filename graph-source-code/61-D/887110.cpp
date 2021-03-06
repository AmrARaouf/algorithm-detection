//Language: GNU C++


#include<iostream>
#include<vector>
#define pb push_back
using namespace std;
const int maxn=100100;
vector<int> adj[maxn],cst[maxn];
long long ans;
long long dfs(int x,int l,long long len){
	bool k=true;
	for(int i=0;i<adj[x].size();i++)
		if(adj[x][i]!=l){
			k=false;
			dfs(adj[x][i],x,len+cst[x][i]);
		}
	if(k)
		ans=max(ans,len);
}
int main(){
	int n,u,v,l;
	long long sum=0;
	cin>>n;
	for(int i=0;i<n-1;i++){
		cin>>u>>v>>l;
		u--;v--;sum+=l;
		adj[u].pb(v);
		adj[v].pb(u);
		cst[u].pb(l);
		cst[v].pb(l);
	}
	dfs(0,-1,0);
	cout<<(2*sum)-ans<<endl;
}
		
	 				 	 	 	    		 	  		