//Language: MS C++


#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

vector <int> G[2010];
int Par[2010], ans;

void DFS(int u, int depth){
	if(depth>ans)	ans=depth;
	for(int i=0;i<(int)G[u].size();i++)if(G[u][i]!=Par[u]){
		DFS(G[u][i],depth+1);
	}
	
}

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>Par[i];
		if(Par[i]!=-1){
			G[i].push_back(Par[i]);
			G[Par[i]].push_back(i);
		}
	}
	ans=0;
	for(int i=1;i<=n;i++)if(Par[i]==-1){
		DFS(i,1);
	}
	cout<<ans<<endl;
}

