//Language: MS C++


#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <map>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <functional>
#include <cstdio>
#include <ctime>
#include <cassert>

using namespace std ;

#define eps 1e-10
#define ll long long
#define ld long double
#define ull unsigned long long
#define REP(i,k,n) for(int i=k;i<n;i++)
#define REV(i,k,n) for(int i=k;i>=n;i--)
#define SZ(x) ((int)x.size())
#define DB(x) { cerr << #x << " = " << x << endl ; }
#define mp make_pair
#define CLR(v,c) memset(v,c,sizeof (v))
typedef pair <ll,ll> pll;

#define INF (1LL << 61)
ll max (ll a,ll b) { return a > b ? a : b ; }

const int NN = 250009 ;

//#define ROOM_311
int main () {
	#ifdef ROOM_311
        time_t et_0 = clock();
		freopen ("in.in","r",stdin) ;
	#endif
		int n ; cin >> n ;
		int c = n / 2 ; 
		c = (c * ( c + 1 )) ; 
		if (!(n & 1)) c -= n / 2 ; 
		cout << c << endl ;
		REP (i,2,n + 1) {
			for (int j = i - 1 ; j >= 1 ; j -= 2) 
				cout << i << ' ' << j << endl ;
		}
	#ifdef ROOM_311
        time_t et_1 = clock();
        fprintf(stderr, "Execution time = %0.3lf s\n", (double)(et_1 - et_0)  / CLOCKS_PER_SEC);
	#endif
	return 0 ;
}