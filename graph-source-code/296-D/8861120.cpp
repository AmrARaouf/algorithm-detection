//Language: GNU C++0x


#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <iomanip>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

#define all(p) (p).begin(), (p).end()
#define odd(x) ((x)&(1))
#define sqr(x) ((x)*(x))
#define fi first
#define se second

#define TASKNAME ""
#define DEBUG

typedef long long ll;

const int N = 555;
const int INF = 1000000000, mod = 1000000007;
const ll LLINF = 1000000000000000000ll;

ll d[N][N];
int n;


int main () {

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%I64d", d[i] + j);
        }
    }

    vector <int> x(n);
    vector <ll> ans(n);

    for (int i = 0; i < n; ++i) {
        int v;
        scanf("%d", &v);

        --v;
        x[n - i - 1] = v;
    }

    for (int nn = 0; nn < n; ++nn) {

        int k = x[nn];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }

        ll sum = 0ll;

        for (int i = 0; i <= nn; ++i) {
            for (int j = 0; j <= nn; ++j) {
                if (i != j) {
                    sum += d[x[i]][x[j]];
                }
            }
        }

        ans[n - nn - 1] = sum;
    }

    for (int i = 0; i < n; ++i) {
        printf("%I64d%c", ans[i], " \n"[i == n - 1]);
    }


    return 0;
}
