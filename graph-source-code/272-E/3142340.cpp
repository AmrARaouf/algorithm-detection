//Language: GNU C++


#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
#define pii pair<int,int>;
using namespace std;
int labels[500000];
int pres[500000];
vector<int> adj[500000];
set<int> extra;

void check(int node){
		if(pres[node]>=2){
			extra.insert(node);
		}
		else extra.erase(node);
}
int main(){
	int n,m;
	
	fill(labels,labels+500000,0);
	fill(pres,pres+500000,0);
	
	cin>>n>>m;
	for (int i = 0; i < m; i += 1)
	{
		int a,b; cin>>a>>b;
		a--;b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
		pres[a]++;pres[b]++;
		check(a);check(b);
	}
	while(!extra.empty()){
		int node = *extra.begin();
		int x;
		for (int i = 0; i < adj[node].size(); i += 1)
		{
			int ne = adj[node][i];
			if(labels[ne]==labels[node]){
				pres[ne]--;
				pres[node]--;
			}
			else{
				pres[ne]++;
				pres[node]++;
			}
			check(ne);
		}
		check(node);
		labels[node] = 1-labels[node];
	}
	for (int i = 0; i < n; i += 1)
	{
		cout<<labels[i];
	}		
	cout<<"\n";
}
