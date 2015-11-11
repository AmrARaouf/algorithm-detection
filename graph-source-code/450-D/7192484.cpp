//Language: GNU C++0x


#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

#define REP(n) for(int _i=0; _i<n; ++_i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define FORE(i,a,b) for(int i=a; i<=b; ++i)

typedef long long LL;

struct Way {
    bool train;
    int u, v;
    LL dist;
    bool operator<(Way const &w) const {
        if(dist == w.dist)
            return train;
        return dist > w.dist;
    }
};

vector<Way> way(400001);
vector<bool> reached(100001);
vector< vector<int> > roads(100001);

int main() {
    priority_queue<Way> plan;
    int n, m, k, trainsUsed = 0;

    cin >> n >> m >> k;

    FOR(i,0,m) {
        cin >> way[i].u >> way[i].v >> way[i].dist;
        way[i].train = false;
        roads[way[i].u].push_back(i);
        roads[way[i].v].push_back(i);
    }

    FOR(j,0,k) {
        cin >> way[m + j].v >> way[m + j].dist;
        way[m + j].u = 1;
        way[m + j].train = true;
        roads[1].push_back(m + j);
    }

    reached[1] = true;
    for(int i : roads[1]) plan.push(way[i]);

    while(n > 1 && !plan.empty()) {
        Way w = plan.top(); plan.pop();
        int city;

        if(!reached[w.u])
            city = w.u;
        else if(!reached[w.v])
            city = w.v;
        else
            continue; // already reached

        reached[city] = true; // now reached
        n--;
        if(w.train) trainsUsed++;

        for(int i : roads[city]) {
            way[i].dist += w.dist;
            plan.push(way[i]);
        }
    }

    cout << k - trainsUsed;

    return 0;
}
