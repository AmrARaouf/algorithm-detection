//Language: GNU C++


//#pragma comment(linker,"/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <ctime>
#include <numeric>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <complex>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
using namespace std;
template<class T> inline T sqr(T x) { return x * x; }
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<LL, LL> PLL;
typedef pair<LL, int> PLI;
typedef pair<LD, LD> PDD;
#define MP make_pair
#define PB push_back
#define sz(x) ((int)(x).size())
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define FOR(i,n) for(int i=0;i<(n);++i)
#define forIt(mp,it) for(__typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))

using namespace std;

#define MAXE 4100005
#define MAXN 4005

int head[MAXN],e[MAXE],nxt[MAXE];
int cnt = 0;

void addEdge(int a,int b){
	e[cnt] = b;
	int tmp = head[a];
	head[a] = cnt;
	nxt[cnt++] = tmp;
}

int a[2005][2005];

int pre[MAXN],lowlink[MAXN],sccno[MAXN];
int dfs_clock,scc_cnt;
stack<int> s;

void tarjan(int u){
	pre[u] = lowlink[u] = ++dfs_clock;
	s.push(u);
	for(int i = head[u];~i;i = nxt[i]){
		int v = e[i];
		if(!pre[v]){
			tarjan(v);
			lowlink[u] = min(lowlink[u],lowlink[v]);
		}else if(!sccno[v]){
			lowlink[u] = min(lowlink[u],pre[v]);
		}
	}
	if(lowlink[u]==pre[u]){
		scc_cnt++;
		for(;;){
			int x = s.top();s.pop();
			sccno[x] = scc_cnt;
			if(x==u) break;
		}
	}
}

//求有向图的强联通分量
void find_scc(int n){
	dfs_clock = scc_cnt = 0;
	for(int i = 0;i<n;i++) sccno[i] = pre[i] = 0;
	for(int i = 0;i<n;i++)
		if(!pre[i]) tarjan(i);
}

int main(void){
#ifndef ONLINE_JUDGE
	//freopen("/Users/mac/Desktop/data.in","r",stdin);
#endif
	int n;
	scanf("%d",&n);
	memset(head,-1,sizeof(head));
	for(int i = 0;i<n;i++){
		addEdge(i+n,i);
		for(int j = 0;j<n;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]) addEdge(i,j+n);
		}
	}
	find_scc(2*n);
	if(scc_cnt==1) puts("YES");
	else puts("NO");
	return 0;
}
