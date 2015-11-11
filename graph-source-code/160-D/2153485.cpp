//Language: GNU C++


//------------------------------------------------------------------------------
//  Problem : 
//  User    : 
//  Date    : 
//------------------------------------------------------------------------------


#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

bool V[111111] , used[111111] ;
int Ans[111111] , ST[111111] , fa[111111] , low[111111] , dfn[111111] , efa[111111] ;
int N , M , K , top ;
vector<int> A[111111] ;

struct Node {
	int x , y , w , z ;
} E[111111] ;


bool cmp( const Node &a , const Node &b ) {
	return a.w < b.w ;
}

int find( int x ) {
	return fa[x] == x ? x : fa[x] = find( fa[x] ) ;
}

void Union( int x , int y ) {
	x = find( x ) ;
	y = find( y ) ;
	fa[x] = y ;
	return ;
}

void dfs( int x ) {
	V[x] = 1 ;
	low[x] = dfn[x] = K++ ;
	for( int i = 0 ; i < A[x].size() ; i++ ) {
		int e = A[x][i] ;
		if( Ans[E[e].z] != 1 && !used[e] ) {
			used[e] = 1 ;
			int y = find( E[e].x ) ;
			if( y == x ) {
				y = find( E[e].y ) ;
			}
			if( !V[y] ) {
				dfs( y ) ;
				low[x] = min( low[x] , low[y] ) ;
				if( low[y] == dfn[y] ) {
					Ans[E[e].z] = 2 ;
				}
			} else {
				low[x] = min( low[x] , dfn[y] ) ;
			}
		}
	}
}

int main( int argc , char *argv[] )
{
	scanf( "%d%d" , &N , &M ) ;
	for( int i = 0 ; i < M ; i++ ) {
		scanf( "%d%d%d" , &E[i].x , &E[i].y , &E[i].w ) ;
		E[i].z = i ;
	}
	sort( E , E + M , cmp ) ;
	for( int i = 1 ; i <= N ; i++ ) {
		fa[i] = i ;
	}
	for( int i = 0 ; i < M ; i++ ) {
		K = 0 ;
		for( int j = i ; E[j].w == E[i].w ; j++ ) {
			int x = E[j].x , y = E[j].y ;
			A[find(x)].clear() ;
			A[find(y)].clear() ;
			if( find( x ) == find( y ) ) {
				Ans[E[j].z] = 1 ;
			}
		}
		for( int j = i ; E[j].w == E[i].w ; j++ ) {
			int x = E[j].x , y = E[j].y ;
			A[find(x)].push_back( j ) ;
			A[find(y)].push_back( j ) ;
			V[find(x)]=V[find(y)] = false ;
		}
		for( int j = i ; E[j].w == E[i].w ; j++ ) {
			int x = E[j].x , y = E[j].y ;
			if( !V[find(x)] ) {
				dfs( find( x ) ) ;
			}
			if( !V[find(y)] ) {
				dfs( find( y ) ) ;
			}
		}
		for( int j = i ; E[j].w == E[i].w ; j++ ) {
			int x = E[j].x , y = E[j].y ;
			Union( x , y ) ;
			i = j ;
		}
	}
	dfs( 1 ) ;
	for( int i = 0 ; i < M ; i++ ) {
		if( Ans[i] == 1 ) {
			printf( "none" ) ;
		} else if( Ans[i] == 2 ) {
			printf( "any" ) ;
		} else {
			printf( "at least one" ) ;
		}
		printf( "\n" ) ;
	}
	return 0;
}

					      		 	 	    	  	 	