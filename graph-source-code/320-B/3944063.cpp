//Language: GNU C++


#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <iomanip>
#define PI acos(-1.0)
using namespace std;
int n,t,x,y,u[105],v[105],m;
bool a[105][105],vis[105],yes;
void dfs(int X){
	if (X==y) yes=1;
	vis[X]=1;
	for(int i=1; i<=m; ++i)
		if (a[X][i]&&!vis[i]) dfs(i);
}
int main(){
	cin>>n;
	for(int i=1; i<=n; ++i){
		cin>>t>>x>>y;
		if (t==1){
			u[++m]=x;
			v[m]=y;
		}
		else{
			for(int j=1; j<=m; ++j)
				for(int k=1; k<=m; ++k)
					a[j][k]=0;
			for(int j=1; j<=m; ++j)
				for(int k=1; k<=m; ++k){
					if (j==k) continue;
					if ((u[k]<u[j]&&u[j]<v[k])||(u[k]<v[j]&&v[j]<v[k])) a[j][k]=1;
				}
			yes=0;
			for(int j=1; j<=m; ++j) vis[j]=0;
			dfs(x);
			if (yes) cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
	return 0;
}
