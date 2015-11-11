//Language: GNU C++11


#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const int maxv=3040;
int n,m;
vector<int> G[maxv];
int dis[maxv][maxv];
int s1,t1,l1,s2,t2,l2;
queue<int> Q;
void bfs(int u){
	dis[u][u]=0;
	Q.push(u);
	while(!Q.empty()){
		int v=Q.front();
		Q.pop();
		for(int i=0;i<G[v].size();i++){
			int vv=G[v][i];
			if(dis[u][vv]>dis[u][v]+1){
				dis[u][vv]=dis[u][v]+1;
				Q.push(vv);
			}
		}
	}
}
void solve(){
	if(dis[s1][t1]>l1||dis[s2][t2]>l2){
		cout<<-1<<endl;
		return;
	}
	int ans=m-dis[s1][t1]-dis[s2][t2];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			 if(dis[s1][i]+dis[i][j]+dis[j][t1]<=l1&&dis[s2][j]+dis[i][j]+dis[i][t2]<=l2)
				 ans=max(ans,m-dis[s1][i]-dis[t2][i]-dis[i][j]-dis[s2][j]-dis[j][t1]);
			 if(dis[s1][i]+dis[i][j]+dis[j][t1]<=l1&&dis[s2][i]+dis[i][j]+dis[j][t2]<=l2){
				  ans=max(ans,m-dis[s1][i]-dis[s2][i]-dis[i][j]-dis[j][t2]-dis[j][t1]);
			 }
			/*int d1=min(dis[s1][i]+dis[j][t1],dis[s1][j]+dis[i][t1]);
			int d2=min(dis[s2][i]+dis[j][t2],dis[s2][j]+dis[i][t2]);
			if(d1+dis[i][j]<=l1&&d2+dis[i][j]<=l2)
				ans=max(ans,m-d1-d2-dis[i][j]);*/
		}
	}
	cout<<ans<<endl;
}
int main(){
	/////freopen("/home/files/CppFiles/in","r",stdin);
	cin>>n>>m;
	memset(dis,0x3f,sizeof dis);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		G[a].pb(b);
		G[b].pb(a);
	}
	cin>>s1>>t1>>l1>>s2>>t2>>l2;
	for(int i=1;i<=n;i++) bfs(i);
	solve();
	return 0;
}

		    		 						 	 		  		  					