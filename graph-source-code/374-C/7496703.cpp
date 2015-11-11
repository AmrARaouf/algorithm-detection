//Language: GNU C++


/* Divanshu Garg */

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include <cctype>
#include <cassert>
#include <complex>

using namespace std;

#define ull unsigned long long
#define ill long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define F(i,a,n) for(int i=(a);i<(n);++i)
#define REP(i,a,n) for(i=(a);i<(n);++i)
#define FD(i,a,n) for(int i=(a);i>=(n);--i)
#define FE(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define Sl(x) scanf("%llu",&x)
#define M(x,i) memset(x,i,sizeof(x))
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define MAX(a,b) ((a)>(b)?(a):(b))
ill ABS(ill a) { if ( a < 0 ) return (-a); return a; }
#define fr first
#define se second

/* Relevant code begins here */

/* Input from file or online */

void input() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
}

/* Input opener ends */

#define N 1003

bool inf;
char s[N][N];
int a[N][N];

int n,m;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int vis[N][N];
int dp[N][N];

char p[] = "DIMA";

int f(int x,int y) {
    if ( inf ) return 0;
    if ( vis[x][y] == 2 ) return dp[x][y];
    if ( vis[x][y] == 1 ) {
        inf = 1;
        return 0;
    }
    vis[x][y] = 1;
    dp[x][y] = 1;
    F(k,0,4) {
        int nx = x+dx[k], ny = y+dy[k];
        if ( nx < 0 || ny < 0 || nx >= n || ny >= m ) continue;
        if ( (a[x][y]+1)%4 != a[nx][ny] ) continue;
        dp[x][y] = max(dp[x][y],f(nx,ny)+1);
    }
    vis[x][y] = 2;
    return dp[x][y];
}

int main() {
    input();
    
    S(n); S(m);
    F(i,0,n) scanf("%s",s[i]);

    F(i,0,n) F(j,0,m) {
        if ( s[i][j] == 'D' ) a[i][j] = 0;
        if ( s[i][j] == 'I' ) a[i][j] = 1;
        if ( s[i][j] == 'M' ) a[i][j] = 2;
        if ( s[i][j] == 'A' ) a[i][j] = 3;
    }
    M(vis,0);
    inf = 0;
    int ans = 0;
    F(i,0,n) F(j,0,m) {
        if ( inf ) break;
        if ( !vis[i][j] ) {
            f(i,j);
        }
        if ( a[i][j] == 0 ) ans = max(ans,dp[i][j]/4);
    }

    if ( inf ) printf("Poor Inna!\n");
    else if ( !ans ) printf("Poor Dima!\n");
    else printf("%d\n", ans);

    return 0;
}