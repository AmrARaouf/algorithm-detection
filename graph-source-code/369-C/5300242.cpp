//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
#define Mod (1000000007LL)
#define eps (1e-8)
#define Pi (acos(-1.0))
using namespace std;
int node[110110];
int x,y,t;
map<long long,bool> f;
bool vis[110110];
int n;
vector<int> g[110110];
int tot;
int ans[110110];
long long tmp1,tmp2;
void dfs(int id)
{
   // printf("%d\n",id);
    vis[id]=true;
    int k=g[id].size();
    int dy;
    for(int i=0;i<k;i++)
    {
        dy=g[id][i];
        //printf("g[%d][%d]=%d\n",id,i,dy);
       // printf("%d %d\n",dy,vis[dy]);
        if(vis[dy]) continue;
        dfs(dy);
        tmp1=(long long)(id)*(long long)(n+1)+dy;
        if(node[dy]) node[id]=1;
        if(!f[tmp1]) continue;
        if(!node[dy])
        {
            node[dy]=2;
            ans[++tot]=dy;
        }
        node[id]=1;
    }
}
int main()
{
    while(~scanf("%d",&n))
    {
        f.clear();
        tot=0;
        memset(vis,false,sizeof(vis));
        memset(node,0,sizeof(node));
        for(int i=1;i<=n;i++)
        g[i].clear();
        for(int i=1;i<n;i++)
        {
            scanf("%d%d%d",&x,&y,&t);
            g[x].push_back(y);
            g[y].push_back(x);
            tmp1=(long long)(x)*(long long)(n+1)+(long long)(y);
            tmp2=(long long)(y)*(long long)(n+1)+(long long)(x);
            if(t==2) f[tmp1]=f[tmp2]=true;
        }
        //puts("fuck");
        dfs(1);
        //puts("fuck");
        printf("%d\n",tot);
        for(int i=1;i<=tot;i++)
        printf("%d%c",ans[i],(i==tot)?'\n':' ');
    }
    return 0;
}
