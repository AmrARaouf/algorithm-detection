//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#define maxn 100009
using namespace std;
vector<int>G[maxn];
stack<int>stk;
queue<int>q;
int n,m,k;
int dfn[maxn];
int id[maxn];
int time=0;
void dfs(int cur)
{
    dfn[cur]=++time;
    id[time]=cur;
    for(int i=0;i<G[cur].size();i++)
    {
        int e=G[cur][i];
        if(dfn[e]&&time-dfn[e]>=k)
        {
            printf("%d\n",time-dfn[e]+1);
            for(int i=time;i>=dfn[e];i--)
            {
                printf("%d ",id[i]);
            }
            exit(0);
        }
        if(!dfn[e])dfs(e);
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        memset(dfn,0,sizeof(dfn));
        if(!dfn[i])dfs(i);
    }
}
