//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

const int MaxN = 105;
const int MaxM = 100005;
struct Edge
{
    int v;
    Edge *nxt;
} buf[MaxM],*g[MaxN],*pt;
void add(int u, int v)
{
    pt->v = v;
    pt->nxt = g[u];
    g[u] = pt++;
}
const int Inf = 10000100;
int n,m,d[MaxN],vst[MaxN],d2[MaxN];
LL dp[MaxN],dp2[MaxN];
void dij()
{
    for(int i = 1; i <= n; i++)d[i] = Inf, vst[i] = 0;
    d[1] = 0;
    while(1)
    {
        int id = -1;
        for(int i = 1; i <= n; i++)if(!vst[i])
            {
                if(id==-1 || d[id]>d[i])id = i;
            }
        if(id==-1)break;
        vst[id] = 1;
        for(Edge *now = g[id]; now; now = now->nxt)
        {
            int v = now->v;
            if(d[v] > d[id]+1)
            {
                d[v] = d[id]+1;
            }
        }
    }
    double ret = 0;
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)d2[i] = Inf, vst[i] = 0, dp[i]=dp2[i] = 0;
        dp[n] = 1;
        dp2[n] = 0;
        d2[n] = 0;
        while(1)
        {
            int id = -1;
            for(int i = 1; i <= n; i++)if(!vst[i])
                {
                    if(id==-1 || d2[id]>d2[i])id = i;
                }
            if(id==-1)break;
            vst[id] = 1;
            for(Edge *now = g[id]; now; now = now->nxt)
            {
                int v = now->v;
                if(d2[v] > d2[id]+1)
                {
                    d2[v] = d2[id]+1;
                }
                if(d2[id]+d[v]+1 == d[n])
                {
                    dp[v] += dp[id];
                    dp2[v] += dp2[id];
                    if(id==k || v==k)
                        dp2[v] += dp[id];
                }
            }
        }
        ret = max(ret,1.0*dp2[1]/dp[1]);
    }

//  printf("%d\n",dp[1]);
    printf("%.10f\n",ret);
}

int main()
{
    scanf("%d%d",&n,&m);
    pt = buf;
    memset(g,0,sizeof(g));
    for(int i = 0; i < m; i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    dij();

    return 0;
}
