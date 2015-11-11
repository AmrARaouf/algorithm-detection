//Language: GNU C++


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 300005

int n, m;
struct node
{
        int v;
        int next;
}e[maxn<<1];
int k, pre[maxn];
bool vis[maxn];

void addE( int u, int v )
{
        e[k].v=v;
        e[k].next=pre[u];
        pre[u]=k++;
}

bool dfs( int u )
{
        int cnt=0;
        for ( int i=pre[u]; i!=-1; i=e[i].next )
                if (vis[e[i].v]==vis[u]) cnt++;
        if (cnt>1)
        {
                vis[u]=!vis[u];
                for ( int i=pre[u]; i!=-1; i=e[i].next )
                        if (!dfs(e[i].v)) return 0;
        }
        return 1;
}

int main( )
{
        scanf("%d%d", &n, &m);
        memset(pre, -1, sizeof(pre));
        int u, v;
        for ( int i=0; i<m; i++ )
        {
                scanf("%d%d", &u, &v);
                addE(u, v);
                addE(v, u);
        }
        int p=0;
        for ( int i=1; i<=n; i++ )
                if (dfs(i)) p++;
        //printf("%d\n", p);
        if (p==n)
        {
                for (int i=1; i<=n; i++)
                        printf("%d",vis[i]);
                printf("\n");
        }
        else printf("-1\n");
        return 0;
}
