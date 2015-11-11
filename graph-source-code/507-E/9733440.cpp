//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
#define maxm 200010
#define maxn 100010
#define INF 111111

struct node
{
    int a, b, c, next; 
    node(){}
    node(int a, int b, int c, int d):
        a(a),b(b),c(c),next(d){}
}edge[maxm];

struct pp
{
    int v, d1 ,d2;
    bool operator < (const pp &x) const
    {
        if(d1!= x.d1)
            return d1 > x.d1;
        return d2< x.d2;
    }
};

int n, m, tot;
int head[maxn], vis[maxn];
int dis[maxn], d[maxn], pre[maxn];
int ans[maxn];
priority_queue<pp> q;

void add(int x, int y, int z)
{
    edge[++tot]= node(x, y, z, head[x]);
    head[x]= tot;
}

void Dij()
{
    memset(d, 0, sizeof d);
    memset(vis, 0, sizeof vis);
    for(int i= 1; i< maxn; i++)
        dis[i]= INF;
    pp N;
    N.v= 1, N.d1= 0, N.d2= 0;   
    q.push(N);  
    while(!q.empty())
    {
        while(vis[N.v] && !q.empty())
        {
            N= q.top();
            q.pop();
        }           
        if(vis[N.v])
            break;
        vis[N.v]= 1;
        dis[N.v]= N.d1;
        d[N.v]= N.d2;
        for(int i= head[N.v]; i!= -1; i= edge[i].next)
            if(!vis[edge[i].b])
            {
                if(dis[N.v]+1< dis[edge[i].b] || (dis[N.v]+1 == dis[edge[i].b] && d[N.v]+edge[i].c> d[edge[i].b]))
                {
                    pp M;
                    M.v= edge[i].b;
                    M.d1= dis[N.v]+1;
                    M.d2= d[N.v]+edge[i].c;
                    q.push(M);
                    dis[edge[i].b]= M.d1;
                    d[edge[i].b]= M.d2;
                    pre[edge[i].b]= i;
                //  if(edge[i].b== 3)
                //      printf("::%d\n",i);
                }
            }       
    }
    memset(ans, 0, sizeof ans);
    int xx= n;
    while(xx!= 1)
    {
    //  printf("%d\n",(pre[xx]+1)/2);
        ans[(pre[xx]+1)/2]= 1;
        xx= edge[pre[xx]].a;
    }
}

int main()
{
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        memset(head, -1, sizeof head);
        int x, y, z;
        tot= 0;
        int sum= 0;
        for(int i= 1; i<= m; i++)
        {
            scanf("%d %d %d",&x,&y,&z); 
            //add(x, y, z);
            add(y, x, z);   
            add(x, y, z);
            if(z)sum++;
        }
        //printf("%d %d %d %d\n",head[1],head[2],edge[1].next,edge[2].next);
        Dij();
        //printf("%d %d\n",dis[n],dis[3]);
        printf("%d\n",sum+dis[n]-2*d[n]);
        for(int i= 2; i<= 2*m; i+=2)
            if(ans[i/2]^edge[i].c)
                printf("%d %d %d\n",edge[i].a,edge[i].b,edge[i].c^1);               
    }
    return 0;
}