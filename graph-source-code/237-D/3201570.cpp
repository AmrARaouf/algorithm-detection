//Language: GNU C++


/*
Bismillahir-rahmanir-rahim
*/

# include <iostream>
# include <fstream>
# include <sstream>
# include <algorithm>
# include <functional> // greater<int>()
# include <vector>
# include <string>
# include <queue>
# include <stack>
# include <list>
# include <map>
# include <set>
# include <cstdio>
# include <cstdlib>
# include <cmath>
# include <ctime>
# include <cstring>
# include <cctype>
# include <climits> // LLONG_MAX , LLONG_MIN , INT_MAX , INT_MIN
# define  sz(X)	(int)(X).size()
# define  pb	push_back
# define  mp	make_pair

using namespace std;

/* TYPE DEFINITIONS */
typedef long long i64;

typedef		vector<int>		vi;
typedef		vector<vi>		vvi;
typedef		pair<int,int>	pi;
typedef		vector<pi>		vpi;
typedef		vector<vpi>		vvpi;
typedef		vector<i64>		v64;
typedef		vector<v64>		vv64;
typedef		pair<i64,i64>	p64;
typedef		vector<p64> 	vp64;
typedef		vector<vp64>	vvp64;
typedef		vector<string>	vs;
typedef		vector<vs>		vvs;
typedef		vector<bool>	vb;
typedef		vector<vb>		vvb;
typedef		vector<char>	vc;
typedef		vector<vc>		vvc;

/* {END} */

int n;
vpi G1[100000];
vpi G2;				int edge2;
vpi G3;
vi arr;

void f(int x, int t=-1, int par=-1)
{
	for (int i=0; i<sz(G1[x]); i++)
	{
		int newx = G1[x][i].first;
		int newt = G1[x][i].second;
		
		if(newx == par) continue;
		
		if(t == -1)	arr.pb(newt);
		else		G3.pb( mp(t,newt) );
		
		f(newx,newt,x);
	}
	
	if(t == -1)
	for (int i=1; i<sz(arr); i++)
	G3.pb( mp(arr[i],arr[i-1]) );
}

int main()
{
	cin >> n;
	
	for (int i=1; i<n; i++)
	{
		int a,b;
		cin >> a >> b;
		a--; b--;
		
		G2.pb( mp(a,b) );
		G1[a].pb( mp(b,edge2) );
		G1[b].pb( mp(a,edge2) );
		
		edge2++;
	}
	
	f(0);
	
	cout << sz(G2) << "\n";
	for (int i=0; i<sz(G2); i++)
	cout << "2 " << G2[i].first+1 << " " << G2[i].second+1 << "\n";
	
	for (int i=0; i<sz(G3); i++)
	cout << G3[i].first+1 << " " << G3[i].second+1 << "\n";
	
	return 0;
}
