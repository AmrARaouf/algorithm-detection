//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MN 2005

int n,a[MN][MN];
int head[MN],there[MN*MN],nx[MN*MN],tot;
inline void addedge(int x,int y)
{
    ++tot; there[tot]=y; nx[tot]=head[x]; head[x]=tot;
}

int dfn[MN],low[MN],ind,in[MN],st[MN],top,scc;
void tarjan(int x)
{
    dfn[x]=low[x]=++ind; st[++top]=x; in[x]=1;
    for(int i=head[x];i;i=nx[i])
    {
        int v=there[i];
        if(!dfn[v])
        {
            tarjan(v); low[x]=min(low[x],low[v]);
        }
        else if(in[v]) low[x]=min(low[x],dfn[v]);
    }
    if(dfn[x]==low[x])
    {
        ++scc;
        int j;
        do
        {
            j=st[top--]; in[j]=0;

        }while(j!=x);
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j)
    {
        scanf("%d",&a[i][j]);
        if(a[i][j]>0 && i!=j) addedge(i,j);
    }
    for(int i=1;i<=n;++i)
    if(!dfn[i])
    tarjan(i);
    if(scc!=1)
    {
        cout<<"NO"<<endl; return 0;
    }
    
    cout<<"YES"<<endl; return 0;

    return 0;
}