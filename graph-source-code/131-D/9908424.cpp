//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > adj;

stack<int> in_stk;
vector<int> the_cycle;
int vis[3003];//in_stak is 1 , out stack is 2 , in_visted is 0;
void get(int node ,int par=-1){
    if(vis[node] == 2)return;
    if(vis[node] == 1){
        if(the_cycle.size())return;
        while(in_stk.size()){
            the_cycle.push_back(in_stk.top());
            if(in_stk.top() == node)break;
            in_stk.pop();
        }
        
    }
    vis[node] = 1;
    in_stk.push(node);
    for(int i=0;i<int(adj[node].size());i++){
        if(adj[node][i] != par )
        get(adj[node][i] , node);
    }
    if(in_stk.size())
    in_stk.pop();
    vis[node]  = 2;
}

int ans[3003] ;


void bfs(int node){
    memset(vis , 0 , sizeof vis);
    queue<int> q;
    q.push(node);
    vis[node] = 1;
    int lvl = 0;
    while(q.size()){
        int sz = q.size();
        while(sz--){
            int cur = q.front() ;
            ans[cur] = min(ans[cur] , lvl);
            q.pop();
            for(int i=0;i<int(adj[cur].size()) ; i++){
                if(!vis[adj[cur][i]]){
                    vis[adj[cur][i]] = 1;
                    q.push(adj[cur][i]);
                }
            }

        }
        lvl++;
    }
}

int main(){
    int n,u,v;
    cin>>n;
    adj.resize(n);
    for(int i=0;i<n;i++){
        cin>>u>>v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    get(0);
    memset(ans,63,sizeof ans);
    for(int i=0;i<int(the_cycle.size()) ; i++){
        bfs(the_cycle[i]);
    }

    for(int i=0;i<n;i++)cout<<ans[i]<<" ";
}
