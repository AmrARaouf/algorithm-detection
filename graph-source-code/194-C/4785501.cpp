//Language: MS C++


#include <stdio.h>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm> 
#include <queue>
using namespace std;
int T = 0;

typedef  vector < vector < int > > table;
int x[4] = { 0 , 0 , -1 , 1 };
int y[4] = { -1 , 1 , 0 , 0 };

table  time ( 52 , vector < int > ( 52 , 0 ) );;
table up ( 52 , vector < int > ( 52 , 0 ) );;
 bool dfs ( pair < int , int > v , pair < int , int > p , const table &graph , bool root )
 { 
     T++;
     int count_child = 0;
     up [ v.first ][ v.second ] = time [ v.first ][ v.second ] = T;
     bool res = false;
     for ( int j = 0; j < 4; ++j )
     {
             if ( graph [ v.first + x[j] ][ v.second + y[j] ] == 1 )
             {
                 pair < int , int > u = make_pair ( v.first + x[j] , v.second +  y[j] );
                 if (u == p)
                     continue;
                 if ( time[u.first][u.second] != 0 )
                     up[ v.first ][ v.second ] = min ( up [ v.first ][ v.second ] , time [ u.first ][ u.second ] );
                 else
                 {
                     bool f = dfs ( u , v , graph , false );
                     if (f)
                         res = true;
                     count_child++;
                     up [ v.first ][ v.second ] = min ( up[ v.first ][ v.second ] , up [ u.first ][ u.second ] );
                     if (!root && up[u.first][u.second] >= time [v.first][v.second] )
                        return true;
                 }
             }
      }
      if ( root && count_child > 1 )
        return true;
      return res;
     
     
 }
     
int main()
{
    int n;
    int m;
    cin >> n;
    cin >> m;
    table v ( n+2 , vector < int > ( m+2 , 0 ) );
    for ( int i = 1; i <= n; ++i )
    {
        for ( int j = 1; j <= m; ++j )
        {
            char ch;
            cin >> ch;
            if ( ch == '#' )
                v[i][j] = 1;
            else v[i][j] = 0;
        }
    }
    int ans = -1;
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= m; ++j )
        {
            if (v[i][j] == 0)
                continue;
            if (ans == -1 && time[i][j] == 0 ) {
                if (dfs ( make_pair( i , j ) , make_pair ( -1 , -1 ) , v , true )) {
                    ans = 1;

                }
                else {
                    ans = 2;
                }
            }
        }
    if (T <= 2) {
        ans = -1;
    }
    cout << ans << "\n";
    return 0;
}