//Language: GNU C++


#include <iostream>
#include <fstream>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <cstdio>
#include <assert.h>

#define mset(x,y) memset(x,y,sizeof(x))
#define INF 1000000000
#define MOD 1000000007
#define pb(X) push_back(X) 
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define FOR(i,n) for (int i=0; i<(n); i++)
#define foreach(it, c) for(__typeof(c.begin()) it = c.begin(); it != c.end(); ++it)
#define gi(n) scanf("%d",&n)
#define gli(n) scanf("%lld",&n)
#define gd(n) scanf("%lf",&n)
#define gs(n) scanf("%s",n)
#define sz(v) ((int) v.size())
#define mp(a, b) make_pair(a, b)
 
using namespace std;
 
typedef long long int lli;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<double> vd;

vector<int> adl[3010];
vector<int> radl[3010];

int cnt[3010][3010];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    int a,  b;
    FOR(i, m)
    {
        scanf("%d%d", &a, &b);
        a--, b--;
        adl[a].pb(b);
        radl[b].pb(a);
    }

    mset(cnt, 0);

    FOR(i, n)
        FOR(j, sz(adl[i]))
            FOR(k, sz(radl[i]))
                if(adl[i][j] != radl[i][k])
                    cnt[adl[i][j]][radl[i][k]]++;

    int sum = 0;

    FOR(i, n)
        FOR(j, n)
            sum += (cnt[i][j] * (cnt[i][j] - 1))/2;

    printf("%d\n", sum);


    return 0;
}