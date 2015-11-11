//Language: GNU C++


#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <fstream>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

const int nmax = 100001;

vector<int> graph[nmax];
vector<int> revgraph[nmax];

int n, m;
int f[nmax];
int go1[nmax], go2[nmax];
bool w1[nmax], w2[nmax];

void dfs1(int u)
{
    if( w1[u] ) return ;
    w1[u] = true;
    go1[u] = 1;
    for( int i = 0; i < graph[u].size(); i ++ )
    {
        int v = graph[u][i];
        dfs1( v );
    }
}

void dfs2(int u)
{
    if( w2[u] ) return ;
    w2[u] = true;
    go2[u] = 1;
    if( f[u] == 1 ) return ;
    for( int i = 0; i < revgraph[u].size(); i ++ )
    {
        int v = revgraph[u][i];
        dfs2( v );
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for( int i = 0; i < n; i ++ )
        scanf("%d", &f[i]);
        
    for( int i = 0; i < m; i ++ )
    {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u-1].push_back(v-1);
        revgraph[v-1].push_back(u-1);
    }
    
    for( int i = 0; i < n; i ++ ) 
        if( f[i] == 1 ) dfs1(i);
    for( int i = 0; i < n; i ++ )
        if( f[i] == 2 ) dfs2(i);
    
    for( int i = 0; i < n; i ++ )
        if( go1[i] && go2[i] ) 
            printf( "1\n" );
        else
            printf( "0\n" );
    
  
    return 0;
}
