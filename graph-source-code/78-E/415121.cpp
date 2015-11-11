//Language: GNU C++


#include <iostream>
#include<cstdio>
#include<string.h>
#include<vector>

#define x first
#define y second
#define N 105
#define INF 0xfffffff
using namespace std;

struct lab{
    int x ;
    int y ;
    lab( int x1 , int y1  ){
        x = x1 ; y = y1 ;
    }
};


struct ed{
    int v ;
    int c ;
    int next ;
}edge[2 * N * N] ;

vector< lab > labs ;

int mov[4][2] = { { 1 , 0 } , { -1 , 0 } , { 0 , 1 } , { 0 , -1 }  } ;

char map[2][15][15] ;
int hash[15][15] ;

int n , t , cnt , h[3 * N] , qu[N][2 * N] , ee  , path[ 105 ][ 105 ] , s , en , high[ 3 * N ] , gap[ 3 * N ];
int mark[N][15][15] , barrier[15][15] , head[N] , tail[N] ;
pair< int , int> mal ;

inline void add( int u , int v , int c ){
    edge[ee].c =c ;
    edge[ee].v = v ;
    edge[ee].next = h[u] ;
    h[u] = ee ++ ;
    swap( u , v ) ;
    edge[ee].c = 0 ;
    edge[ee].v = v ;
    edge[ee].next = h[u] ;
    h[u] = ee ++ ;
}

void graph(){
    memset( h , -1 , sizeof( h ) ) ;
     for( int i = 0 ; i < cnt ; i ++ ){
        for( int j = 0 ; j < cnt ; j ++ ){
            if( path[i][j] ){
                add( i + 1 , j + cnt + 1 , INF ) ;
            }
        }
    }
    for( int i = 0 ; i < n ; i ++ ){
        for( int j = 0 ; j < n ; j ++ ){
            if( hash[i][j] != -1 ){
                add( 0 , hash[i][j] + 1 , map[0][i][j] - '0' ) ;
                add( hash[i][j] + 1 + cnt , 2 * cnt + 1 , map[1][i][j] - '0' ) ;
            }
        }
    }
}

int dfs( int pos , int c ){
    if( pos == en ){
        return c ;
    }
    int sum = c , minh = 2 * cnt + 2 ;
    for( int j = h[pos] ; j != -1 ; j = edge[j].next ){
        if( edge[j].c > 0 ){
            if( high[pos] == high[edge[j].v ] + 1 ){
                int d = min( edge[j].c , sum ) ;
                d = dfs( edge[j].v , d ) ;
                sum -= d ;
                edge[j].c -= d ;
                edge[j^1].c += d ;
                if( sum == 0 || high[s] >= 2 * cnt + 2 ){
                    return c - sum ;
                }
            }
            minh = minh > high[ edge[j].v ] ? high[ edge[j].v ] : minh ;
        }
    }
    if( sum == c ){
        gap[ high[pos] ] -- ;
        if( gap[ high[pos] ] <= 0 ){

            high[s] =  2 * cnt + 2 ;
        }
        high[ pos ] = minh + 1;
        gap[ high[pos] ] ++ ;
    }
    return c - sum ;
}

int sap(){
    int sum = 0 ;
    memset( high , 0 , sizeof( high  ) ) ;
    memset( gap , 0 , sizeof( gap ) ) ;
    gap[0] = 2 * cnt + 2 ;
    while( high[s] < 2 * cnt + 2 ){
        sum += dfs( s , INF ) ;
    }
    return sum ;
}

