//Language: GNU C++


#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <stdlib.h>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <numeric>
#include <utility>
#include <deque>
#include <stack>
#include <bitset>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <limits>
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;
#define MAX 105
#define INF 9999999
int ady[MAX][MAX] , V ,E;

void Init(){
    for(int i = 0 ; i < V ; ++i ){
         for(int j = 0 ; j < V ; ++j ){
                 ady[ i ][ j ] = INF;
         }
        ady[ i ][ i ] = 0;
    }
}

void floyd(){
    for(int k = 0 ; k < V ; ++k ){
        for(int i = 0 ; i < V ; ++i ){
             for(int j = 0 ; j < V ; ++j ){
                    int t = ady[ i ][ k ] + ady[ k ][ j ];
                    if( t < ady[ i ][ j ] ){
                        ady[ i ][ j ] = t;
                    }
             }
        }
    }
}

double table[ MAX ][ MAX ];

int main(){
    int u , v , i , j , cnt , k;
    scanf("%d %d" , &V , &E );
    Init();
    while( E-- > 0 && scanf("%d %d" , &u , &v )){
        u--; v--;
        ady[ u ][ v ] = ady[ v ][ u ] = 1;
        table[ u ][ v ] = table[ v ][ u ] = 1;
    }
    floyd();
    int shortest = ady[ 0 ][ V - 1 ];
    for( k = 0 ; k < V ; ++k )
        for( i = 0 ; i < V ; ++i )
            for( j = 0 ; j< V ; ++j )
                if( ady[ i ][ k ] + ady[ k ][ j ] == ady[ i ][ j ] ) table[ i ][ j ] += table[ i ][ k ] * table[ k ][ j ];

    double maxi = 1.0;
    for( i = 1 ; i < V - 1 ; ++i ){
        if( ady[ 0 ][ i ] + ady[ i ][ V - 1 ] == shortest )
            maxi = max( maxi , 2 *  table[ 0 ][ i ] * table[ i ][ V - 1 ]  / table[ 0 ][ V - 1 ] );
    }
    printf("%.12lf\n" , maxi );

    return 0;
}
