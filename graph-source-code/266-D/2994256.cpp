//Language: GNU C++


#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <ctime>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <utility>
#include <complex>
#include <vector>
#include <bitset>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define x1 ___x1
#define y1 ___y1
#define X first
#define ft first
#define Y second
#define sc second

const int INF = 1000 * 1000 * 1000;
const long double EPS = 1e-13;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt; 

const int N = 200 + 13;
int n, m;

vector<pair<pair<int, int>, int> > e;

inline bool read ()
{
    if (scanf ("%d%d", &n, &m) != 2)
        return false;
        
    forn (i, m)
    {
        int x, y, l;
        
        assert(scanf ("%d%d%d", &x, &y, &l) == 3);
        
        x--, y--;
        
        e.pb(mp(mp(x, y), l));
    }   

    return true;
}

int a[N][N];

const int K = 50;
const int M = 20;

ld ans = INF;

inline ld f (ld val, int x, int y, int len)
{
    ld res = 0;
    
    forn (i, n)
    {
        ld tmp = min(a[x][i] + val, a[y][i] + len - val);
        
        res = max(res, tmp);
        
        if (res > ans - EPS)
            return res;
    }
    
    return res;
}

inline ld calc (int x, int y, int len)
{
    ld d = ld(len) / ld(K);
    
    ld res = INF;

    forn (it1, K)
    {
        ld l = it1 * d, r = (it1 + 1) * d;
    
        forn (it, M)
        {
            ld m1 = l + (r - l) / ld(3), m2 = r - (r - l) / ld(3);
            
            if (f(m1, x, y, len) > f(m2, x, y, len))
                l = m1;
            else
                r = m2;
        }
        
        res = min(res, f((r + l) / ld(2), x, y, len));
    }
    
    return res;
}

inline void solve ()
{
    forn (i, n)
        forn (j, n)
            a[i][j] = INF;

    forn (i, m)
    {
        int x = e[i].ft.ft, y = e[i].ft.sc, l = e[i].sc;
        
        a[x][y] = min(a[x][y], l);
        a[y][x] = min(a[y][x], l);
    }
    
    forn (i, n)
        a[i][i] = 0;
        
    forn (k, n)
        forn (i, n)
            forn (j, n)
                if (a[i][k] != INF && a[k][j] != INF)
                    a[i][j] = min(a[i][j], a[i][k] + a[k][j]);                    
    forn (it, m)
    {
        int x = e[it].ft.ft, y = e[it].ft.sc, l = e[it].sc;
        
        ans = min(ans, calc(x, y, l));
    }
    
    li tmp = li(ans * ld(2) + ld(0.1));
    
    printf ("%.15lf\n", double(ld(tmp) / ld(2)));
}

int main () 
{   
  //  freopen ("input.txt", "r", stdin);
  //  freopen ("output.txt", "w", stdout);
    
 /* n = 200, m = 19900;
    
    forn (i, n)
        for (int j = i + 1; j < n; j++)
            e.pb(mp(mp(i, j), 100000));*/
            
    assert(read());
    solve();
    
    return 0;
}