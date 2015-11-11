//Language: GNU C++


/*
 * D. Cycle in Graph.cpp
 *
 *  Created on: May 12, 2014
 *      Author: abdelkarim
 */
#include <bits/stdc++.h>

using namespace std;

vector < vector<int> > adj(100005);
vector<int> path;
bool vis[100005];
int k;

void dfs(int cur) {
    path.push_back(cur);
    vis[cur] = 1;
    int len = path.size() ;

    if (len > k)
        for (int i = 0; i < (int)adj[cur].size(); i++)
            if (adj[cur][i] == path[0]) {
                printf("%d\n" , len);
                for (int j = 0; j < len ; j++)
                    printf("%d ",path[j] );
                exit(0);
            }

    for (int i = 0; i < (int)adj[cur].size(); i++)
        if (!vis[adj[cur][i]])
            dfs(adj[cur][i]);

    vis[cur] = 0;
    path.pop_back();
}

int main() {
    int a, b, m, n;
    scanf("%d%d%d" , &n , &m , &k);
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= m; i++) {
        scanf("%d%d" , &a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++){
        dfs(i);
    }

    return 0;
}
