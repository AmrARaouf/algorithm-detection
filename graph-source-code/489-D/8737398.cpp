//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#define pb push_back
#define fname ""
#define ll long long
#define s second
#define f first
#define mp make_pair

using namespace std;

int n, m, a[3333];
ll ans;
vector <int> g[3333];

void dfs(int v, int prev, int d) {
    if (d == 2) {
        a[v]++;
        return;
    }
    for (int i = 0; i < g[v].size(); i++) {
        if (g[v][i] != prev) 
            dfs(g[v][i], v, d+1);
    }                   
}

int main() { 
    #ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
    }


    for (int i = 1; i <= n; i++) {
        memset(a, 0, sizeof a);
        dfs(i, -1, 0);
        for (int j = 1; j <= n; j++) {
            if (a[j]) {
                ans += (a[j] * (a[j]-1)) / 2;
            }
        }   
    }      
    cout << ans;
    return 0;
}
    