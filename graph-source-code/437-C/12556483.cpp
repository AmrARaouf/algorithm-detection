//Language: GNU C++


#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 2000 + 10;

PII arr[MAXN];
int g[MAXN][MAXN];
int val[MAXN];
int n, m;

int main() {
    int a, b;
    scanf( "%d%d", &n, &m );
    for( int i = 1; i <= n; ++i ) {
        scanf( "%d", val + i );
        arr[i].first = val[i];
        arr[i].second = i;
    }
    for( int i = 0; i < m; ++i ) {
        scanf( "%d%d", &a, &b );
        g[a][b] = g[b][a] = 1;
    }
    sort( arr + 1, arr + n + 1, greater<PII>() );
    int sum = 0;
    for( int i = 1; i <= n; ++i ) {
        int u = arr[i].second;
        for( int j = 1; j <= n; ++j ) {
            if( g[u][j] ) {
                sum += val[j];
                g[u][j] = g[j][u] = 0;
            }
        }
    }
    printf( "%d\n", sum );
    return 0;
}
 	 							     		  	 		 	 	  		