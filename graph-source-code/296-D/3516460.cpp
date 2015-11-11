//Language: GNU C++


#include<stdio.h>
#include<string.h>
#define ll __int64
#define min(x,y) ((x)<(y)?(x):(y))

const int maxn = 1111 ;
int num[maxn] , vis[maxn] ;
ll l[maxn][maxn] , sum[maxn] ;
ll a[maxn][maxn] ;

int main ()
{
	int n , i , j , k ;
	scanf ( "%d" , &n ) ;
	for ( i = 1 ; i <= n ; i ++ )
		for ( j = 1 ; j <= n ; j ++ )
		{
			scanf ( "%I64d" , &a[i][j] ) ;
			l[i][j] = a[i][j] ;
		}
	for ( i = 1 ; i <= n ; i ++ ) scanf ( "%d" , &num[i] ) ;
	for ( k = n ; k >= 1 ; k -- )
	{
		int p = num[k] ;
		for ( i = 1 ; i <= n ; i ++ )
		{
			if ( !vis[i] ) continue ;
			for ( j = 1 ; j <= n ; j ++ )
			{
				if ( !vis[j] ) continue ;
				l[i][p] = min ( l[i][p] , l[i][j] + a[j][p] ) ;
			}
		}
		for ( i = 1 ; i <= n ; i ++ )
		{
			if ( !vis[i] ) continue ;
			for ( j = 1 ; j <= n ; j++ )
			{
				if ( !vis[j] ) continue ;
				l[p][i] = min ( l[p][i] , l[j][i] + a[p][j] ) ;
			}
		}
		vis[p] = 1 ;
	/*	for ( i = 1 ; i <= n ; i ++ )
		{
			if ( !vis[i] ) continue ;
			for ( j = 1 ; j <= n ; j ++ )
			{
				if ( !vis[j] ) continue ;
				printf ( "l[%d][%d] = %I64d\n" , i , j , l[i][j] ) ;
			}
		}*/
		for ( i = 1 ; i <= n ; i ++ )
		{
			if ( !vis[i] ) continue ;
			for ( j = 1 ; j <= n ; j ++ )
			{
				if ( !vis[i] ) continue ;
				l[i][j] = min ( l[i][j] , l[i][p] + l[p][j] ) ;
			}
		}
		for ( i = 1 ; i <= n ; i ++ )
		{
			if ( !vis[i] ) continue ;
			for ( j = 1 ; j <= n ; j ++ )
			{
				if ( !vis[j] ) continue ;
				sum[k] += l[i][j] ;
			}
		}
	}
	for ( i = 1 ; i <= n ; i ++ ) printf ( "%I64d " , sum[i] ) ;
}
