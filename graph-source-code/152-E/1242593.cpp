//Language: MS C++


#include <string>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
#define MP(A,B) make_pair(A,B)

int m[101][101], N, M, K;
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
char b[101][101];
struct Map
{
	int cost, n, a, b;
	Map(int _c, int _n, int _a, int _b):cost(_c),n(_n),a(_a),b(_b){};
	Map(){};
};
Map dp[1<<7][101][101];

void dfs( int i, int j, int mask )
{
	b[i][j] = 'X';
	if( dp[mask][i][j].n == 1 )
	{
		dfs( i, j, dp[mask][i][j].a );
		dfs( i, j, dp[mask][i][j].b );
	}
	else if( dp[mask][i][j].n == 2 )
		dfs( dp[mask][i][j].a, dp[mask][i][j].b, mask );
}

int main()
{
#if _MSC_VER == 1500
	//freopen( "..\\in.txt", "r", stdin );
#endif
	scanf( "%d%d%d", &N, &M, &K );
	for( int i = 0; i < N; ++ i )
		for( int j = 0; j < M; ++ j )
			scanf( "%d", &m[i][j] );
	for( int msk = 0; msk < ( 1 << 7 ); ++ msk )
		for( int i = 0; i < N; ++ i )
			for( int j = 0; j < M; ++ j )
				dp[msk][i][j].cost = 1<<20, dp[msk][i][j].n = 0;
	for( int i = 0; i < K; ++ i )
	{
		int x, y;
		scanf( "%d%d", &x, &y );
		x --, y --;
		dp[1<<i][x][y].cost = m[x][y];
	}
	for( int mask = 0; mask < ( 1 << 7 ); ++ mask )
	{
		for( int i = 0; i < N; ++ i )
			for( int j = 0; j < M; ++ j )
				for( int sub = mask; sub > 0; sub = mask & ( sub - 1 ) )
				{
					int c = dp[sub][i][j].cost + dp[mask ^ sub][i][j].cost - m[i][j];
					if( dp[mask][i][j].cost > c )
						dp[mask][i][j] = Map(c, 1, sub, mask ^ sub);
				}
		for( int t = 0; t < N * M; ++ t )
		{
			for( int i = 0; i < N; ++ i )
				for( int j = 0; j < M; ++ j )
					for( int k = 0; k < 4; ++ k )
					{
						int ii = i + dir[k][0], jj = j + dir[k][1];
						int c = dp[mask][i][j].cost + m[ii][jj];
						if( c < dp[mask][ii][jj].cost )
							dp[mask][ii][jj] = Map(c, 2, i, j);
					}
		}
	}
	int ansc = 1<<30, ansi, ansj;
	for( int i = 0; i < N; ++ i )
		for( int j = 0; j < M; ++ j )
			if( dp[(1<<K)-1][i][j].cost < ansc )
				ansc = dp[(1<<K)-1][i][j].cost, ansi = i, ansj = j;
	for( int i = 0; i < N; ++ i )
		for( int j = 0; j < M; ++ j )
			b[i][j] = '.';
	dfs( ansi, ansj, (1<<K)-1 );
	printf( "%d\n", ansc );
	for( int i = 0; i < N; ++ i )
	{
		for( int j = 0; j < M; ++ j )
			printf( "%c", b[i][j] );
		printf( "\n" );
	}
	return 0;
}