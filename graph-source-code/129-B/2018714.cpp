//Language: MS C++


/*
* Author : Hakobyan Tigran
*/

#pragma comment(linker, "/STACK:60777216")
#define printTime(begin, end) printf("%.3lf\n", (double)(end - begin) / (double)CLOCKS_PER_SEC)


#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <functional>
#include <complex>
#include <iostream>
#include <fstream>
#include <sstream>
#include <bitset>
#include <limits>
#include <ctime>
#include <cassert>

using namespace std;

#define EPS 1e-9
#define PI acos(-1.0)
#define MOD 1000000007
#define IINF 10000000
#define LINF 1000000000000000002LL

#define mp(a, b) make_pair(a, b)
#define det(a, b, c, d) (a * d - c * b)
#define sbstr(s, i, j) s.substr(i, j - i + 1)

#define CLEAR(dp) memset(dp, -1, sizeof(dp))
#define reset(arr) memset(arr, 0, sizeof(arr))

int n;
int deg[111];
vector < int > g[111];

int main () {
    int m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; ++i) {
        int p, q;
        scanf("%d%d", &p, &q);
        g[p - 1].push_back(q - 1);
        g[q - 1].push_back(p - 1);
        deg[p - 1]++;
        deg[q - 1]++;
    }
    int ans = 0;
    while(true) {
        bool marker = true;
        vector < int > ind;
        for(int i = 0; i < n; ++i) {
            if(deg[i] == 1) ind.push_back(i);
        }
        for(int l = 0; l < ind.size(); ++l) {
            int i = ind[l];
            deg[i]--;
            g[i].clear();
            marker = false;
            for(int j = 0; j < n; ++j) {
                if(i != j) {
                    for(int k = 0; k < g[j].size(); ) {
                        int v = g[j][k];
                        if(v == i) {
                            g[j].erase(g[j].begin() + k);
                            deg[j]--;
                            break;
                        }
                        else {
                            k = k + 1;
                        }
                    }
                }
            }
        }
        if(marker) break;
        ans = ans + 1;
    }
    cout << ans << endl;
    return 0;
}
