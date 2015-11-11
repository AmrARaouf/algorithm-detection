//Language: MS C++


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<vector>
#include<queue>
#include<list>
#include<string>
#include<set>
#include<map>
#include<iomanip>
#include<sstream>
#include<functional>
#include<climits>
#define eps 1e-9
const int mod = 1000000007;
using namespace std;

map<pair<long long, long long>, bool> mp;
struct Edge{
    long long from, to, dist;
    bool train;
    Edge(long long _from, long long _to, long long _dist, bool _train) : from(_from), to(_to), dist(_dist), train(_train){}
    bool operator<(const Edge& a) const{
        if (dist == a.dist) {
            if (train == true && a.train == false) {
                return true;
            }
            if (train == false && a.train == true) {
                return false;
            }
        }
        return dist > a.dist;
    }
};
struct triple{
    long long first, second;
    bool train;
    triple(long long _from, long long _to, bool _train) : first(_from), second(_to), train(_train){}
};
vector<triple> ne[123456];
int dad[123345], dist[123445];
void djkstra(long long idx) {
    memset(dad, -1, sizeof(dad));
    priority_queue<Edge> pq;
    Edge s(idx, idx, 0, 0);
    pq.push(s);
    while (!pq.empty()){
        Edge cur = pq.top();
        pq.pop();
        if (dad[cur.to] != -1) continue;
        if (cur.train == true) {
            mp[make_pair(cur.from, cur.to)] = 1;
            mp[make_pair(cur.to, cur.from)] = 1;
        }
        dad[cur.to] = cur.from;
        dist[cur.to] = cur.dist;
        for (int i = 0; i < ne[cur.to].size(); ++i) {
            long long nfrom = cur.to;
            long long nto = ne[cur.to][i].first;
            int ndist = ne[cur.to][i].second + dist[cur.to];
            if (dad[nto] == -1) pq.push(Edge(nfrom, nto, ndist, ne[cur.to][i].train));
        }
    }
}
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        long long u, v, x;
        scanf("%I64d %I64d %I64d", &u, &v, &x);
        ne[u].push_back(triple(v, x, 0));
        ne[v].push_back(triple(u, x, 0));
    }
    for (int i = 0; i < k; ++i) {
        long long s, y;
        scanf("%I64d %I64d", &s, &y);
        ne[1].push_back(triple(s, y, 1));
        ne[s].push_back(triple(1, y, 1));
    }
    djkstra(1);
    cout << k - mp.size() / 2 << endl;
    return 0;
}