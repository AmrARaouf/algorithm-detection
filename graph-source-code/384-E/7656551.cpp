//Language: GNU C++


#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=2e5+5;
int seg[maxn*4][2],n;
int st[maxn],en[maxn],t;
int a[maxn],q,h[maxn];
vector<int> v[maxn];
void dfs(int par,int root,int hei){
	t++;h[root]=hei;
	st[root]=t;
	for(int i=0 ; i<(int)v[root].size() ; i++){
		int tmp=v[root][i];
		if(tmp!=par)
			dfs(root,tmp,1-hei);
	}
	en[root]=t;
}
void add(int s,int e,int tag,int L,int R,int val,int hei){
	if(s>R || e<L)
		return ;
	if(s>=L && e<=R){
		seg[tag][hei]+=val;
		seg[tag][1-hei]-=val;
		return ;
	}
	int mid=(s+e)/2;
	add(s,mid,tag*2,L,R,val,hei);
	add(mid+1,e,tag*2+1,L,R,val,hei);
}
int get(int s,int e,int tag,int pos,int hei){
	if(pos>e || pos<s)
		return 0;
	if(s==e)
		return seg[tag][hei];
	int mid=(s+e)/2;
	return seg[tag][hei]+get(s,mid,tag*2,pos,hei)+get(mid+1,e,tag*2+1,pos,hei);
}
int main(){
	cin>>n>>q;
	for(int i=1 ; i<=n ; i++)cin>>a[i];
	for(int i=1 ; i<n ; i++){
		int u1,u2;cin>>u1>>u2;
		v[u1].pb(u2);
		v[u2].pb(u1);
	}
	dfs(1,1,0);
	for(int i=1 ; i<=n ; i++)
		add(1,n,1,st[i],st[i],a[i],h[i]);
	while(q--){
		int t,x,y;
		cin>>t>>x;
		if(t==1){
			cin>>y;
			add(1,n,1,st[x],en[x],y,h[x]);
		}
		else
			cout<<get(1,n,1,st[x],h[x])<<"\n";
	}
	return 0;
}
