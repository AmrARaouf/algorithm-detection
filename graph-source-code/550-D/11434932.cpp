//Language: MS C++


#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <vector>
#include <ctime>
#include <cstring>
#include <sstream>

//#include <unordered_map>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, pii> ppii;
typedef vector<int> vi;

#define FILES(in, out) freopen(in, "rt", stdin), freopen(out, "wt", stdout)
#define SA(a, n) FI(n) SI(a[i])
#define SI(n) scanf("%d", &n)
#define SII(x, y) scanf("%d%d", &x, &y)
#define SIII(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define SD(n) scanf("%lf", &n)
#define SPII(n) scanf("%d%d", &n.first, &n.second)
#define FI(n) for (int i=0; i<n; i++)
#define FJ(n) for (int j=0; j<n; j++)
#define FU(n) for (int u=0; u<n; u++)
#define WS(n) while(SI(n) != EOF && n)
#define DB(n) cout<<#n<<" = "<<n<<" ";
#define DBN(n) cout<<#n<<" = "<<n<<"\n";
#define FIX(n) cout.precision(2), cout.setf(cout.fixed)
#define PI(n) printf("%d ", n)
#define PIN(n) printf("%d\n", n)
#define SPACE() putchar(' ')
#define ENDL() putchar('\n')
#define in_count(a, n, x) (upper_bound(a, a+n, x) - lower_bound(a, a+n, x) + 1)


#define x first
#define y second

bool used[100001];

int main() {
    int k;
    SI(k);
    if (k % 2 == 0) {
        puts("NO");
    }
    else {
        puts("YES");
        int n = 0;
        vector<pii> m;

        if (k != 1) {
            for (int i = 2; i <= k + 2; i++)
                for (int j = i + 1; j <= k + 2; j++) {
                m.push_back(pii(i, j));
                }
            int t = (k - 1) / 2;
            for (int i = 0; t; i++) {
                int x = m[i].x;
                int y = m[i].y;
                if (!used[x] && !used[y]) {
                    used[x] = true;
                    used[y] = true;
                    m[i].x = 1;
                    m.push_back(pii(x, 1));
                    t--;
                }
            }
            n = k + 2;
        }
        else {
            n = 1;
        }


        printf("%d %d\n", n * 2, m.size() * 2 + 1);
        FI(m.size())
            printf("%d %d\n", m[i].x, m[i].y);
        printf("%d %d\n", 1, n + 1);
        FI(m.size())
            printf("%d %d\n", m[i].x + n, m[i].y + n);
    }
    cin.get(); cin.get();
    return 0;
}