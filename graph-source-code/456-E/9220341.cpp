//Language: GNU C++


#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 3e5+10;
int root[MAXN],d[MAXN],f,maxm,w;
vector<int>V[MAXN];
int find(int x){
    return x == root[x] ? x : root[x] = find(root[x]);
}
void dfs(int u,int v,int dep){
    root[v] = f;
    if(dep > maxm) maxm = dep,w = v;
    for(int i = 0;i < V[v].size();i ++){
        if(V[v][i] != u) dfs(v,V[v][i],dep+1);
    }
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("in.cpp","r",stdin);
#endif
    int n,m,u,v,q,t;cin >> n >> m >> q;
    for(int i = 0;i < m;i ++){
        scanf("%d%d",&u,&v);
        V[u].push_back(v);
        V[v].push_back(u);
    }
    for(int i = 1;i <= n;i ++){
        if(!root[i]){
            f = i,maxm = -1;
            dfs(i,i,0),maxm = -1;
            dfs(w,w,0),d[i] = maxm;
        }
    }
    while(q--){
        scanf("%d",&t);
        if(t == 1){
            scanf("%d",&u);
            printf("%d\n",d[find(u)]);
        }else{
            scanf("%d%d",&u,&v);
            u = find(u),v = find(v);
            if(u == v) continue;
            root[v] = root[u];
            d[u] = max(max(d[v],d[u]),(d[v] + 1)/2 + (d[u] + 1)/2 + 1);
        }
    }
    return 0;
}
