//Language: GNU C++


#include<cstdio>
#include<set>
#include<cstring>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<map>
#include<stack>
#include<algorithm>
#include<queue>
#include<cmath>
#include<functional>
#include<string>
#include<assert.h>
using namespace std;

#define LL long long
#define uLL unsigned long long
#define B puts("^_^");
#define FILEIN freopen("in", "r", stdin);
#define MP make_pair
#define PB push_back
#define fi first
#define se second
#define PI pair<int, int>
#define VI vector<int>
#define FOR(i, x, y) for(int i=(x); i<(y); ++i) 
#define F(x) for(int i=0; i<(x); ++i)
#define F1(x) for(int i=1; i<=(x); ++i)
#define FJ(x) for(int j=0; j<(x); ++j)
#define FJ1(x) for(int j=1; j<=(x); ++j)
#define FK(x) for(int k=0; k<=(x); ++k)
#define lson (u<<1)
#define rson (u<<1|1)
const int N=500005;
const int INF=0x3f3f3f3f;
//const int M=7+1e9;
inline int IN() {int x; scanf("%d", &x); return x;}
#define GET(x) int x=IN()
inline void OUT(int x) {printf("%d\n", x);}

int fst[N], nxt[N], from[N], to[N], w[N], h;
#define bian for(int i=fst[u]; ~i; i=nxt[i])
void jiabian(int u, int v, int x){
	nxt[h]=fst[u], from[h]=u, to[h]=v, w[h]=x, fst[u]=h++;
}

int n, m;
int d[N], t[N][20], _t[N];
int fa[N][20];
VI ch[N];
vector<pair<int, int> > query;
int zuo[N];
int _root[N];

void dfs(int u, int f){
	if(f==-1) fa[u][0]=u, d[u]=0;
	else t[u][0]=_t[u], fa[u][0]=f, d[u]=d[f]+1;
	F1(19) fa[u][i]=fa[fa[u][i-1]][i-1], t[u][i]=max(t[fa[u][i-1]][i-1], t[u][i-1]);
	int sz=ch[u].size();
	F(sz){
		int v=ch[u][i];
		dfs(v, u);
	}
}

int get(int u, int d){
	F(20) if(d&(1<<i)) u=fa[u][i];
	return u;
}

int rmq(int u, int d){
	int ret=-1;
	F(20) if(d&(1<<i)) ret=max(ret, t[u][i]), u=fa[u][i];
	return ret;
}

int main(){
	//FILEIN
	n=IN(), m=IN();
	int T=0;
	F(m){
		int o=IN();
		int x, y;
		if(o==1){
			x=IN(), y=IN();
			_t[x]=T, ch[y].PB(x);
		} else if(o==2){
			int x=IN();
			zuo[++T]=x;
		} else{
			int x=IN(), y=IN();
			query.PB(MP(x, y));
		}
	}
	F1(n) FJ(ch[i].size()) _root[ch[i][j]]=1;
	F1(n) if(!_root[i]) ch[0].PB(i);
	dfs(0, -1);
	int sz=query.size();
	F(sz){
		int f=query[i].fi, u=zuo[query[i].se];
		if(d[u]<d[f] || get(u, d[u]-d[f])!=f || rmq(u, d[u]-d[f])>=query[i].se)
			puts("NO");
		else puts("YES");
	}
	return 0;
}
