//Language: MS C++


#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <set>
#include <map>
#include <string>

#define M 123450
#define MOD 1000000009

int r[M];

int root(int node)
{
    if(r[node]) return r[node]=root(r[node]);
    return node;
}

int main()
{
    int n,m;
    int i,x,y,r1,r2;
    __int64 s=1;

    //freopen("input.txt","r",stdin);
    
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;++i)
    {
        scanf("%d%d",&x,&y);
        r1=root(x);
        r2=root(y);
        if(r1==r2)
        {
            s=s*2%MOD;
        }
        else
            r[r2]=r1;
        if(s>0) printf("%I64d\n",s-1);
        else printf("%d\n",MOD-1);
    }

    return 0;
}
