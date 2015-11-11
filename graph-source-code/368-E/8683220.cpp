//Language: GNU C++0x


#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> VI;
typedef long long LL;
#define FOR(x, b, e) for(int x=b; x<=(e); ++x)
#define FORD(x, b, e) for(int x=b; x>=(e); --x)
#define REP(x, n) for(int x=0; x<(n); ++x)
#define ALL(c) c.begin(),c.end()

LL fun(LL n) {
    return 1 + ((n % 2) ? (n * (n - 1) / 2) : (n * (n - 1) / 2 + (n - 1) / 2));
}

int main() {
    int n, m, tmp;
    scanf("%d %d", &n, &m);
    VI V(m);
    REP(i, m)
        scanf("%d %d", &tmp, &V[i]);
    sort(ALL(V));
    int hmany = 1;
    while (fun(hmany + 1) <= n)
        hmany++;
    LL sum = 0;

    FORD(i, m - 1, max(m - hmany, 0))
        sum += V[i];

    cout << sum << endl;
    return 0;
}
