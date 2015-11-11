//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#define mp(a , b) make_pair (a , b)
#define pb push_back
#pragma comment(linker,"/STACK:100000000,100000000")
using namespace std;
typedef long long LL;
const int N = 505;
struct Edge {
    int v , next;
}e[N * N];
struct Node {
    int a , b , k;
    Node () {}
    Node (int _a , int _b , int _k):a(_a),b(_b),k(_k){}
};
int mat[N][N] = {0};
int n , m , tot , start[N] , vis[N][N][2];
int dist[N][N][2] , pre[N][N][2];
void add (int u , int v) {
    e[tot].v = v;e[tot].next = start[u];
    start[u] = tot ++;
}
void bfs () {
    dist[1][n][0] = 0;
    queue<Node> que;
    que.push (Node(1 , n , 0));
    while (!que.empty()) {
        Node now = que.front();
        que.pop ();
        int u = now.k == 0 ? now.a : now.b;
        for (int i = start[u] ; i != -1 ; i = e[i].next) {
            Node next = now;
            int v = e[i].v;
            if (now.k == 0) next.a = v;
            else if (now.k == 1) next.b = v;
            if (now.k == 1 && next.a == next.b) continue;
            next.k = 1 - now.k;
            if (vis[next.a][next.b][next.k]) continue;
            vis[next.a][next.b][next.k] = 1;
            dist[next.a][next.b][next.k] = dist[now.a][now.b][now.k] + now.k;
            if (now.k == 0) pre[next.a][next.b][next.k] = now.a;
            else pre[next.a][next.b][next.k] = now.b;
            que.push(next);    
        }
    }
}
vector<int> ret[2];
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    tot = 0 ;memset (start , -1 , sizeof(start));
    scanf ("%d %d" , &n , &m);
    for (int i = 0 ; i < m ; i ++) {
        int u , v;
        scanf ("%d %d" , &u , &v);
        mat[u][v] = mat[v][u] = 1;
    }
    for (int i = 1 ; i <= n ; i ++) {
        for (int j = i + 1 ; j <= n ; j ++) {
            if (mat[i][j]) {
                add (i , j);
                add (j , i);
            }
        }
    }
    bfs ();
    if (!vis[n][1][0]) {
        puts ("-1");
        return 0;
    }
    printf ("%d\n" , dist[n][1][0]);
    int a = n , b = 1 , k = 0;
    while (a != 1 || b != n || k != 0) {
        ret[1 - k].pb(k == 1 ? a : b);
        if (k == 1) a = pre[a][b][k];
        else b = pre[a][b][k];
        k = 1 - k;
    }
    ret[0].pb(1); ret[1].pb(n);
    for (int i = ret[0].size() - 1 ; i >= 0 ; i --)
        printf ("%d%c" , ret[0][i] , i == 0 ? '\n' : ' ');
    for (int i = ret[1].size() - 1 ; i >= 0 ; i --)
        printf ("%d%c" , ret[1][i] , i == 0 ? '\n' : ' ');
    
    return 0;
}
    