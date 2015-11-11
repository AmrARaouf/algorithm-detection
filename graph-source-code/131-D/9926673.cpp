//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;


vector<vector<int> > adj;

int vis[3003] , ID=0;
vector<int> cycle;
void dfs(int node , int par = -1){
    if(vis[node] == ID){
        cycle.push_back(node);
        return ;
    }
    vis[node] = ID;
    for(int i=0;i<adj[node].size();i++){
        if(par != adj[node][i]){
            dfs(adj[node][i] , node);
        }
    }
    
}

int ans[3003];
void bfs(int node){
    ID++;
    vis[node] = ID;
    queue<int> Q;
    Q.push(node);
    int lvl = 0 ;
    while(Q.size()){
        int sz = Q.size();
        while(sz--){
            int cur = Q.front();
            Q.pop();
            ans[cur] = min(lvl , ans[cur]);
            for(int i=0;i<adj[cur].size();i++){
                if(vis[adj[cur][i]] == ID)continue;
                vis[adj[cur][i]]=ID;
                Q.push(adj[cur][i]);
            }
        }
        lvl++;
    }
}


int main() {
    int n;
    int u,v;
    cin>>n;
    adj.clear();
    adj.resize(n);
    
    for(int i=0;i<n;i++){
        cin>>u>>v;u--,v--;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    
    for(int i=0;i<n;i++){
        ID++;
        dfs(i);
    }
    memset(ans , 63 , sizeof ans);
    for(int i=0;i<cycle.size();i++){
        bfs(cycle[i]);
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    
    return 0;
}