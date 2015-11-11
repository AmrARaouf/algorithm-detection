//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define N 100001
#define LL long long

int n;
vector < pair<int,int> > v[N];

int dfs(int x, int fa) {
    int ret = 0;
    for (vector < pair<int,int> >::iterator it = v[x].begin(); it != v[x].end(); ++it)
        if (fa != it->first)
            ret = max(ret, it->second + dfs(it->first, x));
    return ret;
}

int main() {
    LL ans = 0;
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        v[x].push_back(make_pair(y, w));
        v[y].push_back(make_pair(x, w));
        ans += w * 2;
    }
    ans -= dfs(1, -1);
    printf("%I64d\n", ans);
    return 0;
}
