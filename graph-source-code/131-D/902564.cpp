//Language: GNU C++


#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

vector<vector<int> > adj;
vector<int> stk;
int val[3001],root,visit[3001];

void DFS(int u, int v)
{
    if(root>-1)return;
   if(visit[v])
   {
      root = v;
      return;
   }
   visit[v]=1;
    stk.push_back(v);
   for(int i=0;i<adj[v].size();i++)
   {
      if(adj[v][i]==u)continue;
      DFS(v,adj[v][i]);
        if(root>-1)return;
   }
    stk.pop_back();
}

int find(int u, int v, int count)
{
    if(visit[v])return val[v];
    if(val[v]==-1)val[v]=count;
    visit[v]=1;
   for(int i=0; i<adj[v].size(); i++)
   {
        int t;
      if(adj[v][i]==u)continue;
        t = adj[v][i];
      val[v] = max(0, find(v, t, val[v]+1)-1);
   }
    
   return val[v];
}

int main()
{
    //freopen("input.txt","r",stdin);
   int n;
   cin>>n;
   adj.resize(n+1);
   memset(val,-1,sizeof(val));
   memset(visit,0,sizeof(visit));
   root=-1;
   for(int i=1;i<=n;i++)
   {
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }
    DFS(0,1);
    for(int i=0; i<stk.size(); i++)
    {
        if(stk[i]!=root)continue;
        for(;i<stk.size();i++)val[stk[i]]=0;
    }
            
    memset(visit,0,sizeof(visit));
   find(0,root,0);
   for(int i=1;i<=n;i++)cout<<val[i]<<" ";
   return 0;
}
