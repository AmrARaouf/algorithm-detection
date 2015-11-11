//Language: GNU C++0x


/*
 Author:   Harhro94 [Harutyunyan Hrayr]
 IDE:      Visual C++ 2012
*/
//#pragma comment(linker, "/STACK:66777216")
#define _CRT_SECURE_NO_WARNINGS
#include <functional>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <ctime>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
using namespace std;

typedef long long LL;
typedef long double LD;
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()

const int N = 207;
int n, m, be[N], en[N], col[N];
vector<int> G[N];
bool f, used[N];

void dfs(int u, int t = 0)
{
    used[u] = true;
    col[u] = t;
    for(int i = 0; i < sz(G[u]); ++i)
    {
        int to = G[u][i];
        if (used[to] && col[to] == t) f = true;
        if (!used[to]) dfs(to, 1 - t);
    }
}

int main()
{
#ifdef harhro94
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen(task".in", "r", stdin);
    //freopen(task".out", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        cin >> be[i] >> en[i];
        if (be[i] > en[i]) swap(be[i], en[i]);
    }
    for(int i = 0; i < m; ++i)
    {
        for(int j = i + 1; j < m; ++j)
        {
            if ((be[i] < be[j] && be[j] < en[i] && en[j] != en[i] && en[j] != be[i] && !(be[i] < en[j] && en[j] < en[i])) || 
                (be[i] < en[j] && en[j] < en[i] && be[j] != en[i] && be[j] != be[i] && !(be[i] < be[j] && be[j] < en[i]))) // cross
            {
                cerr << i + 1 << " "  << j + 1 << endl;
                G[i].pb(j);
                G[j].pb(i);
            }
        }
    }
    for(int i = 0; i < m; ++i)
        if (!used[i]) dfs(i);
    if (f) puts("Impossible");
    else for(int i = 0; i < m; ++i) putchar(col[i] ? 'i' : 'o');

#ifdef harhro94
    cerr << fixed << setprecision(3) << "\nExecution time = " << clock() / 1000.0 << "s\n";
#endif
    return 0;
}