//Language: GNU C++


#include<cstdio>
#include<iostream>
#include<algorithm>
#include<memory.h>
#include<cstring>
#define inf 0x3fffffff
using namespace std;
int k,n,m,i,j;
int main()
{
    scanf("%d",&k);
    if (k%2==0){printf("NO\n");return 0;}
    if (k==1)
    {
        printf("YES\n2 1\n1 2");
        return 0;
    }
    printf("YES\n%d %d\n",2*k+4,k*(k+2));
    int t=k+2;
    for (i=1;i<k;i++) printf("%d %d\n%d %d\n",i,k+2,i+t,k+2+t);
    for (i=1;i<k;i++) printf("%d %d\n%d %d\n",k,i,k+t,i+t);
    for (i=1;i<k;i++) printf("%d %d\n%d %d\n",k+1,i,k+t+1,i+t);
    printf("%d %d\n%d %d\n",k,k+1,k+t,k+t+1);
    for (i=1;i<k;i++)
        for (j=i+1;j<=k-1;j++)
            if (i+j!=k)printf("%d %d\n%d %d\n",i,j,i+t,j+t);
    printf("%d %d\n",k+2,k+2+t);
}