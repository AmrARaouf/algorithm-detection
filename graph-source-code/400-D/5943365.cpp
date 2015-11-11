//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
struct node
{
    int u,v,w,next;
}edge[202000],ed[202000];
int g[202000],gg[202000];
int en,ee;
int n,m,c,k,p,q;
int size[202000];
int fa[202000];
int cc[202000];

int find(int x)
{
    if (fa[x]==x) return x;
    else return fa[x]=find(fa[x]);
}

int d[600][600];

int main()
{
//    freopen("in.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&c);
    int tp=1;
    for (int i=1; i<=c; i++)
    {
        scanf("%d",&k);
        cc[i]=k;
        for (int j=0; j<k; j++,tp++)
        {
            size[tp]=i;
        }
    }
    int x,y,z;
    en=ee=0;
    for (int i=1; i<=n; i++)
    {
        fa[i]=i;
    }

    for (int i=1; i<=m; i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        edge[en].u=x;
        edge[en].v=y;
        edge[en].w=z;
        en++;
        if (z==0)
        {
            x=find(x);
            y=find(y);
            fa[y]=x;
        }
    }
    bool ok=true;
    int ff=0;
    size[0]=-1;
    for (int i=1; i<=n; i++)
    {
        if (size[i]!=size[i-1])
        {
            ff=find(i);
        }
        else
        {
            if (find(i)!=ff)
            {
                ok=false;
                break;
            }
        }
    }
    if (!ok)
    {
        puts("No");
        return 0;
    }
    puts("Yes");
    tp=1;
    for (int i=0; i<=c; i++)
     for (int j=0; j<=c; j++)
     d[i][j]=(1<<29);

    for (int i=0; i<=c; i++)
    d[i][i]=0;

    for (int i=0; i<m; i++)
    {
        int u=edge[i].u;
        int v=edge[i].v;
        if (size[u]!=size[v])
        {
            d[size[u]][size[v]]=min(d[size[u]][size[v]],edge[i].w);
            d[size[v]][size[u]]=d[size[u]][size[v]];
        }

    }

    for (int k=1; k<=c; k++)
     for (int i=1; i<=c; i++)
     if (i!=k)
      for (int j=1; j<=c; j++)
       if (j!=i && j!=k)
           d[i][j]=min(d[i][j],d[i][k]+d[k][j]);

    for (int i=1; i<=c; i++)
    {
        for (int j=1; j<=c; j++)
        if (d[i][j]<(1<<29))
        cout<<d[i][j]<<" ";
        else cout<<"-1 ";
        cout<<endl;
    }

    return 0;
}
