//Language: MS C++


#pragma warning (disable : 4996)

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
#include <stack>
#include <algorithm>
#include <ios>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <queue>
#include <set>
#include <functional>
#include <cmath>
#include <sstream>
#include <map>
#include <memory.h>
#include <stdio.h>
#include <cassert>
#include <string.h>
#include <math.h>

#define forn(i , n) for (int i = 0; i < n; ++i)
#define down(i, n) for (int i = n - 1; i >= 0; --i)


using namespace std;

typedef unsigned long long int u64;
typedef long long int i64;
typedef vector<i64> vint;
typedef vector<i64> vi64;
typedef pair<int, int> pint;
typedef pair<i64, i64> pi64;

#define FILE_NAME "file"
#define CONTEST "k"
#define M_PI 3.14159265358979323846

double sqr(double a)
{
    return a * a;
}

const i64 inf = 100000000000000000LL;


#define MAXN 300000
#define MODULE 1000000007  
#define E  2.7182818284590452

struct Node
{
    Node()
    {
        u = 0;
    }
    int v;
    int u;
    vector<int> nbr;
};

struct Point
{
    int x, y;
    int used;
    Point()
    {
        used = 0;
    }
};



int main()
{
    clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(15);
    srand(13);
#ifdef FILE_INPUT
    freopen(FILE_NAME ".in", "r", stdin);
    freopen(FILE_NAME ".out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<Node> arr(n);
    forn(i, n)
    {
        cin >> arr[i].v;
    }
    vector<pi64> p(n);
    forn(i, n)
    {
        p[i].first = arr[i].v;
        p[i].second = i;
    }
    sort(p.begin(), p.end(), greater<pint>());
    forn(i, m)
    {
        int a, b;
        cin >> a >> b;
        --a, --b;
        arr[a].nbr.push_back(b);
        arr[b].nbr.push_back(a);
    }
    i64 ans = 0;
    forn(i, n)
    {
        int num = p[i].second;
        forn(j, arr[num].nbr.size())
        {
            int to = arr[num].nbr[j];
            if (arr[to].u == 0)
            {
                ans += arr[to].v;
            }
        }
        arr[num].u = 1;
    }
    cout << ans;
    return 0;
}