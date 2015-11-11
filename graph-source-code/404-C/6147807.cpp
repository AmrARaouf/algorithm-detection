//Language: GNU C++


#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<pair<int, int> > vct;
vector<int> na, nb;
vector<pair<int, int> > forSort;

int main() {
    int k, n, d[100000];
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &d[i]);
        forSort.push_back(pair<int, int>(d[i], i));
    }
    sort(forSort.begin(), forSort.end());
    sort(d, d + n);

    bool suc = true;
    if (d[0] != 0) suc = false;

    na.push_back(0);
    int flag = 1, step = 1;
    while (flag < n && suc) {
        for (vector<int>::iterator it = na.begin(); it != na.end() && suc; it++) {
            int cnt = 0;
            if (*it != 0) cnt++;

            while (cnt < k && d[flag] == step) {
                nb.push_back(flag);
                vct.push_back(pair<int, int>(*it, flag));
                flag++;
                cnt++;
            }
        }
        if (flag < n && d[flag] <= step) suc = false;
        na = nb;
        nb = vector<int>();
        step++;
    }
    if (!suc) puts("-1");
    else {
        printf("%d\n", (int)vct.size());
        for (vector<pair<int, int> >::iterator it = vct.begin(); it != vct.end(); it++) {
            printf("%d %d\n", forSort[it->first].second + 1, forSort[it->second].second + 1);
        }
    }
}
