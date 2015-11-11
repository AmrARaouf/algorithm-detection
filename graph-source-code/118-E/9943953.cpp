//Language: GNU C++


#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;
const int MAXM = 300100;

int n, m, x, y, pi[MAXN], low[MAXN], d[MAXN], ttime;
vector<int> adj[MAXN];
vector<pair<int, int> > sol;
bool mk[MAXN], bridge;

void dfs(int u) {
    mk[u] = true;
    ttime++;
    d[u] = ttime;
    low[u] = d[u];
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (!mk[v]) {
            pi[v] = u;
            sol.push_back(make_pair(u, v));
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else {
            if (d[v] < d[u] && v != pi[u])
                sol.push_back(make_pair(u, v));
            if (pi[u] != v)
                low[u] = min(low[u], d[v]);
        }
    }
    if (pi[u] != 0 && low[u] == d[u])
        bridge = true;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    dfs(1);
    if (bridge)
        cout << 0 << endl;
    else {
        //cout << endl;
        for (int i = 0; i < (int)sol.size(); i++)
            cout << sol[i].first << " " << sol[i].second << endl;
    }
}
