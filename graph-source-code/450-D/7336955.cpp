//Language: GNU C++


#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

const long long INF = 1e18;
const long long N = 1e5;

struct edge{
    long long to, len, own;
};

long long n, m, k, rzd[N], d[N], pr[N];
vector<edge> g[N];

void dkstra(long long s){
    priority_queue< pair<long long, long long> > heap;
    for (int i = 0; i < n; i++){
        d[i] = INF;
    }
    d[s] = 0;
    pr[s] = 0;
    heap.push(make_pair(0, s));
    while (!heap.empty()){
        long long v = heap.top().second;
        long long cur_d = -heap.top().first;
        heap.pop();
        if (cur_d > d[v])
            continue;
        for (int j = 0; j < g[v].size(); j++){
            long long to = g[v][j].to;
            long long len = g[v][j].len;
            if (d[v] + len < d[to]){
                d[to] = d[v] + len;
                pr[to] = g[v][j].own;
                heap.push(make_pair(-d[to], to));
            } else
            if ((d[v] + len == d[to])  && (g[v][j].own == 0) && (pr[to] == 1)){
                d[to] = d[v] + len;
                pr[to] = g[v][j].own;
                heap.push(make_pair(-d[to], to));
            }
        }

    }
}

int main(){
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++){
        long long u, v, x;
        cin >> u >> v >> x;
        u--; v--;
        edge t;
        t.to = v; t.len = x; t.own = 0;
        g[u].push_back(t);
        t.to = u; t.len = x; t.own = 0;
        g[v].push_back(t);
    }
    for (int i = 0; i < n; i++){
        rzd[i] = -1;
    }
    long long ans = 0;
    for (int i = 0; i < k; i++){
        long long s, y;
        cin >> s >> y;
        s--;
        if (rzd[s] == -1)
            rzd[s] = y;
        else {
            if (y <= rzd[s]){
                rzd[s] = y;
                ans++;
            }
            else {
                ans++;
            }
        }
        edge t;
        t.to = s; t.len = y; t.own = 1;
        g[0].push_back(t);
        t.to = 0; t.len = y; t.own = 1;
        g[s].push_back(t);
    }
    dkstra(0);
    for (int i = 0; i < n; i++){
        if (rzd[i] != -1 && pr[i] == 0){
            ans++;
        }
    }
    cout << ans;
}
