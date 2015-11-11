//Language: MS C++


#include <functional>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <sstream>
#include <string>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <set>
#include <map>

#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
typedef pair< int, int > pii;
typedef vector< int > vint;
typedef vector< int64 > vint64;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define forr(i, n) for (int i = (n) - 1; i >= 0; --i)

const int INF = 2000000000;
const double EPS = 1e-9;
const double PI = 3.1415926535897932384626433832795;

template< typename T >
T sqr(const T &x)
{
    return x * x;
}

template< typename T >
string GetString(const T &val)
{
    ostringstream sout;
    sout << val;
    return sout.str();
}


struct Edge
{
    int u, v, id;
    Edge(int _u = 0, int _v = 0, int _id = 0):
        u(_u), v(_v), id(_id) {}
};

struct DSU
{
    vint p;

    DSU(int _n)
    {
        p.resize(_n);
        forn (i, _n)
        {
            p[i] = i;
        }
    }

    int FindSet(int x)
    {
        if (p[x] == x) return x;
        return p[x] = FindSet(p[x]);
    }

    void Unite(int x, int y)
    {
        x = FindSet(x);
        y = FindSet(y);
        
        if ((rand() >> 8) & 1)
            p[x] = y;
        else
            p[y] = x;
    }

    void Unite(const Edge &e)
    {
        Unite(e.u, e.v);
    }

    bool IsIcident(const Edge &e)
    {
        return FindSet(e.u) == FindSet(e.v);
    }
};


const int MAXN = 1001;
const int MAXM = 100005;

vector< Edge > S, M;
int n, m;

void Die()
{
    cout << -1 << endl;
    exit(0);
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("E.txt", "r", stdin);
#endif

    cin >> n >> m;
    forn (i, m)
    {
        char c;
        int u, v;
        cin >> u >> v >> c;
        --u, --v;
        (c == 'S' ? S : M).pb(Edge(u, v, i + 1));
    }

    if (!(n & 1)) Die();

    int cnt = (n - 1) / 2;

    vint res;
    DSU a(n), b(n);
    forn (i, S.size())
    {
        a.Unite(S[i]);
    }
    int mCnt = 0;
    forn (i, M.size())
    {
        if (!a.IsIcident(M[i]))
        {
            a.Unite(M[i]);
            b.Unite(M[i]);
            res.pb(M[i].id);
            ++mCnt;
        }
    }

    if (mCnt < cnt)
    {
        forn (i, M.size())
        {
            if (mCnt >= cnt) break;
            if (!b.IsIcident(M[i]))
            {
                b.Unite(M[i]);
                res.pb(M[i].id);
                ++mCnt;
            }
        }
    }

    int sCnt = 0;
    forn (i, S.size())
    {
        if (!b.IsIcident(S[i]))
        {
            b.Unite(S[i]);
            res.pb(S[i].id);
            ++sCnt;
        }
    }

    if (mCnt != cnt || sCnt != cnt) Die();

    cout << res.size() << endl;
    forn (i, res.size())
    {
        cout << res[i] << ' ';
    }
    cout << endl;
    

    return 0;
}