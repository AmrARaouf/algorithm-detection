//Language: GNU C++


#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <limits.h>

using namespace std;

#define ff(i,x,y) for(int i = (x);i < (y);++i)
#define rep(i,n) ff(i,0,n)
#define st(v) sort(v.begin(),v.end())
#define st2(v,f) sort(v.begin(),v.end(),f)
#define rvs(v) reverse(v.begin(),v.end())
#define pb push_back
bool myfunction (int i,int j) { return (i<j); }
#define fact(x) for(i=x-1;i>0;i--){x=x*i;}
#define MP make_pair
#define F first
#define S second
#define LL long long
#define ULL unsigned long long
#define SIZE(v) (int)v.size()
#define VI vector<int>
#define VVI vector<VI>

typedef pair<int,int> PII;

int sqr(int x) {return x*x;}

struct Node
{
	int x,y;
	void init() {scanf("%d%d",&x,&y);}
};

struct Trench
{
	Node p1, p2;
} data[1005];

int dis(Node a, Node b)
{
	return sqr(a.x-b.x)+sqr(a.y-b.y);
}

int dis(Node a, Trench t)
{
	if(t.p1.x==t.p2.x)
	{
		if(a.y>=t.p1.y&&a.y<=t.p2.y || a.y>=t.p2.y&&a.y<=t.p1.y) return sqr(a.x-t.p1.x);
		else return min(dis(a,t.p1),dis(a,t.p2));
	}
	else
	{
		if(a.x>=t.p1.x&&a.x<=t.p2.x || a.x>=t.p2.x&&a.x<=t.p1.x) return sqr(a.y-t.p1.y);
		else return min(dis(a,t.p1),dis(a,t.p2));
	}
}

int dis(Trench t1, Trench t2)
{
	return min(min(dis(t1.p1,t2),dis(t1.p2,t2)), min(dis(t2.p1,t1),dis(t2.p2,t1)));
}

const int INF=1000000000;

int a,b,n;
Node A,B;

bool chk[1005];
int d[1005];
priority_queue<PII> q;

int main()
{
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif

	double ret=1e10;

	scanf("%d%d",&a,&b);
	A.init(); B.init();
	scanf("%d",&n);
	for(int i=0;i<n;++i) {data[i].p1.init();data[i].p2.init();}

	if(dis(A,B)<=sqr(a))
	{
		printf("%.10lf",sqrt((double)dis(A,B)));
		return 0;
	}
	
	memset(chk,0,sizeof(chk));
	for(int i=0;i<n;++i) d[i]=INF;

	for(int i=0;i<n;++i) if(dis(A,data[i])<=sqr(a))
	{
		chk[i]=true;
		d[i]=1;
		q.push(MP(-1,i));
	}

	while(!q.empty())
	{
		int v=q.top().second; q.pop();

		if(dis(B,data[v])<=sqr(a))
		{
			double ans=sqrt((double)dis(B,data[v]));
			ans+=d[v]*(a+b);
			ret=min(ret,ans);
		}

		for(int i=0;i<n;++i) if(!chk[i] && dis(data[v],data[i])<=sqr(a) && d[v]+1<d[i])
		{
			d[i]=d[v]+1;
			q.push(MP(-d[i],i));
		}
	}

	if(ret==1e10) printf("-1\n");
	else printf("%.10lf",ret);
}