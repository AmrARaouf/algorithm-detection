//Language: GNU C++


#if defined(__GNUC__)
#pragma GCC optimize ("O2")
#endif
#if defined(_MSC_VER)
#pragma comment(linker, "/STACK:36777216")
#endif
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <ctime>
using namespace std;

#define CLR(arr,val) memset(arr,val,sizeof(arr))
#define SQR(x) ((x)*(x))
#define REP(i,a,b) for(int i=a;i<b;i++)
#define REV(i,a,b) for(int i=a-1;i>=b;i--)
#define rep(i,n) REP(i,0,n)
#define rev(i,n) REV(i,n,0)
#define ITER(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(v) v.begin(),v.end()
#define PB push_back
#define MP make_pair
#define PQ priority_queue
#define MPQ priority_queue<int, std::vector<int>, std::greater<int> >

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;

const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
const double PI = 3.141592653589793238;
const double eps = 1e-9;

inline int INT()
{
    register int c = getchar();
    int x = 0;
    for( ; ( c < 48 || c > 57 ); c = getchar() );
    for( ; ( c > 47 && c < 58 ); c = getchar() ) x = x * 10 + c - 48;
		return x;
}
#define MAX 100010
int d[MAX], deg[MAX];
vector<int> nodes[MAX];
bool vis[MAX];

int main()
{
	//std::ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen( "in.txt", "r", stdin );
	//freopen( "out.txt", "w", stdout );
	clock_t program_start, program_end;
	program_start = clock();
#endif
    int n = INT(), _max = INT();
    vector<PII > res;
    REP(i, 1, n + 1)
        d[i] = INT();
    REP(i, 1, n + 1)
        nodes[d[i]].PB(i);
    if ( nodes[0].size() != 1 ) goto fail;
    vis[nodes[0][0]] = true;
    rep(i, n)
    {
        rep(k, nodes[i].size())
        rep(j, nodes[i - 1].size())
        {
            int u = nodes[i - 1][j];
            int v = nodes[i][k];
            if ( deg[u] < _max && deg[v] < _max )
            {
                res.PB(make_pair(u, v));
                deg[u]++;
                deg[v]++;
                vis[v] = true;
                break;
            }
        }
    }
    REP(i, 1, n + 1) if ( !vis[i] )
        goto fail;
    printf("%d\n", res.size());
    rep(i, res.size())
        printf("%d %d\n", res[i].first, res[i].second);
    goto finished;
    fail:
        puts("-1");
    finished:;
#ifndef ONLINE_JUDGE
	program_end = clock();
	cerr << "Time consumed: " << endl << ( program_end - program_start ) << " MS" << endl;
#endif
}