void bfs( int d , int c ){
    int x = labs[d].x ;
    int y = labs[d].y ;
    int tmp = hash[x][y] ;
    while( head[d] != tail[d] && mark[d][ qu[d][ head[d]] ][ qu[d][head[d] + 1] ] != c ){
        x = qu[d][head[d] ++] ;
        y = qu[d][head[d] ++] ;
        if( barrier[x][y] != -1 ){
            continue ;
        }
        for( int i = 0 ; i < 4 ; i ++ ){
            int x1 = x + mov[i][0] ;
            int y1 = y + mov[i][1] ;
            if( x1 < 0 || x1 >= n || y1 < 0 || y1 >= n ){
                continue ;
            }
            if( map[0][x1][y1] == 'Z' || map[0][x1][y1] == 'Y' || barrier[x1][y1] != -1 || mark[d][x1][y1] != -1 ){
                continue ;
            }
            else{
                mark[d][x1][y1] = mark[d][x][y] + 1 ;
                int tmp2 = hash[x1][y1] ;
                path[tmp][tmp2] = 1 ;
                qu[d][tail[d] ++] = x1 ;
                qu[d][tail[d] ++] = y1 ;
            }
        }
    }
}

void bfs1( int c ){
    int qu[2 * N] ;
    qu[0] = mal.x ;
    qu[1] = mal.y ;
    int head = 0 ;
    int tail = 2 ;
    barrier[mal.x][mal.y] = 0 ;
    while( head != tail ){
        int x = qu[head ++] ;
        int y = qu[head ++] ;
        for( int i = 0 ; i < 4 ; i ++ ){
            int x1 = x + mov[i][0] ;
            int y1 = y + mov[i][1] ;
            if( x1 < 0 || x1 >= n || y1 < 0 || y1 >= n ){
                continue ;
            }
            if( map[0][x1][y1] == 'Z' || map[0][x1][y1] == 'Y' || barrier[x1][y1] != -1 ){
                continue ;
            }
            barrier[x1][y1] = barrier[x][y] + 1 ;
            if( barrier[x1][y1] != c ){
                qu[tail ++] = x1 ;
                qu[tail ++] = y1 ;
            }
        }
    }
}

void predeal(){
    memset( barrier , -1 , sizeof( barrier ) ) ;
    memset( mark , -1 , sizeof( mark ) ) ;
    for( int j = 0 ; j < labs.size() ; j ++ ){
        int x = labs[j].x ;
        int y = labs[j].y ;
        qu[ hash[x][y] ][0] = x ;
        qu[ hash[x][y] ][1] = y ;
        mark[ hash[x][y] ][x][y] = 0 ;
        tail[j] = 2 ;
        head[j] = 0 ;
    }
    for( int i = 0 ; i < t ; i ++ ){
        for( int j = 0 ; j < labs.size() ; j ++ ){
            bfs( j , i + 1 ) ;
        }
        memset( barrier , -1 , sizeof( barrier ) ) ;
        bfs1( i + 1 ) ;
    }
    for( int i = 0 ; i < cnt ; i ++ ){
        path[i][i] = 1 ;
    }
}


int main()
{
    while( scanf( "%d%d" , &n , &t ) != EOF ){
        memset( hash , -1 , sizeof( hash ) ) ;
        ee = 0 ;
        cnt = 0 ;
        labs.clear() ;
        for( int i = 0 ; i < 2 ; i ++ ){
            for( int j = 0 ; j < n ; j ++ ){
                scanf( "%s" , map[i][j] ) ;
            }
        }
        for( int i = 0 ; i < n ; i ++ ){
            for( int j = 0 ; j < n ; j ++ ){
                if( map[0][i][j] == 'Z' ){
                    mal.x = i ;
                    mal.y = j ;
                    continue ;
                }
                if( map[0][i][j] >= '0' && map[0][i][j] <= '9' ){
                    lab a( i , j ) ;
                    labs.push_back( a ) ;
                    hash[i][j] = cnt ++ ;
                   // cout<<i<<" "<<j<<" "<<cnt - 1<<endl;
                }
            }
        }
        s = 0 ; en = 2 * cnt + 1 ;
        memset( path , 0 , sizeof( path ) ) ;
        predeal() ;
        //cout<<"sddfasdfasfasdf"<<endl;
        graph() ;
//        for( int i = 0 ; i < cnt ; i ++ ){
//            for( int j = 0 ; j < cnt ; j ++ ){
//                cout<<path[i][j]<<" " ;
//            }
//            cout<<endl;
//        }
        printf( "%d\n" , sap() ) ;
    }
    return 0;
}
