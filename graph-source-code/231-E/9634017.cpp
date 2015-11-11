//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;

const int N=100010, mod=1000000007, LOG=20;
int n, m, a, b, k, t, two[N], id[N], val[N], cyc_sz[N], par[N];
int T[N], P[N][LOG], L[N];
vector<int>adj[N], adj2[N];
bool vis[N], InMyWay[N];

void In()
{
   scanf("%d %d",&n,&m);
   for(int i=0;i<m;i++)
   {
       scanf("%d %d",&a,&b);
       a--, b--;
       adj[a].push_back(b), adj[b].push_back(a);
   }
}

void Power()
{
    two[0]=1;
    for(int i=1;i<=n;i++)
      two[i]=two[i-1]*2, two[i]%=mod;
}

void Add_Cycle(int start, int num)
{
    id[start]=t, cyc_sz[t]++;
    while(par[--num]!=start)
    {
        id[par[num]]=t, cyc_sz[t]++;
    }
    t++;
}

void Go(int node, int prv)
{
    if(InMyWay[node])
    {
        Add_Cycle(node, prv);
        return;
    }
    if(vis[node])
        return;
    vis[node]=1, InMyWay[node]=1;
    par[prv]=node;
    for(int i=0;i<adj[node].size();i++)
    {
        int to=adj[node][i];
        if(prv!=0 && par[prv-1]==to)
            continue;
        Go(to, prv+1);
    }
    if(id[node]==-1)
        Add_Cycle(node, prv+1);
    InMyWay[node]=0;
}

void Detect_Cycles()
{
    memset(id,-1,sizeof id);
    for(int i=0;i<n;i++)
        if(!vis[i])
            Go(i,0);
}

void Make_New_Graph()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            int from=id[i], to=id[adj[i][j]];
            if(from!=to)///they aren't from the same cycle
                adj2[from].push_back(to);
        }
    }
}

void DFS(int node, int prv, int depth)
{
    T[node]=prv, L[node]=depth;
    if(prv!=-1)
        val[node]+=val[prv];
    val[node]+=(cyc_sz[node]>1);
    for(int i=0;i<adj2[node].size();i++)
    {
        int to=adj2[node][i];
        if(to!=prv)
            DFS(to, node, depth+1);
    }
}


void Prepare_LCA()
{
    memset(P,-1,sizeof P);
    DFS(0,-1,0);
    for (int i=0;i<t;i++)
          P[i][0]=T[i];
    for (int j=1;(1<<j)<t;j++)
        for (int i=0;i<t;i++)
            if (P[i][j-1]!=-1)
                P[i][j]=P[P[i][j-1]][j-1];
}

int LCA(int p, int q)
{
    int tmp, log, i;
    if(L[p]<L[q])
        swap(p,q);
    for(log=1;(1<<log)<=L[p];log++);
        log--;
    for(i=log;i>=0;i--)
        if (L[p]-(1<<i)>=L[q])
            p=P[p][i];
    if(p==q)
        return p;
    for(i=log;i>=0;i--)
        if (P[p][i]!=-1 && P[p][i]!=P[q][i])
            p=P[p][i], q=P[q][i];
    return T[p];
}

void Out()
{
   scanf("%d",&k);
   for(int i=0;i<k;i++)
   {
       scanf("%d %d",&a,&b);
       a--, b--;
       a=id[a], b=id[b];
       int lca=LCA(a,b);
       int p=val[a]+val[b]-(2*val[lca])+(cyc_sz[lca]>1);
       printf("%d\n",two[p]);
   }
}

int main()
{
   //freopen("r.txt","r",stdin);
   In();
   Power();
   Detect_Cycles();
   Make_New_Graph();
   Prepare_LCA();
   Out();

    return 0;
}