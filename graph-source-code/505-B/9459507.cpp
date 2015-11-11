//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define maxn 308
bool vis[maxn],val[maxn];
int vv[maxn],nxt[maxn],ww[maxn];
int first[maxn];
int fuck[maxn];
int e;
void init()
{
    e = 0;
    memset(first,-1,sizeof(first));
}

void addedge(int u,int v,int c)
{
    vv[e] = v;  nxt[e] = first[u];  ww[e] = c;  first[u] = e++;
    vv[e] = u;  nxt[e] = first[v];  ww[e] = c;  first[v] = e++;
}

void dfs(int s,int t,int u,int d)
{
    if(u == t)  return;
    for(int i = first[u];i != -1;i = nxt[i])
    {
        int v = vv[i];
        int w = ww[i];
        if(w != d)  continue;
        if(vis[v])  continue;
        vis[v] = 1;
        dfs(s,t,v,d);
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        init();
        for(int i = 1;i <= m;i++)
        {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            addedge(u,v,c);
        }
        int q;
        scanf("%d",&q);
        while(q--)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            val[u] = 1;
            int ans = 0;
            for(int i = 0;i < 108;i++)
            {
                memset(vis,0,sizeof(vis));
                memset(val,0,sizeof(val));
                dfs(u,v,u,i);
                if(vis[v])  ans++;
            }
            cout << ans << endl;
        }
    }
}
