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
bool M[2010];
bool Mark[2010];

void DFS(int u){
	Mark[u]=1;
	for(int i=0;i<(int)G[u].size();i++)if(Mark[G[u][i]]==0){
		DFS(G[u][i]);
	}
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		G[x].push_back(y+1000);
		G[y+1000].push_back(x);
		M[x]=1;
		M[y+1000]=1;
	}
	int ans=-1;
	for(int i=1;i<2010;i++)if((M[i]==1)&&(Mark[i]==0)){
		ans+=1;
		DFS(i);
	}
	cout<<ans<<endl;
	
}

