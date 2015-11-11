//Language: GNU C++


#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<set>
using namespace std ;
set<pair<int, int> > s ;
int a[1000005] ;
int main ()
{
	int n , i , m ;
	int x , y , max , k , j ;
	scanf ( "%d%d" , &n , &m ) ;
	for ( i = 1 ; i <= n ; i ++ )
	{
		scanf ( "%d" , a + i ) ;
		s.insert ( make_pair ( a[i] , a[i] ) ) ;
	}
	while ( m -- )
	{
		scanf ( "%d%d" , &x , &y ) ;
		s.insert ( make_pair ( a[x] , a[y] ) ) ;
		s.insert ( make_pair ( a[y] , a[x] ) ) ;
	}
	i = 0 ;
	for ( set<pair<int,int> >::iterator it = s.begin() ; it != s.end() ; it ++ )
		a[++i] = (*it).first ;
	int ans = 1 ;
	k = 1 ;
	int p = a[1] ;
	for ( j = 2 ; j <= i ; j++ )
	{
		if ( a[j] == a[j-1] )
		{
			k ++ ;
			if ( k > ans )
			{
				ans = k ;
				p = a[j] ;
			}
		}
		else k = 1 ;
	}
	printf ( "%d\n" , p ) ;
}