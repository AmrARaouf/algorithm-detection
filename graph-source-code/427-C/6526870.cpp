//Language: GNU C++


#include <list>
#include <set>
#include <map>
#include <ctime>
#include <stack>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <queue>
#include <deque>
#include <bitset>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <iterator>
#include <cassert>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <complex>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
 
#define LL long long
#define int64 LL

typedef vector < int > VI;
typedef pair< int , int > pii;
typedef pair < LL , LL > PLL;
#define fr first
#define se second
#define pi M_PI
#define rad(x) (x)*acos(-1)/180.0
#define EPS 1e-6
#define INF 10000*100000
stringstream ss;
#define two(x) ( 1LL<<x )
#define sq(x) ( (x)*(x) )
LL mod = 1000000007LL;

/**************************Code****************************/

const int max_n = 100000 + 10;
vector < int > g[max_n];
vector < int > bg[max_n];
int cc_index[max_n];
bool mark[max_n];
int order[max_n], size = 0;
int n , m ;
int mn[max_n], cnt[max_n], cost[max_n];

void dfs( int x )
{
	mark[x] = 1;
	for( int i = 0 ; i < g[x].size() ; i ++ )
		if( !mark[ g[x][i] ] )
			dfs( g[x][i] );
	order[ n - ++size ] = x ;
}
void bdfs( int x , int index )
{
	cc_index[x] = index ;
	for( int i = 0 ; i < bg[x].size() ; i ++ )
		if( cc_index[ bg[x][i] ] == -1 )
			bdfs( bg[x][i] , index );
}

int main()
{
	int x, y;
	cin >> n;
	for( int i = 0 ; i < n ; i ++ )
		cin >> cost[i];
	cin >> m;
	for( int i = 0 ; i < m ; i ++ )
	{
		cin >> x >> y;
		x --, y --;
		g[x].push_back( y );
		bg[y].push_back( x );
	}
	for( int i = 0 ; i < n ; i ++ )
		if( !mark[i] )
			dfs( i );
	memset( cc_index , -1 , sizeof cc_index );
	int cc = 0;
	for( int i = 0 ; i < n ; i ++ )
		if( cc_index[ order[i] ] == -1 )
			bdfs( order[i] , cc ++ );
	for( int i = 0 ; i < cc ; i ++ )
		mn[i] = INF, cnt[i] = 0;
	for( int i = 0 ; i < n ; i ++ )
	{
		int k = cc_index[i];
		if( cost[i] < mn[k] )
			mn[k] = cost[i], cnt[k] = 1;
		else if( cost[i] == mn[k] )
			cnt[k] ++;
	}
	LL ans = 1, tot = 0;
	for( int i = 0 ; i < cc ; i ++ )
	{
		tot += mn[i];
		ans = ans * cnt[i] % mod;
	}
	cout << tot << " " << ans << endl;
	return 0;
}
