//Language: GNU C++


//This is the painkiller...
#include <cstdio>
#include <iostream>
#include <sstream>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <list>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
#include <ctime>
#include <set>
#include <vector>
#include <cctype>
#include <cassert>
#include <complex>
#include <numeric>
using namespace std;
#define abv(a) ((a)>0?(a):-(a))
#define sqr(a) ((a)*(a))
#define mem(a,v) memset(a,v,sizeof(a))
#define pb push_back
#define mp make_pair
#define sz(x) int((x).size())
#define x first
#define y second
#define all(a) (a).begin(),(a).end()
#define rep(i,n) for(int i=0;i<int(n);i++)
#define repi(i,a,n) for(int i=int(a);i<int(n);i++)
#define repe(i,a) for(__typeof((a).begin()) i=(a).begin();i!=(a).end();i++)
#if !ONLINE_JUDGE
#define debug(args...) (Debugger()) , args
#else
#define debug(args...)
#endif

class Debugger{ public: Debugger(const std::string& _separator = ","): first(true), separator(_separator){} template<typename ObjectType>Debugger& operator , (const ObjectType& v) { if(!first) std::cerr << separator; std::cerr << v; first = false; return *this; } ~Debugger() { std::cerr << endl; } private: bool first; std::string separator; }; template <typename T1, typename T2> inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p) { return os << "(" << p.first << "," << p.second << ")"; } template<typename T> inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v) { bool first = true; os << "{"; for(unsigned int i = 0;i < v.size();i++){ if(!first) os << ","; os << v[i]; first = false; } return os << "}"; } template<typename T> inline std::ostream &operator << (std::ostream & os,const std::set<T>& v) { bool first = true; os << "{"; for (typename std::set<T>::const_iterator ii = v.begin();ii != v.end();++ii) { if(!first) os << ","; os << *ii; first = false; } return os << "}"; } template<typename T1, typename T2> inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v) { bool first = true; os << "{"; for (typename std::map<T1, T2>::const_iterator ii = v.begin();ii != v.end();++ii) { if(!first) os << ","; os << *ii ; first = false; } return os << "}"; }template<class X,class Y> std::istream & operator >>(std::istream &i,std::pair<X,Y> &a){i>>a.first>>a.second; return i;}template<class X> std::istream & operator >>(std::istream &is,std::vector<X> &a){for(int i=0;i<int(a.size());i++)is>>a[i];return is;}

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

#define inf (1<<30)

int cnt[100005],child[100005];
vector<vi> adj,isBad;
vi ans;

int forePlay(int u,int w)
{
	cnt[u]=0;
	rep(i,sz(adj[u]))
	{
		int v=adj[u][i];
		int c=isBad[u][i];
		if(v!=w)cnt[u]+=c+forePlay(v,u);
	}
	return cnt[u];
}

int blowJob(int u,int w)
{
	child[u]=1;
	rep(i,sz(adj[u]))
	{
		int v=adj[u][i];
		if(v!=w)child[u]+=blowJob(v,u);
	}
	return child[u];
}

void fuck(int u,int w)
{
	//~ debug(u,w,child[u],cnt[u]);
	//~ if(child[u]==1)ans.pb(u+1);
	if(u!=w && cnt[u]==0)ans.pb(u+1);
	rep(i,sz(adj[u]))
	{
		int v=adj[u][i];
		if(v==w)continue;
		if(cnt[v]>0 || isBad[u][i]==1)fuck(v,u);
		//~ else ans.pb(v+1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	//~ freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	isBad=adj=vector<vi>(n);
	rep(i,n-1)
	{
		int u,v,t;
		cin>>u>>v>>t;
		u--,v--;
		adj[u].pb(v);
		adj[v].pb(u);
		isBad[u].pb(int(t==2));
		isBad[v].pb(int(t==2));
	}
	mem(cnt,0);
	forePlay(0,0);
	blowJob(0,0);
	//~ debug(vi(cnt,cnt+n));
	//~ debug(vi(child,child+n));
	fuck(0,0);
	cout<<sz(ans)<<endl;
	rep(i,sz(ans))cout<<ans[i]<<" ";
	return 0;
}














