//Language: GNU C++


#include<iostream>
#include<cstdio>

using namespace std;

const int maxn = 510;
const int maxm = 1000000;

struct state {
    int same , par , step , u , v;
};

int n , m , tot;
bool adj[maxn][maxn] , vis[2][maxn][maxn];
state Q[maxm];
int res[2][maxn];

void input() {
    scanf( "%d%d" , &n , &m );
    for ( int i = 1 ; i <= m ; i++ ) {
        int u , v; scanf( "%d%d" , &u , &v );
        adj[u][v] = adj[v][u] = true;
    }
}

void push( int same , int par , int step , int u , int v ) {
    if ( vis[same][u][v] || ( same && u == v ) ) return;
    vis[same][u][v] = true;
    Q[++tot].same = same , Q[tot].par = par , Q[tot].step = step , Q[tot].u = u , Q[tot].v = v;
}

void solve() {
    push( true , 0 , 0 , 1 , n );
    
    int end = -1;
    for ( int i = 1 ; i <= tot ; i++ )
        if ( Q[i].same ) {
            if ( Q[i].u == n && Q[i].v == 1 ) {
                end = i;
                break;
            }
            for ( int k = 1 ; k <= n ; k++ )
                if ( adj[Q[i].u][k] ) push( 0 , i , Q[i].step , k , Q[i].v );
        } else {
            for ( int k = 1 ; k <= n ; k++ )
                if ( adj[Q[i].v][k] ) push( 1 , i , Q[i].step + 1 , Q[i].u , k );
        }
    
    if ( end == -1 ) printf( "-1\n" ); else {
        int ans = Q[end].step;
        res[0][ans] = n , res[1][ans] = 1;
        for ( int i = ans - 1 ; i >= 0 ; i-- ) {
            end = Q[Q[end].par].par;
            res[0][i] = Q[end].u , res[1][i] = Q[end].v;
        }
        printf( "%d\n" , ans );
        for ( int i = 0 ; i <= ans ; i++ ) printf( "%d " , res[0][i] ); printf( "\n" );
        for ( int i = 0 ; i <= ans ; i++ ) printf( "%d " , res[1][i] ); printf( "\n" );
    }
}

int main() {
    input();
    solve();
    
    return 0;
}
