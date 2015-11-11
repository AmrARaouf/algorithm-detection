//Language: GNU C++


//In the name of Allah
//
//
//////////////////////
// Program: 
// Written By Alireza Farhadi (LGM)
//////////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cctype>
#include <climits>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <utility>
#include <vector>
#include <bitset>
#include <deque>
#include <iomanip>
#include <complex>
#include <fstream>
#include <sstream>
#include <map>
//#include <list>


using namespace std;

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define show(x) cerr<<((#x))<<" = "<<((x))<<" "<<endl
#define bit(a,b) (((a)>>(b))&1)
#define gcd __gcd
#define endl '\n'
#define bcnt(x) ((__builtin_popcount(x)))
#define sz(x) ((int((x).size())))
#define sqr(x) ((((x))*((x))))

template<class T> inline void smn(T &a,const T &b){if(b<a) a=b;}
template<class T> inline void smx(T &a,const T &b){if(b>a) a=b;}
template<class T> inline T rev(const T & a){T _=a; reverse(_.begin(),_.end()); return _;}

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pie;

const double eps=1e-9;
const ld leps=1e-14;
const int MN=2*1000*100+100,INF=(1u<<31)-1;
vector <int> point;
int dis[MN];
vector <int> list[MN],w[MN],no[MN];
map<int,int> mp;
int x[MN],d[MN],t[MN],p[MN];
int p1[MN],p2[MN];
vector <int> res;
int end;
struct cmp
{
	bool operator () (const int & a,const int & b)
	{
		if (dis[a]!=dis[b])
			return dis[a]<dis[b];
		return a<b;
	}
};
set <int,cmp> me;
void dig(int a)
{
	for (int i=0;i<sz(point);i++)
		dis[i]=INF;
	dis[a]=0;
	me.insert(a);
	while (!me.empty())
	{
		int v=*me.begin();
		if (v==end) break;
		me.erase(me.begin());
		for (int i=0;i<list[v].size();i++) if (dis[list[v][i]]>dis[v]+w[v][i])
		{
			int u=list[v][i];
			me.erase(u);
			dis[u]=dis[v]+w[v][i];
			p1[u]=v;
			p2[u]=no[v][i];
			me.insert(u);
		}
	}
}
int n,l;
int main(int argc,char * argv[])
{
	ios_base::sync_with_stdio(false);
	cin>>n>>l;
	point.push_back(0);
	point.push_back(l);
	for (int i=0;i<n;i++)
	{
		cin>>x[i]>>d[i]>>t[i]>>p[i];
		if (x[i]-p[i]>=0)
		{
			point.push_back(x[i]-p[i]);
			point.push_back(x[i]+d[i]);
		}
	}
	sort(point.begin(),point.end());
	point.resize(unique(point.begin(),point.end())-point.begin());
	for (int i=0;i<sz(point);i++)
		mp[point[i]]=i;
	end=mp[l];
	for (int i=0;i<n;i++) if (x[i]-p[i]>=0)
	{
		int f=mp[x[i]-p[i]],s=mp[x[i]+d[i]];
		list[f].push_back(s);
		w[f].push_back(p[i]+t[i]);
		no[f].push_back(i+1);
	}
	for (int i=1;i<sz(point);i++)
	{
		int f=point[i-1],s=point[i];
		list[mp[f]].push_back(mp[s]);
		list[mp[s]].push_back(mp[f]);
		w[mp[f]].push_back(s-f);
		w[mp[s]].push_back(s-f);
		no[mp[f]].push_back(-1);
		no[mp[s]].push_back(-1);
	}
	dig(0);
	int now=end;
	cout<<dis[now]<<endl;
	while (now!=0)
	{
		if (p2[now]!=-1)
			res.push_back(p2[now]);
		now=p1[now];
	}
	cout<<res.size()<<endl;
	for (int i=sz(res)-1;i>=0;i--)
		cout<<res[i]<<" ";
	cout<<endl;

	return 0;
}
