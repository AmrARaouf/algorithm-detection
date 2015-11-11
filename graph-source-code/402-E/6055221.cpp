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
int vis[N], sccno[N], scc_cnt;
vector<int> S;

int n;

void dfs1(int u)
{
    if(vis[u]) return ;
    vis[u] = 1;
    for(int i = 0; i < n; i ++) if(G[u][i]) dfs1(i);
    S.push_back(u);
}

void dfs2(int u)
{
    if(sccno[u]) return ;
    sccno[u] = scc_cnt;
    for(int v = 0; v < n; v ++) if(G[v][u]) dfs2(v);
}

bool find_scc()
{
    scc_cnt = 0;S.clear();
    memset(sccno, 0, sizeof(sccno));
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < n; i ++) dfs1(i);
    for(int i = n - 1; i >= 0; i --)
        if(!sccno[S[i]]) scc_cnt ++, dfs2(S[i]);
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
