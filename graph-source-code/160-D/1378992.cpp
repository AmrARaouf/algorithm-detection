//Language: GNU C++


#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn=2*100010;
const int Bei=18;
struct ppp{
    int u,v,w,id;
    ppp(){}
    ppp(int u,int id):u(u),id(id){}
} a[maxn];

struct edge{
    int from,to,w,next,id;
} e[maxn];

int fa[maxn];
int flag[maxn];
int cnt,box[maxn];
int nodefa[maxn];
vector <ppp> qu[maxn];
int lca[maxn];
int dep[maxn];
int ffa[maxn][Bei+1],dp[maxn][Bei+1];

void adds(int u,int v,int w,int id)
{
    e[cnt].from=u;
    e[cnt].to=v;e[cnt].w=w;e[cnt].id=id;
    e[cnt].next=box[u];box[u]=cnt++;
}

void add(struct ppp x)
{
   // printf("add %d %d %d %d\n",x.u,x.v,x.w,x.id);
    adds(x.u,x.v,x.w,x.id);
    adds(x.v,x.u,x.w,x.id);
}

bool cmp(const ppp &u,const ppp &v){
    return u.w<v.w;
}

int find_fa(int u)
{
    if (fa[u]!=u) fa[u]=find_fa(fa[u]);
    return fa[u];
}

void dfs(int u,int fas,int deps,int w)
{
    if (fas==-1)
    {
        for(int i=0;i<=Bei;i++)
        {
            ffa[u][i]=u;
            dp[u][i]=0;
        }
        //ans[u]=0;
    } else
    {
        ffa[u][0]=fas;
        dp[u][0]=w;
        for(int i=1;i<=Bei;i++)
        {
            ffa[u][i]=ffa[ ffa[u][i-1] ][i-1];
            dp[u][i]=max(dp[u][i-1],dp[ ffa[u][i-1] ][i-1]);
        }
        //ans[u]=ans[fas]+w;
    }
    fa[u]=u;
    dep[u]=deps;
    for(int p=box[u];p!=-1;p=e[p].next)
     if (e[p].to!=fas)
     {
         dfs(e[p].to,u,deps+1,e[p].w);
         fa[ e[p].to ]=u;
         nodefa[ e[p].to ]=p;
     }
    int len=qu[u].size();
    for(int i=0;i<len;i++)
     if (fa[ qu[u][i].u ]!=-1)
        lca[ qu[u][i].id ]=find_fa( qu[u][i].u );
}

int lcas(int u,int v)
{
    int t=dep[u]-dep[v];
    int *x=&u;
    if  (dep[u]<dep[v])
    {
        t=dep[v]-dep[u];
        x=&v;
    }
    int k=0;
    int ans=0;
    while(t)
    {
        if (t&1)
        {
           // printf("ans=%d *x=%d k=%d dp=%d\n",ans,*x,k,dp[*x][k]);
            ans=max(ans,dp[*x][k]);
            *x=ffa[*x][k];
        }
        t>>=1;
        k++;
    }
   // printf("u=%d v=%d ans=%d\n",u,v,ans);
    if (u==v) return ans;
    for(int i=Bei;i>=0;i--)
     if (ffa[u][i]!=ffa[v][i])
     {
         //printf("(%d %d)\n",dp[u][i],dp[v][i]);
         ans=max(ans,dp[u][i]);
         ans=max(ans,dp[v][i]);
         u=ffa[u][i];
         v=ffa[v][i];
     }
    ans=max(ans,dp[u][0]);
    ans=max(ans,dp[v][0]);
    return ans;
}

void work(int u,int w,int end)
{
   // bool ans=0;

    while(1)
    {
        u=find_fa(u);
        if (dep[u]<=dep[end]) break;
        if (e[nodefa[u]].w==w)
        {
            lca[ e[nodefa[u]].id ]=-2;
            //ans=1;
        }
        fa[u]=find_fa(e[nodefa[u]].from);
    }
    //return ans;
}


int main()
{
    int n,m;

    //freopen("in.in","r",stdin);
    while(scanf("%d %d",&n,&m)==2)
    {
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&a[i].u,&a[i].v,&a[i].w);
            a[i].id=i;
        }
        sort(a,a+m,cmp);
        cnt=0;
        memset(box,-1,sizeof(box));
        for(int i=1;i<=n;i++)
        {
            fa[i]=i;
            qu[i].clear();
        }
        for(int i=0;i<m;i++)
        {
            int t1=find_fa(a[i].u);
            int t2=find_fa(a[i].v);
            if (t1!=t2)
            {
                fa[t1]=t2;
                add(a[i]);
            } else
            {
                qu[a[i].u].push_back( ppp(a[i].v,a[i].id) );
                qu[a[i].v].push_back( ppp(a[i].u,a[i].id) );
            }
        }
        memset(fa,-1,sizeof(fa));
        memset(lca,-1,sizeof(lca));
        memset(nodefa,0,sizeof(nodefa));
        dfs(1,-1,0,0);
        for(int i=1;i<=n;i++) fa[i]=i;
       // for(int i=0;i<m;i++) printf("%d ",lca[i]);puts("");
        for(int i=0;i<m;i++)
         if (lca[a[i].id]>0)
         {
             int t=lca[a[i].id];
             work(a[i].u,a[i].w,t);
             work(a[i].v,a[i].w,t);
             //printf("max=%d\n",lcas(a[i].u,a[i].v));
             if (lcas(a[i].u,a[i].v)==a[i].w) lca[a[i].id]=-2;
         }
        for(int i=0;i<m;i++)
         if (lca[i]==-1) puts("any"); else
         if (lca[i]==-2) puts("at least one");
         else puts("none");
    }
    return 0;
}
