//Language: GNU C++


#include<iostream>
#include<vector>
using namespace std;

int n,m;
vector<int> g[333333];
int party[333333];

void dfs(int i)
{
    int se=0;
    for(int j=0;j<g[i].size();j++)
    if(party[g[i][j]]==party[i]) se++;
    if(se>1)
    {
        party[i]=1-party[i];
        for(int j=0;j<g[i].size();j++)
        dfs(g[i][j]);
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=1;i<=n;i++) dfs(i);
    for(int i=1;i<=n;i++) cout<<party[i];
    return 0;
}