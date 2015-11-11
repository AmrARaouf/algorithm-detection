//Language: GNU C++


/*
    Edges = (summation degree[i])/2
    Now if we remove a bridge,
    Edges = (k - 1 + (x - 1) * k)/2 = (k * x - 1)/2
    if k = even -> Edges can never be integer.
       k = odd -> Edges can be integer if x is also odd. Next odd is k+2
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    scanf("%d",&k);
    if(k%2==0)
    {
        printf("NO\n");
        return 0;
    }
    if(k==1)
    {
        printf("YES\n2 1\n1 2");
        return 0;
    }
    int nodes=2*(k+2);
    int edges=1+(k*(k+2)-1);
    printf("YES\n");
    printf("%d %d\n",nodes,edges);
    for(int i=2;i<=k;i++)
    {
        printf("1 %d\n",i);
        printf("%d %d\n",k+3,k+2+i);
    }
    printf("1 %d\n",k+3);
    for(int i=2;i<=k;i++)
    {
        for(int j=i+2-(i%2);j<=k;j++)
        {
            printf("%d %d\n",i,j);
            printf("%d %d\n",i+k+2,k+2+j);
        }
    }
    for(int i=2;i<=k;i++)
    {
        printf("%d %d\n",i,k+1);
        printf("%d %d\n",i,k+2);
        printf("%d %d\n",i+k+2,2*k+3);
        printf("%d %d\n",i+k+2,2*k+4);
    }
    printf("%d %d\n",k+1,k+2);
    printf("%d %d\n",2*k+3,2*k+4);
}
