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
#include <queue>
#include <string.h>
#include <vector>

using namespace std;

#define inf 0x3fffffffffffffff
const int maxn=100010;
const int maxe=100010*2;

int head[maxn],var[maxe],next[maxe],tot,w[maxe],n,m;
long long dis[maxn];
bool vis[maxn];
vector<int> g[maxn];
vector<int>::iterator it;

void add(int u,int v,int ti)
{
    var[tot]=v,w[tot]=ti,next[tot]=head[u],head[u]=tot++;
}
int late(int v,int tim)
{
    it=find(g[v].begin(),g[v].end(),tim);
    if(it==g[v].end()) return tim;
    for(it++,tim++;it!=g[v].end();it++,tim++)
      if((*it)!=tim) return tim;
    return tim;
    int l=it-g[v].begin();
    int start=l;
    int r=g[v].size()-1,ret=l;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(g[v][mid]<=tim+mid-start) ret=mid,l=mid+1;
        else r=mid-1;
    }
    return g[v][ret]+1;
    /*while(1)
    {
        int id=lower_bound(g[v].begin(),g[v].end(),tim)-g[v].begin();
        if(id==g[v].size()||g[v][id]!=tim) return tim;
        tim++;
    }*/
}
long long spfa()
{
    queue<int> q;
    dis[1]=0;
    memset(vis,0,sizeof(vis));
    for(q.push(1);!q.empty();q.pop())
    {
        int cur=q.front();
        vis[cur]=0;
        int dd=late(cur,dis[cur]);
        for(int i=head[cur];i!=-1;i=next[i])
        {
            int v=var[i];
            long long tmp=dd+w[i];
           // if(v==n) { ans=min(ans,tmp);continue; }
            //tmp=late(v,tmp);
            if(tmp<dis[v]) {
               dis[v]=tmp;
               if(!vis[v]) vis[v]=1,q.push(v);
            }
        }
    }
    if(dis[n]>=inf) return -1;
    else return dis[n];
}
int main()
{
    int a,b,c,k;
    while(scanf("%d%d",&n,&m)==2)
    {
        tot=0;
        memset(head,-1,sizeof(head));
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c);
            add(b,a,c);
        }
        for(int i=1;i<=n;i++)
        {
            g[i].clear();
            scanf("%d",&k);
            for(int j=0;j<k;j++) scanf("%d",&a),g[i].push_back(a);
            dis[i]=inf;
        }
        printf("%I64d\n",spfa());
    }
    return 0;
}
/*
2 1
1 2 3
0
1 3
*/
