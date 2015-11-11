//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector <vector <int> > adj;
    adj.resize(n + 1);
    int cnt[101];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < m; ++ i) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        ++ cnt[a];
        ++ cnt[b];
    }
    int result = 0;
    do {
        vector <int> v;
        for (int i = 1; i <= n; ++ i)
            if (cnt[i] == 1)
                v.push_back(i);
        int N = v.size();
        if (N == 0)
            break;
        ++ result;
        for (int i = 0; i < N; ++ i) {
            int node = v[i];
            -- cnt[node];
            int sz = adj[node].size();
            for (int j = 0; j < sz; ++ j)
                -- cnt[adj[node][j]];
        }
    } while(true);
    printf("%d\n", result);
    return 0;
}