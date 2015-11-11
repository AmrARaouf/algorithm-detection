//Language: MS C++


#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <map>
#include <set>
#include <string.h>
using namespace std;

#define sz(x) int((x).size())
const int inf = 1000000000;
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define pi 2*acos(0.0)
#define sqr(a) (a)*(a)
#define mp make_pair
#define pb push_back
typedef long long Int;

int xf[2001],yf[2001],xt[2001],yt[2001];
set< pair<double,int> > s;
double D[2001];

inline double d(int x,int y,int p,int q)
{
	return sqrt(sqr(x-p+0.0)+sqr(0.0+y-q));
}

inline Int d2(int x,int y,int p,int q)
{
	return sqr((Int)x-p)+sqr((Int)y-q);
}

inline double ab(double s)
{
	return s>0?s:-s;
}

inline double ok(int x,int y,int p1,int q1,int p2,int q2)
{
	Int a=q2-q1,b=p1-p2,c=-(p1*a+q1*b);
	Int l1=d2(p1,q1,p2,q2),l2=d2(x,y,p1,q1),l3=d2(x,y,p2,q2);
	if(l2+l1>=l3 && l1+l3>=l2)
	{
		return ab(a*x+b*y+c)/sqrt(0.0+a*a+b*b);
	}else
		return inf;
}

inline double Dist(int x,int y)
{
	double ans=inf;
	ans=min(ans,d(xf[x],yf[x],xf[y],yf[y]));
	ans=min(ans,d(xf[x],yf[x],xt[y],yt[y]));
	ans=min(ans,d(xt[x],yt[x],xf[y],yf[y]));
	ans=min(ans,d(xt[x],yt[x],xt[y],yt[y]));

	ans=min(ans,ok(xf[x],yf[x],xf[y],yf[y],xt[y],yt[y]));
	ans=min(ans,ok(xt[x],yt[x],xf[y],yf[y],xt[y],yt[y]));
	ans=min(ans,ok(xf[y],yf[y],xf[x],yf[x],xt[x],yt[x]));
	ans=min(ans,ok(xt[y],yt[y],xf[x],yf[x],xt[x],yt[x]));

	return ans;
}
int main()
{
	//freopen("input.txt","r",stdin);
	int a,b;
	cin>>a>>b;

	int xa,ya,xb,yb;
	cin>>xa>>ya>>xb>>yb;

	int n;
	cin>>n;
	FOR(i,1,n)cin>>xf[i]>>yf[i]>>xt[i]>>yt[i];
	xf[0]=xa;yf[0]=ya;xt[0]=xf[0];yt[0]=yf[0];
	++n;
	xf[n]=xb;yf[n]=yb;xt[n]=xf[n];yt[n]=yf[n];

	FOR(i,0,n)D[i]=inf;

	D[0]=0;
	s.clear();
	s.insert(mp(0,0));


	int add=0;
	for(;;)
	{
		if(s.empty())break;
		int v=s.begin()->second;
		if(v==n){printf("%.7f\n",D[n]);return 0;}
		s.erase(s.begin());
		FOR(i,1,n)
			if(Dist(v,i) <= a && D[v]+Dist(v,i)+add<D[i])
			{
				s.erase(mp(D[i],i));

				if(i==n)
				D[i]=D[v]+Dist(v,i)+add;else
				D[i]=D[v]+a+add;

				s.insert(mp(D[i],i));
			}
		add=b;
	}

	if(D[n]==inf)cout<<"-1"<<endl;else
		printf("%.7f\n",D[n]);
	return 0;
}