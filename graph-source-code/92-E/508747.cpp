//Language: MS C++


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=100105;
const int Mod=1000000009;

int f[maxn];
int n,m,ans;

void init()
{
    for (int i=1;i<=n;i++)
        f[i]=i;
}

int find(int x)
{
    if (x!=f[x])
        f[x]=find(f[x]);
    return f[x];
}

void Union(int a,int b)
{
    int x=find(a);
    int y=find(b);
    f[y]=x;
}

int main()
{
    int a,b;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        ans=1; init();
        while (m--)
        {
            scanf("%d%d",&a,&b);
            if (find(a)==find(b))
            {
                ans+=ans;
                if (ans>=Mod)
                    ans-=Mod;
            }
            else
                Union(a,b);
            printf("%d\n",(ans+Mod-1)%Mod);
        }
    }
    return 0;
}
