//Language: MS C++


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<math.h>
#include<queue>
#include<stack>
#include<sstream>
#include<stdio.h>
#include<map>
#include<set>
#include<memory.h>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
#define FOR(I,N) for(int(i)=0;i<int(N);++i)
#define FORK(I,N,K) for(int(i)=0;i<int(N);i+=int(K))
class edge{
public:
    int x, y, cap, nxt;
    edge(int a, int b, int c, int d){
        x = a; y = b;
        cap = c; nxt = d;
    }
};

int n, g[50][50], k;
vector<edge>v;
int cap[50][50];
int last[50];
void add(int a, int b, int c){
    edge e = edge(a, b, c, last[a]);
    last[a] = v.size();
    v.push_back(e);
    e = edge(b, a, 0, last[b]);
    last[b] = v.size();
    v.push_back(e);
}
int oo = 1 << 25, par[50];
bool Path(int src, int sink){
    queue<int>q;
    q.push(src);
    memset(par, -1, sizeof(par));
    par[src] = src;
    while (!q.empty()){
        src = q.front(); q.pop();
        for (int i = last[src]; i != -1; i = v[i].nxt){
            int nxt = v[i].y;
            if (v[i].cap > 0 && par[nxt] == -1){
                par[nxt] = i;
                if (nxt == sink)
                    return 1;
                q.push(nxt);
            }
        }
    }
    return 0;
}
int MaxFlow(int src, int sink){
    int ret = 0;
    while (Path(src , sink)){
        int flow = oo;
        for (int i = sink; i != src; i = v[par[i]].x)
            flow = min(flow, v[par[i]].cap);
        ret += flow;
        for (int i = sink; i != src; i = v[par[i]].x){
            v[par[i]].cap -= flow;
            v[par[i] ^ 1].cap += flow;
        }
    }
    return ret;
}
vector<int>G[50];
int cost[50];
#define mp make_pair
int DIJ(){
    priority_queue<pair<int, int> >q;
    FOR(0, n)
        cost[i] = oo;
    par[0] = 0;
    q.push(mp(0, 0));
    cost[0] = 0;
    while (!q.empty()){
        pair<int, int> p = q.top(); q.pop();
        FOR(0, G[p.second].size()){
            int nxt = G[p.second][i];
            int r = cap[p.second][nxt] == 0;
            if (cost[nxt] > cost[p.second] + r){
                cost[nxt] = cost[p.second] + r;
                par[nxt] = p.second;
                q.push(mp(-cost[nxt], nxt));
            }
        }
    }
    int cur = n - 1;
    while (cur){
        if (cap[par[cur]][cur])
            --cap[par[cur]][cur];
        cur = par[cur];
    }
    return cost[n - 1];
}
int main(){
    cin >> n >> k;
    memset(last, -1, sizeof(last));
    for (int i = 0; i < n - 1; ++i){
        for (int j = 0; j < n; ++j){
            cin >> g[i][j];
            if (g[i][j])
                add(i, j, g[i][j]);
        }
    }
    int res = MaxFlow(0, n - 1);
    for (int i = 0; i < v.size(); i+=2){
        int x = v[i].x , y = v[i].y , c = v[i].cap;
        G[x].push_back(y);
        cap[x][y] += c;
    }
    while (true){
        int Q = DIJ();
        if (Q > k)
            break;
        res += 1;
        k -= Q;
    }
    cout << res << endl;
    cin >> n;
}