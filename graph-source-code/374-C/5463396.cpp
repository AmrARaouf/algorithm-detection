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
//#include <climits>
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
#define fx(x) fixed<<setprecision(x)
#define fl endl<<flush

template<class T> inline void smn(T &a,const T &b){if(b<a) a=b;}
template<class T> inline void smx(T &a,const T &b){if(b>a) a=b;}
template<class T> inline T _rev(const T & a){T _=a; reverse(_.begin(),_.end()); return _;}


/*
ifstream fin(".in");
ofstream fout(".out");
#define cin fin
#define cout fout
*/

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pie;
typedef pie pii;
typedef complex<double> point;

const double eps=1e-8;
const ld leps=1e-14;
const int MN=1000+1000;
char mp[MN][MN];
int mark[MN][MN];
int n,m;
ll bst[MN][MN];
ll res=0;
map<char,char> next;
void dfs(int x,int y)
{
	mark[x][y]=1;
	bst[x][y]=1;
	for (int i=x-1;i<=x+1;i++) for (int j=y-1;j<=y+1;j++) if (i>=0 && j>=0 && i<n && j<m && abs(i-x)+abs(j-y)==1 && mp[i][j]==next[mp[x][y]] )
	{
		if (mark[i][j]==0)
		{
			dfs(i,j);
			smx(bst[x][y],1+bst[i][j]);
		}
		else if (mark[i][j]==1)
			bst[i][j]=(1LL<<40);
		else
			smx(bst[x][y],1+bst[i][j]);	
	}
	mark[x][y]=2;
}
int main()
{
	ios_base::sync_with_stdio(false);
	next['D']='I';
	next['I']='M';
	next['M']='A';
	next['A']='D';
	cin>>n>>m;
	for (int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>mp[i][j];
	for (int i=0;i<n;i++) for (int j=0;j<m;j++) if (mark[i][j]==0 && mp[i][j]=='D')
	{
		dfs(i,j);
		smx(res,bst[i][j]);
	}
	if (res>=(1LL<<40))
		cout<<"Poor Inna!"<<endl;
	else if (res/4==0)
		cout<<"Poor Dima!"<<endl;
	else
		cout<<res/4<<endl;
	return 0;
}
