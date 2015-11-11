//Language: MS C++


#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int inf=200009;
int bo[inf];
int eo[inf];
int be[inf];
int ee[inf];
int lev[inf];
int ce=0,co=0;
pair<int,int>sgt[inf*4];
int num[inf];
int idx[inf];
vector<int>adj[inf];
void dfs(int x,int p,int l)
{
    lev[x]=l;
    be[x]=ce;
    bo[x]=co;
    idx[x]=l%2?co++:ce++;
    for (int i=0; i<(int)adj[x].size(); ++i)
        if (adj[x][i]!=p)
            dfs(adj[x][i],x,l+1);
    ee[x]=ce-1;
    eo[x]=co-1;
}
#define le x+x
#define ri x+x+1
#define mid (l+r)/2
int s,e,v;
bool t;
void update(int x,int l,int r)
{
    if (s<=l && e>=r)
    {
        if (t)
            sgt[x].first+=v;
        else
            sgt[x].second+=v;
        return;
    }
    if (mid>=s)
        update(le,l,mid);
    if (mid+1<=e)
        update(ri,mid+1,r);
}
int get(int x,int l,int r)
{
    if (l==r)
        return t?sgt[x].first:sgt[x].second;
    if (mid>=s)
        return (t?sgt[x].first:sgt[x].second)+get(le,l,mid);
    return (t?sgt[x].first:sgt[x].second)+get(ri,mid+1,r);
}
int main()
{
    int n,m,a,b;
    scanf("%d%d",&n,&m);
    for (int i=1; i<=n; ++i)
        scanf("%d",&num[i]);
    for (int i=0; i<n-1; ++i)
    {
        scanf("%d%d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,1,0);
    while(m--)
    {
        scanf("%d",&a);
        if (a==1)
        {
            scanf("%d%d",&a,&b);
            s=bo[a],e=eo[a],t=true,v=lev[a]%2?b:-b;
            if (s<=e)
                update(1,0,n-1);
            s=be[a],e=ee[a],t=false,v=lev[a]%2?-b:b;
            if (s<=e)
                update(1,0,n-1);
        }
        else
        {
            scanf("%d",&a);
            t=lev[a]%2;
            s=idx[a];
            printf("%d\n",num[a]+get(1,0,n-1));
        }
    }
}
