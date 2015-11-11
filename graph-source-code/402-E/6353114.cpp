//Language: GNU C++


//#pragma warning (disable: 4786)
//#pragma comment (linker, "/STACK:16777216")
//HEAD
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <string>
#include <set>
#include <stack>
#include <map>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;
//LOOP
#define FE(i, a, b) for(int i = (a); i <= (b); ++i)
#define FD(i, b, a) for(int i = (b); i>= (a); --i)
#define REP(i, N) for(int i = 0; i < (N); ++i)
#define CLR(A,value) memset(A,value,sizeof(A))
#define CPY(a, b) memcpy(a, b, sizeof(a))
#define FC(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
//INPUT
#define RI(n) scanf("%d", &n)
#define RII(n, m) scanf("%d%d", &n, &m)
#define RIII(n, m, k) scanf("%d%d%d", &n, &m, &k)
#define RS(s) scanf("%s", s)
//OUTPUT
#define WI(n) printf("%d\n", n)
#define WS(s) printf("%s\n", s)

typedef long long LL;
const int INF = 1000000007;
const double eps = 1e-10;
const int MAXN = 1000010;

int n;
bitset<2010>f[2010];
int main ()
{
    RI(n);
    REP(i, n) REP(j, n)
    {
        int x;
        RI(x);
        f[i][j] = !!x;
    }
    REP(k, n) REP(i, n)
    if (f[i][k]) f[i] |= f[k];
    int fla = 1;
    REP(i, n) REP(j, n) if (!f[i][j])
    {
        fla = 0; break;
    }
    if (fla) puts("YES");
    else puts("NO");
    return 0;
}
