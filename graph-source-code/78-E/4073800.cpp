//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <stack>
using namespace std;

#define mod 100000007
#define INF 0x3f3f3f3f
#define LL long long
#define mxn 350
#define mxe 30000

int id[15][15], die[15][15], dit[15][15], n, cnt;
char s1[15][15], s2[15][15];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
struct node {
    int x, y;
    node(){}
    node(int x, int y) : x(x), y(y) {}
};

int dis[mxn], pre[mxn], gap[mxn], arc[mxn], f[mxe], cap[mxe];
int first[mxn], next[mxe], vv[mxe], e;
int sap( int s, int t, int n )
{
    int q[mxn], j, mindis, ans = 0, front = 0, rear = 1, u, v, low;
    bool found, vis[mxn];
    memset( dis, 0, sizeof(dis) );
    memset( gap, 0, sizeof(gap) );
    memset( vis, 0, sizeof(vis) );
    memset( arc, 0, sizeof(arc) );
    memset( f, 0, sizeof(f) );
    q[0] = t; vis[t] = true; dis[t] = 0; gap[0] = 1;
    while( front < rear ) {
        u = q[front++];
        int i = first[u];
        while( i != -1 ) {
            v = vv[i];
            if( !vis[v] ) {
                dis[v] = dis[u] + 1;
                vis[v] = true;
                q[rear++] = v;
                gap[dis[v]]++;
                arc[v] = first[v];
            }
            i = next[i];
        }
    }
    u = s; low = INF; pre[s] = s;
    while( dis[s] < n ) {
        found = false;
        for( int &i = arc[u];i != -1;i = next[i] )
        if( dis[vv[i]] == dis[u]-1 && cap[i] > f[i] ) {
            found = true; v = vv[i];
            low = low < cap[i]-f[i]? low : cap[i]-f[i];
            pre[v] = u; u = v;
            if( u == t ) {
                while( u - s ) {
                    u = pre[u];
                    f[arc[u]] += low;
                    f[arc[u]^1] -= low;
                }
                ans += low; low = INF;    
            }
            break;
        }
        if( found )
            continue;
        mindis = n;
        for(int i = first[u]; i != -1; i = next[i] )
            if( mindis > dis[vv[i]] && cap[i] > f[i] ) {
                mindis = dis[vv[j = i]];
                arc[u] = i;
            };
        gap[dis[u]]--;
        if( gap[dis[u]] == 0 )
            return ans;
        dis[u] = mindis + 1;
        gap[dis[u]]++;
        u = pre[u];
    }
    return ans;
}

inline void add(int u,int v,int c)
{
    next[e] = first[u], vv[e] = v, cap[e] = c, first[u] = e++;
    next[e] = first[v], vv[e] = u, cap[e] = 0, first[v] = e++;
}

void init( int t ) {
    memset( die, -1, sizeof(die) );
    queue<node> q;
    for( int i = 0; i < n; ++i )
        for( int j = 0; j < n; ++j )
            if( s1[i][j] == 'Z' )
                die[i][j] = 0, q.push( node(i, j) );
    while( !q.empty() ) {
        node u = q.front(); q.pop();
        if( die[u.x][u.y] == t )
            continue;
        for( int i = 0; i < 4; ++i ) {
            int fx = u.x + dx[i];
            int fy = u.y + dy[i];
            if( fx >= 0 && fx < n && fy >= 0 && fy < n )
                if( s1[fx][fy] != 'Y' && die[fx][fy] == -1 )
                    die[fx][fy] = die[u.x][u.y] + 1, q.push( node(fx, fy) );
        }
    }
}

void bfs( int x, int y, int t ) {
    memset( dit, -1, sizeof(dit) );
    queue<node> q;
    dit[x][y] = 0;
    q.push( node(x, y) );
    while( !q.empty() ) {
        node u = q.front(); q.pop();
        if( s2[u.x][u.y] > '0' && s2[u.x][u.y] <= '9' )
            add( id[x][y], id[u.x][u.y] + cnt, 1000 );
        if( dit[u.x][u.y] == t || dit[u.x][u.y] >= die[u.x][u.y] && die[u.x][u.y] != -1 )
            continue;
        for( int i = 0; i < 4; ++i ) {
            int fx = u.x + dx[i];
            int fy = u.y + dy[i];
            if( fx >= 0 && fx < n && fy >= 0 && fy < n )
                if( s2[fx][fy] != 'Y' && dit[fx][fy] == -1 )
                    if( die[fx][fy] == -1 || die[fx][fy] >= dit[u.x][u.y] + 1 )
                        dit[fx][fy] = dit[u.x][u.y] + 1, q.push( node(fx, fy) );
        }
    }
}

int main()
{
    int t;
    memset( first, -1, sizeof(first) );
    scanf( "%d%d", &n, &t );
    for( int i = 0; i < n; ++i )
        for( int j = 0; j < n; ++j )
            id[i][j] = ++cnt;
    int S = 0, T = cnt * 2 + 1;
    for( int i = 0; i < n; ++i ) {
        scanf( "%s", s1[i] );
        for( int j = 0; j < n; ++j )
            if( s1[i][j] > '0' && s1[i][j] <= '9' )
                add( S, id[i][j], s1[i][j] - '0' );
    }
    for( int i = 0; i < n; ++i ) {
        scanf( "%s", s2[i] );
        for( int j = 0; j < n; ++j )
            if( s2[i][j] > '0' && s2[i][j] <= '9' )
                add( id[i][j] + cnt, T, s2[i][j] - '0' );
    }
    init( t );
    for( int i = 0; i < n; ++i )
        for( int j = 0; j < n; ++j )
            if( s1[i][j] > '0' && s1[i][j] <= '9' )
                bfs( i, j, t );
    add( S, T, 0 );
    printf( "%d\n", sap(S, T, T) );
    return 0;
}