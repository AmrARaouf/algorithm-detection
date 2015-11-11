//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX = 1e5+10;
const int inf = 0x3f3f3f3f;



int dist[510][510],fa[MAX],check[MAX];
int c[MAX],sum[MAX];
void make(int n)
{
    for(int i=1;i<=n;i++) fa[i]=i;
}
int find(int x)
{
    if(fa[x]!=x)
    fa[x]=find(fa[x]);
    return fa[x];
}
void Union(int a,int b)
{
    int x=find(a),y=find(b);
    if(x!=y) fa[x]=y;
}
int main()
{
    int n,m,k,flag;
    int u,v,x;
    while(scanf("%d %d %d",&n,&m,&k)==3)
    {
        memset(sum,0,sizeof(sum));
        memset(check,0,sizeof(check));
        make(n);
        for(int i=0;i<=k;i++) for(int j=0;j<=k;j++)
        dist[i][j]=inf;
        for(int i=1;i<=k;i++) scanf("%d",&c[i]);
        for(int i=1;i<=k;i++) sum[i]=sum[i-1]+c[i];
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&u,&v,&x);
            int uu=lower_bound(sum+1,sum+k+1,u)-sum;
            int vv=lower_bound(sum+1,sum+k+1,v)-sum;
            dist[uu][vv]=dist[vv][uu]=min(dist[uu][vv],x);
            if(x==0) Union(u,v);
        }
        flag=1;
        for(int i=1;i<=n;i++)
        {
            int pos=lower_bound(sum+1,sum+k+1,i)-sum;
            int u=find(i);
            if(check[pos]&&u!=check[pos])
            {
                flag=0;
                break;
            }
            else check[pos]=u;
        }
        if(flag)
        {
            for(int i=1;i<=k;i++) dist[i][i]=0;
            for(int m=1;m<=k;m++)
            for(int i=1;i<=k;i++)
            for(int j=1;j<=k;j++)
            dist[i][j]=min(dist[i][m]+dist[m][j],dist[i][j]);
            printf("Yes\n");
            for(int i=1;i<=k;i++)
            {
                for(int j=1;j<=k;j++)
                {
                    if(dist[i][j]==inf) dist[i][j]=-1;
                    if(j==1) printf("%d",dist[i][j]);
                    else printf(" %d",dist[i][j]);
                }
                printf("\n");
            }
        }
        else printf("No\n");
    }
    return 0;
}
