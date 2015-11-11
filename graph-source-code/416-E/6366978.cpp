//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef  long long LL;          
const int N = 505;
const int inf = 1000000000;
int n , m , path[N][N] , dist[N][N];
int cnt[N][N] , ans[N][N];
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
#endif
    scanf ("%d %d" , &n , &m);
    for (int i = 1 ; i <= n ; i ++) {
        for (int j = 1 ; j <= n ; j ++)
            path[i][j] = inf;
    }
    while (m --) {
        int u , v , w;
        scanf ("%d %d %d" , &u , &v , &w);
        path[u][v] = path[v][u] = min (path[u][v] , w);
    }
    for (int i = 1 ; i <= n ; i ++) {
        for (int j = 1 ; j <= n ; j ++)
            dist[i][j] = path[i][j];
        dist[i][i] = 0;
    }
    for (int k = 1 ; k <= n ; k ++) {
        for (int i = 1 ; i <= n ; i ++) 
            for (int j = 1 ; j <= n ; j ++) 
                dist[i][j] = min (dist[i][j] , dist[i][k] + dist[k][j]);
        
    }
    for (int i = 1 ; i <= n ; i ++) {
        for (int j = 1 ; j <= n ; j ++) 
            for (int k = 1 ; k <= n ; k ++) {
                if (path[i][k] != inf && dist[k][j] != inf && dist[i][j] == path[i][k] + dist[k][j])  
                    cnt[i][j] ++;
            }
    }
    for (int i = 1 ; i <= n ; i ++) {
        for (int j = i + 1 ; j <= n ; j ++) 
            for (int k = 1 ; k <= n ; k ++)
                if (dist[i][k] != inf && dist[k][j] != inf && dist[i][j] == dist[i][k] + dist[k][j]) {
                    ans[i][j] += cnt[k][j];
        }
    }
    for (int i = 1 ; i <= n ; i ++)
        for (int j = i + 1 ; j <= n ; j ++)
            printf ("%d " , ans[i][j]);
    return 0;
}