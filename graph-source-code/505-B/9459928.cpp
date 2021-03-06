//Language: GNU C++


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <string>
#include <stdio.h>
using namespace std;
vector<vector<vector<int > > > rel;
vector<bool> reach;
bool dfs(int a, int b, int col){
    if(a==b) return true;
    if(reach[a]) return false;
    reach[a]=true;
    for(int i=0;i<rel[col][a].size();++i)
        if(dfs(rel[col][a][i],b, col)) return true;
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    rel.resize(m+1);
    for(int i=0;i<m+1;++i)
        rel[i].resize(n+1);
    for(int i=0;i<m;++i){
        int a,b,c;
        cin>>a>>b>>c;
        rel[c][a].push_back(b);
        rel[c][b].push_back(a);
    }
    int q;
    cin>>q;
    for(int i=0;i<q;++i){
        int a,b;
        cin>>a>>b;
        int acc=0;
        for(int col=1;col<=m;++col){
            reach.assign(n+1,0);
            if(dfs(a,b,col)) ++acc;
        }
        cout<<acc<<endl;
    }
}