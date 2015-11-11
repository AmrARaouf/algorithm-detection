//Language: MS C++


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main(){
//	freopen("input.txt","r",stdin);
	int n,m;
	cin>>n>>m;
	vector<int> f(n);
	for(int i=0;i<n;i++)
		cin>>f[i];
	vector<vector<int> > gp(n),go(n),gi(n),gt(n);
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--; b--;
		gi[a].push_back(go[b].size());
		gp[a].push_back(b);
		go[b].push_back(a);
		gt[b].push_back(0);
	}
	queue<int> q;
	vector<int> u(n);
	for(int i=0;i<n;i++)
		if(f[i]==1){
			u[i]=1;
			q.push(i);
		}
	while(!q.empty()){
		int v=q.front();
		q.pop();
		for(int i=0;i<gp[v].size();i++){
			int b=gp[v][i];
			if(f[gp[v][i]]==0 || f[gp[v][i]]==2)
				gt[b][gi[v][i]]=1;
			if(u[b]==0 && f[b]!=1){
				u[b]=1;
				q.push(b);
			}
		}
	}
	vector<int> e(n);
	for(int i=0;i<n;i++)
		if(f[i]==2 && u[i]){
			e[i]=1;
			q.push(i);
		}
	while(!q.empty()){
		int v=q.front();
		q.pop();
		for(int i=0;i<go[v].size();i++){
			int b=go[v][i];
			if(gt[v][i]==1 && e[b]==0){
				e[b]=1;
				q.push(b);
			}
		}
	}
	for(int i=0;i<n;i++)
		cout<<e[i]<<endl;
	

}