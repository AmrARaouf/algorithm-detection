//Language: GNU C++0x


#include <math.h>
#include <limits.h>
#include <complex>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <complex.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

using namespace std;

const int N = 5e5;

vector<int> ans, v;
vector<pair<int, int>> g[N];
int used[N], n, m, cur[N];

void dfs(int x) {
    for (int &i = cur[x]; i < g[x].size(); i++) {
        if (!used[g[x][i].second]) {
            used[g[x][i].second] = true;
            dfs(g[x][i].first);
        }
    }
    ans.push_back(x);
}

int main() {
//  freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x; --y;
        g[x].push_back(make_pair(y, i));
        g[y].push_back(make_pair(x, i));
    }
    for (int i = 0; i < n; i++) {
        if (g[i].size() % 2 == 1) {
            v.push_back(i);
        }
    }
    int nom = m;
    for (int i = 0; i + 1 < v.size(); i += 2) {
        g[v[i]].push_back(make_pair(v[i + 1], nom));
        g[v[i + 1]].push_back(make_pair(v[i], nom));
        ++nom;
    }
    if (nom % 2 == 1) {
        g[0].push_back(make_pair(0, nom));
        g[0].push_back(make_pair(0, nom));
    }
    dfs(0);
    //cerr << ans.size() << endl;
    ans.pop_back();
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); i++) {
        if (i % 2 == 0) {
            printf("%d %d\n", ans[i] + 1, ans[i + 1] + 1);
        } else {
            printf("%d %d\n", ans[i + 1] + 1, ans[i] + 1);
        }
    }
}
