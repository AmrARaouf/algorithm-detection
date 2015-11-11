//Language: GNU C++


#include <cstdio>
#include <cstring>

int set[2200],n,m,u,v,c,i,j;

int find(int x)
{
    if(x==set[x])return x;
    else return set[x]=find(set[x]);
}

void add(int a,int b)
{
    set[find(a)]=find(b);
}

int main()
{
    for(i=0;i<220;i++)
        set[i]=i;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&u,&v,&c);
        if(c==0)
        {
            add(u,v+n);
            add(v,u+n);
        }
        else
        {
            add(u,v);
            add(v+n,u+n);
        }
    }
    for(i=1;i<=n;i++)
    {
        if(find(i)==find(i+n))break;
    }
    if(i<=n)
    {
        puts("Impossible");
        return 0;
    }
    bool vis[120];
    int ans[120],x;
    m=0;
    memset(vis,0,sizeof(vis));
    for(i=1;i<=n;i++)
    {
        if(vis[i])continue;
        x=find(i);
        vis[i]=0;
        for(j=1;j<=n;j++)
        {
            if(vis[j])continue;
            if(find(j)==x)vis[j]=1;
            else if(find(j+n)==x)
            {
                vis[j]=1;
                ans[m++]=j;
            }
        }
    }
    printf("%d\n",m);
    for(i=0;i<m;i++)
        printf("%d ",ans[i]);
    return 0;
}
