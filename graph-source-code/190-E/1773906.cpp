//Language: GNU C++


// I'm the Topcoder
//C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
//C++
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <stack>
#include <string>
#include <list>
#include <queue>
#include <map>
#include <vector>
#include <deque>
#include <set>
using namespace std;

//*************************JUDGE**************************
#define LOCAL_HOST
#define ONLINE_JUDGE
#define TIME_OUT_PUT

//**************************CONSTANT***********************
#define INF 0x7F7F7F7F
#define eps 1e-8
#define PI acos( -1. )
#define PI2 asin ( 1. );
typedef long long LL;
//typedef __int64 LL;   //codeforces
#define MP make_pair
typedef vector<int> VI;
typedef vector<int> VS;
typedef pair<int , int> PII;
#define pb push_back
#define mp make_pair

//***************************SENTENCE************************
#define FOR(a,b,i) for ( i = a ; i < b ; i++ )
#define FORE(a,b,i) for ( i = a ; i <= b ; i++ )
#define REP(i,n) FOR(0,n,i)
#define CL(a,b) memset ( a , b , sizeof ( a ) )
#define sqr(a,b) sqrt ( (double)(a)*(a) + (b)*(b) )

//****************************FUNCTION************************
template < typename T > double DIS ( T va , T vb ) { return sqr ( va.x - vb.x , va.y - vb.y ); }
template < class T> inline T INT_LEN( T v ) { int len = 1 ; while ( v /= 10 ) ++len; return len; }
template < typename T > inline T square ( T va , T vb ) { return va * va + vb * vb ; }
//end

#define cy 500005
#define MAXN 1000005

struct P{
	int F , S;
	bool operator < ( P const &v ) const {
		return F ^ v.F ? F < v.F : S < v.S;
	}
};

map < P , bool >p;
queue < int > q;
bool vis[cy];
VI vec[cy];
int N , M;

void init ( int n ){
	memset ( vis , 0 , -~n * sizeof ( vis[0] ) );
	for ( int i = 1 ; i <= n ; i++ ){
		q.push ( i );
	}
}

void input ( int n , int m ){
	init ( n );
	int i;
	P po;
	for ( i = 0 ; i < m ; i++ ){
		scanf ( "%d%d" , &po.F , &po.S );
		if ( po.F > po.S ) swap ( po.F , po.S );
		p.insert ( mp ( po , true ) );
	}
}

void bfs ( int k , int u ){
	int v;
	P tm;
	map < P , bool >::iterator iter;
	vis[u] = true;
	queue < int > qq , tmp;
	qq.push ( u );
	while ( !qq.empty() ){
		u = qq.front();
		vec[k].push_back ( u );
		qq.pop();
		while ( !q.empty() ){
			v = q.front();
			q.pop();
			if ( vis[v] ) continue;
			tm.F = min ( u , v ) , tm.S = max ( u , v );
			iter = p.find ( tm );
			if ( iter != p.end() ){
				tmp.push ( v );
			}else {
				vis[v] = true;
				qq.push ( v );
			}
		}
		while ( !tmp.empty() ){
			q.push ( tmp.front() );
			tmp.pop();
		}
	}
}

void solve ( int n , int m ){
	int i , len , j , k = 0;
	for ( i = 1 ; i <= n ; i++ ){
		if ( !vis[i] ){
			bfs ( k , i );
			k++;
		}
	}
	printf ( "%d\n" , k );
	for ( i = 0 ; i < k ; i++ ){
		len = vec[i].size();
		printf ( "%d" , len );
		for ( j = 0 ; j < len ; j++ ){
			printf ( " %d" , vec[i][j] );
		}
		puts ( "" );
	}
}

int main (void){
	while ( 2 == scanf ( "%d%d" , &N , &M ) ){
		input ( N , M );
		solve ( N , M );
	}
	return 0;
}