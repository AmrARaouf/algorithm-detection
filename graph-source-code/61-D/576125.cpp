//Language: GNU C++


#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;

typedef double db;
typedef long long LL;
#define mp make_pair
#define pb push_back

const int maxn = 100005;
vector< pair<int,int> > E[ maxn ];
int n;
LL f[ maxn ][ 2 ];
vector< pair< LL, int > > v;

void gao( int x, int fa){
     int i;
     
     f[ x ][ 0 ] = f[ x ][ 1 ] = 0;
     for(i = 0; i < E[ x ].size(); ++ i) {
          if(E[x][i].first != fa) {
                 gao( E[x][i].first, x);                       
                 f[ x ][ 0 ] += f[ E[x][i].first ][ 0 ] + (LL)2 * E[x][i].second;
          }       
     }
     v.clear();
     for(i = 0; i < E[ x ].size(); ++ i) {
          if(E[x][i].first != fa) {
                 v.push_back( mp(f[ E[x][i].first][1] - f[ E[x][i].first][0] - E[x][i].second, E[x][i].first) );   
          }       
     } 
     sort( v.begin(), v.end()) ; 
     //if (x == 0) cout <<"vv = " << v[ 0 ].second << endl;
     for(i = 0; i < E[ x ].size(); ++ i) {
          if(E[x][i].first != fa) {
              if( E[x][i].first == v[ 0 ].second)
                  f[ x ][ 1 ] += E[x][i].second + f[ E[x][i].first ] [ 1 ];  
              else f[ x ][ 1 ] += f[ E[x][i].first ][ 0 ] + (LL)2 * E[x][i].second;       
          }       
     }
     //cout << "x = " << x << endl;
     //cout << f[ x ][ 0 ] <<' '<< f[ x ][ 1 ] << endl;         
}

void get(){
      int i;
      for(i = 0; i < n; ++ i) E[ i ].clear();
      for(i = 1; i < n; ++ i){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            -- a; -- b;
            E[ a ].pb( mp( b, c )) ;
            E[ b ].pb( mp( a, c )) ;      
      }    
}

void work(){
     gao( 0 , - 1) ; 
     int i, j;
     cout << min( f[ 0 ][ 0 ], f[ 0 ] [ 1 ] ) << endl;    
}

int main(){
    while( cin >> n){
        get();
        work();
    }
    return 0;
}
/*
3
1 2 3
2 3 4

2
1 2 3

3
1 2 3
1 3 3

5
5 3 60
4 3 63
2 1 97
3 1 14

*/

		 	 	  	   	 		  	 		  		