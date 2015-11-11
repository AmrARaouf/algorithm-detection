//Language: GNU C++


#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
using namespace std;
vector<int> s,p,v,v2,l;
vector<vector<int> > e;
int far,maxd;
int par(int nd){
	if(p[nd]==nd) return nd;
	return p[nd]=par(p[nd]);
}
int dfs(int nd,int pr,int ds){
	if(v[nd]) return 0;
	v[nd]=1;
	p[nd]=pr;
	if(ds>maxd) far=nd,maxd=ds;
	int size=1;
	for(int i=0;i<e[nd].size();i++){
		size += dfs(e[nd][i],pr,ds+1);
	}
	return s[nd]=size;
}
void dfs2(int nd,int ds){
	if(v2[nd]) return;
	v2[nd]=1;
	if(ds>maxd) far=nd,maxd=ds;
	for(int i=0;i<e[nd].size();i++){
		dfs2(e[nd][i],ds+1);
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	int n,m,q,x,y,z;
	cin >> n >> m >> q;
	e.resize(n);
	s.resize(n,0);
	p.resize(n,0);
	v.resize(n,0);
	v2.resize(n,0);
	l.resize(n,0);
	for(int i=0;i<m;i++){
		cin >> x >> y;
		x--; y--;
		e[x].pb(y);
		e[y].pb(x);
	}
	for(int i=0;i<n;i++){
		far=i;
		maxd=0;
		//v.clear(); v.resize(n,0);
		dfs(i,i,0);
		//v.clear(); v.resize(n,0);
		maxd=0;
		dfs2(far,0);
		l[i] = maxd;
	}
	for(int i=0;i<q;i++){
		cin >> z;
		if(z==1){
			cin >> x;
			x--;
			//cout << x << " " << par(x) << " " << l[par(x)] << endl;
			cout << l[par(x)] << "\n";
		}
		else {
			cin >> x >> y;
			x--; y--;
			x = par(x); y = par(y);
			if(x==y) continue;
			if(s[x]<s[y]) swap(x,y);
			p[y] = x;
			s[x] += s[y];
			l[x] = max((l[x]>>1) + (l[y]>>1) + (l[x]&1) + (l[y]&1) + 1,l[x]);
			l[x] = max(l[y],l[x]);
			//cout << x << " " << par(x) << " " << l[par(x)] << " : " << y << " " << par(y) << " " << l[par(y)] << endl;
		}
	}
	return 0;
}