//Language: GNU C++0x


#include<bits/stdc++.h>
#define LL long long
using namespace std;

int n,m,a,b,t, d[100005];
int total = 0, ans = 1<<28,pathCost = 1<<28, q[100005];
bool v[100005],belongsPath[200005] = {0};
int from[200005], to[200005], nxt[200005], adj[200005], w[200005], e = 0;
vector<int> optimalPath,tmpPath;

void add_edge(int a, int b, int type){
    from[e] = a; to[e] = b; w[e] = type;
    nxt[e] = adj[a]; adj[a] = e++;
}

void bfs(int src){
    for(int i=0; i<=n; i++) d[i] = 1<<28; 
    int i,j;
    d[src] = i = j = 0;
    q[j++] = src;
    while(i<=j && q[i] != n){
        for(int k=adj[q[i]]; k!=-1; k=nxt[k]){
            if(d[from[k]] + 1 < d[to[k]]){
                d[to[k]] = d[from[k]] + 1;
                q[j++] = to[k];
            }
        }
        i++;
    }
}

void dfs(int x, int c){
    if(x == n){
        if(c < pathCost){ // stupid but just try to cut cost
            pathCost = c;
            optimalPath = tmpPath;
        }
        return;
    }
    for(int i=adj[x]; i!=-1;i=nxt[i]){
        if(d[to[i]] == d[x]+1 && c+!w[i] < pathCost){
            tmpPath.push_back(i);
            dfs(to[i], c + !w[i]);
            tmpPath.pop_back();
        }
    }
}

int main() {
    scanf("%d%d", &n,&m);
    for(int i=0; i<=n;i++) adj[i] = -1;
    for(int i=0; i<m;i++){
        scanf("%d%d%d", &a,&b,&t);
        add_edge(a,b,t);add_edge(b,a,t);
        total += t;
    }
    bfs(1);
    dfs(1,0);
    
    printf("%d\n", total - d[n] + 2*pathCost);
    for(int i=0; i<optimalPath.size();i++) belongsPath[optimalPath[i]] = 1;
    for(int i=0; i<e;i+=2)
        if(belongsPath[i] | belongsPath[i+1]){
            if(!w[i]) printf("%d %d %d\n", from[i], to[i], !w[i]);
        }
        else{
            if(w[i]) printf("%d %d %d\n", from[i], to[i], !w[i]);
        }
    
    return 0;
}