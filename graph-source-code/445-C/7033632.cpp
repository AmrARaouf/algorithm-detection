//Language: GNU C++


#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define FOR(i,n) for(i=0;i<(n);i++)
#define CLR(a) memset(a,0,sizeof(a))
using namespace std;
int q[505];
int main()
{
    int n,m,x,y,z,i,j;
    int v,e;
    double as,mas;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        scanf("%d",&q[i]);
    }
    int mi,mj;
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        x--,y--;
        scanf("%d",&z);
        as=1.0*(q[x]+q[y])/z;
        if(i==0) as=mas=1.0*(q[x]+q[y])/z;
        else if(as>mas)
        {
            mas=as;
        }
    }
    printf("%.15lf\n",mas);
    return 0;
}
