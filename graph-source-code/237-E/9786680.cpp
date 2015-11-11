//Language: GNU C++0x


#include<bits/stdc++.h>
using namespace std;
namespace SPFAMCF
{
    const int maxn=5000,maxm=50000,inf=1000000000;
    
    struct Edge
    {
        Edge(){}
        Edge(int a,int b,int c,int d){v=a,f=b,w=c,nxt=d;}
        int v,f,w,nxt;
    };
    
    int n,lmt;
    int g[maxn+10];
    Edge e[maxm+10];
    int nume;
    int src,sink;
    
    void addedge(int u,int v,int c,int w)
    {
        e[++nume]=Edge(v,c,w,g[u]);
        g[u]=nume;
        e[++nume]=Edge(u,0,-w,g[v]);
        g[v]=nume;
    }
    
    void init()
    {
        memset(g,0,sizeof g);
        nume=1;
    }
    queue<int>que;
    bool inQue[maxn+10];
    int dist[maxn+10];
    int prev[maxn+10],pree[maxn+10];
    
    bool findPath()
    {
        while(!que.empty())que.pop();
        que.push(src);
        memset(dist,63,sizeof dist);
        dist[src]=0;
        inQue[src]=true;
        while(!que.empty())
        {
            int u=que.front();
            que.pop();
            for(int i=g[u];i;i=e[i].nxt)
            {
                if(e[i].f>0 && dist[u]+e[i].w<dist[e[i].v])
                {
                    dist[e[i].v]=dist[u]+e[i].w;
                    prev[e[i].v]=u;
                    pree[e[i].v]=i;
                    if(!inQue[e[i].v])
                    {
                        inQue[e[i].v]=true;
                        que.push(e[i].v);
                    }
                }
            }
            inQue[u]=false;
        }
        return dist[sink]<inf;
    }
    
    pair<int,int> augment()
    {
        int u=sink;
        int delta=inf;
        while(u!=src)
        {
            if(e[pree[u]].f<delta)delta=e[pree[u]].f;
            u=prev[u];
        }
        u=sink;
        while(u!=src)
        {
            e[pree[u]].f-=delta;
            e[pree[u]^1].f+=delta;
            u=prev[u];
        }
        return make_pair(delta,dist[sink]*delta);
    }
    
    pair<int,int> mincostflow(int s,int t)
    {
        src=s,sink=t;
        int f=0,ans=0;
        while(findPath())
        {
            auto u=augment();
            ans+=u.second;
            f+=u.first;
        }
        return make_pair(ans,f);
    }
}

string t;
int n;
string a[101];
int tms[101];
using SPFAMCF::inf;
using SPFAMCF::addedge;
using SPFAMCF::mincostflow;
int main()
{
    cin>>t>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i]>>tms[i];
    int N=n+26;
    SPFAMCF::init();
    for(char c='a';c<='z';++c)
        addedge(c-'a'+1+n,N+1,count(t.begin(),t.end(),c),0);
    for(int i=1;i<=n;++i)
    {
        addedge(0,i,tms[i],0);
        for(char c='a';c<='z';++c)
            addedge(i,n+1+(c-'a'),count(a[i].begin(),a[i].end(),c),i);
    }
    auto ans=mincostflow(0,N+1);
    cout<<(ans.second==t.length()?ans.first:-1);
}