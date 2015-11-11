//Language: GNU C++


#include<iostream>
#include<queue>
#include<algorithm>
#include<list>
#include<map>
#include<vector>
#include<string>
#include<sstream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
#define Space " "
#define Author "DemoVersion"
#define MAXN 112345
#define ull unsigned long long
struct edge{
    int w,v;
    void set(int V,int W){v=V,w=W;}
};
vector<edge> R[MAXN];
long long  dfs(int v,int p){
    long long  max=0,tmp;
    for(vector<edge>::iterator k = R[v].begin(); k != R[v].end() ; k++){
        if(k->v==p)continue;
        tmp=dfs(k->v,v)+k->w;
        if(tmp>max)max=tmp;
    }
    return max;
}
int main(){
    int n,i,v,u,w;
    long long sum=0,p;
    edge T;
    for(cin>>n,i=0;i<n-1;i++){
        cin>>u>>v>>w;
        sum+=w;
        T.set(v,w);
        R[u].push_back(T);
        T.set(u,w);
        R[v].push_back(T);
    }
    p=dfs(1,0);
    cout<<sum*2-p<<endl;
    return 0;
}
