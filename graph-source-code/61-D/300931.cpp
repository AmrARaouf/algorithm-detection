//Language: GNU C++


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <numeric>
#include <limits>
#include <iterator>
using namespace std;

const int INF=(1<<30)-1;
const int DIRX[]={-1, 0, 0, 1,-1,-1, 1, 1}, DIRY[]={ 0,-1, 1, 0,-1, 1,-1, 1};
const double ERR=1e-9, PI=(2*acos(0.0));

template<class T> inline T MIN(T a,T b) {return ((a<b)?a:b);}
template<class T> inline T MAX(T a,T b) {return ((b<a)?a:b);}
template<class T> inline void checkMIN(T& a,T b) {if(b<a) a=b;}
template<class T> inline void checkMAX(T& a,T b) {if(a<b) a=b;}
template<class T> inline T SQR(T x) {return (x*x);}
template<class T> T GCD(T a,T b) {if(!b) return a; else return GCD(b,a%b);}
inline int compareDouble(double x,double y,double err=ERR) { double d=x-y; if(d>err) return 1; if(d<-err) return -1; return 0;}

#define rep(x,n)	for(x=0;x<(int)(n);x++)
#define FOR(x,a,b)	for(x=(a);x<=(b);x++)
#define ROF(x,a,b)	for(x=(a);x>=(b);x--)
#define MEM(X,byte)	memset((X),(byte),sizeof(X))
#define ALL(X)		(X).begin(),(X).end()
#define SIZE(X)		((int)(X).size())
#define EACH(X,itr)	for( __typeof((X).begin()) itr=(X).begin(); itr!=(X).end(); itr++)
#define CONTAINS(X,item)	((X).find(item) != (X).end())
#define CONTAINS_n(X,item)	(find(ALL(X),(item)) != (X).end())
#define PB	push_back
#define MP	make_pair
#define fs	first
#define sc	second

typedef unsigned long long	ULL;
typedef long long		LL;
typedef stringstream	SS;
typedef vector<string>	VS;
typedef vector<int>		VI;
typedef vector<LL>		VL;
typedef pair<int,int>	Pii;

#define sz 100002
vector <Pii> adj[sz];
bool col[sz];
LL sum=0, mx=0;

LL dfs(int x, LL d)
{
	col[x]=1;
	checkMAX(mx,d);
	LL sum=0, t;
	int i,j,k;
	rep(i,SIZE(adj[x]))
	{
		j=adj[x][i].fs;
		k=adj[x][i].sc;
		if(col[j]) continue;
		dfs(j,d+k);
	}
	return (sum+sum-mx);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int i,j,k,n,w;
	cin>>n;
	FOR(k,1,n-1)
	{
		cin>>i>>j>>w;
		adj[i].PB(MP(j,w));
		adj[j].PB(MP(i,w));
		sum+=w;
	}
	
	dfs(1,0);
	cout<<(2*sum-mx);
	return 0;
}
