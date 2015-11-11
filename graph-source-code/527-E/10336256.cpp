//Language: GNU C++0x


#include<bits/stdc++.h>
using namespace std;

struct Edge
{
    int to,id;
    Edge(int to = 0,int id = 0):to(to),id(id) {}
};

int n,m;
bool vis[500000+10];
int now_edge[200000+10];
vector<Edge> edges[200000+10];
vector<int> res;


void dfs(int u)
{
    while(now_edge[u] < edges[u].size())
    {
        if(vis[edges[u][now_edge[u]].id]) ++now_edge[u];
        else
        {
            vis[edges[u][now_edge[u]].id] = 1;
            dfs(edges[u][now_edge[u]].to);
            res.push_back(u);
        }
    }
}

int main()
{
//    freopen("./test.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i = 0;i < m;++i)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        edges[a].push_back(Edge(b,i));
        edges[b].push_back(Edge(a,i));
    }
    int t = -1;
    for(int i = 1;i <= n;++i)
        if(edges[i].size() & 1)
        {
            if(t == -1)
                t = i;
            else
            {
                edges[i].push_back(Edge(t,m));
                edges[t].push_back(Edge(i,m));
                ++m;
                t = -1;
            }
        }
    if(m&1)
    {
        edges[1].push_back(Edge(1,m));
        edges[1].push_back(Edge(1,m));
        m++;
    }
    res.push_back(1);
    dfs(1);
    printf("%d\n",m);
    for(int i = 0;i < res.size()-1;++i)
        if(i & 1) printf("%d %d\n",res[i],res[i+1]);
        else printf("%d %d\n",res[i+1],res[i]);
    return 0;
}
