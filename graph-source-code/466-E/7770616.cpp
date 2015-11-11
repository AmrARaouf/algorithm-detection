//Language: GNU C++


#include<cstdio>
#include<cmath>
#define N 500000
int pre[N],p[N],tt[N],d[N],fa[N],r[N],s[N][20],a[N],b[N],typ[N],l[N],h[N],root[N],f[N];
int dp,ti,n,m,i,sum,j,w;
int newmin(int a,int b)
{
    if (d[a]<d[b]) return a;return b;
}
int lca(int a,int b)
{
    int t;
    a=r[a];
    b=r[b];
    if (a>b)
    {
        t=a;a=b;b=t;
    }
    t=log(b-a+1)/log(2);
    return newmin(s[a][t],s[b-(1<<t)+1][t]);
}
int gf(int x)
{
    int p,t;
    p=x;
    while (p!=fa[p]) p=fa[p];
    while (x!=p)
    {
        t=fa[x];
        fa[x]=p;
        x=t;
    }
    return p;
}
int gff(int x)
{
    int p,t;
    p=x;
    while (p!=f[p]) p=f[p];
    while (x!=p)
    {
        t=f[x];
        f[x]=p;
        x=t;
    }
    return p;
}
void link(int x,int y)
{
    dp++;pre[dp]=p[x];p[x]=dp;tt[dp]=y;
}
void dfs(int x,int deep)
{
    int i;
    i=p[x];
    ti++;
    r[x]=ti;
    s[ti][0]=x;
    d[x]=deep;
    while (i)
    {
        dfs(tt[i],deep+1);
        ti++;
        s[ti][0]=x;
        i=pre[i];
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++)
    {
    f[i]=i;
    fa[i]=i;
    }
    
    for (i=1;i<=m;i++)
    {
        scanf("%d",&typ[i]);
        if (typ[i]!=2)
        {
            scanf("%d%d",&a[i],&b[i]);
            if (typ[i]==1)
            {
            root[a[i]]=1;
            f[gff(a[i])]=gff(b[i]);
            link(b[i],a[i]);
            }
        }
        else
            scanf("%d",&a[i]);
    }

    for (i=1;i<=n;i++)
    if (root[i]==0)
    dfs(i,0);
    
    for (i=ti;i>=1;i--)
    for (j=1;j<=log(ti)/log(2);j++)
    if (i+(1<<j)-1<=ti)
    s[i][j]=newmin(s[i][j-1],s[i+(1<<(j-1))][j-1]);
    
    
    for (i=1;i<=m;i++)
    {
        if (typ[i]==1)
            fa[gf(a[i])]=gf(b[i]);
        else
        if (typ[i]==2)
        {
            sum++;h[sum]=gf(a[i]);l[sum]=a[i];
        }
        else
        {
            if (gff(a[i])==gff(l[b[i]]))
            {
            w=lca(l[b[i]],a[i]);
            if ((w==a[i])&&(d[w]>=d[h[b[i]]]))
            printf("YES\n");
            else
            printf("NO\n");
           }
           else
           printf("NO\n");
        }
    }
}