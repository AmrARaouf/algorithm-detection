//Language: MS C++


#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <unordered_map>
#include <queue>
using namespace std;
const int maxn = 105;
#define mp(x, y) make_pair(x, y)
#define In(x, y) ((x>=0) && (x<n) && (y>=0) && (y<m))

int n;
int main() {
    scanf("%d", &n);
    int ans = (n - n / 2) * (n / 2);
    printf("%d\n", ans);
    for (int i = n / 2 + 1; i <= n; i++) {
        for (int j = 1; j <= n / 2; j++) {
            printf("%d %d\n", i, j);
        }
    }
    return 0;
}