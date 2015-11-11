//Language: GNU C++


#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>
#include <cassert>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define forup(i,a,b) for(int i=a; i<b; ++i)
#define fordn(i,a,b) for(int i=a; i>b; --i)
#define rep(i,a) for(int i=0; i<a; ++i)

#define dforup(i,a,b) for(i=a; i<b; ++i)
#define dfordn(i,a,b) for(i=a; i>b; --i)
#define drep(i,a) for(i=0; i<a; ++i)

#define slenn(s,n) for(n=0; s[n]!=13 and s[n]!=0; ++n);s[n]=0

#define gi(x) scanf("%d",&x)
#define gl(x) cin>>x
#define gd(x) scanf("%lf",&x)
#define gs(x) scanf("%s",x)

#define pis(x) printf("%d ",x)
#define pin(x) printf("%d\n",x)
#define pls(x) cout<<x<<" "
#define pln(x) cout<<x<<"\n"
#define pds(x) printf("%.12f ",x)
#define pdn(x) printf("%.12f\n",x)
#define pnl() printf("\n")

#define fs first
#define sc second

#define pb push_back

const int inv=1000000000;
const int minv=-inv;

const int max_m=1010;
const int max_n=1010;

int m,n;
bool a[max_m][max_n];
int deg[max_m][max_n];

int di[4]={0,0,-1,1};
int dj[4]={-1,1,0,0};

int xi,xj;

bool isone(int i, int j)
{
	if(i<0 or i>=m) return false;
	if(j<0 or j>=n) return false;
	return a[i][j];
}

int fgcd(int p, int q)
{
	if(p==0) return q;
	else return fgcd(q%p,p);
}

bool visited[max_m][max_n]={0};
queue<int> Qi,Qj;
void BFS(int si, int sj)
{
	visited[si][sj]=true;
	Qi.push(si); Qj.push(sj);

	int vti,vtj;
	int nbi,nbj;
	while(not Qi.empty())
	{
		vti=Qi.front(); vtj=Qj.front();
		Qi.pop(); Qj.pop();

		rep(k,4)
		{
			nbi=vti+di[k]; nbj=vtj+dj[k];
			if(isone(nbi,nbj) and (not visited[nbi][nbj]))
			{
				Qi.push(nbi);
				Qj.push(nbj);
				visited[nbi][nbj]=true;
			}
		}
	}
}

int main()
{
	gi(m); gi(n);

	xi=-1; xj=-1;
	rep(i,m)
		rep(j,n)
		{
			int t; gi(t);
			a[i][j]=(bool(t));

			if(a[i][j] and xi==-1 and xj==-1)
			{
				xi=i;
				xj=j;
			}
		}

	bool valid=true;

	BFS(xi,xj);

	rep(i,m)
		rep(j,n)
			if(a[i][j] and (not visited[i][j]))
				valid=false;

	if(not valid)
	{
		pin(-1);
		return 0;
	}

	int nodd=0;
	rep(i,m)
		rep(j,n)
		{
			if(not a[i][j])
			{
				deg[i][j]=0;
				continue;
			}

			int cdeg=0;
			rep(k,4)
			{
				if(isone(i+di[k],j+dj[k]))
					++cdeg;
			}
			deg[i][j]=cdeg;
			nodd+=(cdeg%2);

			if(cdeg==0) valid=false;
		}

	//cout<<valid<<" "<<nodd<<"\n";

	if((not valid) or (nodd!=0 and nodd!=2))
	{
		pin(-1);
		return 0;
	}

	//cout<<"here\n";

	int g=0;
	rep(i,m)
		rep(j,n)
		{
			if(not a[i][j]) continue;
			bool critical=false;

			if(deg[i][j]!=2) critical=true;
			if(isone(i-1,j) xor isone(i+1,j)) critical=true;
			if(isone(i,j-1) xor isone(i,j+1)) critical=true;

			if(critical)
			{
				g=fgcd(g,abs(i-xi));
				g=fgcd(g,abs(j-xj));

				//cout<<i<<" "<<j<<" "<<g<<"\n";
			}
		}

	if(g==0 or g==1)
		pin(-1);
	else
	{
		for(int i=2; i<=g; ++i)
			if(g%i==0)
				pis(i);
		pnl();
	}
	
	return 0;
}