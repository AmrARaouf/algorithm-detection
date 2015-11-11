//Language: MS C++


#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

const int maxN = 2007;

int n, r;
int deg[maxN];
vector < int > g[maxN];

int main () {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        int p;
        scanf("%d", &p);
        if(p != -1) {
            deg[p - 1]++;
            g[i].push_back(p - 1);
        }
    }

    int ans = 0;
    for(int it = 0; it < n; ++it) {
        vector < int > v;
        for(int i = 0; i < n; ++i) {
            if(deg[i] == 0) {
                v.push_back(i);
            }
        }
        if(v.empty()) {
            break;
        }
        ans++;
        for(int i = 0; i < v.size(); ++i) {
            deg[v[i]]--;
            for(int j = 0; j < g[v[i]].size(); ++j) {
                int to = g[v[i]][j];
                deg[to]--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
        




