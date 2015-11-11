//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define lson step << 1
#define rson step << 1 | 1
#define error {puts("-1");return 0;}
using namespace std;
typedef long long LL;
const int N = 100005;
const int MOD = 100000000;
struct Edge {
    int v , w , next , id;
}e[N << 3];
int pos[N << 2] , m = 0;
int n , l;
int tot = 0 , start[N << 2];
int ans[N << 2] , cnt = 0;
struct Node {
    int x , d , t , p , id , f;
    void input (int i) {
        id = i;f = 1;
        scanf ("%d %d %d %d" , &x , &d , &t , &p);
        if (x - p < 0 || x + d > l) {
            f = 0;
            return;
        }
        pos[m ++] = x - p;
        pos[m ++] = x + d;
    }
}a[N];
struct DIJ {
    int u , d;
    DIJ () {}
    DIJ (int _u , int _d):u(_u) , d(_d) {}
    bool operator < (const DIJ &n) const {
        return d > n.d;
    }
};
void add (int u , int v , int w , int k) {
    e[tot].v = v;
    e[tot].w = w;
    e[tot].id = k;
    e[tot].next = start[u];
    start[u] = tot ++;
}
int path[N << 2] , pre[N << 2] , dist[N << 2] , in[N << 2];
void gao (int v) {
    if (v == 0) return;
    int u = pre[v] , k = path[v];
    if (k != -1) ans[cnt ++] = k;
    gao (u);
}
void dij (int st , int ed) {
    for (int i = 0 ; i < m ; i ++)
        dist[i] = 1000000005;
    priority_queue<DIJ>que;
    que.push (DIJ (st , 0));
    dist[st] = 0;
    while (!que.empty ()) {
        int u = que.top().u;
        que.pop ();
        if (in[u]) continue;
        in[u] = 1;
        for (int i = start[u] ; i != -1 ; i = e[i].next) {
            int v = e[i].v , w = e[i].w , k = e[i].id;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                path[v] = k;
                pre[v] = u;
                que.push(DIJ(v , dist[v]));
            }
        }
    }
    gao (ed);
    printf ("%d\n%d\n" , dist[ed] , cnt);
    for (int i = cnt - 1 ; i >= 0 ; i --)
        printf ("%d\n" , ans[i]);
}
int main () {
    #ifndef ONLINE_JUDGE 
        freopen ("input.txt" , "r" , stdin);
    #endif
    memset (start , -1 , sizeof(start));
    scanf ("%d %d" , &n , &l);
    for (int i = 0 ; i < n ; i ++)
        a[i].input (i + 1);
    pos[m ++] = 0; pos[m ++] = l;
    sort (pos , pos + m);
    m = unique (pos , pos + m) - pos;
    for (int i = 0 ; i < m - 1 ; i ++) {
        add (i , i + 1 , pos[i + 1] - pos[i] , -1);
        add (i + 1 , i , pos[i + 1] - pos[i] , -1);
    }
    for (int i = 0 ; i < n ; i ++) {
        if (a[i].f) {
            int u = lower_bound (pos , pos + m , a[i].x - a[i].p) - pos;
            int v = lower_bound (pos , pos + m , a[i].x + a[i].d) - pos;
            add (u , v , a[i].p + a[i].t , i + 1);
        }
    }
    dij (0 , m - 1);
    return 0;
}