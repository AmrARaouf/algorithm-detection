//Language: GNU C++


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100005];
int color[100005];
map< pair<int,int> , bool> viscolor;
int cnt[100005];
int clrs[100005];
bool vis[100005];
set <int> st[100005];
void dfs(int node)
{
    vis[node]=1;
    for(int i=0; i<adj[node].size(); i++)
    {
        if(!vis[adj[node][i]])
        {
            if(color[node]!=color[adj[node][i]])
            {
                st[color[node]].insert(color[adj[node][i]]);
                st[color[adj[node][i]]].insert(color[node]);
                //if(!viscolor[make_pair(color[node],color[adj[node][i]])]) { cnt[color[node]]++; viscolor[make_pair(color[node],color[adj[node][i]])]=1; }
                //if(!viscolor[make_pair(color[adj[node][i]],color[node])]) { cnt[color[adj[node][i]]]++; viscolor[make_pair(color[adj[node][i]],color[node])]=1; }
            }
            dfs(adj[node][i]);
        }
    }

}
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=0; i<n ;i++)
    {
        cin >> clrs[i];
        color[i+1]=clrs[i];
    }
    for(int i=0; i<m; i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        if(color[a]!=color[b])
            {
                st[color[a]].insert(color[b]);
                st[color[b]].insert(color[a]);
    
            }
    }
    //dfs(1);
    sort(clrs,clrs+n);
    int mx=-1; int ans;
    for(int i=0; i<n; i++)
            {
           
                int x=st[clrs[i]].size();
                if(mx<x) mx=x,ans=clrs[i];
            }
    cout << ans;
    return 0;
}
