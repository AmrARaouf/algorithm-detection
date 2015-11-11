//Language: GNU C++


#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <set>
#include <map>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <math.h>
#include <iomanip>
using namespace std;

#define FOR0(i,n) for( i = 0 ; i < n ; i++ )
#define FOR1(i,n) for( i = 1 ; i <= n ; i++ )
#define sys_p system( "pause" )
#define End return 0
#define pb push_back 
#define mp make_pair

ifstream Cin("input.txt");
ofstream Cout( "output.txt" );    

typedef long long ll ;

struct solve
{
       ll a, b, c ;
};

struct way
{
       ll a, b ;
};

bool operator < ( way a, way b )
{
     return a.a < b.a ;
}

main()
{ 
      ll n, m, i, j, k, d[201][201], INF = (ll)1e12 ;
      
      FOR0( i, 201 )
        FOR0( j, 201 )
          d[i][j] = ( i == j ? 0 : INF ) ;
      
      cin >> n >> m ;
      vector < solve > r(m) ;
      FOR0( i, m )
      {
        cin >> r[i].a >> r[i].b >> r[i].c ;
        r[i].a -- ; r[i].b -- ; 
        d[ r[i].a ][ r[i].b ] = d[ r[i].b ][ r[i].a ] = r[i].c ;
      }
      FOR0( k, n )
        FOR0( i, n )
          FOR0( j, n )
            d[i][j] = min( d[i][j], d[i][k] + d[k][j] ) ;
      
      //FOR0( i, n )
      //  FOR0( j, n )
      //    cout << i << " " << j << " " << d[i][j] << endl ;
          
      vector < way > w(n) ;
      
      double ans = (double)INF ;
      ll M ;
      
      FOR0( i, m )
      {
           ll a = r[i].a, b = r[i].b, c = r[i].c ;
           FOR0( j, n )
           {
                 w[j].a = d[a][j] ;
                 w[j].b = d[b][j];
           }
           sort( w.rbegin(), w.rend() ) ;
           M = w[0].b ; ans = min( ans, (double)w[0].a ) ;
           //cout << M << " " << ans << endl ;
           FOR1( j, n-1 )
           {
                 if( w[j].a + c > M && M + c > w[j].a )
                   ans = min( ans, 0.5 * ( w[j].a + c + M ) ) ;
                 else
                   ans = min( ans, (double)max( w[j].a, M ) ) ;
                 M = max( M, w[j].b ) ;
           }
      }
      
      printf( "%.10f", ans ) ;
} 
