//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
#include <cstdlib>
#include <string>
#include <set>
#include <stack>
#define LL long long
#define pii pair<int,int>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 110;
struct arc {
    int to,flow,cost,next;
    arc(int x = 0,int y = 0,int z = 0,int nxt = -1) {
        to = x;
        flow = y;
        cost = z;
        next = nxt;
    }
};
arc e[10000];
int head[maxn],d[maxn],p[maxn],S,T,n,k,tot;
bool in[maxn];
void add(int u,int v,int flow,int cost) {
    e[tot] = arc(v,flow,cost,head[u]);
    head[u] = tot++;
    e[tot] = arc(u,0,-cost,head[v]);
    head[v] = tot++;
}
bool spfa() {
    queue<int>q;
    for(int i = 0; i <= n; ++i) {
        d[i] = INF;
        p[i] = -1;
        in[i] = false;
    }
    d[S] = 0;
    q.push(S);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        in[u] = false;
        for(int i = head[u]; ~i; i = e[i].next) {
            if(e[i].flow && d[e[i].to] > d[u] + e[i].cost) {
                d[e[i].to] = d[u] + e[i].cost;
                p[e[i].to] = i;
                if(!in[e[i].to]){
                    in[e[i].to] = true;
                    q.push(e[i].to);
                }
            }
        }
    }
    return p[T] > -1;
}
int solve() {
    int cost = 0,flow = 0;
    while(spfa()) {
        int theMin = INF;
        for(int i = p[T]; ~i; i = p[e[i^1].to])
            theMin = min(theMin,e[i].flow);
        if(cost + d[T]*theMin > k) return flow + (k - cost)/d[T];
        flow += theMin;
        cost += d[T]*theMin;
        for(int i = p[T]; ~i; i = p[e[i^1].to]) {
            e[i].flow -= theMin;
            e[i^1].flow += theMin;
        }
    }
    return flow;
}
int main() {
    while(~scanf("%d %d",&n,&k)) {
        memset(head,-1,sizeof(head));
        S = 0;
        T = n-1;
        int tmp;
        for(int i = tot = 0; i < n; ++i)
            for(int j = 0; j < n; ++j) {
                scanf("%d",&tmp);
                if(tmp) {
                    add(i,j,tmp,0);
                    add(i,j,k,1);
                }
            }
        printf("%d\n",solve());
    }
    return 0;
}


                                                   