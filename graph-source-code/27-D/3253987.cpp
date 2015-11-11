//Language: GNU C++


// In The Name Of GoD
// Ring Road 2
// Date : 91 / 12 / 15

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define X first
#define Y second

using namespace std ;

const int MXM = 231 ;
vector < int > ngbr[MXM] , Xngbr[MXM] , list ;
vector < pair < int , int > > edge ;
int mlfe[MXM] , n , m , num_mlfe = 1 ;
bool mark[MXM] ;
void input() ;

int nqz ( int v ) {
	return ( v < m ? v+m : v-m ) ;
}

bool cncd ( int a , int b )
{
	bool rslt = false ;
	for ( int i = 0 ; i < 2 ; i++ )
	{
		if ( ( edge[a].X < edge[b].X && edge[b].X < edge[a].Y )
		&&   ( edge[b].Y < edge[a].X || edge[a].Y < edge[b].Y ) )
			rslt = true ;
		swap( edge[b].X , edge[b].Y ) ;
	}
	return rslt ;
}

void TSAT_push( int a , int b )
{
//	cerr << a << " " << b << endl ;
	ngbr[nqz(a)].push_back(b)  ;
	ngbr[nqz(b)].push_back(a)  ;
	Xngbr[b].push_back(nqz(a)) ;
	Xngbr[a].push_back(nqz(b)) ;
}

void DFS ( int v )
{
	mark[v] = true ;
	for ( int i = 0 ; i < int(ngbr[v].size()) ; i++ )
		if ( !mark[ngbr[v][i]] )
			DFS (ngbr[v][i]) ;
	list.push_back( v ) ;
	//cerr << v << " " ;
}

void XDFS( int v )
{
	//cerr << v << " " << num_mlfe << endl ;
	mlfe[v] = num_mlfe ;
	for ( int i = 0 ; i < int(Xngbr[v].size()) ; i++ )
		if ( mlfe[Xngbr[v][i]] == 0 )
			XDFS ( Xngbr[v][i] ) ;
}

string towSAT ( vector < pair < int , int > > &v )
{
	string rslt ;
	for ( int i = 0 ; i < m ; i++ )	mark[i] = false , mlfe[i] = 0 ;
	for ( int i = 0 ; i < m ; i++ )
		for ( int j = i+1 ; j < m ; j++ )
			if ( cncd(i,j) )
			{
				TSAT_push(i,j) ;
				TSAT_push( nqz(i) , nqz(j) ) ;
			}
	for ( int i = 0 ; i < 2*m ; i++ )
		if ( !mark[i] )
			DFS(i) ;
	reverse ( list.begin() , list.end() ) ;
	//cerr << endl ;
	for ( int i = 0 ; i < 2*m ; i++ )
		if ( mlfe[list[i]] == 0 )
			XDFS(list[i]) , num_mlfe++ ;
	for ( int i = 0 ; i < m ; i++ )
	{
		if ( mlfe[i] == mlfe[nqz(i)] )	return "Impossible" ;
		if ( mlfe[i] > mlfe[nqz(i)] )	rslt += 'o' ;
		else 							rslt += 'i' ;
	}
	return rslt ;
}

int main()
{
	input() ;
	cout << towSAT( edge ) ;
	return 0 ;
}

void input()
{
	cin >> n >> m ;
	for ( int i = m ; i-- ; )
	{
		int a , b ;
		cin >> a >> b ;a-- ; b-- ;
		if ( b < a )	swap(a,b) ;
		edge.push_back( make_pair ( a , b ) ) ;
	}
}
