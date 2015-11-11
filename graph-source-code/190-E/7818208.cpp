//Language: GNU C++0x


#pragma warning( disable : 4996)
#define _USE_MATH_DEFINES
#pragma comment(linker, "/STACK:666000000")

#define bublic public

#include <algorithm>
#include <assert.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <time.h>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>

#define nextLine() {for(int c=getchar(); c!='\n' && c!=EOF; c=getchar());}
#define sqr(a) ((a)*(a))
#define has(mask,i) (((mask) & (1<<(i))) == 0 ? false : true)
#define set_true(mask, i) (mask|(1<<(i)))
#define set_false(mask, i) (~((~mask)|(1<<(i))))

#define Equal(a, b) (fabsl(a, b) < 1e-9)
#define Less(a, b) (a < b && !Equal(a, b))
#define Greater(a, b) (a > b && !Equal(a, b))

using namespace std;

#ifdef SCHULLZ
#define TASK "file"
#define eprintf(...) fprintf(stdout, __VA_ARGS__)
#define parr(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++)cout<<a[i][j]<<" ";puts("");}puts("");
#define log(x) cout << #x << " = " << x << endl
#else
#define TASK "file"
#define eprintf(...) 
#define parr(a,n,m)
#define log(x)
#endif

#define pb(_o_) push_back(_o_)

typedef long long LL;
typedef unsigned long long ULL;
typedef long double ldb;

typedef pair<int,int> pii;
typedef pair<pii,int> tiii;
typedef pair<pii,pii> fiiii;
#define aaa first.first
#define bbb first.second
#define ccc second.first
#define ddd second.second
#define mp(x, y) make_pair(x, y)
#define mpp(x, y, z) make_pair(mp(x, y), z)
#define mppp(x, y, z, a) make_pair(mp(x, y), mp(z, a))

#define sci(a) (1 == scanf("%d", &a))
#define scii(a,b) (2 == scanf("%d%d", &a, &b))
#define sciii(a,b,c) (3 == scanf("%d%d%d", &a, &b, &c))
#define sciiii(a,b,c,d) (4 == scanf("%d%d%d%d", &a, &b, &c, &d))
#define sciiiii(a,b,c,d,e) (5 == scanf("%d%d%d%d%d", &a, &b, &c, &d, &e))

#define scin(a) (1 == scanf("%d\n", &a))
#define sciin(a,b) (2 == scanf("%d%d\n", &a, &b))
#define sciiin(a,b,c) (3 == scanf("%d%d%d\n", &a, &b, &c))
#define sciiiin(a,b,c,d) (4 == scanf("%d%d%d%d\n", &a, &b, &c, &d))
#define sciiiiin(a,b,c,d,e) (5 == scanf("%d%d%d%d%d\n", &a, &b, &c, &d, &e))

#define FORN(i,n) for(int i = 0; i < (int)n; i++)
#define FORR(i,n) for(int i = n - 1; i >= 0; i--)
#define FORS(it,a) for(auto it = a.begin(); it != a.end(); it++)

typedef vector<int> vi;
typedef vector<vi> vvi;

#ifdef SCHULLZ
typedef vector<int> vc;
typedef vector<vc> vvc;
#else
typedef vector<char> vc;
typedef vector<char> vvc;
#endif

const int INF = (1 << 30) - 1;
const ldb EPS = 1e-9;

void ML(const bool v)
{
    if (v)
        return;
    int *ass;
    for (;;)
    {
        ass = new int[2500000];
        for (int i = 0; i < 2500000; i++)
            ass[i] = rand();
    }
}

void TL(const bool v)
{
    if (v)
        return;
    for (;;)
        cout << rand() % (rand() % 1000 + 1) << endl;
}

void PE(const bool v)
{
    if (v)
        return;
    for (int i = 0; i < 10000; i++)
        printf("%c", rand() % 256);
    exit(0);
}

int n, m;
vector<unordered_set<int> > b;


bool LoAd()
{
    b.clear();
    if (!scii(n, m))
        return false;
    b.resize(n + 1);
    for (int f, t, i = 0; i < m; i++)
    {
        scii(f, t);
        b[f].insert(t);
        b[t].insert(f);
    }
    //for (int i = 1; i <= n; i++)
    //  sort(b[i].begin(), b[i].end());
    return true;
}

vvi res;
//bool was[500500];
set<int> not_was;

void bfs(const int v0)
{
    queue<int> q;
    q.push(v0);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        res.back().push_back(v);
        int doom = -1;
        FORS(it, not_was) if (*it != v && b[v].count(*it) == 0)
        {
            if (-1 != doom)
                not_was.erase(doom);
            q.push(*it);
            doom = *it;
        }
        if (-1 != doom)
            not_was.erase(doom);
    }

}

int p[500500];

void SoLvE()
{
    res.clear();
    //memset(was, false, sizeof(was));
    for (int i = 1; i <= n; i++)
    {
        not_was.insert(i);
        p[i] = i;
    }
    random_shuffle(p + 1, p + n + 1);
    for (int ii = 1; ii <= n; ii++)
    {
        int i = p[ii];
        if (1 == not_was.count(i))
        {           
            not_was.erase(i);
            res.push_back(vi());
            bfs(i);
        }
    }
    cout << res.size() << endl;
    FORS(it, res)
    {
        printf("%d", it->size());
        FORS(jt, (*it))
            printf(" %d", *jt);
        puts("");
    }
}

int main()
{
    srand( (int) time(NULL));
    //srand( (int) 43);
#ifdef SCHULLZ
    freopen(TASK".in","r",stdin);   freopen(TASK".out","w",stdout);
    for (int i = 0; LoAd(); i++)
        SoLvE();
#else
    LoAd();
    SoLvE();
#endif
    return 0;
}