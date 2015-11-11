//Language: GNU C++11


#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define maxn 1000
#define inf 1e9
#define ll long long
using namespace std;
vector<int> adj[maxn];
int vis[maxn],v[maxn];
pair<int,int> arr[maxn];
int main(){
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> v[i];
		arr[i] = mp(-v[i],i);
	}
	for(int i=0;i<m;i++){
		int x,y;
		cin >> x >> y;
		x--; y--;
		adj[x].pb(y); adj[y].pb(x);
	}
	sort(arr,arr+n);
	ll tot = 0;
	for(int i=0;i<n;i++){
		int u = arr[i].second;
		vis[u]=1;
		for(int j=0;j<adj[u].size();j++){
			int nd = adj[u][j];
			if(vis[nd]) continue;
			tot += v[nd];
		}
	}
	cout << tot << endl;
}