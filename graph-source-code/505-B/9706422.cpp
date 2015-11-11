//Language: GNU C++


#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<map>
#include<bitset>
using namespace std;
vector<int> graph[105][105];

void DFS(vector<int> grap[],int u,bool vis[],int v){

vis[u]=1;
for(int i=0;i<grap[u].size();i++){
if(vis[grap[u][i]]==0){
     DFS(grap,grap[u][i],vis,v) ;
}
}

}


int main(){
//freopen("input.txt","r",stdin);
int n,m;cin>>n>>m;
for(int i=1;i<=m;i++){

int c,u,v;cin>>u>>v>>c;
graph[c-1][u-1].push_back(v-1);
graph[c-1][v-1].push_back(u-1);

}

int q;cin>>q;
while(q--){
int u,v;cin>>u>>v;
int count=0;
for(int i=0;i<m;i++){
    bool vis[105]={0};
    DFS(graph[i],u-1,vis,v) ;

    if(vis[v-1]) count++;
}
cout<<count<<endl;
}


return 0;
}
