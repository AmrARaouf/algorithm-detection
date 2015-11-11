//Language: GNU C++


#include<list>
#include<set>
#include<map>
#include<ctime>
#include<stack>
#include<string>
#include<vector>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstdlib>
#include<cctype>
#include<cstring>
#include<iterator>
#include<cassert>
#include<fstream>
#include<numeric>
#include<iomanip>
#include<sstream>
#include<iostream>
#include<algorithm>
using namespace std;
 
#define For(i,n) for( int i=0; i < n; i++)
#define FOR(i,a,b) for( __typeof(b) i=(a); i<=(b); i++)
#define ALL(c)  c.begin() , c.end()
#define LL long long
#define SET(t,v) memset((t), (v), sizeof(t))

typedef vector < int > VI;
typedef pair< int , int > PII;
#define fr first
#define se second

bool a[100][100];
bool mark[100][100];
int n, m;

int f( int x , int y )
{
	int ret = 0;
	if( x-1 >= 0 && a[x-1][y] )
		ret ++;
	if( x+1 < n && a[x+1][y] )
		ret ++;
	if( y-1 >= 0 && a[x][y-1] )
		ret ++;
	if( y+1 < m && a[x][y+1] )
		ret ++;
	return ret;
}

void DFS( int x , int y )
{
	mark[x][y] = true;
	if( x+1 < n && a[x+1][y] && !mark[x+1][y] )
		DFS( x+1 , y );
	if( x-1 >= 0 && a[x-1][y] && !mark[x-1][y] )
		DFS( x-1 , y );
	if( y+1 < m && a[x][y+1] &&!mark[x][y+1] )
		DFS( x , y+1 );
	if( y-1 >= 0  && a[x][y-1] && !mark[x][y-1] )
		DFS( x , y-1 );
}

int g( int x , int y )
{
	memset( mark , false , sizeof mark );
	int cnt = 0;
	a[x][y] = false;
	For( i , n )
		For( j , m )
			if( a[i][j] && !mark[i][j] )
			{
				DFS( i , j );
				cnt ++;
			}
	a[x][y] = true;
	if( cnt > 1 )
		return 1;
	else
		return 1000000;
}

int main()
{
	char tmp;
	int cnt = 0;
	cin >> n >> m;
	For( i , n )
		For( j , m )
		{
			mark[i][j] = false;
			cin >> tmp;
			a[i][j] = tmp == '#';
			if( tmp == '#' )
				cnt ++;
		}
	int mn = 1000000;
	For( i , n )
		For( j , m )
			if( a[i][j] )
			{
				mn = min( mn , min( f( i , j ) , g( i , j ) ) );
			}
	if( mn == 1000000 || cnt < 3 )
		cout << "-1" << endl;
	else
		cout << mn << endl;
	return 0;
}
