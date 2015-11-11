//Language: GNU C++


/*
ID: freezuo2
PROG: ride
LANG: C++            
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

#define maxR 110
#define M 100010
#define N 35
#define inf 0x3f3f3f3f

int vv[M<<1], nxt[M<<1], cc[M<<1], h[M], e = 0;
vector<int> vec[M];
int col[M];
int n, m, k, s[M];

int vis[M];
int dfs( int u, int x )
{
	int cnt = 1;
	vis[u] = x;
	int v;
	for( int i = h[u]; i+1; i = nxt[i] ) if( !cc[i] ){
		v = vv[i];
		if(  vis[v] ) continue;
		cnt += dfs( v, x );
	}
	return cnt;
}

int check()
{
	int cnt = 0;
	for( int i = 1; i <= n; ++i ) if( !vis[i] )
		dfs( i, ++cnt );
	int t = 1;
	for( int i = 1; i <= k; ++i ){
		cnt = 0;
		
		cnt = vis[t];
		while( t <= s[i] ){
			if( vis[t] != cnt ) return 0;
			++t;
		}
	}
	return 1;
}
int dis[510][510];
int main()
{
	scanf( "%d%d%d", &n, &m, &k );
	int t = 1;
	for( int i = 1; i <= k; ++i ){
		scanf( "%d", &s[i] );
		s[i] += s[i-1];
		while( t <= s[i] )
			col[t++] = i;
	}
	memset( h, -1, sizeof(h) );
	int u, v, c;
	for( int i = 0; i < m; ++i ){
		scanf( "%d%d%d", &u, &v, &c );
		vv[e] = v, nxt[e] = h[u], cc[e] = c, h[u] = e++;
		vv[e] = u, nxt[e] = h[v], cc[e] = c, h[v] = e++;
	}
	if( !check() ){
		puts( "No" );
		return 0;
	}
	memset( h, -1, sizeof(h) ); e = 0;
	memset( dis, 0x3f, sizeof(dis) );
	for( int i = 0; i < m*2; ++i ){
		v = vv[i], u = vv[i^1];
		if( col[v] != col[u] ){
			v = col[v], u = col[u];
			dis[v][u] = dis[u][v] = min( dis[u][v], cc[i] );
		}
	}
	for( int i = 1; i <= k; ++i ) dis[i][i] = 0;
	for( int x = 1; x <= k; ++x )
		for( int i = 1; i <= k; ++i ) if( dis[i][x] != inf )
			for( int j = 1; j <= k; ++j ) if( dis[x][j] != inf )
				dis[i][j] = min( dis[i][j], dis[i][x] + dis[x][j] );
	puts( "Yes" );
	for( int i = 1; i <= k; ++i, puts( "" ) )
		for( int j = 1; j <= k; ++j ){
			if( dis[i][j] == inf ) dis[i][j] = -1;
			printf( "%d ", dis[i][j] );
		}

}