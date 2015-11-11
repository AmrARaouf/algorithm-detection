//Language: MS C++


//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
int n, m;
int s, t;
int gr[ 2000 ][ 2000 ]; long long d[ 2000 ]; int adj[ 2000 ][ 2000 ], reach[ 2000 ];
long long gr2[ 2000 ][ 2000 ]; long long dist[ 2000 ]; int ad[ 2000 ][ 2000 ], rch[ 2000 ];
long long costs[ 2000 ], maxs[ 2000 ];
void diji1( int a ) {
    for( int i = 0; i < 2000; i ++ ) {
        d[ i ] = 99999999999999;
    }
    priority_queue < pair < long long, int > > q;
    q.push( make_pair( 0, a ) );
    dist[ a ] = 0;
    while( ! q.empty() ) {
        long long curD = - q.top().first, curi = q.top().second;
        q.pop();
        for( int i = 0; i < reach[ curi ]; i ++ ) {
            int curNgb = adj[ curi ][ i ];
            if( ( curD + gr[ curi ][ curNgb ] ) < d[ curNgb ] ) {
                d[ curNgb ] = curD + gr[ curi ][ curNgb ];
                //    cout << curD + gr[ curi ][ curNgb ] << '\n';
                q.push( make_pair( - ( curD + gr[ curi ][ curNgb ] ), curNgb ) );
            }
        }
    }
    return;
}
void diji2( int a ) {
    for( int i = 0; i < 2000; i ++ ) {
        dist[ i ] = 99999999999999;
    }
    priority_queue < pair < long long, int > > q;
    q.push( make_pair( 0, a ) );
    dist[ a ] = 0;
    while( ! q.empty() ) {
        long long curD = - q.top().first, curi = q.top().second;
        q.pop();
        for( int i = 0; i < rch[ curi ]; i ++ ) {
            int curNgb = ad[ curi ][ i ];
            if( ( curD + gr2[ curi ][ curNgb ] ) < dist[ curNgb ] ) {
                dist[ curNgb ] = curD + gr2[ curi ][ curNgb ];
                q.push( make_pair( - ( curD + gr2[ curi ][ curNgb ] ), curNgb ) );
            }
        }
    }
    return;
}
int main() {
    for( int i = 0; i < 2000; i ++ ) {
        for( int j = 0; j < 2000; j ++ ) {
            gr[ i ][ j ] = 1000000000;
        }
    }
    cin >> n >> m >> s >> t;
    s --;
    t --;

    int temp, temp1, temp2;

    for( int i = 0; i < m; i ++ ) {
        cin >> temp >> temp1 >> temp2;
        temp --; temp1 --;
        if( gr[ temp ][ temp1 ] == 1000000000 ) {
            adj[ temp ][ reach[ temp ] ] = temp1;
            reach[ temp ] ++;
            adj[ temp1 ][ reach[ temp1 ] ] = temp;
            reach[ temp1 ] ++;
        }
        gr[ temp ][ temp1 ] = gr[ temp1 ][ temp ] = min( gr[ temp ][ temp1 ], temp2 );
    }
    for( int i = 0; i < n; i ++ ) {
        cin >> maxs[ i ] >> costs[ i ];
    }
    for( int i = 0; i < n; i ++ ) {
        diji1( i );
        for( int j = 0; j < n; j ++ ) {
            gr2[ i ][ j ] = - 1;
            if( d[ j ] <= maxs[ i ] ) {
                gr2[ i ][ j ] = costs[ i ];
                ad[ i ][ rch[ i ] ] = j;
                rch[ i ] ++;
            }
        }
    }
    diji2( s );
    if( dist[ t ] == 99999999999999 ) {
        cout << - 1 << '\n';
        return 0;
    }
    cout << dist[ t ] << '\n';
    return 0;
}