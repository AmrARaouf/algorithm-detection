//Language: GNU C++0x


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
typedef long long LL;
const LL N = 100000 + 9;
LL fa[N];
LL s[N];
LL cnt;
LL father(LL v) {
    if (fa[v] != v) fa[v] = father(fa[v]);
    return fa[v];
}
void merge(LL x, LL y, LL d) {
    LL fx = father(x);
    LL fy = father(y);
    if (fx != fy) {
        s[fx] += s[fy] + d;
        s[fy] = 0;
        fa[fy] = fx;
        ++cnt;
    } else s[fx] += d;
}
LL n, m, p, q;

set< pair<LL, LL> > heap;

int main() {
    scanf("%I64d%I64d%I64d%I64d", &n, &m, &p, &q);
    cnt = 0;
    for (LL i = 1; i <= n; ++i) fa[i] = i;
    for (LL i = 1; i <= m; ++i) {
        LL x, y, d;
        scanf("%I64d%I64d%I64d", &x, &y, &d);
        merge(x, y, d);
    }
    if (!cnt) {
        if (p) {
            if (q < n - p || q > n - 1) {
                puts("NO");
                return 0;
            }
        } else {
            if (q != n) {
                puts("NO");
                return 0;
            }
        }
    } else {
        if (q < n - cnt - p || q > n - cnt) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");

    for (LL i = 1; i <= n; ++i) fa[i] = father(fa[i]);
    for (LL i = 1; i <= n; ++i)
        if (fa[i] == i) {
            heap.insert(make_pair(s[i], i));
        }
    LL nd = n - cnt - q;
    LL MAX = 1000000000;
    LL sum = 0;
    for (LL i = 1; i <= nd; ++i) {
        LL f1 = (*heap.begin()).second; heap.erase(*heap.begin());
        LL f2 = (*heap.begin()).second; heap.erase(*heap.begin());
        printf("%I64d %I64d\n", f1, f2);
        LL nn = min(s[f1] + s[f2] + 1, MAX);
        merge(f1, f2, nn);
        heap.insert(make_pair(s[f1], f1));
    }

    for (LL i = 1; i <= n; ++i) fa[i] = father(fa[i]);

    LL x, y;

    for (LL i = 1; i <= n; ++i)
        if (fa[i] != i) {
            x = i, y = fa[i];
        }
    for (LL i = 1; i <= p - nd; ++i)
        printf("%I64d %I64d\n", x, y);

    return 0;
}