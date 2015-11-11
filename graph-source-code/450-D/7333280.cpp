//Language: GNU C++


#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
#include<utility>
#include<string>
#include <sstream>
#include <queue>
typedef long long int LL;
const LL INF = 1LL << 60;
using namespace std;
vector< vector< pair<LL, LL> > > graph;
bool train[210000] = {false};
LL dist[210000];
LL n, m, t;

void diji(int s) {
    priority_queue< pair< LL, LL >, vector< pair<LL, LL> >, greater< pair< LL, LL > > > pq;
    dist[s] = 0;
    for(int i=1;i<=n;i++)  
    {  
        if(dist[i]!=INF)  
        {  
            pq.push(make_pair(dist[i],i));  
        }  
    }  
    while (!pq.empty()) {
        pair< LL, LL > p = pq.top();
        pq.pop();
        LL d = p.first;
        LL u = p.second;
        if (dist[u] != d)
            continue;
        for (int i = 0; i < graph[u].size(); i++) {
            LL v = graph[u][i].second;
            LL dv = graph[u][i].first;
            if (dist[v] >= dist[u] + dv) {
                if (train[v])
                    train[v] = false;
            }
            if (dist[v] > dist[u] + dv) {
                dist[v] = dist[u] + dv;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

int main() {
    cin >> n >> m >> t;
    graph.assign(n + 1, vector< pair<LL, LL> >());
    for (LL i = 0; i <= n; i++) {
        dist[i] = INF;
        train[i] = false;
    }
    for (LL i = 0; i < m; i++) {
        int t1, t2;
        LL t3;
        cin >> t1 >> t2 >> t3;
        graph[t1].push_back(make_pair(t3, t2));
        graph[t2].push_back(make_pair(t3, t1));
    }
    for (LL i = 0; i < t; i++) {
        LL t1, t2;
        cin >> t1 >> t2;
        train[t1] = true;
        dist[t1] = min(dist[t1], t2);
    }
    diji(1);
    LL res = t;
    for (LL i = 1; i < n + 1; i++) {
        if (train[i])
            res--;
    }
    cout << res << endl;
}


