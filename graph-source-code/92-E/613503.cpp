//Language: GNU C++


#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>

using namespace std;

const double pi = acos(-1.0);
const double eps = 1E-7;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
#define sqr(x) ((x)*(x))
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define ME(a) memset((a), 0, sizeof((a)))
#define MM(a, b) memcpy((a), (b), sizeof((a)))
#define FOR(i,n) for (int (i) = 0; (i) < (n); ++(i))
#define REP(i,a,b) for (int (i) = (a); (i) < (b); ++(i))

const int MOD = 1000000009;
const int maxn = 100005;
int fa[maxn], n, m;

    inline int getfa(int va)
    {
        if (fa[va] == va) return va;
        fa[va] = getfa(fa[va]);
        return fa[va];
    }

int main()
{
    scanf("%d%d", &n, &m); for (int i = 1; i <= n; ++i) fa[i] = i;
    int ans = 1;
    for (; m--; ) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (getfa(x) != getfa(y)) fa[getfa(x)] = getfa(y);
        else {
            ans += ans;
            if (ans >= MOD) ans -= MOD;
        }
        printf("%d\n", (ans + MOD - 1) % MOD);
    }
    return 0;
}
