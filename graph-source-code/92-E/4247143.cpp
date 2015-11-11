//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define L(t) t<<1
#define R(t) t<<1|1
const int maxn=100005;
const int MOD=1000000009;
int f[maxn];
int find(int x)
{
    int r=x;
    while(f[r]!=-1)
    {
        r=f[r];
    }
    int t;
    while(x!=r)
    {
        t=f[x];
        f[x]=r;
        x=t;
    }
    return r;
}
int main()
{
   // freopen("in.txt","r",stdin);
    int n,m;
    __int64 ans=0;
    memset(f,-1,sizeof(f));
    scanf("%d%d",&n,&m);
    for(int i=0,v,u,fa,fb;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        fa=find(u);
        fb=find(v);
        if(fa==fb)
        {
            ans=(2*ans+1)%MOD;

        }
        else
        {
            if(fa<fb)
                f[fb]=fa;
            else
                f[fa]=fb;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

 	  	 				  	  			     	