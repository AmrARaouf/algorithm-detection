//Language: GNU C++


#include<bits/stdc++.h>
#include <ext/numeric>
#include<stdlib.h>
using namespace std;
using namespace __gnu_cxx;
int n, m, x, y, mn = INT_MAX;
pair<int, int> w[4003];
bool boo, a[4003][4003];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        a[--x][--y] = a[y][x] = 1;
        w[x].second = x;
        (w[x].first)++;
        w[y].second = y;
        (w[y].first)++;
    }
    sort(w, w + n);
    int strt = n;
    for (int i = 0; i < n; i++)
        if (w[i].first) {
            strt = i;
            break;
        }
    for (int i = strt; i < n; i++) {
        for (int j = strt; j < n; j++) {
            if (i == j)
                continue;
            if (a[w[i].second][w[j].second]) {
                for (int k = strt; k < n; k++) {
                    if (i == k || k == j)
                        continue;
                    if (a[w[k].second][w[j].second]
                            && a[w[k].second][w[i].second]) {
                        mn = min(mn, w[i].first + w[j].first + w[k].first - 6);
                        boo = 1;
                    }
                }
            }
        }
    }
    cout << (boo ? mn : -1) << '\n';
}
