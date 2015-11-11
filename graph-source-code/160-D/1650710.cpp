//Language: GNU C++


#include<iostream>
#include<cstring>
#include <cstdio>
#include<string>
#include<queue>
#include<vector> 
#include<map>
#include <set>
#include<ctime>
#include<cmath>
#include <cstdlib>
#include<algorithm>
#include <iomanip>
using namespace std;

const int N=200005;
const int INF=((1<<31)-1);
int ans[N];
struct edge_t{
	int from,to,id;
	edge_t* next;
};
struct cutting_edge{
	int cnt,scnt;
	int dfn[N],low[N],vis[N];
	edge_t* list[N];
	void init(int n){
		for(int i=0;i<=n;i++){
			list[i]=NULL;
			vis[i]=0;
		}
	}
	void add(int u,int v,int w){
		edge_t* L;edge_t* R; L=new edge_t; R=new edge_t;
		L->from=u; L->to=v; L->id=w; L->next=list[u];
		R->from=v; R->to=u; R->id=w; R->next=list[v];
		list[u]=L; list[v]=R;
	}
	void dfs(int u,int p){
		dfn[u]=low[u]=++cnt;
		vis[u]=1;
		map<int,int> mpp;
		for(edge_t* i=list[u];i;i=i->next){
			int v=i->to;
			int id=i->id;
			if(!vis[v]) {  
				dfs(v,u);
				low[u]=min(low[u],low[v]); 
				if(dfn[u]<low[v]) {
					scnt++;
					ans[id]=1;
				}
			}
			else if(vis[v]==1 && (v!=p|| mpp[v])) {
				low[u]=min(dfn[v],low[u]);
			}
			if(vis[v]==1 && v==p) mpp[v]=true;
		}
	}
	int tarjan(int n){
		cnt=0; scnt=0;
		for(int i=1;i<=n;i++) if(!vis[i]) dfs(i,-1);
		return scnt;
	}
}ce;

struct node{
	int u,v,w,id;
}e[N];
struct ufind{
	int f[N];
	void init(int x) { for(int i=0;i<=x;i++) f[i]=i;}
	int find(int x) { return f[x]==x?x:f[x]=find(f[x]);}
	void set_friend(int i,int j){ f[find(i)]=find(j);}
	bool is_friend(int i,int j){
		return find(i)==find(j) ? 1:0;
	}
}uf;
bool cmp(node a,node b){
	return a.w<b.w;
}
void kruskal(int n,int m){
	sort(e,e+m,cmp);
	uf.init(n);
	int pre=0;
	for(int i=0;i<=m;i++){
		if(e[pre].w!=e[i].w){
			int cnt=1;
			map<int,int>mpp;
			for(int j=pre;j!=i;j++){
				if(!uf.is_friend(e[j].u,e[j].v)){
					if(!mpp[ uf.find(e[j].u) ]) mpp[uf.find(e[j].u)]=cnt++;
					if(!mpp[ uf.find(e[j].v) ]) mpp[uf.find(e[j].v)]=cnt++;
				}
			}
			ce.init(cnt);
			for(int j=pre;j!=i;j++){
				if(!uf.is_friend(e[j].u,e[j].v)){
					ce.add(mpp[uf.find(e[j].u)],mpp[uf.find(e[j].v)],e[j].id);
					ans[e[j].id]=2;
				}
			}
			ce.tarjan(cnt);
			for(int j=pre;j!=i;j++){
				if(!uf.is_friend(e[j].u,e[j].v)){
					uf.set_friend(e[j].u,e[j].v);
				}
			}
			pre=i;
		}
	}
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		e[m].w=INF;
		for(int i=0;i<m;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			e[i].u=u; e[i].v=v; e[i].w=w; e[i].id=i;
		}
		memset(ans,0,sizeof(ans));
		kruskal(n,m);
		for(int i=0;i<m;i++){
			if(ans[i]==0) printf("none\n");
			else if(ans[i]==1) printf("any\n");
			else printf("at least one\n");
		}
	}
}
					  	  	 	 	 		  	     	