//Language: GNU C++


#include    <iostream>
#include    <algorithm>
#include    <vector>

#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; i++)
#define FOR_(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define _FOR(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define abs(x) (x) < 0? -(x) : (x)

#define LL long long
#define NM 3001

using namespace std;

int n, m, a[NM][NM];

vector <int> adj[NM];

LL res;

LL Damn(int x) {
    LL res = 0, cnt;
    FOR_(i, 1, n) {
        if (i == x) continue;
        cnt = 0;
        FOR(j, 0, adj[x].size()) {
            cnt += a[adj[x][j]][i];
        }
        res += (cnt - 1) * cnt / 2;
    }
    return res;
}

int main() {

    ios::sync_with_stdio(0);
    cin >>n >>m;
    int x, y;
    FOR(i, 0, m) {
        cin >>x >>y;
        a[x][y] = 1;
        adj[x].push_back(y);
    }
    FOR_(i, 1, n) {
        res += Damn(i);
    }
    cout <<res;
    return 0;

}
