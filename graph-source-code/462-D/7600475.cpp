//Language: GNU C++


/* DELAPAN.3gp */
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <utility>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
using namespace std;

#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__)
	#define GetTime() fprintf(stderr,"Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC)
#else
	#define debug(...) 
	#define GetTime() 
#endif

//type definitions
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vint;

//abbreviations
#define A first
#define B second
#define MP make_pair
#define PB push_back

//macros
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define REPD(i,n) for (int i = (n)-1; 0 <= i; --i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for (int i = (a); (b) <= i; --i)
#define FORIT(it,c) for (__typeof ((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define ALL(a) (a).begin(),(a).end()
#define SZ(a) ((int)(a).size())
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) ((s).find(a) != (s).end())
#define MX(a,b) a = max((a),(b));
#define MN(a,b) a = min((a),(b));

inline void OPEN(const string &s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

/* -------------- end of DELAPAN.3gp's template -------------- */

#define MOD 1000000007LL

int n;
vector<int> adj[100005];
int black[100005];

long long dp[100005][5];
int vis[100005];


void work(int pos, int parent){
	if (vis[pos]) return;
	vis[pos] = 1;

	dp[pos][1] = 0LL;
	dp[pos][0] = 1LL;
	
	REP(i, SZ(adj[pos])){
		int u = adj[pos][i];
		if (u == parent) continue;

		work(u, pos);

		dp[pos][1] = (dp[pos][1] * dp[u][0]) % MOD;
		dp[pos][1] = (dp[pos][1] + (dp[pos][0] * dp[u][1]) % MOD) % MOD;
		dp[pos][0] = (dp[pos][0] * dp[u][0]) % MOD;
	}
	if (black[pos])
		dp[pos][1] = dp[pos][0];
	else		
		dp[pos][0] = (dp[pos][0] + dp[pos][1]) % MOD;
}

int main(){
	scanf("%d", &n);
	REP(i, n-1){
		int x;
		scanf("%d", &x);

		adj[i+1].PB(x);
		adj[x].PB(i+1);
	}
	int impossibru = 1;
	REP(i, n){
		scanf("%d", &black[i]);
		if (black[i]) impossibru = 0;
	}

	if (impossibru){
		printf("0\n");
		return 0;
	}

	RESET(vis, 0);
	work(0,-1);
	printf("%I64d\n", dp[0][1]);

	return 0;
}
