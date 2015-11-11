//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;

const int maxn = (int) 1e3 + 10;

int G[maxn][maxn],dep[maxn],data[maxn],n;
int   dfs(int u ,int fa){

    if(dep[u]) return dep[u];
    int ok = 1;
    for(int i = 1; i<= n; ++ i){
        if(G[u][i] && i !=fa) {
            dep[u] = max(dfs(i,u) + 1, dep[u]);
            ok = 0;
        }
    }
    return ok?ok:dep[u];
}

int main(){
    int k;
    while(scanf("%d%d",&n,&k) != EOF){
        memset(G,1,sizeof(G));
        memset(dep,0,sizeof(dep));
        for(int i = 1; i<= k; ++ i){
            for(int j = 1;j <= n; ++ j) scanf("%d",&data[j]);
            for(int j = 1;j <= n; ++ j)
                for(int l = j + 1;l <= n; ++ l) G[data[l]][data[j]] = 0;
        }
        for(int i = 1; i<= n; ++ i) G[i][i] = 0;
        for(int i = 1; i<= n; ++ i){
             dfs(i,0);
        }
        int ans = 1;
        for(int i = 1; i<= n; ++ i) ans = max(ans,dep[i]);
        printf("%d\n",ans);
    }
}
