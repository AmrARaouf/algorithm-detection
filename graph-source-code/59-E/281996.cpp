//Language: GNU C++


#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <cstring>
#define oo (int)1e9
#define fill( a , v ) memset( a , v , sizeof (a) )
#define bits( x ) __builtin_popcount( x )
#define gcd( a , b ) __gcd( a, b )
#define lcm( a , b ) (a/gcd( a, b ) ) * b
#define s(n)scanf( "%d" , &n )
#define add push_back
const int mxn = 100000 + 10;
typedef long long ll;
#define pii pair<int,int>
using namespace std;

vector<int>v[3010];
int A,B,C;
int n,m,k;
bool vis[3001][3001];
pii prevF[3001][3001];
vector< pair< pii , int > >BS;

int main()
{
    s(n);s(m);s(k);
    
    while( m-- )
    {
           s(A);s(B);
           v[A].add( B );
           v[B].add( A );           
    }
    
    while( k-- )
    {
           s(A);s(B);s(C);
           BS.add( make_pair( make_pair( A,B ) , C ) );
    }

    sort( BS.begin() , BS.end() );

  
    queue<int>q;
    

       q.push( 0 );
       q.push( 1 );       
       //q.push( 1 );
       vis[0][ 1 ] = 1;
       prevF[0][ 1 ].first = -2;
       prevF[0][ 1 ].second = -2;       
    
    while( q.size() )
    {
        int c1 = q.front();q.pop();
        int c2 = q.front();q.pop();
        //int d = q.front();q.pop();        
        
        if( c2 == n )
        {
            vector<pii>soln;
            do
            {
              soln.add( make_pair( c1,c2 ) );
              int C2 = prevF[c1][c2].second;
              int C1 = prevF[c1][c2].first;
              c1 = C1;
              c2 = C2;
            }while( prevF[c1][c2].first != -2 && prevF[c1][c2].second != -2 );
            
            printf( "%d\n" , soln.size() );
            for(int i=soln.size()-1;i>=0;i--) printf( "%d " , soln[i].first );
            cout << n << endl;

            return 0;
        }
        
        for(int i=0;i<v[c2].size();i++)
        if( !vis[c2][ v[c2][i] ] && !binary_search( BS.begin() , BS.end()  , make_pair( make_pair( c1 , c2 ) , v[c2][i] ) ) )
        {
            vis[c2][ v[c2][i] ] = 1;
            q.push( c2 );
            q.push( v[c2][i] );            
            prevF[ c2 ][ v[c2][i] ] = make_pair(c1,c2);
        }
    }
    

    puts( "-1" );

}
