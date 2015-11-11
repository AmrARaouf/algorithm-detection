//Language: GNU C++


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
#include <fstream>
#include <list>
using namespace std;


//LOOP
#define FF(i, a, b) for(int i = (a); i < (b); ++i)
#define FE(i, a, b) for(int i = (a); i <= (b); ++i)
#define FED(i, b, a) for(int i = (b); i>= (a); --i)
#define REP(i, N) for(int i = 0; i < (N); ++i)
#define CLR(A,value) memset(A,value,sizeof(A))
#define FC(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)

//OTHER
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define all(x) (x).begin(),(x).end()

//INPUT
#define RI(n) scanf("%d", &n)
#define RII(n, m) scanf("%d%d", &n, &m)
#define RIII(n, m, k) scanf("%d%d%d", &n, &m, &k)
#define RIV(n, m, k, p) scanf("%d%d%d%d", &n, &m, &k, &p)
#define RV(n, m, k, p, q) scanf("%d%d%d%d%d", &n, &m, &k, &p, &q)
#define RS(s) scanf("%s", s)

//OUTPUT
#define WI(n) printf("%d\n", n)
#define WS(n) printf("%s\n", n)

//debug
//#define online_judge
#ifndef online_judge
#define debugt(a) cout << (#a) << "=" << a << " ";
#define debugI(a) debugt(a) cout << endl
#define debugII(a, b) debugt(a) debugt(b) cout << endl
#define debugIII(a, b, c) debugt(a) debugt(b) debugt(c) cout << endl
#define debugIV(a, b, c, d) debugt(a) debugt(b) debugt(c) debugt(d) cout << endl
#else
#define debugt(a)
#define debugI(v)
#define debugII(a, b)
#define debugIII(a, b, c)
#define debugIV(a, b, c, d)
#endif

#define sqr(x) (x) * (x)
typedef long long LL;
typedef unsigned long long ULL;
typedef vector <int> VI;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-10;
const int MOD = 1000000007;
const int MAXN = 110000;
const double PI = acos(-1.0);

template <class T>
T abs(T x)
{
    return x < 0 ? -x : x;
}

int ind[600], father[MAXN], dis[600][600];
int number, kase, type, a, b, c;

void init()
{
    REP(i, MAXN)
        father[i] = i;
}

int getfather(int n)
{
    if (father[n] == n)
        return n;
    else
        return father[n] = getfather(father[n]);
}

void merge(int a, int b)
{
    int fa = getfather(a), fb = getfather(b);
    father[fb] = fa;
}

int gettype(int n)
{
    return lower_bound(ind, ind + type, n) - ind;
}

int main()
{
//    freopen("in.txt", "r", stdin);
    while (~RIII(number, kase, type))
    {
        init();
        CLR(dis, INF);

        FE(i, 1, type)
        {
            RI(ind[i]);
            ind[i] += ind[i - 1];
        }
        FE(i, 1, kase)
        {
            RIII(a, b, c);
            if (c == 0)
                merge(a, b);
            int ta = gettype(a), tb = gettype(b);
            if (ta != tb)
                dis[ta][tb] = dis[tb][ta] = min(dis[ta][tb], c);
        }
        FE(i, 1, type)
        {
            int t = getfather(ind[i]);
            FF(j, ind[i - 1] + 1, ind[i])
            {
                if (getfather(j) != t)
                {
                    puts("No");
                    goto end;
                }
            }
        }
        puts("Yes");
        FE(i, 1, type)
            dis[i][i] = 0;
        //
        FE(k, 1, type) FE(i, 1, type) FE(j, 1, type)
            dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        FE(i, 1, type)
        {
            FE(j, 1, type)
                cout << (dis[i][j] == INF ? -1 : dis[i][j]) << ' ';
            cout << endl;
        }
        //
        end:;
    }
    return 0;
}
