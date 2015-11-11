//Language: GNU C++


#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>

using namespace std;

int s[510];
long long  d[510][510];
long long ans[510];
int n;

int main(){
    while(scanf("%d",&n)==1)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) scanf("%I64d",&d[i][j]);
        for(int i=1;i<=n;i++)
            scanf("%d",&s[i]);
        memset(ans,0,sizeof(ans));
        for(int i=n;i>=1;i--)
            for(int j=n;j>=1;j--)
                for(int k=n;k>=1;k--)
                {
                    int u,v,t;
                    u=s[i];  v=s[j];  t=s[k];
                    d[v][t]=min(d[v][t],d[v][u]+d[u][t]);
                    if(j>=i&&k>=i) ans[i]+=d[v][t];
                }
        for(int i=1;i<n;i++)
            printf("%I64d ",ans[i]);
        printf("%I64d\n",ans[n]);
    }
    return 0;
}
