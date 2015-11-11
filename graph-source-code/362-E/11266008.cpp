//Language: GNU C++11


/* in the name of ALLAH, most gracious, most merciful */

//{{{ ************[       Template       ]************
#include <bits/stdtr1c++.h>
using namespace std;
//{{{ ************[  Loops               ]************
#define FORAB(i, a, b)  for (__typeof (b) i = (a), i##_b = (b); i <= i##_b; ++i)
#define REP(i, n)       FORAB (i, 0, (n) - 1)
#define FOR(i, n)       FORAB (i, 1, (n))
#define ROFBA(i, a, b)  for (__typeof (b) i = (b), i##_a = (a); i >= i##_a; --i)
#define PER(i, n)       ROFBA (i, 0, (n) - 1)
#define ROF(i, n)       ROFBA (i, 1, (n))
#define FOREACH(i, s)   for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
//}}}
//{{{ ************[  Floating points     ]************
#define EPS             DBL_EPSILON
#define ABS(x)          (((x) < 0) ? - (x) : (x))
#define ZERO(x)         (ABS (x) < EPS)
#define EQUAL(x, y)     (ZERO ((x) - (y)))
//}}}
//{{{ ************[  Macros              ]************
#define MS(x, y)        memset ((x), y, sizeof ((x)))
#define CLR(x)          MS ((x), 0)
#define RST(x)          MS ((x), -1)
#define ALL(x)          (x).begin (), (x).end ()
#define SZ(x)           ((int) (x).size ())
#define UNIQUE(x)       (x).resize (unique (ALL (x)) - (x).begin ())
#define PB              push_back
#define MP              make_pair
#define F               first
#define S               second
//}}}
//{{{ ************[  Debugger            ]************
template <class A, class B> ostream &operator << (ostream &o, const pair <A, B> &p) { // for std::pair
    return o << "(" << p.first << ", " << p.second << ")";
}

template <class T> void __print__ (string param, T &x) { cout << param << " :: " << x << endl; }
template <class T> void __print__ (string param, T x [], int n) {
    cout << string (param, 0, param.find (',')) << " :: ";
    REP (i, n) cout << (i ? ", " : "[") << x [i]; cout << "]\n";
}

template <class T> void __stl_print__ (T &x) { // for all STL containers
    cout << "["; FOREACH (i, x) cout << (i != x.begin () ? ", " : "") << *i; cout << "]" << endl;
}

#define NL { cout << endl; }
#define LOG(...) { __print__ (#__VA_ARGS__, __VA_ARGS__); }
#define SLOG(x) { cout << #x << " :: "; __stl_print__ (x); }
//}}}
//{{{ ************[  Utilities           ]************
template <class A, class B, class C> inline C power (A p, B e, C m) {
    long long ret = 1;
    for (; e; e >>= B (1)) {
        if (e & 1) ret = (ret * p) % m;
        p = (p * p) % m;
    }
    return (C) (ret >= 0 ? ret : (ret + m));
}

template <class T> inline bool read (T &x) {
    int c, sgn = 1;
    for (c = getchar (); ~c && (c <'0' || c > '9'); c = getchar ()) if (c == '-') sgn = -1;
    for (x = 0; ~c && ('0' <= c && c <= '9'); c = getchar ()) x = x * 10 + c - '0';
    x *= sgn;
    return ~c;
}

vector <string> tokenizer (string s) {
    vector <string> vs; istringstream iss (s);
    for (string token; iss >> token; ) vs.PB (token);
    return vs;
}

template <class A, class B> inline A max (A a, B b) { return a > b ? a : b; }
template <class A, class B> inline A min (A a, B b) { return a < b ? a : b; }
template <class A, class B> inline void swap (A &a, B &b) { A temp = a; a = b; b = temp; }
template <class A, class B> inline B mod (A a, B m) { return (a %= m) >= 0 ? a : (a + m); }
template <class A, class B> inline B modInv (A a, B m) { return power (a, m - 2, m); }
template <class A> string toString (A x) { stringstream ss; ss << x; return ss.str (); }
template <class A> void toNumber (string s, A &x) { istringstream iss (s); iss >> x; }

// int dx [] = {0, -1, 0, 1}, dy [] = {-1, 0, 1, 0}; // 4 directions, clockwise
// int dx [] = {0, -1, -1, -1, 0, 1, 1, 1}, dy [] = {-1, -1, 0, 1, 1, 1, 0, -1}; // 8 directions, clockwise
// int dx [] = {-1, -2, -2, -1, 1, 2, 2, 1}, dy [] = {-2, -1, 1, 2, 2, 1, -1, -2}; // knight's move, clockwise

// cin.sync_with_stdio (false); cin.tie (false);
// cout << fixed << setprecision (10) << p << endl;
//}}}
//{{{ ************[  Typedefs && Consts  ]************
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <PII> VII;

const int MAX_N = int (1e2) + 7;
const int MAX_E = int (1e4) + 7;
// const int MOD   = int (1e9) + 7;
const int INF   = 1 << 30;
const double PI = 2 * acos (0.0);
//}}}
//}}}

//{{{ ************[         MCMF         ]************
// 1. Complexity: 
// 2. All edges are directed
// 3. Change FLOW_TYPE
// 4. Adjust queue size

typedef int FLOW_TYPE;
FLOW_TYPE f [MAX_E], c [MAX_E];

int nV, s, t, d [MAX_N], p [MAX_N], mark [MAX_N], last [MAX_N];
int nE, to [MAX_E], from [MAX_E];
LL w [MAX_E];

inline void addEdge (int u, int v, FLOW_TYPE cap, LL weight) { 
    to [nE] = v, from [nE] = last [u], f [nE] = 0, c [nE] = cap, last [u] = nE, w [nE++] = weight;
    to [nE] = u, from [nE] = last [v], f [nE] = 0, c [nE] = 0, last [v] = nE, w [nE++] = -weight;
}

int q [MAX_N * 10]; // is this enough?
LL mcmf (LL minCost) {
    FLOW_TYPE flow = 0;

    while (true) {
        RST (p);
        p [s] = -2; d [s] = 0; q [0] = s;

        for (int l = 0, r = 1; l < r; ) {
            int u = q [l++]; mark [u] = 0;

            for (int e = last [u]; ~e; e = from [e]) {
                int v = to [e];
                if ((c [e] - f [e]) && (p [v] == -1 || d [u] + w [e] < d [v])) {
                    d [v] = d [u] + w [e];
                    p [v] = e;

                    if (!mark [v]) q [r++] = v, mark [v] = 1;
                }
            }
        }

        if (p [t] == -1) break;

        int F = -1;
        for (int i = t; i != s; i = to [p [i] ^ 1])
            if (F == -1 || F > c [p [i]] - f [p [i]])
                F = c [p [i]] - f [p [i]];
        for (int i = t; i != s; i = to [p [i] ^ 1])
            f [p [i]] += F, f [p [i] ^ 1] -= F;

        if (1LL * F * d [t] <= minCost) minCost -= F * d [t], flow += F;
        else { flow += minCost / d [t]; break; }
    }

    return flow;
}


void init (int _nV) {
    nV = _nV; s = 0, t = nV - 1;
    nE = 0; RST (last);
}
//}}}

int main () {
#ifdef Local
    freopen ("input.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
#endif

    int n, k;
    scanf ("%d %d", &n, &k);

    init (n);
    REP (i, n) REP (j, n) {
        int x; scanf ("%d", &x);
        if (!x) continue;

        addEdge (i, j, x, 0);
        addEdge (i, j, k, 1);
    }

    printf ("%d\n", (int) mcmf (k));
    return 0;
}

