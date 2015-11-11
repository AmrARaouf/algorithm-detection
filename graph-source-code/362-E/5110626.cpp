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
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

using namespace std;

int aa[55][55];

#define MAXN 1005 
#define MAXE 100005

struct Edge{
	int from,to,cap,flow,cost;
	Edge(int from,int to,int cap,int flow,int cost):
		from(from),to(to),cap(cap),flow(flow),cost(cost){
	}
	Edge(){}
} e[MAXE];

int head[MAXN],d[MAXN],next[MAXE],a[MAXN],p[MAXN];
bool inq[MAXN];

class MCMF{
public:
	int cnt,s,t;
	int node;
	MCMF():cnt(0){
		memset(head,-1,sizeof(head));
	}
	void addEdge(int from,int to,int cap,int cost){
		e[cnt] = Edge(from,to,cap,0,cost);
		int tmp = head[from];
		head[from] = cnt;
		next[cnt++] = tmp;
		e[cnt] = Edge(to,from,0,0,-cost);
		tmp = head[to];
		head[to] = cnt;
		next[cnt++] = tmp;
	}
	bool spfa(LL &flow,LL &cost,LL c){
		for(int i = 0;i<=node;i++){
			d[i] = INF;
			inq[i] = false;
		}
		d[s] = 0,inq[s] = true,p[s] = 0,a[s] = INF;
		deque<int> q;
		q.push_front(s);
		while(!q.empty()){
			int u = q.front();
			q.pop_front();
			inq[u] = false;
			for(int i = head[u];~i;i = next[i]){
				Edge &ed = e[i];
				if(ed.cap>ed.flow&&d[ed.to]>d[u]+ed.cost){
					d[ed.to] = d[u]+ed.cost;
					p[ed.to] = i;
					a[ed.to] = min(a[u],ed.cap-ed.flow);
					if(!inq[ed.to]){
						inq[ed.to] = true;
                        if(!q.empty()&&d[ed.to]>d[q.front()]) q.push_front(ed.to);
                        else q.push_back(ed.to);
						//q.push(ed.to);
					}
				}
			}
		}
		if(d[t]==INF) return false;
		if(cost+1ll*d[t]*a[t]>c){
			flow+=(c-cost)/d[t];
			cost+=(c-cost)/d[t]*d[t];
			return false;
		}else{ 
			flow+=a[t];
			cost+=1ll*d[t]*a[t];
		}
		int u = t;
		while(u!=s){
			e[p[u]].flow+=a[t];
			e[p[u]^1].flow-=a[t];
			u = e[p[u]].from;
		}
		return true;
	}
	int maxFlow(LL c){
		LL flow = 0,cost = 0;
		while(spfa(flow,cost,c)){
		}
		return flow;
	}
	void buildGraph(int n,int k){
		node = n+1;
		for(int i = 1;i<=n;i++)
			for(int j = 1;j<=n;j++){
				if(aa[i][j]==0) continue;
				addEdge(i,j,aa[i][j],0);
				addEdge(i,j,k,1);
			}
		s = 1,t = n;
	}
 };


int main(void){
#ifndef ONLINE_JUDGE 
      freopen("/home/xing89qs/桌面/data.in","r",stdin);
#endif
	int n,k;
	cin>>n>>k;
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=n;j++) cin>>aa[i][j];
	MCMF mcmf;
	mcmf.buildGraph(n,k);
	printf("%d\n",mcmf.maxFlow(k));
}
