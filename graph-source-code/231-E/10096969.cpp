//Language: GNU C++0x


#include<cstdio>
#include<algorithm>
#include<vector>
typedef long long ll;
using namespace std;
int N,M;
const int maxn =1e5+7;
const ll mod =1e9+7;
vector<int >p[maxn];
vector<int>g[maxn];
int dfn[maxn],low[maxn],dindex,cover[maxn],bcnt,st[maxn],stp,circle[maxn],L[maxn],fa[maxn],anc[maxn][30], val[maxn][30],n,Q;
ll two[maxn];
void tarjan(int u,int fa)
{
    dfn[u]=low[u]=++dindex;
    st[stp++]=u;
    for(int i=0; i<p[u].size(); i++)
    {
        int v=p[u][i];
        if(v==fa)continue;
        if(dfn[v]==0)
        {
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
        }
        else  low[u]=min(dfn[v],low[u]);
    }
    if(dfn[u]==low[u])
    {
        int v;
        int cir=0;
        do
        {
            cir++;
            if(cir>=2)circle[bcnt]=1;
            v=st[--stp];
            cover[v]=bcnt;
        }
        while(v!=u);
        bcnt++;
    }
}
void dfs(int u,int father,int depth)
{
    L[u]=depth;
    fa[u]=father;
    for(int i=0; i<g[u].size(); i++)
    {
        int v=g[u][i];
        if(father!=v)
        {
            dfs(v,u,depth+1);
        }
    }
}
void pre_lca()
{
    for(int i=0; i<n; i++)
    {
        anc[i][0]=fa[i];
        val[i][0]=circle[fa[i]];
        for(int j=1; (1<<j)<n; j++)anc[i][j]=-1,val[i][j]=0;
    }
    for(int j=1; (1<<j)<n; j++)
    {
        for(int i=0; i<n; i++)
        {
            if(anc[i][j-1]!=-1)
            {
                int a=anc[i][j-1];
                anc[i][j]=anc[a][j-1];
                val[i][j]=val[i][j-1]+val[a][j-1];
            }
        }
    }
}
int do_lca(int u,int v)
{
    int re=circle[u]+circle[v];
    if(L[u]<L[v])swap(u,v);
    int log;
    for(log=1; (1<<log)<=L[u]; log++);
    log--;
    for(int i=log; i>=0; i--)
    {
        if(L[u]-(1<<i)>=L[v])
        {
            re+=val[u][i];
            u=anc[u][i];
        }
    }
    if(u==v)return re-circle[u];
    for(int i=log; i>=0; i--)
    {
        if(anc[u][i]>=0&&anc[u][i]!=anc[v][i])
        {
            re+=val[u][i];
            re+=val[v][i];
            u=anc[u][i];
            v=anc[v][i];
        }
    }
    return re+circle[fa[u]];
}
int main()
{
    two[0]=1;
    for(int i=1; i<maxn; i++)two[i]=(two[i-1]*2)%mod;
    scanf("%d %d",&N,&M);
    for(int i=1; i<=M; i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        p[u].push_back(v);
        p[v].push_back(u);
    }
    for(int i=1; i<=N; i++)if(!dfn[i])tarjan(i,-1);
    n=bcnt;
    for(int i=1; i<=N; i++)
        for(int j=0; j<p[i].size(); j++)
            if(cover[p[i][j]]!=cover[i])
                g[cover[i]].push_back(cover[p[i][j]]);
    dfs(0,-1,0);
    pre_lca();
    scanf("%d",&Q);
    while(Q--)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        u=cover[u];
        v=cover[v];
        printf("%I64d\n",two[do_lca(u,v)]);
    }
    return 0;
}

		  		 				   	 	  					 	 				