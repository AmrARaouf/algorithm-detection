//Language: GNU C++


#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<ll> adj[20005];
ll bfs(ll n,ll m)
{
    if(n==m)
    return 0;
    queue< pair<ll,ll> > q;
    q.push( make_pair(n,0));
    ll steps=0;
    bool visited[20005];
    memset(visited,0,sizeof(visited));
    visited[n]=true;
    while(!q.empty())
    {
        pair <ll,ll> p=q.front();
        //cout<<p.first<<endl;
       if(p.first==m)
       return p.second;
        visited[p.first]=true;
        q.pop();
        if(p.first <10005)
        {
            for(ll i=0;i<adj[p.first].size();i++)
            {
                if(!visited[adj[p.first][i]])
                {
                q.push( make_pair(adj[p.first][i],p.second+1));
                //cout<<adj[p][i]<<endl;
                }
            }
        }
        //steps++;
    }
    //return steps;
}
int main()
{
    for(ll i=1;i<10005;i++)
    {
        if(i!=1)
        adj[i].push_back(i-1);
        
        adj[i].push_back(2*i);
    }
    ll n,m;
    cin>>n>>m;
    cout<<bfs(n,m)<<endl;
    return 0;
}