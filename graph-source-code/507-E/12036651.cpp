//Language: GNU C++


// In the name of GOD
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define f first
#define s second
vector< pii > adj[100010];
int s[100010]={0};
int d[100010]={0};
int vis[100010]={0};
int par[100010];
bool is[100010];
vector< pair < pii,int > > edges;
int main()
{
    int n,m;
    int x,y,z;
    scanf("%d%d",&n,&m);
    int damaged=0;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        adj[x].pb(mp(y,z));
        adj[y].pb(mp(x,z));
        if(!z)
            damaged++;
        edges.pb(mp(mp(x,y),z));
    }
    queue< int > bfs;
    bfs.push(1);
    d[1]=0;
    s[1]=0;
    vis[1]=1;
    while(!bfs.empty())
    {
        int t=bfs.front();
        vis[t]=2;
        bfs.pop();
        for(int i=0;i<adj[t].size();i++)
        {
            if(vis[adj[t][i].f]==2)
                continue;
            if(!vis[adj[t][i].f])
            {
                vis[adj[t][i].f]=1;
                s[adj[t][i].f]=s[t]+1;
                if(adj[t][i].s==0)
                    d[adj[t][i].f]=d[t]+1;
                else
                    d[adj[t][i].f]=d[t];
                par[adj[t][i].f]=t;
                bfs.push(adj[t][i].f);
            }
            else if(vis[adj[t][i].f]==1)
            {
                if((s[adj[t][i].f])>(s[t]+1))
                {
                    par[adj[t][i].f]=t;
                    s[adj[t][i].f]=s[t]+1;
                    if(adj[t][i].s==0)
                        d[adj[t][i].f]=d[t]+1;
                    else
                        d[adj[t][i].f]=d[t];
                }
                else if(s[adj[t][i].f]==(s[t]+1)) 
                {
                    if(adj[t][i].s==0)
                    {
                        d[adj[t][i].f]=min(d[adj[t][i].f],d[t]+1);
                        if(d[adj[t][i].f]==(d[t]+1))
                            par[adj[t][i].f]=t;
//                      cout<<d[8]<<endl;
                    }
                    else
                    {
                        d[adj[t][i].f]=min(d[adj[t][i].f],d[t]);
                        if(d[adj[t][i].f]==d[t])
                            par[adj[t][i].f]=t;
                    }
                }
            }
        }
    }
    int idx=n;
    while(idx!=1)
    {
        is[idx]=1;
        idx=par[idx];
    }
    is[1]=1;
    int undamaged=m-damaged;
    cout<<d[n]+undamaged-(s[n]-d[n])<<endl;
    for(int i=0;i<m;i++)
    {
        if(is[edges[i].f.f] && is[edges[i].f.s] && (par[edges[i].f.s]==edges[i].f.f || par[edges[i].f.f]==edges[i].f.s))
        {
            if(edges[i].s==0)
                printf("%d %d %d\n",edges[i].f.f,edges[i].f.s,1);
        }
        else
        {
            if(edges[i].s==1)
                printf("%d %d %d\n",edges[i].f.f,edges[i].f.s,0);
        }
    }
    return 0;
}