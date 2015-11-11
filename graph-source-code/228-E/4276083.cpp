//Language: GNU C++


#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <set>
#define MAXN 110
#define MAXM 20010
#define INF 1000000007
#define MP(x,y) make_pair(x,y)
#define FI first
#define SE second
#define EPS 1e-8
using namespace std;
int he[MAXN],to[MAXM],nex[MAXM],co[MAXM],top;
bool vi[MAXN],ty[MAXN],had[MAXN],asp[MAXN];
void add(int u,int v,int c)
{
    to[top]=v;
    nex[top]=he[u];
    co[top]=c;
    he[u]=top++;
}
bool dfs(int h)
{
    bool flag=1;
    vi[h]=1;
    for(int i=he[h];i!=-1&&flag;i=nex[i])
    {
        if(vi[to[i]])   flag&=(ty[h]==ty[to[i]])^!co[i];
        else    ty[to[i]]=ty[h]^!co[i],flag&=dfs(to[i]);
    }
    return flag;
}
int main()
{
    //freopen("/home/moor/Code/input","r",stdin);
    int n,m,cnt;
    bool flag=0;
    while(scanf("%d%d",&n,&m)==2)
    {
        cnt=0;
        memset(he,-1,sizeof(he));
        memset(had,0,sizeof(had));
        memset(asp,0,sizeof(asp));
        top=0;
        flag=1;
        for(int i=0;i<m;++i)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c);
            add(b,a,c);
            if(c==0)    flag=0;
        }
        if(flag)
        {
            printf("0\n");
            continue;
        }
        for(int i=1;i<=n;++i)
            if(!had[i])
            {
                flag=0;
                for(int j=he[i];j!=-1;j=nex[j])
                    if(co[j]==0)
                        flag=1;
                if(flag)
                {
                    memset(vi,0,sizeof(vi));
                    vi[i]=1,ty[i]=0;
                    flag=dfs(i);
                    if(!flag)   continue;
                    for(int j=1;j<=n;++j)
                    {
                        if(vi[j])   had[j]=1;
                        if(vi[j]&&ty[j])   asp[j]=1,++cnt;
                    }
                }
                else    had[i]=1;
            }
        flag=1;
        for(int i=1;i<=n&&flag;++i)
            if(!had[i]) flag=0;
        if(!flag)   printf("Impossible\n");
        else
        {
            printf("%d\n",cnt);
            for(int i=1,s=0;i<=n;++i)
                if(asp[i])
                    printf("%s%d",s++?" ":"",i);
            printf("\n");
        }
    }
    return 0;
}
