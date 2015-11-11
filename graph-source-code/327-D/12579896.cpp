//Language: GNU C++


/*
	In the Name of God
	Aida Mousavi
	Indivisual Narengies Round12
*/

#include <vector>
#include <map>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <complex>
#include <queue>
#include <stack>
#include <map>
#include <bitset>
#include <iomanip>
#include <set>
#include <stack>
#include <stdio.h>

using namespace std;

#define MAXN 60
#define X first
#define Y second
#define CLR(x,a) memset(x,a,sizeof(x))
#define FOR(i,b) for(ll i=0;i<(b);i++)
#define FOR1(i,b) for(ll i=1;i<=(b);i++)
#define FORA(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORB(i,b,a) for(ll i=(b);i>=(a);i--)
#define sh(x) cerr<<(#x)<<" = "<<(x)<<endl
#define EPS 0.00001
#define ull unsigned long long int
#define ll long long 
#define MP make_pair
#define PB push_back
#define ALL(v) (v).begin(),(v).end()
#define sz size()
#define EXIST(a,b) find(ALL(a),(b))!=(a).end()
#define Sort(x) sort(ALL(x))
#define UNIQUE(v) Sort(v); (v).resize(unique(ALL(v)) - (v).begin())
#define timestamp(x) printf("Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define N 10020
//const double PI = acos(-1);
typedef complex<double> point;
typedef pair<int,int> pii;
typedef pair<char, pii> piii;
typedef vector<int> vi;
typedef vector<vi > vii;
typedef vector<pii> vpii;
typedef vector<piii> vpiii;

string mp[510];
bool viz[510][510];
vpiii ans;
int diff[4][2]={{-1,0},{0,1},{1,0},{0,-1}}; 
int n,m;
void f(int i, int j)
{
	if(i<0 || j<0 || i>=n || j>=m || mp[i][j]=='#' || viz[i][j]) return;
	viz[i][j]=true;
	ans.PB(piii('B',pii(i,j)));
	//sh(i);sh(j);sh("B");
	FOR(k,4)
	{
		int ni=i+diff[k][0];
		int nj=j+diff[k][1];
		f(ni,nj);
	}
	ans.PB(piii('D',pii(i,j)));
	//sh(i);sh(j);sh("D");
	ans.PB(piii('R',pii(i,j)));
	//sh(i);sh(j);sh("R");
}
int main()
{
	cin>>n>>m;
	FOR(i,n) cin>>mp[i];
	CLR(viz,false);
	FOR(i,n)
		FOR(j,m)
		{
			if(mp[i][j]=='.' && (!viz[i][j]))
			{
				f(i,j);
				//sh("ans----");
				//FOR(k,ans.sz) cout<<ans[k].X<<" "<<ans[k].Y.X+1<<" "<<ans[k].Y.Y+1<<endl;
				//sh("------");
				ans.pop_back();
				ans.pop_back();	
			}
		}
	cout<<ans.sz<<endl;
	FOR(i,ans.sz)
	{
		printf("%c %d %d\n",ans[i].X,ans[i].Y.X+1,ans[i].Y.Y+1);
	}
}

   	 	 		  		 				   						 	 	