//Language: GNU C++


#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<set>
#include<map>
#include<queue>
#include<cassert>

using namespace std;

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef long long ll;

const int inf=(int)1e9;
const double INF=1e12, EPS=1e-9;

const int MX = 100010, MXL = 17;
const int mod = 1000000007;
int pw[MX], p[MX], a[MX], b[MX];
int n, m, pa[MXL][MX];
vi e[MX];
map<int, int> to;

int root(int x){
	if(x == p[x]) return x;
	return p[x] = root(p[x]);
}

int stk[MX], sz, num;
bool v[MX], v2[MX], isloop[MX];
void dfs(int cur, int prev){
	v[cur] = 1;
	stk[sz++] = cur;
	//dbg(cur);
	
	rep(i, e[cur].size()) if(e[cur][i] != prev){
		int t = e[cur][i];
		if(v[t] && !v2[cur]){
			int j;
			//rep(j, sz) cerr<<stk[j]<<(j==sz-1?"\n":" ");
			//cerr<<"t: "<<t<<" cur: "<<cur<<" prev: "<<prev<<endl;
			for(j = sz - 1; ; j--){
				//dbg(j); dbg(stk[j]);
				to[stk[j]] = num;
				v2[stk[j]] = isloop[num] = 1;
				if(stk[j] == t) break;
			}
			num++;
		}
		else{
			if(!v[t]) dfs(t, cur);
		}
	}
	sz--;
	if(!v2[cur]){
		to[cur] = num++;
		v2[cur] = 1;
	}
}

int cnt[MX], depth[MX];
vector<vi> g;
void rec(int cur, int d, int c, int prev){
	if(isloop[cur]) c++;
	depth[cur] = d++;
	cnt[cur] = c;
	pa[0][cur] = prev;
	
	rep(i, g[cur].size()) if(cnt[g[cur][i]] < 0){
		rec(g[cur][i], d, c, cur);
	}
}

void run()
{
	pw[0] = 1;
	rep(i, MX - 1) pw[i + 1] = pw[i] * 2 % mod;
	rep(i, MX) p[i] = i;
	
	cin >> n >> m;
	rep(i, m){
		cin >> a[i] >> b[i];
		a[i]--; b[i]--;
		e[a[i]].pb(b[i]);
		e[b[i]].pb(a[i]);
		
		int x = root(a[i]), y = root(b[i]);
		if(x != y) p[y] = x;
	}
	rep(i, n) if(!v[i]) dfs(i, -1);
	//rep(i, n) cerr<<"i: "<<i<<" to[i]: "<<to[i]<<endl;
	
	g = vector<vi>(num);
	vector<pi> es;
	rep(i, m){
		int x = to[a[i]], y = to[b[i]];
		if(x == y) continue;
		if(x > y) swap(x, y);
		es.pb(mp(x, y));
	}
	sort(all(es));
	es.erase(unique(all(es)), es.end());
	
	rep(i, es.size()){
		g[es[i].first].pb(es[i].second);
		g[es[i].second].pb(es[i].first);
	}
	
	memset(cnt, -1, sizeof(cnt));
	rep(i, num) if(cnt[i] < 0) rec(i, 0, 0, -1);
	rep(i, MXL - 1) rep(j, num) pa[i + 1][j] = pa[i][j] >= 0 ? pa[i][pa[i][j]] : -1;
	/*
	rep(i, num) cerr<<"i: "<<i<<" "<<pa[0][i]<<endl;
	rep(i, num) cerr<<"i: "<<i<<" cnt[i]: " <<cnt[i]<<" depth[i]: "<<depth[i]<<endl;
	*/
	int q;
	cin >> q;
	rep(i, q){
		int x, y;
		cin >> x >> y;
		if(root(--x) != root(--y)){
			cout << 0 << endl;
			continue;
		}
		
		x = to[x]; y = to[y];
		//dbg(x); dbg(y);
		if(x == y){
			cout << (isloop[x] ? 2 : 1) << endl;
		}
		else{
			int s = x, t = y;
			if(depth[s] > depth[t]) swap(s, t);
			for(int i = MXL - 1; i >= 0; i--) if(pa[i][t] >= 0 && depth[s] <= depth[pa[i][t]]) t = pa[i][t];
			
			//cerr<<"x: "<<x<<" y: "<<y<<" s: "<<s<<" t: "<<t<<endl;
			if(s != t){
				for(int i = MXL - 1; i >= 0; i--) if(pa[i][s] != pa[i][t]){
					s = pa[i][s]; t = pa[i][t];
				}
				s = pa[0][s];
				assert(s >= 0);
			}
			t = pa[0][s];
			//cerr<<"x: "<<x<<" y: "<<y<<" s: "<<s<<" t: "<<t<<endl;
			cout << pw[cnt[x] + cnt[y] - (t < 0 ? 0 : cnt[t]) - cnt[s]] << endl;
		}
	}
	
}

int main()
{
#ifndef ONLINE_JUDGE
	//int cs=3;rep(i,cs)
#endif
	run();
}
