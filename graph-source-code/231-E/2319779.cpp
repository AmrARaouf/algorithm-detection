//Language: GNU C++


#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <vector>
#include <stack>
#include <list>
#include <utility>
#include <queue>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VP;
typedef vector<string> VS;

#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define FORE(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();it++)
#define ALL(x) x.begin(),x.end()
#define CLR(x, v) memset((x),v,sizeof (x))
#define gcd(a, b) __gcd(a, b)
#define PB push_back 
#define MP make_pair
#define INF 2000000007

int toInt(string s){ istringstream sin(s); int t; sin>>t; return t; }
template<class T> string toString(T x){ ostringstream sout; sout<<x; return sout.str(); }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
#define MOD 1000000007
VI g[200010];
int label[200010];
int st[200010], t;
int vis[200010], in[200010];
int n,m,k;
int cnt;
ll mypow(int n)
{
	ll ans = 1, p = 2;
	while(n) {
		if(n&1) ans=ans*p%MOD;
		p=p*p%MOD;
		n>>=1;
	}
	return ans;
}
void dfs(int pre, int x)
{
//	cout<<x<<" "<<pre<<" "<<vis[x]<<endl;
	int i;
//	FOR(i,0,t)cout<<st[i]<<" ";cout<<endl;
	if(vis[x]) {
		if(label[x]) return;
		if(t) ++cnt;
		while(t) {
			int u = st[t-1];
//			if(u==12)cout<<" ** "<<x<<" "<<cnt<<endl;
			t--;
			in[u] = 0;
			label[u] = cnt;
			if(u == x) break;
		}
		return;
	}
	vis[x] = 1;
	st[t++] = x;
	in[x] = 1;
	int p = -1;
	FORE(it,g[x]) if(*it != pre) {
		dfs(x, *it);
	}
	if(in[x]) {
		t--;
		in[x] = 0;
		label[x] = ++cnt;
	}
}
int p[200010];
VI r[200010];
int qx[100010], qy[100010];
int tw[200010];
int *sz = in;
map<PII,ll> mp;
VI* q = g;
int find(int x)
{
	if(p[x] == x) return x;
	return p[x] = find(p[x]);
}
void Union(int a, int b)
{
	int pa = find(a), pb = find(b);
	if(pa != pb) p[pa] = pb;
}
void tarjan(int x, int pre)
{
	if(vis[x]) return;
	p[x] = x;
	FORE(it,r[x]) if(*it!=pre){
		tarjan(*it,x);
		Union(*it,x);
		p[find(x)] = x;
	}
	vis[x] = 1;
	FORE(it,q[x]) if(vis[*it]) {
		int mx = max(*it,x), mn = min(x,*it);
		mp[MP(mx,mn)] = p[find(*it)];
	}
}
void dfs1(int x, int v)
{
	if(vis[x]) return;
	vis[x] = 1;
	tw[x] = v+(sz[x]>1);
	FORE(it,r[x]) dfs1(*it,tw[x]);
}
int main()
{
	cin>>n>>m;
	int i, j;
	FOR(i,0,m) {
		int u,v;
		cin>>u>>v;
		g[u].PB(v);
		g[v].PB(u);
	}
	dfs(0, 1);
	CLR(in,0);
	FOR(i,1,n+1) {
		sz[label[i]]++;
		FORE(it,g[i]) {
			int u = i, v = *it;
			if(label[u] != label[v]) {
				r[label[u]].PB(label[v]);
				r[label[v]].PB(label[u]);
			}
		}
	}
	FOR(i,1,n+1) g[i].clear();
//	FOR(i,1,n+1)cout<<label[i]<<endl;
	cin>>k;
	FOR(i,0,k) {
		int x,y;
		cin>>x>>y;
		qx[i] = label[x];
		qy[i] = label[y];
		q[qx[i]].PB(qy[i]);
		q[qy[i]].PB(qx[i]);
	}
	CLR(vis,0);
	dfs1(1,0);
	CLR(vis,0);
	tarjan(1,0);
	FOR(i,0,k) {
		int anc = mp[MP(max(qx[i],qy[i]),min(qx[i],qy[i]))];
		int tot = tw[qx[i]]+tw[qy[i]]-2*tw[anc];
		if(sz[anc]>1) tot++;
//		cout<<qx[i]<<" "<<qy[i]<<endl;
//		cout<<qx[i]<<" "<<qy[i]<<" "<<anc<<" "<<tot<<endl;
		cout << mypow(tot) << endl;
	}
	return 0;
}
