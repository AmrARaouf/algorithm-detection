//Language: GNU C++


// Author: Nishant R. Krishan
#include <iostream>
#include <sstream>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <deque>
#include <bitset>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <vector>
#include <queue>
#include <cassert>
#include <ctime>

using namespace std;

#define VI vector < int >
#define VVI(A,N,M) vector< VI > A( N, VI (M) )
#define LD long double
#define LL long long
#define LLU unsigned long long
#define SI ({int x;scanf("%d",&x);x;})
#define SC ({char x;scanf("%c",&x);x;})
#define SLL ({LL x;scanf("%lld",&x);x;})
#define SLLU ({LLU x;scanf("%llu",&x);x;})
#define PI acos(-1)
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define getSize(x) ((int) (x).size()) 
#define SORT(c) sort(all(c))
#define FIT(it,v) for (typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define FITD(it,v) for (typeof(v.rbegin()) it = v.rbegin(); it != v.rend(); it++)
#define IATOV(a) ({vector<int> v(a,a+sizeof(a)/sizeof(int));v;})
#define CATOV(a) ({vector<char> v(a,a+sizeof(a)/sizeof(char));v;})
#define sieve(a) ({int b=ceil(sqrt(a));VI d(a,0);VI e;int f=2;e.pb(2);e.pb(3);for(int x=1;x<b+1;x++){for(int y=1;y<b+1;y++){int n=(4*x*x)+(y*y);if(n<=a&&(n%12==1||n%12==5)){d[n]^=1;}n=(3*x*x)+(y*y);if(n<=a&&n%12==7){d[n]^=1;}n=(3*x*x)-(y*y);if(x>y&&n<=a&&n%12==11){d[n]^=1;}}}for(int r=5;r<b+1;r++){if(d[r]){for(int i=r*r;i<a;i+=(r*r)){d[i]=0;}}}for(int c=5;c<a;c++){if(d[c]){e.pb(c);}}e;})
#define INF 1000000007
#define EPS 1e-9

/********************************************************************************************************************************/
int n,m;
string G[510];
bool used[510][510];
vector<pair<int, int> > curr;
vector< vector<pair<int, int> > > comm;
vector<string> final;

string convertToString(int X)
{
	string res="";
	while(X!=0)
	{
		res += (X%10) +'0';
		X /= 10;
	}
	if( res=="" )
		res = "0";
	reverse(all(res));
	return res;
}

bool isNear(int x1, int y1, int x2, int y2)
{
	if((x1==x2)&&(abs(y1-y2)==1))
		return true;
	else if((y1==y2)&&(abs(x1-x2)==1))
		return true;
	return false;
}
void dfs(int x, int y)
{
	used[x][y] = true;
	int count=0;
	if(x>0 && !used[x-1][y] && G[x-1][y]!='#')
	{
		dfs(x-1,y);
		count++;
		curr.push_back(make_pair(x,y));
	}
	if(y<m-1 && !used[x][y+1] && G[x][y+1]!='#')
	{
		dfs(x,y+1);
		count++;
		curr.push_back(make_pair(x,y));

	}
	if(y>0 && !used[x][y-1] && G[x][y-1]!='#')
	{
		dfs(x,y-1);
		count++;
		curr.push_back(make_pair(x,y));

	}
	if(x<n-1 && !used[x+1][y] && G[x+1][y]!='#')
	{
		dfs(x+1,y);
		count++;
		curr.push_back(make_pair(x,y));

	}
	if( count==0 )
		curr.push_back(make_pair(x,y));
}

void buildCity()
{
	memset(used,0,sizeof(used));
	int i,j;
	for(i=0;i<n;++i)
	{
		for(j=0;j<m;++j)
		{
			if(!used[i][j] && G[i][j]!='#')
			{
				curr.clear();
				dfs(i,j);
				comm.push_back(curr);
			}


		}
	}
}

void destruct(int x, int y)
{
	if(G[x][y]=='.')
		return;
	string res = "D ";
	res += convertToString(x+1);
	res += " ";
	res += convertToString(y+1);
	final.push_back(res);
	G[x][y] = '.';
}
void buildB(int x, int y)
{
	if(G[x][y]=='B')
		return;
	else if(G[x][y]=='R')
	{
		destruct(x,y);
	}
	string res = "B ";
	res += convertToString(x+1);
	res += " ";
	res += convertToString(y+1);
	final.push_back(res);
	G[x][y] = 'B';
}

void buildR(int x, int y)
{
	if(G[x][y]=='R')
		return;
	string res = "R ";
	res += convertToString(x+1);
	res += " ";
	res += convertToString(y+1);
	final.push_back(res);
	G[x][y] = 'R';
}


int main(int argc, char** argv) {
	cin>>n>>m;

	comm.clear();
	int i,j;
	for(i=0;i<n;++i)
		cin>>G[i];
	buildCity();

	int L=0;
/*	for(i=0;i<getSize(comm);++i)
	{
		if(getSize(comm[i])==1)
			L += 1;
		else
			L += 2*(getSize(comm[i])-1) + getSize(comm[i])-2;
	}
*/
//	cout<<L<<endl;
	for(i=0;i<getSize(comm);++i)
	{
		if(getSize(comm[i])==1)
			buildB(comm[i][0].first,comm[i][0].second);
		else
		{
			for(j=0;j<getSize(comm[i])-1;++j)
			{
				if( !isNear(comm[i][j].first,comm[i][j].second,comm[i][j+1].first,comm[i][j+1].second) )
					continue;
				buildB(comm[i][j+1].first,comm[i][j+1].second);
				buildR(comm[i][j].first,comm[i][j].second);
				if(j!=getSize(comm[i])-2)
					destruct(comm[i][j+1].first,comm[i][j+1].second);
			}
		}
	}

	cout<<getSize(final)<<endl;
	for(i=0;i<getSize(final);++i)
	{
		cout<<final[i]<<endl;
	}
	return 0;
}

