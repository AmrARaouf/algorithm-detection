//Language: GNU C++


#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fornd(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define forabd(i, a, b) for (int i = (int)(b); i >= (int)(a); i--)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define clr(a , b) memset(a, b, sizeof(a))
#define sqr(x) ((x) * (x))
#define fil(a, b) memset(a, b, sizeof(a));
#define pb push_back
#define mp make_pair
#define se(x) cout<<#x<<" = "<<x<<endl
#define inf 0x3f3f3f3f
#define pai acos(-1.0)
#define mod 100000000
#define MAXN 600100
#define eps 1e-8
#define L(x) ((x) << 1)
#define R(x) ((x) << 1 | 1)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

int head[2*MAXN] , pre[2*MAXN] , nxt[2*MAXN] , now[2*MAXN] , e ;
int dfn[MAXN] , low[MAXN] , vis[MAXN] , ch[2*MAXN] ;
int n , m , idx ;

void init() {
    clr(head , -1) ;
    clr(vis , 0) ;
    clr(ch , 0) ;
    e = 0 ;
    idx = 0 ;
}

void addedge(int u , int v) {
    pre[e] = v , nxt[e] = head[u] , now[e] = u , head[u] = e++ ;
}

int dfs(int u) {
    dfn[u] = low[u] = ++idx ;
    vis[u] = 1 ;
    for(int i = head[u] ; i != -1 ; i = nxt[i]) {
        int v = pre[i] ;
        if(ch[i ^ 1]) continue ;
        ch[i] = 1 ;
        if(vis[v]) low[u] = min(low[u] , dfn[v]) ;
        else {
            if(!dfs(v)) return 0 ;
            low[u] = min(low[u] , low[v]) ;
            if(dfn[u] < low[v]) return 0 ;
        }
    }
    return 1 ;
}

void solve() {
    init() ;
    forn(i , m) {
        int u , v ;
        scanf("%d%d", &u , &v) ;
        addedge(u , v) ;
        addedge(v , u) ;
    }
    if(!dfs(1)) {
        printf("0\n") ;
    }
    else {
        forn(i , e) {
            if(ch[i]) {
                printf("%d %d\n", now[i] , pre[i]) ;
            }
        }
    }
}

int main() {
//    freopen("in" , "r" , stdin) ;
//    freopen("out" , "w" , stdout) ;
    while(scanf("%d%d", &n , &m) != EOF) {
        solve() ;
    }
    return 0 ;
}
