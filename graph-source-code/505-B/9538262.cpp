//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
typedef vector<pi> vi;
vector<vi> adj(101);
vector<bool> visited(101);
int x=0;
int dfs(int u,int v,int color)
{
    visited[u]=true;
    if(u==v)
    {
        return 1;
    }
    for(int i=0; i<adj[u].size(); i++)
    {
        pi m=adj[u][i];
        if(m.second==color && visited[m.first]==0)
        {
            if(m.first==v)
            {
               x=1;
                return 1;
            }
            dfs(m.first,v,color);
        }
    }
    return x;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++)
    {
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        u--;
        v--;
        c--;
        adj[u].push_back(make_pair(v,c));
        adj[v].push_back(make_pair(u,c));
    }

    int q;
    scanf("%d",&q);
    while(q--)
    {
        int u,v;
        int count=0;
        scanf("%d%d",&u,&v);
        u--;
        v--;
        for(int i=0; i<=100; i++)
        {
            for(int j=0; j<n; j++)
            {
                visited[j]=false;

            }
            x=0;
            if(dfs(u,v,i))
                count++;

        }
        cout<<count<<"\n";
    }
    return 0;
}
