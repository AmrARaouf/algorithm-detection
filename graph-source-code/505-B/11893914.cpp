//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <iostream>
using namespace std;
const int MAX = 105;
typedef pair <int,int> P;
int n,m,q;
vector <int> G[MAX][MAX];
int visit[MAX][MAX];
int con[MAX][MAX];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 0; i < m; ++i)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        G[a][c].push_back(b);
        G[b][c].push_back(a);
    }
    scanf("%d",&q);
    for(int i = 0; i < q; ++i)
    {
        int s,t;
        queue <P> que;
        scanf("%d%d",&s,&t);
        memset(con,0,sizeof(con));
        memset(visit,0,sizeof(visit));
        for(int i = 1; i <= m; ++i)
        {
            visit[s][i] = 1;
            con[s][i] = 1;
            que.push(P(s,i));
        }
        while(!que.empty())
        {
            P tp = que.front(); que.pop();
            int u = tp.first, color = tp.second;
            for(int i = 0; i < G[u][color].size(); ++i)
            {
                int v = G[u][color][i];
                if(!visit[v][color])
                {
                    con[v][color] = 1;
                    visit[v][color] = 1;
                    que.push(P(v,color));
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= m; ++i)
        {
            if(con[t][i])
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
