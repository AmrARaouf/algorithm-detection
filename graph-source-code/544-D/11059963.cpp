//Language: GNU C++11


//
//  Created by TaoSama on 2015-05-10
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, m;
vector<int> G[3005];

int s1, t1, s2, t2, d1, d2;
int d[3005][3005];

void bfs(int cur) {
    queue<int> q; q.push(cur);
    memset(d[cur], 0x3f, sizeof d[cur]);
    d[cur][cur] = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int i = 0; i < G[u].size(); ++i) {
            int v = G[u][i];
            if(d[cur][v] == INF) {
                d[cur][v] = d[cur][u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> m) {
        for(int i = 1; i <= m; ++i) {
            int u, v; cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        cin >> s1 >> t1 >> d1;
        cin >> s2 >> t2 >> d2;

        for(int i = 1; i <= n; ++i) bfs(i);

        if(d[s1][t1] > d1 || d[s2][t2] > d2) {
            cout << "-1\n";
            continue;
        }

        int ans = d[s1][t1] + d[s2][t2];
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                int x = d[s1][i] + d[i][j] + d[j][t1];
                int y1 = d[s2][i] + d[i][j] + d[j][t2];
                if(x <= d1 && y1 <= d2) ans = min(ans, x + y1 - d[i][j]);
                int y2 = d[t2][i] + d[i][j] + d[j][s2];
                if(x <= d1 && y2 <= d2) ans = min(ans, x + y2 - d[i][j]);
            }
        }
        cout << m - ans << '\n';
    }
    return 0;
}
