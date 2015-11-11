//Language: GNU C++


#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
#define pii pair<ll,int>
#define inf (1ll<<60)
#define ll long long
using namespace std;
const int maxn=100005;
int n,m,s,t;
int a,b,l;
struct Edge
{
    int from,to;
    int w;
    int next;
}edges[maxn*2];
struct Point
{
    ll w;
    int id;
    Point(ll a,int b):w(a),id(b){}
    bool operator<(const Point& u) const
    {
        return w>u.w;
    }
};
int ne;
int head[maxn];
ll ds[maxn];
ll dt[maxn];
bool vis[maxn];
int ans[maxn];
int cost[maxn];
void addEdge(int from,int to,int w)
{
    edges[ne].from=from;
    edges[ne].to=to;
    edges[ne].w=w;
    edges[ne].next=head[from];
    head[from]=ne++;
}
void Dij(int s,ll* d,int flag)
{
    //cout<<s<<endl;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)
        d[i]=inf;
    d[s]=0;
   // vis[s]=1;
    priority_queue<Point>que;
    que.push(Point(0,s));
    while(!que.empty()) {
        Point u=que.top();
        que.pop();
        if(d[u.id]<u.w) {
            continue;
        }
        for(int i=head[u.id];i!=-1;i=edges[i].next) {
            if((flag==0&&(i&1))||(flag==1&&i%2==0))
                continue;
            if( d[edges[i].to]>u.w+edges[i].w) {
                d[edges[i].to]=u.w+edges[i].w;
            //    vis[edges[i].to]=1;
                que.push(Point(d[edges[i].to],edges[i].to));
            }
        }
    }
}
Edge E[maxn*2];
int h[maxn];
int c=0;
int dfs_clock;
int dfn[maxn];
int low[maxn];
bool Vis[maxn*2];
void add(int from,int to,int id)
{
    E[c].from=from;
    E[c].to=to;
    E[c].w=id;
    E[c].next=h[from];
    h[from]=c++;

    E[c].from=to;
    E[c].to=from;
    E[c].w=id;
    E[c].next=h[to];
    h[to]=c++;
}
void build()
{
    memset(h,-1,sizeof(h));
    for(int i=0,j=0;i<ne;i+=2,j++) {
        if(ds[edges[i].from]+edges[i].w+dt[edges[i].to]==ds[t]) {
            add(edges[i].from,edges[i].to,j);
        }
    }
}
void dfs(int u)
{
    dfn[u]=low[u]=++dfs_clock;
    for(int i=h[u];i!=-1;i=E[i].next) {
        int v=E[i].to;
        if(!dfn[v]) {
            Vis[i]=Vis[i^1]=true;
            dfs(v);
            low[u]=min(low[v],low[u]);
            if(low[v]>dfn[u]) {
                ans[E[i].w]=1;
            }
        }
        else if(dfn[v]<dfn[u] && !Vis[i]) {
            Vis[i]=Vis[i^1]=1;
            low[u]=min(low[u],dfn[v]);
        }
    }
}
void findBridge()
{
    dfs_clock=0;
    memset(dfn,0,sizeof(dfn));
    memset(Vis,0,sizeof(Vis));
    for(int i=1;i<=n;i++) {
        if(!dfn[i])
            dfs(i);
    }
}
int main()
{
    memset(ans,-1,sizeof(ans));
    ne=0;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    memset(head,-1,sizeof(head));
    for(int i=0;i<m;i++) {
        scanf("%d%d%d",&a,&b,&l);
        addEdge(a,b,l);
        addEdge(b,a,l);
    }
    Dij(s,ds,0);
    Dij(t,dt,1);
   // cout<<ds[t]<<" "<<dt[s]<<endl;
    build();
    findBridge();
  //  for(int i=0;i<m;i++)
  //      cout<<ans[i]<<" ";
   // cout<<endl;
    for(int i=0,j=0;i<ne;i+=2,j++) {
        if(ans[j]==-1) {
            //cout<<edges[i].from<<" "<<edges[i].to<<endl;
            ll op=ds[t]-1-(ds[edges[i].from]+dt[edges[i].to]);
            //cout<<op<<endl;
            if(op>0) {
                ans[j]=0;
                cost[j]=edges[i].w-op;
                //cout<<cost[i]<<endl;
            }
        }
    }
    for(int i=0;i<m;i++) {
        if(ans[i]==1) {
            printf("YES\n");
        }
        else if(ans[i]==-1) {
            printf("NO\n");
        }
        else {
            printf("CAN %d\n",cost[i]);
        }
    }
    return 0;
}



















