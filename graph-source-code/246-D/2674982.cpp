//Language: GNU C++


#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <cassert>
#include <complex>

using namespace std;

#define ST first
#define ND second
#define MP make_pair
#define PB push_back

typedef long long LL;
typedef long double LD;

typedef vector<int> VI;
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(VAR(i,a);i<(b);++i)
#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SIZE(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
#define ZERO(x) memset(x,0,sizeof(x))

VI color;

vector< set<int> > adj;

set<int> C;

int main () {
    int n,m;
    scanf("%d %d",&n,&m);
    color.assign(n,0);
    REP(i,n) { cin >> color[i]; C.insert(color[i]);}
    adj.assign(*C.rbegin()+1, set<int>());
    REP(i,m) {
        int u,v;
        scanf("%d %d",&u,&v);
        --u; --v;
        if(color[u] != color[v]) {
            adj[color[u]].insert(color[v]);
            adj[color[v]].insert(color[u]);
        }
    }
    int maior = -10, ans = 10000010;
    for(set<int>::iterator it = C.begin(); it != C.end(); ++it) {
        int x = SIZE(adj[*it]);
        if(x > maior) {
            maior = x;
            ans = *it;
        }
    }
    printf("%d",ans);
    return 0;
}