//Language: GNU C++0x


//by maximumSHOT

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <time.h>
#include <clocale>
#include <fstream>
#include <conio.h>
#include <random> 
#include <utility>
#include <bitset>

using namespace std;

#define forx(i,n) for(int i(0);i < n;i++)
#define vec vector
#define mp make_pair
#define ALL(x) (x).begin(), (x).end()

typedef long L;
typedef long long LL;
typedef pair<LL, LL> pll;
typedef long double LD;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<double> vdouble;
typedef vector<vector<double>> vvdouble;
typedef vec<bool> vbool;
typedef vec<vec<bool>> vvbool;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;
typedef pair<int,double> pid;
typedef unsigned long long ull;
typedef unsigned int ui;
const int inf = 1000 * 1000 * 1000;
const LL inf64 = LL(inf) * inf;
const LL base  = 1e9+7;
inline LL Sqr(LL a){return a*a;}
struct Tripple
{
    int first;
    int second;
    int third;

    void make_tripple(int a,int b,int c)
    {
        first  = a;
        second = b;
        third  = c;
    }
};
bool cmp1(Tripple a,Tripple b)
{
    return a.first < b.first;
}
bool cmp2(Tripple a,Tripple b)
{
    return a.second < b.second;
}
bool cmp3(Tripple a,Tripple b)
{
    return a.third < b.third;
}

// GL begin

vec<LL> parent;
LL n;
vec<pll> crd;

// GL end

//Functions begin

void make_set(int v)
{
    parent[v] = v;
}

int find_set(int v)
{
    if(parent[v] == v) return v;
    return parent[v] = find_set(parent[v]);
}

void union_set(int a,int b)
{
    int q = find_set(a);
    int p = find_set(b);
    parent[p] = q;
}

//Functions end

bool solve()
{
    ios_base::sync_with_stdio(0);
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    srand(time(NULL));
    //#define cin fin
    //#define cout fout

    cin >> n;

    parent.resize(n);
    crd.resize(n);

    for(int i(0);i < n;i++)
    {
        make_set(i);
        cin >> crd[i].first >> crd[i].second;
    }

    for(int i(0);i < n;i++)
    {
        for(int j(0);j < n;j++)
        {
            if(i == j) continue;
            if(crd[i].first == crd[j].first || crd[i].second == crd[j].second) 
                union_set(i, j);
        }
    }

    LL ans = 0;

    for(int i(0);i < n;i++)
    {
        for(int j(0);j < n;j++)
        {
            if(i == j) continue;
            bool f = (find_set(i) == find_set(j));
            if(f) continue;
            else
            {
                ans++;
                union_set(i, j);
            }
        }
    }

    cout << ans << '\n';

    //_getch();
    return true;
}

int main(int argc,char **argv)
{
    //while(solve());
    solve();

    return 0;
}