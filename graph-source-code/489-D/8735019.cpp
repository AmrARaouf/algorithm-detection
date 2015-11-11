//Language: GNU C++0x


#include <cstdio>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cstring>

#define pb push_back

const int MAX = 3014 ;

using namespace std;

vector < int > gr [ MAX ] ;
vector < int > din [ MAX ] ;
bitset < MAX > viz ;

int cnt [ MAX ] , numar [ MAX ] ;

int main(              )
{
    //freopen ( "D.in" , "r" , stdin ) ;
    //freopen ( "D.out" , "w" , stdout ) ;

    int n , m ;
    scanf ( "%d %d" ,&n ,&m ) ;
    for ( ; m ; -- m )
    {
        int x , y ;
        scanf ( "%d %d" , &x , &y ) ;
        gr [ x ].pb ( y ) ;
        cnt [ y ] ++ ;
        din [ y ].pb ( x ) ;
    }
    long long SOL = 0 ;
    for ( int i = 1 ; i <= n ; ++ i )
        if ( cnt [ i ] >= 2 )
        {
            memset ( numar , 0 , sizeof ( numar ) ) ;
            for ( auto x : din [ i ] )
                if ( cnt [ x ] >= 1 )
                for ( auto y : din [ x ] )
                    if ( y != i )
                    numar [ y ] ++ ;
            for ( int j = 1 ; j <= n ; ++ j )
                if ( numar [ j ] >= 2 ){
                    SOL = SOL + 1LL * ( numar [ j ] ) * ( numar [ j ] - 1 ) / 2 ;
            }
        }
    printf ( "%I64d\n" , SOL  ) ;
    return 0;
}
