//Language: GNU C++


// General Coding Template by rabbit125 @2014/02/13
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <cstring>
#include <cmath>
#include <map>
#include <stack>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <climits>
#include <bits/stdc++.h>
/* Define Useful Vars. */
#define ULL  unsigned long long
#define LLI  long long
#define BIT         17
#define INF 1000000000
#define MOD 1000000007
#define STRMAX    1000
#define MAX     120000
using namespace std ;
int e[ MAX ] , p[ MAX ] ;
int GetP( int a )
{
  while( p[a] != 0 )
    a = p[a] = GetP( p[a] ) ;
  return a ;
}
int main( )
{
    int n , m ;
    while( ~scanf( "%d%d" , &n , &m ) )
    {
      int K , I ;
      int x , y , py ;
      vector <int> q , curr_p ;
      memset( p , 0 , sizeof( p ) ) ;
      memset( e , 0 , sizeof( e ) ) ;
      for( int i = 0 ; i < m ; i++ )
      {
        scanf( "%d" , &K ) ;
        if( K == 1 )
        {
          scanf( "%d%d" , &x , &y ) ;
          e[ x ] = y ;
          // Both ok..
          p[ x ] = y ;
          //p[ x ] = GetP( y ) ;
        }
        else if( K == 2 )
        {
          scanf( "%d" , &x ) ;
          q.push_back( x ) ;
          curr_p.push_back( GetP( x ) ) ;
        }
        else if( K == 3 )
        {
          scanf( "%d%d" , &x , &I ) ;
          y = q[ I-1 ] ;
          py = curr_p[ I-1 ] ;
          while( y != py )
          {
            if( y == x )
              break ;
            y = e[y] ;
          }
          if( y == x )
            printf( "YES\n" ) ;
          else
            printf( "NO\n" ) ;
        }
      }
    }
    return 0 ;
}
/*
4 9
1 4 3
2 4
3 3 1
1 2 3
2 2
3 1 2
1 3 1
2 2
3 1 3
*/
/*
test output data
*/
