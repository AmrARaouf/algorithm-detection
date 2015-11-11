//Language: GNU C++


#include <cstdio>
#include <algorithm>

using namespace std;

const int maxN = 510;

int main( void ) {
     int n, m, w[maxN];
     
     scanf("%i %i", &n, &m);
     
     for( int i = 1; i <= n; i++ )
          scanf("%i", &w[i]);
     
     double maxW = 0.0;
     
     for( int i = 0; i < m; i++ ) {
          int a, b, c;
          scanf("%i %i %i", &a, &b, &c);
          
          maxW = max( maxW, 1.0 * (w[a]+w[b]) / c );
     }
     
     printf("%.11f\n", maxW);
     
     return 0;
}
