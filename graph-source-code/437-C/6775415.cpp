//Language: GNU C++


#include <stdio.h>
#include <conio.h>
int main(){
    int n,m,a[1000],H[1000],Adj[2000*10],pointX[1000],pointY[1000];
    int u,v,sum=0;
    scanf("%d%d",&n,&m);
    for (int i=1; i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d",&u,&v);
        if (a[u]>a[v]) sum+=a[v]; else sum+=a[u];
    }

    printf("%d",sum);
}
