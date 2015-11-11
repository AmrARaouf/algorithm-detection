//Language: GNU C++


#include <cstdio>
#include <vector>

using namespace std;

const int inf = 10000;

int N, M;
int dist[110][110], A[1000], B[1000];

long long pwn[1000], numPaths[110][110];

vector < int > v[101];

inline int floydWarshall(){

    for ( int k = 0; k < N; ++k ){
        for ( int i = 0; i < N; ++i ){
            for ( int j = 0; j < N; ++j ){
                if ( dist[i][k] + dist[k][j] == dist[i][j] ){ numPaths[i][j] += ( long long ) numPaths[i][k] * numPaths[k][j]; }
                if ( dist[i][k] + dist[k][j] < dist[i][j] ){ dist[i][j] = dist[i][k] + dist[k][j]; numPaths[i][j] = ( long long ) numPaths[i][k] * numPaths[k][j]; }
            }
        }
    }

}

int main( void ){

    for ( int i = 0; i <= 100; ++i ){
        for ( int j = 0; j <= 100; ++j ) dist[i][j] = inf;
        dist[i][i] = 0;
    }

    scanf( "%d%d", &N, &M );
    for ( int i = 0; i < M; ++i ){
        int a, b; scanf( "%d%d", &a ,&b ); --a; --b;
        dist[a][b] = dist[b][a] = 1;
        ++numPaths[a][b]; ++numPaths[b][a];
        v[a].push_back( i ); v[b].push_back( i );
        A[i] = a; B[i] = b;
    }


    floydWarshall();
    for ( int i = 0; i < N; ++i ) numPaths[i][i] = 1;

    for ( int i = 0; i < M; ++i ){
        if ( ( dist[0][ A[i] ] + dist[ B[i] ][N - 1] + 1 ) == dist[0][N - 1] ) pwn[i] = ( long long ) numPaths[0][ A[i] ] * numPaths[ B[i] ][N - 1];
        if ( ( dist[0][ B[i] ] + dist[ A[i] ][N - 1] + 1 ) == dist[0][N - 1] ) pwn[i] = ( long long ) numPaths[0][ B[i] ] * numPaths[ A[i] ][N - 1];

    }


    long long maxPaths = 0;
    for ( int i = 0; i < N; ++i ){
        long long  tmpPaths = 0;
        for ( int j = 0; j < v[i].size(); ++j ) tmpPaths += pwn[ v[i][j] ];
        maxPaths = max( maxPaths, tmpPaths );
    }


    printf( "%.8lf\n", ( double ) maxPaths / numPaths[0][N - 1] );

    return 0;

}
