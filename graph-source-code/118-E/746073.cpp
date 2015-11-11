//Language: GNU C++


#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <bitset>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define li       	long long int
#define rep(i,to)	for(li i=0;i<((li)(to));++i)
#define pb       	push_back
#define sz(v)    	((li)(v).size())
#define bit(n)   	(1ll<<(li)(n))


#define MAX 300005
#define P pair<pair<li,li>,li> 



//  UNION_N

#define UNION_N MAX
li union_parent[UNION_N];
void union_init(){
	rep(i,UNION_N) union_parent[i]=i;
}
li union_find(li a){
	if(union_parent[a]==a) return a;
	return union_parent[a]=union_find(union_parent[a]);
}
void union_union(li a,li b){
	union_parent[union_find(a)]=union_find(b);
	return ;
}







vector<pair<li,li> > ans;
pair<li,li> edge[MAX];
vector< P > E[MAX];
bool used[MAX];
bool eused[MAX];
vector<li> vec;


#define x first
#define y second
#define MP make_pair
li dfs(li pos){
	if(used[pos]) return pos;
	used[pos]=true;
	rep(i,sz(E[pos]))if(!eused[E[pos][i].second]){
		P pp=E[pos][i];
		eused[E[pos][i].second]=true;
		li tmp=dfs(pp.x.x);
		eused[E[pos][i].second]=false;
		if(tmp==-1) return -1;
		if(tmp!=pos){ 
			vec.pb(pos); 
			li t0=edge[pp.y].x;
			li t1=edge[pp.y].y;
			if(union_find(t0)!=pos) swap(t0,t1);
			ans.pb(MP(t0,t1));
			eused[pp.y]=true;
			return tmp;
		}
		li t0=edge[pp.y].x;
		li t1=edge[pp.y].y;
		if(union_find(t0)!=pos) swap(t0,t1);
		ans.pb(MP(t0,t1));
		eused[pp.y]=true;

		if(sz(vec)==0) continue;
		rep(j,sz(vec))rep(k,sz(E[vec[j]])){
			P p=E[vec[j]][k];
			if(eused[p.y]) continue;
			if(p.x.x==pos){
				eused[p.y]=true;
				ans.pb(MP(edge[p.y].x,edge[p.y].y));
				continue;
			}
			union_parent[vec[j]]=pos;
			E[p.x.x][p.x.y]=MP(MP(pos,sz(E[pos])),p.y);
			E[pos].pb(p);
		}
		vec.clear();
	}
	return -1;
}

int main(){
	union_init();
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	rep(i,m){
		scanf("%d%d",&a,&b); a--; b--;
		E[a].pb(MP(MP(b,sz(E[b])),i));
		E[b].pb(MP(MP(a,sz(E[a])-1),i));
		edge[i]=MP(a,b);
	}
	rep(i,MAX) used[i]=false;
	rep(i,MAX) eused[i]=false;
	dfs(0);
	rep(i,m)if(!eused[i]){ cout<<"0"<<endl; return 0; }
	cout<<endl<<endl;
	rep(i,sz(ans)) cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
}
