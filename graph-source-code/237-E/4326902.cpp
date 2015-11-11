//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cctype>
#define vi vector < int >
#define mod 1000000007
#define inf 987654321
#define dinf -inf
#define lo long long int
#define S(n) scanf("%d",&n);
#define SL(n) scanf("%lld",&n);
#define P(n) printf("%d",n);
#define PL(n) printf("%lld",n);
#define spa printf(" ");
#define st(a,v) memset(a, v, sizeof (a))
#define nwl puts("");
using namespace std;

const int sz = 500 + 5;
int flow [ sz ][ sz ];
int mark [ sz ];
string tar;
int n;
int b=1;
int N;
int path (int node, int fl) {
    if (node == N - 1)
        return fl;
    mark [ node ] = b;
    for (int i = 0; i < N; i++) {
        if (mark [ i ] < b && flow[node][i]) {
            int tmp = path (i, min (fl, flow[node][i]));
            if (tmp > 0) {
                flow[node][i] -= tmp;
                flow[i][node] += tmp;
                return tmp;
            }
        }
    }
    return 0;
}
int main ( ) {
    cin >> tar >> n;
    N = n + 26 + 2;
    int len = (int)tar.size ( );
    for (int i = 0; i < len; i++) {
        flow [ n + 1 + tar[i] - 'a' ] [ N - 1]++;
    }
    for (int i = 0; i < n; i++) {
        string p;
        int q;
        cin >> p >> q;
        for (int j = 0; j < (int)p.size ( ); j++)
            flow[ i + 1] [ n + 1 + p[ j ] - 'a' ]++;
        flow[ 0 ][ i + 1 ] = q;///cost
    }
    while (path(0, 987654321)) {
        b++;
    }
  //  cout << b << endl;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = n + 1; j <= n + 26; j++)
            ans += i*flow[j][i];
    }
    for (int i = n + 1; i <= n + 26; i++)
        if (flow[i][ N - 1])
            ans = -1;
    P(ans);
    nwl;
}
