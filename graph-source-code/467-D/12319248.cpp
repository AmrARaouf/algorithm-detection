//Language: MS C++


#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <cmath>
#include <memory.h>
#include <algorithm>
using namespace std;
int n,m,id = 0;
map<string,int> mp;
map<string,int>::iterator it;
char s[100001];
int L[300007] ,R[300007],v[100007];
vector<vector<int> > g;

int getIdx(){
    int N = strlen(s);
    for(int i=0;i<N;i++)
        s[i] |= 0x20;
    if(mp.count(s)) return mp[s];
    L[id] = R[id] = 0;
    for(int i=0;i<N;i++){
        L[id]++;
        R[id] += s[i] == 'r';
    }
    g.resize(id+1);
    return mp[s]=id++;
}
const int MAX = 300003;
int idx[MAX], low[MAX], compOf[MAX],dfs= 1;
bool vis[MAX];
vector<int> S;
vector<pair<int,int> > comp;
vector<vector<int> > G;
pair<int,int> dp[MAX];

void DFS(int u,int p){
    idx[u] = low[u] = dfs++;
    vis[u] = 1;
    S.push_back(u);
    for(int i=0;i<(int)g[u].size();i++){
        int v = g[u][i];
        if(idx[v]==0)
            DFS(v,u);
        if(vis[v])
            low[u] = min(low[u],low[v]);
    }
    if(idx[u]==low[u]){
        pair<int,int> best = make_pair((int)1e9,(int)1e9);
        while(true){
            int v = S.back();
            S.pop_back();
            compOf[v] = comp.size();
            vis[v] = 0;
            best = min(best,make_pair(R[v],L[v]));
            if(u==v)
                break;
        }
        comp.push_back(best);
    }
}

pair<int,int> calc(int u){
    if(dp[u].first!=-1) return dp[u];
    dp[u] = comp[u];
    for(int i=0;i<(int)G[u].size();i++){
        int v = G[u][i];
        dp[u] = min(dp[u],calc(v));
    }
    return dp[u];
}

int main()
{
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%s",s);
        v[i] = getIdx();
    }
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",s);
        int a = getIdx();
        scanf("%s",s);
        int b = getIdx();
        g[a].push_back(b);
    }
    for(int i=0;i<(int)g.size();i++)
        idx[i] = vis[i] = 0;
    for(int i=0;i<(int)g.size();i++)
        if(idx[i]==0)
            DFS(i,-1);
    G.resize(comp.size());
    for(int i=0;i<(int)g.size();i++)
        for(int j=0;j<(int)g[i].size();j++){
            int a = compOf[i];
            int b = compOf[g[i][j]];
            if(a!=b)
                G[a].push_back(b);
        }
    for(int i=0;i<(int)G.size();i++)
        dp[i].first = dp[i].second = -1;
    long long r(0),len(0);
    for(int i=0;i<m;i++){
        pair<int,int> p = calc(compOf[v[i]]);
        r += p.first;
        len += p.second;
    }
    printf("%I64d %I64d",r,len);
    return 0;
}
