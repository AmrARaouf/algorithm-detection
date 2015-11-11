//Language: GNU C++


//
// e.cpp -- E
//
// Siwakorn Sriakaokul - ping128
// Written on Thursday, 14 November 2013.
//

#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <algorithm>
#include <map>
#include <ctype.h>
#include <string.h>

#include <assert.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PII2;

#define INF 1000000000
#define MAXN 55

struct MinCostFlow {
    /* Min Cost Flow with a required flow (can't be changed to normal by
     * a little modification
     * using SPFA (Shortest Path Faster Algor) in case the cost is negative
     * so if the cost is always positive, it can be replaced by Dijkstra
     */

    struct Edge {
        int v, cap, rev;
        double cost;
    };

    bool visited[MAXN];
    vector<Edge> edges[MAXN];
    pair<int, int> prev[MAXN]; // for tracing back the path getting from the shortest path, prev[v] : (u, index of u in edges[v])
    double dist[MAXN];

    int n;

    MinCostFlow(int n) : n(n) {
        Reset();
    }

    double AddEdge(int u, int v, int capacity, double cost){
        Edge e1 = {v, capacity, edges[v].size(), cost};
        Edge e2 = {u, 0, edges[u].size(), -cost};
        edges[u].push_back(e1);
        edges[v].push_back(e2);
    }

    void Reset(){
        for(int i = 0; i < n; i++ ){
            edges[i].clear();
            visited[i] = false;
        }
    }

    bool spfa(int s, int t){
        for(int i = 0; i < n; i++ ) dist[i] = INF;
        dist[s] = 0;
        queue<int> Q;
        Q.push(s);
        visited[s] = true;
        while(!Q.empty()){
            int u = Q.front();
            Q.pop();
            visited[u] = 0;
            for(int i = 0; i < edges[u].size(); i++ ){
                int v = edges[u][i].v;
                if(edges[u][i].cap > 0 && dist[v] > dist[u] + edges[u][i].cost){
                    dist[v] = dist[u] + edges[u][i].cost;
                    prev[v] = pair<int, int>(u, i);
                    if(!visited[v]){
                        visited[v] = true;
                        Q.push(v);
                    }
                }
            }
        }
        return dist[t] != INF;
    }

    // return the minimum cost for getting that required_flow
    // return INF if maxflow < required_flow
    double GetMinCostFlow(int s, int t, int required_flow){
        double totalCost = 0;
        while(required_flow > 0){
            int flow = required_flow;
            if(!spfa(s, t)){ // can't reach
                break;
            }

            for(int i = t; i != s; i = prev[i].first)
                flow = min(flow, edges[prev[i].first][prev[i].second].cap);

            if(flow == 0) break;
            required_flow -= flow;
            for(int i = t; i != s; i = prev[i].first){
                edges[prev[i].first][prev[i].second].cap -= flow;
                edges[i][edges[prev[i].first][prev[i].second].rev].cap += flow;
            }
            totalCost += flow * dist[t];
        }
        return required_flow == 0 ? totalCost : INF;
    }
};

int caps[MAXN][MAXN];

int main(){
    int N, K;
    int c;
    scanf("%d %d", &N, &K);

    for(int i = 0; i < N; i++ )
        for(int j = 0; j < N; j++ )
            scanf("%d", &caps[i][j]);

    int left = 0, right = 1000000000;
    while(left <= right){
        int mid = (left + right) / 2;
        MinCostFlow solver = MinCostFlow(N);
        for(int i = 0; i < N; i++ )
            for(int j = 0; j < N; j++ ){
                if(caps[i][j] == 0) continue;
                solver.AddEdge(i, j, caps[i][j], 0);
                solver.AddEdge(i, j, INF, 1);
            }

        LL cost = solver.GetMinCostFlow(0, N - 1, mid);
        if(cost <= K) left = mid + 1;
        else right = mid - 1;
    }

    cout << right << endl;
    return 0;
}
