//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <stack>
using namespace std;

#define mod 100000007
#define oo 0x3f3f3f3f
#define LL long long

struct edge {
	int u, v;
	bool tp, is;
}e[100005];

int fa1[1005], fa2[1005], n, m;

int find1( int x ) {
	return x == fa1[x] ? x : find1(fa1[x]);
}

int find2( int x ) {
	return x == fa2[x] ? x : find2(fa2[x]);
}

int main()
{
	int a = 0, b = 0;
	char c[5];
	scanf( "%d%d", &n, &m );
	for( int i = 1; i <= n; ++i )
		fa1[i] = fa2[i] = i;
	for( int i = 0; i < m; ++i ) {
		scanf( "%d%d%s", &e[i].u, &e[i].v, c );
		if( c[0] == 'S' ) {
			e[i].tp = true;
			int fu = find1(e[i].u);
			int fv = find1(e[i].v);
			if( fu != fv )
				fa1[fu] = fv;
		}
		else e[i].tp = false;
	}
	if( n % 2 == 0 ) {
		puts( "-1" );
		return 0;
	}
	for( int i = 0; i < m; ++i ) if( !e[i].tp ) {
		int fu = find1(e[i].u);
		int fv = find1(e[i].v);
		if( fu != fv ) {
			fa1[fu] = fv;
			fa2[find2(e[i].u)] = find2(e[i].v);
			++b;
			e[i].is = true;
		}
	}
	if( b * 2 > n - 1 ) {
		puts( "-1" );
		return 0;
	}
	for( int i = 0; i < m && b * 2 < n - 1; ++i ) if( !e[i].tp ) {
		int fu = find2(e[i].u);
		int fv = find2(e[i].v);
		if( fu != fv ) {
			fa2[fu] = fv;
			++b;
			e[i].is = true;
		}
	}
	if( b * 2 != n - 1 ) {
		puts( "-1" );
		return 0;
	}
	for( int i = 0; i < m && a * 2 < n - 1; ++i ) if( e[i].tp ) {
		int fu = find2(e[i].u);
		int fv = find2(e[i].v);
		if( fu != fv ) {
			fa2[fu] = fv;
			++a;
			e[i].is = true;
		}
	}
	if( a * 2 != n - 1 ) {
		puts( "-1" );
		return 0;
	}
	printf( "%d\n", n - 1 );
	for( int i = 0; i < m; ++i )
		if( e[i].is )
			printf( "%d ", i + 1 );
	puts("");
	return 0;
}
 	  		 					    				 			  	