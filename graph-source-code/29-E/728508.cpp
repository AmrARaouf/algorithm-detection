//Language: GNU C++


#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<set>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;

#define FOR(x,y,z) for(int x=y;x<=z;++x)
#define FORD(x,y,z) for(int x=y;x>=z;--x)
#define FOReach(x,Z) for(__typeof((Z).begin()) x=(Z).begin();x!=(Z).end();++x)
#define REP(x,y) for(int x=0;x<y;++x)

#define PB push_back
#define ALL(X) (X).begin(),(X).end()
#define SZ(X) ((int)(X).size())
#define CLR(X,x) memset(X, x, sizeof(X))

#define MP make_pair
#define ST first
#define ND second

#define DBG

#ifdef DBG
#define debug printf
#else
#define debug(fmt, ...)
#endif


const int MAX = 500;
const int INF = 1000000001;

VI G[MAX+1];

int D[MAX+1][MAX+1];
PII P[MAX+1][MAX+1];
bool vis[MAX+1][MAX+1][2];

int n, m;

VI ans1, ans2;

void bfs() {
	vector< pair<PII,bool> > Q;
	VPII parents;
	Q.PB(MP(MP(1, n), false));
	parents.PB(MP(0, 0));
	vis[1][n][0] = true;
	REP(foo,Q.size())
	{
		PII v = Q[foo].ST;
		bool c = Q[foo].ND;
		if(v == MP(n, 1) && !c) {
			printf("%d\n", D[n][1]);
			do
			{
				ans1.PB(v.ST);
				ans2.PB(v.ND);
				v = P[v.ST][v.ND];
			}
			while(v != MP(1, n));
			ans1.PB(1);
			ans2.PB(n);
			FOReach(i,ans2)
				printf("%d ", *i);
			printf("\n");
			FOReach(i,ans1)
				printf("%d ", *i);
			printf("\n");
			return;
		}
		if(!c) {
			FOReach(u,G[v.ST])
				if(!vis[*u][v.ND][1]) {
					vis[*u][v.ND][1] = true;
					Q.PB(MP(MP(*u, v.ND), true));
					parents.PB(v);
				}
		}
		else {
			FOReach(u,G[v.ND])
				if(!vis[v.ST][*u][0] && v.ST != *u) {
					vis[v.ST][*u][0] = true;
					P[v.ST][*u] = parents[foo];
					D[v.ST][*u] = D[parents[foo].ST][parents[foo].ND] + 1;
					Q.PB(MP(MP(v.ST, *u), false));
					parents.PB(MP(0, 0));
				}
		}
	}
	printf("-1\n");
}

int main(int argc, char *argv[]) {
	scanf("%d %d", &n, &m);
	while(m--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		G[a].PB(b);
		G[b].PB(a);
	}
	bfs();
	return 0;
}

