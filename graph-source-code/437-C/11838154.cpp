//Language: GNU C++


#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1e3 + 5;

int c[N];
long long res = 0;

int main() {
    ///freopen("test.inp", "r", stdin);
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; ++i) cin >> c[i];
    for(int i=1; i<=m; ++i) {
        int u, v;
        cin >> u >> v;
        res += min(c[u], c[v]);
    }
    cout << res;
}
