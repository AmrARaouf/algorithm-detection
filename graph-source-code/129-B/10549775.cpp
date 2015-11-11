//Language: GNU C++11


#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "delete_this.hpp"
#define t(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define t(...)
#endif

unordered_set<int> g[100 + 5];
vector<int> satu;
int main() {
    // unordered_set<int> z = {1};
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 0; i <= m - 1; i++) {
        int a, b;
        scanf("%d", &a);
        scanf("%d", &b);
        g[a].insert(b);
        g[b].insert(a);
    }
    int ans = 0;
    while (1) {
        for (int i = 1; i <= n; i++) {
            if ((int)g[i].size() == 1) {
                satu.emplace_back(i);
            }
        }
        if ((int)satu.size() == 0) {
            break;
        }
        t(ans);
        for (auto &e : satu) {
            int zz = -1;
            if ((int)g[e].size() != 0) {
                zz = *g[e].begin();
                if ((int)g[zz].size() != 0) {
                    g[zz].erase(e);
                }
            }
            g[e].clear();
        }
        ans++;
        satu.clear();
    }
    printf("%d\n", ans);
    return 0;
}

