//Language: GNU C++


#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define maxn 100000
#define maxm 21001
#define mo 999987

using   namespace std;

struct  data
{
        int x,y;
};

data    a[maxm],pos[maxm];
int     u[3005][3005];
int     n,m,t,kth;
int     hashtable[mo+10][2],q[mo*10],dist[maxm*2],fa[maxm*2],pr[maxm*2];
bool    vis[mo];
vector<int> st[maxn];

bool    hash(int x, int y, bool flag)
{
        int k=(x*n+y)%mo;
        while (hashtable[k][0]!=-1 && (hashtable[k][0]!=x || hashtable[k][1]!=y)) k=(k+1)%mo;
        if (hashtable[k][0]!=-1) return true;
        if (!flag) return false;
        hashtable[k][0]=x; hashtable[k][1]=y; return false;
}

void    init()
{
        scanf("%d%d%d",&n,&m,&kth);
        int x,y,z; t=0;
        for (int i=0; i<maxn; i++) st[i].clear();
        for (int i=1; i<=m; i++)
        {
                scanf("%d%d",&a[i].x,&a[i].y);
                x=a[i].x; y=a[i].y;
                u[x][y]=++t; pos[t].x=x; pos[t].y=y; st[x].push_back(t);
                u[y][x]=++t; pos[t].x=y; pos[t].y=x; st[y].push_back(t);
        }
        memset(hashtable,255,sizeof(hashtable));
        for (int i=1; i<=kth; i++)
        {
                scanf("%d%d%d",&x,&y,&z);
                if (!u[x][y] || !u[y][z]) continue;
                hash(u[x][y],u[y][z],true);
        }
}

void    slove()
{
        memset(vis,0,sizeof(vis));
        memset(dist,60,sizeof(dist));
        int fir=1, las=0; int num , ans=dist[0];
        for (int i=0; i<st[1].size(); i++)
        {
                vis[st[1][i]]=true;
                dist[st[1][i]]=1;
                if (pos[st[1][i]].y==n)
                {
                        ans=1;
                        num=st[1][i];
                }
                fa[st[1][i]]=0;
                q[++las]=st[1][i];
        }
        while (fir<=las)
        {
                int p=q[fir++];
                int x=pos[p].y;
                for (int i=0; i<st[x].size(); i++)
                        if (!hash(p,st[x][i],false) && dist[p]+1<dist[st[x][i]])
                        {
                                dist[st[x][i]]=dist[p]+1;
                                fa[st[x][i]]=p;
                                if (pos[st[x][i]].y==n && dist[st[x][i]]<ans)
                                {
                                        ans=dist[st[x][i]];
                                        num=st[x][i];
                                }
                                if (!vis[st[x][i]])
                                {
                                        vis[st[x][i]]=true;
                                        q[++las]=st[x][i];
                                }

                        }
                vis[p]=false;
        }
        if (ans>100000)
        {
                cout<<-1<<endl;
                return;
        }
        printf("%d\n",ans);
        int tot=0;
        while (num!=0)
        {
                pr[++tot]=pos[num].y;
                num=fa[num];
        }
        cout<<1;
        for (int i=tot; i>0; i--) printf(" %d",pr[i]);
}

int     main()
{
        init();
        slove();
        return 0;
}
