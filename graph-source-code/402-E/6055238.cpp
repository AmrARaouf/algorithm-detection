//Language: GNU C++


#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<stack>
#include<cstdio>

using namespace std;
const int N = 2100;
const int INF = 1e9 + 7;

inline int get_int(){
    int ret=0;char c;
    while(!isdigit(c=getchar()));
    do {ret = (ret<<3)+(ret<<1)+c-'0';
    }while(isdigit(c=getchar()));
    return ret;
}

int G[N][N];
int pre[N], lowlink[N], sccno[N], dfs_clock, scc_cnt;
stack<int> S;

int n;

void dfs(int u)
{
    pre[u] = lowlink[u] = ++ dfs_clock;
    S.push(u);

    for(int v = 0; v < n; v ++) if(G[u][v])
    {
        if(!pre[v])
        {
            dfs(v);
            lowlink[u] = min(lowlink[u], lowlink[v]);
        } else if(!sccno[v])
        {
            lowlink[u] = min(lowlink[u], pre[v]);
        }
    }

    if(lowlink[u] == pre[u])
    {
        scc_cnt ++;
        for(;;)
        {
            int x = S.top();S.pop();
            sccno[x] = scc_cnt;
            if(x == u) break;
        }
    }
}

bool find_scc()
{
    dfs_clock = scc_cnt = 0;
    memset(sccno, 0, sizeof(sccno));
    memset(pre, 0, sizeof(pre));
    for(int i = 0; i < n; i ++)
        if(!pre[i]) dfs(i);
    return scc_cnt == 1;
}

int main()
{
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
                G[i][j] = get_int();
        if(find_scc()) puts("YES");
        else puts("NO");
    }
}
