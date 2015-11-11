//Language: GNU C++


#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <deque>
#include <list>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

const int tmax = (int)1e5 + 100;
vector < int > graph[tmax];


#define mp make_pair
#define pb push_back
vector < pair < int , pair<int,int> > > cycle;
int visited[tmax], parent[tmax];
int n,m,k;

void dfs( int node, int cc )
{
    visited[node] = cc;
    for( int i = 0; i < graph[node].size(); i++)
    {
        int no = graph[node][i];
        if( visited[no] == -1 )
        {
            dfs(no,cc+1);
            parent[no] = node;
        }
        else if( abs(visited[node] - visited[no])  >= k )
            cycle.pb(mp(node,mp(no,visited[node]-visited[no])));
    }
}
void rec( int node, int fim )
{
    printf("%d ", node);
    if( node == fim ) return;
    rec(parent[node],fim);
}
int main()
{

    scanf("%d %d %d", &n, &m, &k);
    for( int i = 0; i < m; i++)
    {
        int a,b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    set < int > used;
    for( int i = 0; i < 1000; i++)
    {
        int newpos = rand()%n + 1;
        if( used.find(newpos) != used.end()) continue;
        used.insert(newpos);
        for( int j = 0; j <= n; j++)
            visited[j] = -1, parent[j] = -1;
        cycle.clear();
        dfs(newpos,1);
        if( cycle.size() )
        {
            printf("%d\n", cycle[0].second.second+1);
            rec(cycle[0].first,cycle[0].second.first);
            printf("\n");
            return 0;
        }
    }
    return 0;
}
