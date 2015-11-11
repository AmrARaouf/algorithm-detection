//Language: GNU C++11


// Smile please :)

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cctype>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <climits>
//#include <unordered_map>
//#include <unordered_set>
using namespace std;

//#undef KVARK_DEBUG

#ifdef KVARK_DEBUG
    #include "../h/debug.h"
#else
#define dbg(...) (void(1));
#define dbg2(...) (void(1));
#define dbg3(...) (void(1));
#define dbg4(...) (void(1));
#define dbg5(...) (void(1));
#define dbgp(...) (void(1));
#define dbg_arr(...) (void(1));
#define dbg_vec(...) (void(1));
#endif
#define endl "\n"

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vector<int> > vvi;
typedef vector<vector<pii> > vvpii;
typedef vector<vector<long long> > vvll;
typedef vector<long long> vll;
typedef long long int llint;

#define all(v) (v.begin()), (v.end())

template <typename T>
inline T sqr(const T& a) {
    return a * a;
}

template <typename T>
inline int sign(const T& a) {
    return a < 0 ? -1 : a > 0;
}

void task();

int main() {
#ifdef KVARK
    freopen("src/input.txt", "r", stdin);
    //freopen("src/debug.txt", "w", stderr);
    //freopen("src/output.txt", "w", stdout);
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
ios_base::sync_with_stdio(0);

    task();

#ifdef KVARK_DEBUG
    my_debug::printProcessInfo();
#endif
    return 0;
}

int n;

int id = 2;
vpii g;

void create() {
    for (int i = 0; i < n - 1; ++i)
        g.push_back(pii{id, id + i + 1});

    ++id;
    for (int i = id; i < id + n-1; ++i)
        for (int j = id + n-1; j < id + 2 * n-2; ++j)
            g.push_back(pii{i, j});

    for (int j = id + n-1; j < id + 2 * n-2; j += 2)
        g.push_back(pii{j, j + 1});

    id = id + 2 * n - 2;
}

void task(){
    cin >> n;
    if (n == 1) {
        cout << "YES\n";
        cout << "2 1\n1 2";
        return;
    }

    if (n % 2 == 0) {
        cout << "NO";
        return;
    }

    for (int i = 0; i < n; ++i) {
        g.push_back(pii{1, id});
        create();
    }

    cout << "YES\n";
    cout << id - 1 << ' ' << g.size() << endl;
    for (auto p: g)
        cout << p.first << ' ' << p.second << endl;

}
