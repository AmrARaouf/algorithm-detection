//Language: GNU C++


#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;
struct Edge
{
    int u,v,w,id,pre;
};
Edge e[MAXN];
bool cmp(const Edge &a,const Edge &b)
{
    return a.w<b.w;
}
int fa[MAXN],id[MAXN],step[MAXN];
int p[MAXN],p2[MAXN];
Edge ee[2*MAXN];
int hh[MAXN],ecnt;
int use[MAXN],anse[MAXN],w[MAXN],dp[MAXN];
int faa[MAXN][20],maxx[MAXN][20];
void addEdge(int u,int v,int id,int w)
{
    ee[ecnt].id=id;
    ee[ecnt].w=w;
    ee[ecnt].v=v;
    ee[ecnt].pre=hh[u];
    hh[u]=ecnt++;
}
void dfs(int node,int pre,int idd,int w)
{
    fa[node]=pre;
    id[node]=idd;
    faa[node][0]=pre;
    maxx[node][0]=w;
    for (int i=1; i<20; i++)
    {
        faa[node][i]=faa[faa[node][i-1]][i-1];
        maxx[node][i]=max(maxx[node][i-1],maxx[faa[node][i-1]][i-1]);
    }
    for (int i=hh[node]; i!=-1; i=ee[i].pre)
    {
        int v=ee[i].v;
        if (v==pre) continue;
        step[v]=step[node]+1;
        dfs(v,node,ee[i].id,ee[i].w);
    }
}
int getfa(int v,int *p)
{
    if (p[v]==v) return v;
    return p[v]=getfa(p[v],p);
}
int findmax(int u,int v)
{
    int ans=0;
    if (step[u]>step[v]) swap(u,v);
    int num=step[v]-step[u],cnt=0;
    while (num!=0)
    {
        if (num%2==1)
        {
            ans=max(ans,maxx[v][cnt]);
            v=faa[v][cnt];
        }
        cnt++;
        num/=2;
    }
    if (u==v) return ans;
    for (int i=19; i>=0; i--)
    {
        if (faa[u][i]!=faa[v][i])
        {
            ans=max(ans,maxx[u][i]);
            ans=max(ans,maxx[v][i]);
            u=faa[u][i];
            v=faa[v][i];
        }
    }
    ans=max(ans,maxx[u][0]);
    ans=max(ans,maxx[v][0]);
    return ans;
}
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)==2)
    {
        for (int i=0; i<m; i++)
        {
            scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
            w[i]=e[i].w;
            e[i].id=i;
        }
        sort(e,e+m,cmp);
        for (int i=1; i<=n; i++)
            p[i]=i;
        int cntt=0;
        memset(use,0,sizeof(use));
        memset(hh,-1,sizeof(hh));
        ecnt=0;
        int root;
        for (int i=0; i<m; i++)
        {
            int ra=getfa(e[i].u,p);
            int rb=getfa(e[i].v,p);
            if (ra==rb) continue;
            p[ra]=rb;
            cntt++;
            use[e[i].id]=1;
            root=e[i].u;
            addEdge(e[i].u,e[i].v,e[i].id,e[i].w);
            addEdge(e[i].v,e[i].u,e[i].id,e[i].w);
            if (cntt==n-1) break;
        }
        step[root]=0;
        dfs(root,root,-1,0);
        for (int i=0; i<20; i++)
        {
            faa[root][i]=root;
            maxx[root][i]=0;
        }
        memset(anse,0,sizeof(anse));
        for (int i=1; i<=n; i++)
            p2[i]=i;
        for (int i=0; i<m; i++)
        {
            if (use[e[i].id]) continue;
            int uu=e[i].u,vv=e[i].v,ww=e[i].w;
            int maxw=findmax(uu,vv);
            if (ww==maxw) anse[e[i].id]=1;
            int ru=getfa(uu,p2),rv=getfa(vv,p2);
            if (step[ru]<step[rv]) swap(ru,rv);
            while (step[ru]>step[rv])
            {
                p2[ru]=getfa(fa[ru],p2);
                if (w[id[ru]]==ww)
                    anse[id[ru]]=1;
                ru=p2[ru];
            }
            if (ru==rv) continue;
            while (ru!=rv)
            {
                if (step[ru]>step[rv])
                {
                    p2[ru]=getfa(fa[ru],p2);
                    if (w[id[ru]]==ww)
                        anse[id[ru]]=1;
                    ru=p2[ru];
                }
                else
                {
                    p2[rv]=getfa(fa[rv],p2);
                    if (w[id[rv]]==ww)
                        anse[id[rv]]=1;
                    rv=p2[rv];
                }
            }
        }
        for (int i=0; i<m; i++)
        {
            if (anse[i]==1) puts("at least one");
            else if (anse[i]==0&&!use[i]) puts("none");
            else puts("any");
        }
    }
    return 0;
}
