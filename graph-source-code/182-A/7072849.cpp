//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#define maxn 1009
#define maxm 5000009
#define eps 1e-9
using namespace std;
struct Seg
{
    int x1,x2,y1,y2;
    void init()
    {
        if(x1>x2)
            swap(x1,x2);
        if(y1>y2)
            swap(y1,y2);
    }
}p[maxn];
struct node
{
    int u;
    double d;
    bool operator<(const node &rhs)const
    {
        return d>rhs.d;
    }
};
struct Edge
{
    int v,next;
    double w;
}edge[maxm];
int head[maxn],tot,n;
double d[maxn];
bool done[maxn];
inline void addedge(int u,int v,double w)
{
    edge[tot].w=w;
    edge[tot].v=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
int dis(Seg a,Seg b)
{
    int dx=0,dy=0;
    if(a.x2<b.x1)
        dx=b.x1-a.x2;
    else if(b.x2<a.x1)
        dx=a.x1-b.x2;
    if(a.y2<b.y1)
        dy=b.y1-a.y2;
    else if(b.y2<a.y1)
        dy=a.y1-b.y2;
    return dx*dx+dy*dy;
}
int sgn(double x)
{
    if(fabs(x)<eps)
        return 0;
    else if(x>0)
        return 1;
    else
        return -1;
}
void Dijkstra()
{
    priority_queue<node>q;
    for(int i=0;i<n;i++)
        d[i]=1e15;
    node tmp;
    tmp.u=0;tmp.d=0;
    d[0]=0;
    q.push(tmp);
    while(!q.empty())
    {
        node now=q.top();
        q.pop();
        int u=now.u;
        if(done[u])
            continue;
        done[u]=1;
        for(int e=head[u];e!=-1;e=edge[e].next)
        {
            int v=edge[e].v;
            double w=edge[e].w;
            if(d[v]>d[u]+w)
            {
                d[v]=d[u]+w;
                tmp.u=v;tmp.d=d[v];
                q.push(tmp);
            }
        }
    }
}
int main()
{
    int a,b,N;
    scanf("%d%d",&a,&b);
    int x,y;
    scanf("%d%d",&x,&y);
    p[0].x1=p[0].x2=x;p[0].y1=p[0].y2=y;
    scanf("%d%d",&x,&y);
    p[1].x1=p[1].x2=x;p[1].y1=p[1].y2=y;
    scanf("%d",&N);
    for(int i=2;i<2+N;i++)
    {
        scanf("%d%d%d%d",&p[i].x1,&p[i].y1,&p[i].x2,&p[i].y2);
        p[i].init();
    }
    memset(head,-1,sizeof(head));
    n=N+2;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
    {
        int len=dis(p[i],p[j]);
        if(len>a*a)
            continue;
        if(j==1)
            addedge(i,j,sqrt(len));
        else
            addedge(i,j,a+b);
    }
    Dijkstra();
    if(sgn(d[1]-1e15)>=0)
        printf("-1\n");
    else
        printf("%.10f\n",d[1]);
    return 0;
}
