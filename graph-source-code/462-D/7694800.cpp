//Language: GNU C++


#include<cstdio>
#include<algorithm>
#define N 1001000
#define P 1000000007
using namespace std;
int dp,n,a,i,top;
long long f[N][2],z[N];
int stack[N],p[N],tt[N],pre[N],color[N];
void link(int x,int y)
{
    dp++;pre[dp]=p[x];p[x]=dp;tt[dp]=y;
}
void dfs(int x,int fa)
{
    int i;
    
    i=p[x];
    if (color[x]==1)
    {
        f[x][0]=0;
        f[x][1]=1;
    }
    else 
    {
        f[x][0]=1;
        f[x][1]=0;
    }
    while (i)
    {
        if (tt[i]!=fa)
            dfs(tt[i],x);
        i=pre[i];
    }
    
    top=0;
    i=p[x];
    while (i)
    {
            if (tt[i]!=fa)
            {
            top++;stack[top]=tt[i];
            }
            i=pre[i];
    } 
    z[top+1]=1;
    for (i=top;i>=1;i--)
    z[i]=z[i+1]*(f[stack[i]][0]+f[stack[i]][1])%P;
    

    
        top=0;
        i=p[x];
        while (i)
        {
            if (tt[i]!=fa)
            {
            top++;
            if (color[x]==1)
            f[x][1]=f[x][1]*(f[tt[i]][0]+f[tt[i]][1])%P;
            else
            {
            f[x][1]=(f[x][1]+((f[x][0]*f[tt[i]][1])%P)*z[top+1])%P;
            f[x][0]=f[x][0]*(f[tt[i]][0]+f[tt[i]][1])%P;
            }
            }
            i=pre[i];
        } 
    
}
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n-1;i++)
    {
        scanf("%d",&a);
        a++;
        link(i+1,a);
        link(a,i+1);
    } 
    for (i=1;i<=n;i++)
        scanf("%d",&color[i]);
    dfs(1,0);
    printf("%I64d",f[1][1]);
} 