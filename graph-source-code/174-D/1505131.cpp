//Language: GNU C++


#include <stdio.h>
#include <vector>
#include <string.h>
#define MAXN 100000

using namespace std;

vector < int > Graph[MAXN], rGraph[MAXN];

int state[MAXN+10];
bool visited[3][MAXN+10];

void dfs(int node)
{
    if(visited[0][node])
        return;
    visited[0][node] = true;
    int tm = Graph[node].size();
    for(int i = 0; i < tm; i++)
        dfs(Graph[node][i]);
}

void rdfs(int node)
{
    if(visited[1][node])
        return;
    visited[1][node] = true;
    if(state[node] == 1)
        return;
    int tm = rGraph[node].size();
    for(int i = 0; i < tm; i++)
        rdfs(rGraph[node][i]);
}


int main()
{
    int n,m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", &state[i]);
    for(int i = 0; i < m; i++)
    {
        int a,b;
        scanf("%d %d", &a, &b);
        a--,b--;
        Graph[a].push_back(b);
        rGraph[b].push_back(a);
    }
    for(int i = 0; i < n; i++)
    {
        if(state[i] == 1)
            dfs(i);
        else if(state[i] == 2)
            rdfs(i);
    }
    for(int i = 0; i < n; i++)
        printf("%d\n", visited[1][i] && visited[0][i]);
    return 0;
}
