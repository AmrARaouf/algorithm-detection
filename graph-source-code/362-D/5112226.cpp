//Language: GNU C++


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

typedef long long llint;

const int N = 100100;

int parent[ N ];

int n, q, m, p;

vector< int > graf[ N ];

struct par {
    int x;
    llint val;
    par( int _x = 0, llint _val = 0 ) {
        x = _x;
        val = _val;
    }
    inline bool friend operator <( const par &A, const par &B ) {
        if( A.val != B.val ) return A.val < B.val;
        return A.x < B.x;
    }
};

set< par > S;

llint HOW[ N ];
int comp;

int find( int x ) { return x == parent[ x ] ? x : parent[ x ] = find( parent[ x ] ); }

int x1 = -1, x2 = -1;

inline void load( ) {
    scanf( "%d %d %d %d", &n, &m, &p, &q );
    for( int i = 1; i <= n; i++ ) S.insert( par( i, 0 ) ), parent[ i ] = i;
    comp = n;
    for( int i = 0; i < m; i++ ) {
        int x, y, val;
        scanf( "%d %d %d", &x, &y, &val );
        x1 = x;
        x2 = y;
        x = find( x );
        y = find( y );
        if( x != y ) {
            S.erase( S.find( par( x, HOW[ x ] ) ) );
            S.erase( S.find( par( y, HOW[ y ] ) ) );
            parent[ y ] = x;
            S.insert( par( x, HOW[ x ] + HOW[ y ] + val ) );
            HOW[ x ] = HOW[ x ] + HOW[ y ] + val;
            comp--;
        }
        else {
            S.erase( S.find( par( x, HOW[ x ] ) ) );
            S.insert( par( x, HOW[ x ] + val ) );
            HOW[ x ] += val;
        }
    }
}

inline llint minic( const llint &A, const llint &B ) { return A < B ? A : B; }

inline void solve( ) {
   // printf( "comp == %d\n", comp );
    if( comp < q ) { printf( "NO\n" ); return; }
    if( ( comp == n && comp == q && p ) ){ printf( "NO\n" ); return; }
    if( comp - p > q ) { printf( "NO\n" ); return; }
   // for( set< par > :: iterator it = S.begin( ); it != S.end( ); it++ ) printf( "%d %d\n", it -> x, it -> val );
    
    printf( "YES\n" );
    while( p ) {
        if( comp == q ) {
            printf( "%d %d\n", x1, x2 );
            p--;
            continue;
        }
        int x = S.begin( ) -> x;
        llint val = S.begin( ) -> val;
        S.erase( S.begin( ) );
        int y = S.begin( ) -> x;
        llint val2 = S.begin( ) -> val;
        //printf( "dada %d %d\n", val, val2 );
        printf( "%d %d\n", x, y );
        parent[ y ] = x;
        S.erase( S.begin( ) );
        llint sol = minic( val + val2 + 1, 1000000000 ) + val + val2 ;
        S.insert( par( x, sol ) );
        HOW[ x ] = sol;
        x1 = x;
        x2 = y;
       // printf( "%d\n", HOW[ x ] );
      //  system( "pause" );
        p--;
        comp--;
       // for( set< par > :: iterator it = S.begin( ); it != S.end( ); it++ ) printf( "%d %d\n", it -> x, it -> val );
    }
   // while( p >= 1 ) printf( "%d %d\n", x1, x2 ), p--;
}

int main( void ) {
    load( );
    solve( );
   // system( "pause" );
    return 0;
}

            
    
