//Language: GNU C++


#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<map>
#include<queue>
using namespace std;
#define M 1000007
#define N 210
#define ll long long

char s1[15][15], s2[15][15];
int id[15][15], cnt;
int s, t, T, n;
int xz, yz;
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
bool inside( int x, int y )
{
        return x >= 0 && y >= 0 && x < n && y < n && s1[x][y] >= '0' && s1[x][y] <= '9';
}

int vv[M], nxt[M], cap[M], h[N], e;
int pre[N], vis[N];
void add( int u, int v, int c )
{
        vv[e] = v, nxt[e] = h[u], cap[e] = c, h[u] = e++;
        vv[e] = u, nxt[e] = h[v], cap[e] = 0, h[v] = e++;
}

int q1[M], q2[M], h1, h2, t1, t2;
int v1[15][15], v2[15][15];
void bfs( int x, int y )
{
        if( s2[x][y] != 0 ){
                add( id[x][y]+cnt, t, s2[x][y] - '0' );
        }
        if( s1[x][y] == '0' ) return ;
        add( s, id[x][y], s1[x][y] - '0' );
        if( s2[x][y] != 0 ){
                add( id[x][y], id[x][y]+cnt, 10 );
        }

        int sx = x, sy = y;
        h1 = t1 = h2 = t2 = 0;
        q1[t1++] = x, q1[t1++] = y;
        q2[t2++] = xz, q2[t2++] = yz;

        int up1 = t1, up2 = t2;
        memset( v1, -1, sizeof(v1) );
        memset( v2, -1, sizeof(v2) );
        v1[x][y] = v2[xz][yz] = 0;

        int x1, y1;
        while( h1 < t1 ){

                while( h1 < up1 ){
                        x = q1[h1++], y = q1[h1++];
                        if( v2[x][y] >= 0 ) continue;
                        for( int i = 0; i < 4; ++i ){
                                x1 = x + dir[i][0];
                                y1 = y + dir[i][1];
                                if( inside( x1, y1 ) && v1[x1][y1] < 0 ){
                                        v1[x1][y1] = v1[x][y] + 1;
                                        if( v1[x1][y1] > T ) break;
                                        if( v2[x1][y1] >= 0 ) continue;
                                        q1[t1++] = x1, q1[t1++] = y1;

                                        if( s2[x1][y1] != '0' ){
                                                add( id[sx][sy], id[x1][y1] + cnt, 10 );
                                        }
                                }
                        }
                }
                up1 = t1;

                while( h2 < up2 ){
                        x = q2[h2++], y = q2[h2++];

                        for( int i = 0; i < 4; ++i ){
                                x1 = x + dir[i][0];
                                y1 = y + dir[i][1];
                                if( inside( x1, y1) && v2[x1][y1] < 0 ){
                                        v2[x1][y1] = v2[x][y] + 1;
                                        q2[t2++] = x1, q2[t2++] = y1;
                                }
                        }
                }
                up2 = t2;
        }
}

bool bfs()
{
        queue<int> q;
        memset( vis, 0,  sizeof(vis) );
        vis[s] = 1;

        q.push( s );
        int u, v;
        while( !q.empty() ){
                u = q.front(), q.pop();
                for( int i = h[u]; i+1; i = nxt[i] ) if( cap[i] > 0 && !vis[vv[i]]){
                        v = vv[i];
                        pre[v] = i;
                        if( v == t ) return 1;
                        vis[v] = 1, q.push( v );

                }
        }
        return 0;
}
int maxFlow()
{
        int ans = 0, mi, v;

        while( bfs() ){
                mi = 10000000;
                v = t;
                while( v - s ){
                        v = pre[v];
                        mi = min( mi, cap[v] );
                        v = vv[v^1];
                }
                ans += mi;

                v = t;
                while( v - s ){
                        v = pre[v];
                        cap[v] -= mi;
                        cap[v^1] += mi;
                        v = vv[v^1];
                }
        }
        return ans;
}
int main()
{
       // freopen( "a.in", "r", stdin );
        //freopen( "a.out", "w", stdout );
        cin>>n>>T;
        for( int i = 0; i < n; ++i ) cin>>s1[i];
        for( int i = 0; i < n; ++i ) cin>>s2[i];
        memset( h, -1, sizeof(h) ); e = 0;
        memset( id, -1, sizeof(id) );
        cnt = 0;
        for( int i = 0; i < n; ++i )
                for( int j = 0; j < n; ++j ){
                        if( s1[i][j] == 'Z' ) xz = i, yz = j;
                        else if( inside( i, j ) ) id[i][j] = ++cnt;
                }
        s = 0, t = 2*cnt + 1;
        for( int i = 0; i < n; ++i )
                for( int j = 0; j < n; ++j ) if( inside( i, j ) ) {
                        bfs( i, j );
                }

        cout<<maxFlow()<<endl;
}
