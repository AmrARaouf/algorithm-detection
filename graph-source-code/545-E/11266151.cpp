//Language: GNU C++


#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
#define X first
#define Y second

const int N = 3e5+100;
const int M = 2*N;
int head[N];
typedef long long ll;
struct Edge
{
    int v,w,nxt;
    int id;
}es[M];

int n,m,cnt;
void inline add_edge(int u,int v,int w,int id)
{
    es[++cnt].v=v;
    es[cnt].w=w;
    es[cnt].nxt=head[u];
    es[cnt].id=cnt;
    head[u]=cnt;
    es[cnt+m].v=u;
    es[cnt+m].w=w;
    es[cnt+m].id=cnt+m;
    es[cnt+m].nxt=head[v];
    head[v]=cnt+m;
}
ll dis[N];
queue<int>q;
bool vis[N];
void spfa(int s)
{
    for(int i=1;i<=n;i++) dis[i]=(ll)1<<60,vis[i]=0;
    dis[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front(); q.pop();
        vis[u]=0;
        for(int i=head[u];~i;i=es[i].nxt)
        {
            int v=es[i].v,w=es[i].w;
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                if(vis[v]==0) vis[v]=1,q.push(v);
            }

        }
    }
}
typedef pair<ll,int> pii;
priority_queue<pii,vector<pii>,greater<pii> >que;
bool book[N];
int ans[N],top;
int main()
{
    memset(head,-1,sizeof(head));
    cin>>n>>m;
    int u,v,w;
    for(int i=1;i<=m;i++) scanf("%d%d%d",&u,&v,&w),add_edge(u,v,w,i);
    int s;
    cin>>s;
    spfa(s);
    ll res=0;
    for(int u=1;u<=n;u++)
    {
        ll p,minn=(ll)1<<60;
        for(int i=head[u];~i;i=es[i].nxt)
        {
            v=es[i].v,w=es[i].w;
            if(dis[u]==dis[v]+w&&minn>w) minn=w,p=es[i].id;
        }
        if(minn!=(ll)1<<60) res+=minn,ans[++top]=p;
    }
    cout<<res<<endl;
    for(int i=1;i<=top;i++) printf("%d ",(ans[i]-1)%m+1);
}


/*



*/
