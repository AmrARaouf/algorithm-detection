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

#define MAXN 100005
#define MAXM 1000005

int vis[MAXM];
int circle[MAXM];
int tot,cnt;
int head[MAXN],nxt[MAXM],e[MAXM];
int in[MAXN],out[MAXN];
int deg[MAXN];
int cur[MAXN];

void addEdge(int u,int v){
	e[cnt] = v;
	int tmp = head[u];
	head[u] = cnt;
	nxt[cnt++] = tmp;
}

void dfs(int u){
	for(;~cur[u];cur[u] = nxt[cur[u]]){
		if(vis[cur[u]]) continue;
		vis[cur[u]] = vis[cur[u]^1] = 1;
		dfs(e[cur[u]]);
		if(cur[u]==-1) break;
	}
	circle[tot++] = u;
}

int main(void){
#ifndef ONLINE_JUDGE
	freopen("/Users/mac/Desktop/data.in","r",stdin);
#endif
	vector<PII> ans;
	int n,m;
	scanf("%d %d",&n,&m);
	memset(head,-1,sizeof(head));
	FOR(i,m){
		int a,b;
		scanf("%d %d",&a,&b);
		deg[a]++,deg[b]++;
		addEdge(a,b);
		addEdge(b,a);
	}
	int last = -1;
	for(int i = 1;i<=n;i++){
		if(deg[i]%2==1){
			if(~last){
				addEdge(last,i);
				addEdge(i,last);
				last = -1;
			}else last = i;
		}
	}
	for(int i = 1;i<=n;i++) cur[i] = head[i];
	for(int i = 1;i<=n;i++){
		if(~cur[i]){
			tot = 0;
			dfs(i);
			for(int j = 1;j<tot;j++){
				if(j&1) ans.PB(MP(circle[j],circle[j-1]));
				else ans.PB(MP(circle[j-1],circle[j]));
			}
			//FOR(j,tot) cout<<circle[j]<<" ";cout<<endl;
		}
	}
	int sz = ans.size();
	for(int i = 0;i<sz;i++){
		out[ans[i].first]++;
		in[ans[i].second]++;
	}
	vector<int> nin,nout;
	for(int i = 1;i<=n;i++){
		if(in[i]%2) nin.PB(i);
		if(out[i]%2) nout.PB(i);
	}
	int x = min(nin.size(),nout.size());
	for(int i = 0;i<x;i++) ans.PB(MP(nout[i],nin[i]));
	for(int i = x;i<(int)nin.size();i++) ans.PB(MP(1,nin[i]));
	for(int i = x;i<(int)nout.size();i++) ans.PB(MP(nout[i],1));
	sz = ans.size();
	printf("%d\n",sz);
	for(int i = 0;i<sz;i++) printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}

