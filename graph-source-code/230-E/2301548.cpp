//Language: MS C++


#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;
const int lmax=1000005;
typedef __int64 i64;

i64 n,m,sum[lmax],ans;
int main()
{
    int i;
    //ios::sync_with_stdio(0);
    scanf("%I64d%I64d",&n,&m);
    for(i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        sum[a]++;
        sum[b]++;
    }
    ans=0;
    for(i=1;i<=n;i++)
    {
        ans+=sum[i]*(n-1-sum[i]);
    }
    ans>>=1;
    ans=n*(n-1)*(n-2)/6-ans;
    printf("%I64d\n",ans);
}