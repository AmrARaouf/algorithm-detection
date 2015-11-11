//Language: GNU C++


#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
const int mm=310000;
int f[mm];
map<int,int>mp;///离散指针
vector<int>g[mm];///邻接表
int a,b,m;
int pos;
bool vis[mm];//记录走过的点
bool flag;
bool dfs(int u,int dep)///dep访问不同点的个数
{

  if(dep==pos){cout<<f[u]<<" ";return 1;}
  for(int i=0;i<g[u].size();i++)
      if(!vis[g[u][i]])
      { vis[g[u][i]]=1;
        if(dfs(g[u][i],dep+1))
        {
          cout<<f[u]<<" ";return 1;
        }
        vis[g[u][i]]=0;
      }


}
int main()
{
  while(cin>>m)
  { mp.clear();pos=0;
    for(int i=0;i<mm;i++)
      g[i].clear();
     for(int i=0;i<m;i++)
    { cin>>a>>b;
      if(mp[a]==0)mp[a]=++pos,f[pos]=a;///离散化
      if(mp[b]==0)mp[b]=++pos,f[pos]=b;
      g[mp[a]].push_back(mp[b]);
      g[mp[b]].push_back(mp[a]);

    }
    memset(vis,0,sizeof(vis));
    int x=1;///保证所搜路径包含解路径
    for(int i=1;i<=pos;i++)
      if(g[i].size()==1)x=i;
      vis[x]=1;
    dfs(x,1);
    cout<<"\n";
  }
}