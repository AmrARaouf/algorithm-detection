//Language: GNU C++


#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
#include <algorithm>
#define N 100010
using namespace std;
map<int,int> mp;
vector<int> g[N];
int id[N],ans[N],cnt[N],a=-1,b=-1;
void dfs(int u,int fa,int &idx)
{
    for(int i=0;i<g[u].size();i++){
        if(g[u][i]==fa) continue;
        ans[idx++]=id[g[u][i]];
        dfs(g[u][i],u,idx);
    }
}
int main()
{
    int n,idx=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        if(mp.find(u)==mp.end()) id[idx]=u,mp[u]=idx++;
        if(mp.find(v)==mp.end()) id[idx]=v,mp[v]=idx++;
        u=mp[u],v=mp[v];
        g[u].push_back(v);
        g[v].push_back(u);
        cnt[u]++,cnt[v]++;
    }
    for(int i=0;i<idx;i++) if(cnt[i]==1) {a=i;break;}
    idx=1,ans[0]=id[a];
    dfs(a,-1,idx);
    for(int i=0;i<idx;i++) cout<<ans[i]<<" ";
    return 0;
}
