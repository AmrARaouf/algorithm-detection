//Language: GNU C++


#include<stdio.h>
int a[10000010];
int main(){
    int i,j,n,m,x,y;
    __int64 sum,tot;
    scanf("%d%d",&n,&m);
    tot=(__int64)n*(n-1)*(n-2)/6;
    for(i=0;i<m;i++){
        scanf("%d%d",&x,&y);
        a[x]++;
        a[y]++;
    }
    sum=0;
    for(i=1;i<=n;i++)
        sum+=(__int64)a[i]*(n-1-a[i]);
    printf("%I64d\n",tot-sum/2);
    return 0;
}
