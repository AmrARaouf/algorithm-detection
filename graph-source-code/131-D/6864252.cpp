//Language: GNU C++0x


#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int M = 3000;
vector<int> g[M];
int n, m, p[M], cycle_st, cycle_end, d[M];
char cl[M], used[M];

void read() {
    scanf("%d", &n);
    m = n;
    for(int i = 0, a, b; i < m; ++i) {
        scanf("%d%d", &a, &b);
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i = 0; i < n; ++i) {
        p[i] = -1;
        cl[i] = 0;
    }
    cycle_st = -1;
}

bool dfs(int v, int prev = -1) {
    cl[v] = 1;
    for(size_t i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if(to == prev) continue;
        if(cl[to] == 0) {
            p[to] = v;
            if(dfs(to, v)) return true;
        }
        else if(cl[to] == 1) {
            cycle_end = v;
            cycle_st = to;
            return true;
        }
    }
    cl[v] = 2;
    return false;
}

void bfs(queue<int> &q) {
    used[cycle_st] = true;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(size_t i = 0; i < g[v].size(); ++i) {
            int to = g[v][i];
            if(!used[to]) {
                d[to] = d[v] + 1;
                used[to] = true;
                q.push(to);
            }
        }
    }
}

void find_cycle() {
    for(int i = 0; i < n; ++i) {
        if(dfs(i)) break;
    }
    queue<int> cycle;
    cycle.push(cycle_st);
    for(int v = cycle_end; v != cycle_st; v = p[v]) {
        cycle.push(v);
        used[v] = true;
    }
    bfs(cycle);
}

void output() {
    for(int i = 0; i < n; ++i) {
        printf("%d ", d[i]);
    }
}

int main() {
    read();
    find_cycle();
    output();
}
