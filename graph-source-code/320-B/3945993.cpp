//Language: MS C++


#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <vector>
#include <complex>
#include <ctime>
#include <stack>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector< VI > VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

#define REP(i, n) for(int i = 0; i < n; ++i)
#define RREP(i, n) for(int i = n - 1; i >= 0; --i)
#define FOR(i, x, y) for(int i = x; i <= y; ++i)
#define RFOR(i, x, y) for(int i = x; i >= y; --i)
#define SZ(a) (int)(a).size()
#define ALL(a) (a).begin(),(a).end()
#define SORT(a) sort(ALL(a)) 
#define CLEAR(x) memset(x, 0, sizeof x);
#define COPY(FROM, TO) memcpy(TO, FROM, sizeof TO);
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define pb push_back
#define sqr(x) (x)*(x)
#define X first
#define Y second
const long double pi=acos(-1.0);
const long double eps = 1e-9;

int used[101];
int n;
VVI g;
vector<pair<int, int> > mas;
bool f (int a, int b) {
    if (mas[b].X < mas[a].X && mas[a].X < mas[b].Y) 
        return true;
    if (mas[b].X < mas[a].Y && mas[a].Y < mas[b].Y) 
        return true;
    return false;
}

void dfs(int v, int p = -1) {
    used[v] = 1;
    REP (i, mas.size()) {
        if (i == p)
            continue;
        if (i != v && !used[i] && f(v, i)) {
            dfs(i);
        }
    }
}
int main () {
    cin >> n;
    g.resize(n);
    REP (i, n) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        if (t1 == 1) {
            mas.pb(make_pair(t2, t3));
        } else {
            memset(used, 0, sizeof(used));
            dfs(t2 - 1);
            if (used[t3 - 1]) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}