//Language: GNU C++


# include<iostream>
# include<cstdio>
# include<vector>
# include<cstring>
using namespace std;
const int maxn = 300010;
vector<int>g[maxn];
int n,m,ans[maxn];

void dfs(int u)
{
    int cnt = 0,len = g[u].size();
    for(int i=0;i<len;++i)
        if(ans[u] == ans[g[u][i]]) cnt++;
    if(cnt>=2)
    {
        ans[u]^=1;
        for(int i=0;i<len;++i)
            if(ans[u] == ans[g[u][i]]) dfs(g[u][i]);
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=1;i<=n;++i) dfs(i);
    for(int i=1;i<=n;++i) cout<<ans[i];
    cout<<endl;
    return 0;
}
