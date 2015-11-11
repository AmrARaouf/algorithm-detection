//Language: GNU C++


#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

#define sf scanf
#define pf printf

typedef __int64 LL;
const int Maxn=100100;
int a[Maxn],x;
int ans[Maxn],num;
int cmp(int x,int y)
{
    return x>y;
}
void _init()
{
    int i;
    for(i=1;i<Maxn;i++)
    {
        ans[i]=(i&1)?((i-1)*i/2+1):((i-1)/2*i+i);
        if(ans[num++]>2000010) break;
    }
}
int main()
{
    _init();
    int n,m;
    while(~sf("%d%d",&n,&m))
    {
        int tmp;
        for(int i=1;i<=num;i++)
        {
            if(ans[i]>n)
            {
                tmp=i-1;
                break;
            }
        }
        for(int i=0;i<m;i++)
            sf("%d%d",&x,&a[i]);
        sort(a,a+m,cmp);
        LL ans=0;
        for(int i=0;i<tmp;i++)
            ans+=a[i];
        pf("%I64d\n",ans);
    }
    return 0;
}
