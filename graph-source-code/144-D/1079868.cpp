//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <algorithm>

int n,m,s;
const int MaxN = 100005;
struct Edge
{
    int v,w;
    Edge *nxt;
}buf[MaxN*2],*g[MaxN],*pt;

void add(int u, int v, int w)
{
    pt->v = v;
    pt->w = w;
    pt->nxt = g[u];
    g[u] = pt++;
}

const int Inf = 1000000001;
int q[MaxN],in[MaxN],d[MaxN];
void spfa()
{
    for(int i = 1; i <= n; i++)d[i] = Inf;
    d[s] = 0;
    int front=0,rear=0;
    q[rear++]=s;
    in[s] = 1;
    while(front!=rear)
    {
        int u = q[front];
        in[u] = 0;
        front = (front+1)%MaxN;
        for(Edge *now = g[u]; now; now = now->nxt)
        {
            int v = now->v, w = now->w;
            if(d[v] > d[u]+w)
            {
                d[v] = d[u]+w;
                if(!in[v])
                {
                    q[rear++] = v;
                    in[v] = 1;
                    rear %= MaxN;
                }
            }
        }
    }
}

int main()
{
    pt = buf;
    int L;
    scanf("%d%d%d",&n,&m,&s);
    for(int i = 0; i < m; i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);add(b,a,c);
    }
    scanf("%d",&L);
    spfa();
    int ret = 0, ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(d[i]==L)ret++;
        for(Edge *now = g[i]; now; now = now->nxt)
        {
            int v = now->v, w = now->w, f1=0,f2=0;
            if(d[i]<L && d[i]+w>L && w-(L-d[i])+d[v]>=L)f1=1,ans++;
            if(d[v]<L && d[v]+w>L && w-(L-d[v])+d[i]>L)f2=1,ans++;
//          if(f1&&f2&&L*2==d[i]+d[v]+w)ans--;
        }
    }
//  printf("%d %d\n",ret,ans);
    printf("%d\n",ret+ans/2);


    return 0;
}
