//Language: GNU C++


#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

struct edge{int s,t,n;}e[100010];
struct query{int o,x,y;}a[100010];
int n,m,h[100010],deep[100010],r[100010],p[100010],q[100010],bz[100010][20],f[100010][20];
queue <int> Q;

void prepare()
{
    int i,x,y;
    for (i=1; i<=m; i++)
        if (a[i].o==1)
            {
                bz[a[i].x][0]=a[i].y,f[a[i].x][0]=i;
                e[i]=(edge){a[i].y,a[i].x,h[a[i].y]},h[a[i].y]=i;
            }
    for (i=1; i<=n; i++)
        if (!bz[i][0])  deep[i]=1,r[i]=i,Q.push(i);
    while (!Q.empty())
        for (i=h[x=Q.front()],Q.pop(); y=e[i].t,i; i=e[i].n)
            deep[y]=deep[x]+1,r[y]=r[x],Q.push(y);
    for (int j=1; j<20; j++)
        for (int i=1; i<=n; i++)
            bz[i][j]=bz[bz[i][j-1]][j-1],f[i][j]=max(f[i][j-1],f[bz[i][j-1]][j-1]);
}

int query(int x,int y)
{
    if (deep[x]>deep[y])  return -1;
    int res=0;
    for (int i=19; i>=0; i--)
        if (deep[bz[y][i]]>=deep[x])
            res=max(res,f[y][i]),y=bz[y][i];
    if (x==y)  return res;  else  return -1;
}

void work()
{
    scanf("%d %d",&n,&m);
    for (int i=1; i<=m; i++)
        {
            scanf("%d",&a[i].o);
            if (a[i].o==2)  scanf("%d",&a[i].x);
            else  scanf("%d %d",&a[i].x,&a[i].y);
        }
    prepare();
    for (int i=1,cnt=0,t; i<=m; i++)
        if (a[i].o==2)  p[++cnt]=a[i].x,q[cnt]=i;
        else  if (a[i].o==3)
            {
                t=query(a[i].x,p[a[i].y]);
                if ((0<=t)&&(t<q[a[i].y]))  printf("YES\n");
                else  printf("NO\n");
            }
}

int main()
{
    work();
    return 0;
} 
