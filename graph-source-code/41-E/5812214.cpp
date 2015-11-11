//Language: GNU C++


#include <cmath>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
int n ;

int main()
{
    cin >> n ;
    int m = n / 2 ;
    cout << m * ( n - m ) << endl ;
    for ( int i = 1 ; i <= m ; i ++ )
    for ( int j = m + 1 ; j <= n ; j ++ )
        cout << i << " " << j << endl ;
    return 0 ;
}