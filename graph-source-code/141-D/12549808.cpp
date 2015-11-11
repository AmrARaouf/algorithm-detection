//Language: GNU C++11


//be name khoda

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define sz(x) (int)x.size()
#define pii pair<int,int>

typedef long long ll;

const int MAXN=3*1000*100+100;

struct edge{
	int b,t,index;
	edge(int b,int t,int index)
		:b(b),t(t),index(index){}
};

vector <edge> v[MAXN];
vector <int> a;
ll n,l,dist[MAXN];
map <int,int> ma;
bool mark[MAXN];
pii par[MAXN];

void checkrikht(int u)
{
	if(u>=0 && !ma[u])
	{
		ma[u]=a.size();
		a.pb(u);
	}
}

int dijkstra()
{
	priority_queue <pii> Q;
	fill(dist,dist+sz(a)+1,1e13);
	Q.push(mp(0,0));
//	mark[0]=1;
	while(!Q.empty())
	{
		pii x=Q.top();
		Q.pop();
		if(mark[x.S])
			continue;
//		cout<<x.S<<" "<<x.F<<" "<<a[x.S]<<endl;
		mark[x.S]=1;
		dist[x.S]=-x.F;
		for(auto u:v[x.S])
			if(dist[u.b]>dist[x.S]+u.t)
			{
				par[u.b]=mp(x.S,u.index);
				dist[u.b]=dist[x.S]+u.t;
				Q.push({-dist[u.b],u.b});
			}
	}
	return dist[sz(a)-1];
}

int main()
{
	ios_base::sync_with_stdio(0);
	vector <pair<int ,edge> > vtemp;
	cin>>n>>l;
	a.pb(0);
	a.pb(l);
	for(int i=0;i<n;i++)
	{
		int x,t,p,l;
		cin>>x>>l>>t>>p;
		int u=x-p;
		int v=x+l;
		if(u>=0) a.pb(u);
		a.pb(v);
		if(u>=0) vtemp.push_back(mp(u,edge(v,t+p,i+1)));
	}
	sort(all(a));
	a.resize(unique(all(a))-a.begin());
/*	for(auto u:a)
		cout<<u<<" ";
	cout<<endl;//*/
	for(int i=0;i<sz(a);i++){
		ma[a[i]]=i;
		if(i<sz(a)-1){
		v[i].pb(edge(i+1,a[i+1]-a[i],-1));
		v[i+1].pb(edge(i,a[i+1]-a[i],-1));}}
	for(auto u:vtemp)
		v[ma[u.F]].pb(edge(ma[u.S.b],u.S.t,u.S.index));
/*
	for(int i=0;i<sz(a);i++)
		for(auto u:v[i])
			cout<<i<<" "<<u.b<<" "<<u.t<<" "<<u.index<<endl;//*/
	cout<<dijkstra()<<endl;
/*	for(int i=0;i<sz(a);i++)
		cout<<par[i].F<<" "<<par[i].S<<endl;*/
	int t=sz(a)-1;
	vector <int> ans;
	par[0]={-1,-1};
	while(t!=-1)
	{
		if(par[t].S!=-1)
			ans.pb(par[t].S);
		t=par[t].F;
	}
	cout<<sz(ans)<<endl;
	reverse(all(ans));
	for(auto u:ans)
		cout<<u<<" ";
	cout<<endl;
	return 0;
}
