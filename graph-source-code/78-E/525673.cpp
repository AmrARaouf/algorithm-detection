//Language: GNU C++


#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<string>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<climits>
#include<complex>
#define mp make_pair
#define pb push_back
using namespace std;
const int maxm=450000;
const int maxn=51000;
const int inf=0x7fffffff/100;
struct graph 
{
    struct edge
    {
        int v,flow,c,next;
    }a[maxm*4];
    int tot,start[maxn],n,m,s,t;
    inline void init(int _n)
    {
        n=_n;
        memset(start,-1,sizeof(start));
        tot=0;
    }
    void _addedge(int u,int v,int flow)
    {
        a[tot].v=v;
        a[tot].flow=a[tot].c=flow;
        a[tot].next=start[u];
        start[u]=tot++;
    }
    void addedge(int u,int v,int flow)
    {
        //printf("%d %d %d\n",u,v,flow);
        _addedge(u,v,flow);
        _addedge(v,u,0);
    }
    int h[maxn],gap[maxn];
    inline int dfs(int pos,int cost)
    {
        if (pos==t)
        {
            return cost;
        }
        int i,j,k,mi=n-1,lv=cost,d;
        for (i=start[pos];i!=-1;i=a[i].next)
        {
            int v=a[i].v,fl=a[i].flow;
            if (fl>0)
            {
                if (h[v]+1==h[pos])
                {
                    d=min(fl,lv);
                    d=dfs(v,d);
                    a[i].flow-=d;
                    a[i^1].flow+=d;
                    lv-=d;
                    if (h[s]>=n)
                    {
                        return cost-lv;
                    }
                    if (!lv)break;
                }
                mi=min(mi,h[v]);
            }
        }
        if (lv==cost)
        {
            --gap[h[pos]];
            if (!gap[h[pos]])h[s]=n;
            h[pos]=mi+1;
            ++gap[h[pos]];
        }
        return cost-lv;
    }
    int sap()
    {
        memset(gap,0,sizeof(gap));
        memset(h,0,sizeof(h));
        gap[s]=n;
        int ret=0;
        while (h[s]<n)
        {
            ret+=dfs(s,INT_MAX);
        }
        return ret;
    }
}g;
char s[2][12][12];
int n,t;
int dis[12][12];
int dx[]={-1,0,0,1};
int dy[]={0,1,-1,0};
int iq[12][12][62];
int main()
{
    int i,j,k,l=0;
    scanf("%d%d",&n,&t);
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            for (k=0;k<=t;k++)
            {
                iq[i][j][k]=l++;
            }
        }
    }

    g.s=l;
    g.t=g.s+1;
    for (i=0;i<n;i++)
    {
        scanf("%s",s[0][i]);
    }
    for (i=0;i<n;i++)
    {
        scanf("%s",s[1][i]);
    }
    memset(dis,10,sizeof(dis));
    queue<pair<pair<int,int>,int> >q;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            if (s[0][i][j]=='Z')
            {
                q.push(mp(mp(i,j),0));
                dis[i][j]=0;
            }
        }
    }
    int vis[12][12]={0};
    vis[i][j]=1;
    while (!q.empty())
    {
        pair<pair<int,int>,int>pii=q.front();
        q.pop();
        int x=pii.first.first;
        int y=pii.first.second;
        int d=pii.second;
        for (i=0;i<4;i++)
        {
            int tx=x+dx[i];
            int ty=y+dy[i];
            if (tx>=0&&ty>=0&&tx<n&&ty<n&&!vis[tx][ty]&&s[0][tx][ty]!='Y')
            {
                dis[tx][ty]=d+1;
                vis[tx][ty]=1;
                q.push(mp(mp(tx,ty),d+1));
            }
        }
    }
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            if (s[0][i][j]=='Z'||s[0][i][j]=='Y')dis[i][j]=-1;
            //printf("%d ",dis[i][j]);
        }
        //puts("");
    }
    int all=n*n*(t+1)+2;
    g.init(all);
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            for (k=0;k<t;k++)
            {
                if (k>=dis[i][j])continue;
                for (l=0;l<4;l++)
                {
                    int tx=i+dx[l];
                    int ty=j+dy[l];
                    if (tx>=0&&ty>=0&&tx<n&&ty<n&&k+1<=dis[tx][ty])
                    {
                        g.addedge(iq[i][j][k],iq[tx][ty][k+1],inf);
                    }
                }
            }
        }
    }
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            if (isdigit(s[0][i][j]))
            {
                int f=s[0][i][j]-'0';
                if (!f)continue;
                g.addedge(g.s,iq[i][j][0],f);
            }
        }
    }
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            if (isdigit(s[1][i][j]))
            {
                int f=s[1][i][j]-'0';
                if (!f)continue;
                for (k=0;k<t;k++)
                {
                    //g.addedge(iq[i][j][k],g.t,f);
                    g.addedge(iq[i][j][k],iq[i][j][k+1],inf);
                }
                g.addedge(iq[i][j][t],g.t,f);
            }
        }
    }
    
    cout<<g.sap()<<endl;
                    
                        
            
    return 0;
}