//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<cctype>
#include<vector>
#include<queue>
using namespace std;
#define MX 3005

int diss1[MX];
int dist1[MX];
int diss2[MX];
int dist2[MX];
int tem[MX];
int n, m;
vector<int> adj[MX];

void bfs(int dis[], int s)
{
    memset(dis,12,sizeof(int)*(n+1));
    dis[s] = 0;
    queue<int> qu;
    qu.push(s);
    while(!qu.empty())
    {
        int u = qu.front();
        qu.pop();
        for(int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];
            if(dis[v] > 3005)
            {
                dis[v] = dis[u]+1;
                qu.push(v);
            }
        }
    }
}

int main()
{
    int u, v;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int s1, s2, t1, t2, l1, l2;
    scanf("%d%d%d", &s1, &t1, &l1);
    scanf("%d%d%d", &s2, &t2, &l2);
    bfs(diss1,s1);
    bfs(dist1,t1);
    bfs(diss2,s2);
    bfs(dist2,t2);
    int res = 10000;
    for(int i = 1; i < n; i++)
    {
        bfs(tem,i);
        for(int j = 1; j <= n; j++)
        {
            if(tem[j]+diss1[i]+dist1[j] <= l1 && tem[j]+diss2[i]+dist2[j] <= l2)
                res = min(res,tem[j]+diss1[i]+dist1[j]+diss2[i]+dist2[j]);
            if(tem[j]+diss1[i]+dist1[j] <= l1 && tem[j]+diss2[j]+dist2[i] <= l2)
                res = min(res,tem[j]+diss1[i]+dist1[j]+diss2[j]+dist2[i]);
        }
    }
    if(diss1[t1] <= l1 && diss2[t2] <= l2)
        res = min(diss1[t1]+diss2[t2],res);
    if(res == 10000)
        res = -1;
    else
        res = m-res;
    printf("%d\n", res);
    return 0;
}