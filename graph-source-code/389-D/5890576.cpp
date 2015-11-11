//Language: GNU C++0x


#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
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
#include <ctime>
#include <limits>
using namespace std;

#define pairii pair<int, int>
#define llong long long
#define pb push_back
#define sortall(x) sort((x).begin(), (x).end())
#define INFI  numeric_limits<int>::max()
#define INFL  numeric_limits<long>::max()
#define INFLL numeric_limits<llong>::max()
#define INFD  numeric_limits<double>::max()
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923
#define FOR(i,s,n) for (int (i) = (s); (i) < (n); (i)++)
#define FORZ(i,n) FOR((i),0,(n))

int powInt(int x, int y) {
    int r = 1;
    while (y > 0) {
        if (y & 1) r = (r * x);
        x = (x * x);
        y /= 2;
    }
    return r;
}

int qrt(long k, int ex) {
    int res = 1;
    while (powInt(res, ex) <= k) {
        res++;
    }
    return res-1;
}

int main() {
    int k;
    cin >> k;
    vector<int> nds;
    int ex = 3;
    int sum, n;
    do {
        int tmpk = k;
        sum = 0;
        while (tmpk > 0) {
            int tmp = qrt((long)tmpk, ex);
            nds.pb(tmp);
            tmpk -= powInt(tmp,ex);
        }
        FORZ(i,nds.size()) {
            sum+=nds[i];
        }
        n = ex*sum + 2;
        if (n > 1000) {
            nds.clear();
            ex++;
        }
    } while (n > 1000);

    string init(n,'N');
    vector<string> g(n, init);
    FOR(i, 2, sum+2) {
        g[0][i] = 'Y';
        g[i][0] = 'Y';
        g[1][i+(ex-1)*sum] = 'Y';
        g[i+(ex-1)*sum][1] = 'Y';
    }
    int offset = 2;
    cout << n << endl;
    FORZ(i,nds.size()) {
        int c = nds[i];
        FOR(j,offset,offset+c) {
            FOR(q,0,ex-1) {
                FOR(p,0,nds[i]) {
                    g[j+q*sum][(q+1)*sum+p+offset] = 'Y';
                    g[(q+1)*sum+p+offset][j+q*sum] = 'Y';
                }
            }
        }
        offset += c;
    }
    
    FORZ(i,n) {
        cout << g[i] << endl;
    }
    return 0;
}