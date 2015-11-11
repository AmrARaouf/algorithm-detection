//Language: MS C++


// In the Name Of God

#include <iostream>
#include <fstream>

#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

#define inf (int)(~0u/2)
#define ll_inf (int)1 << 62
#define int long long
#define float long double
#define eps (1e-8)
#define for2(i, a, b) for ( int (i) = (a); (i)<(b); (i)++ )
#define mp make_pair
#define f1 first
#define f2 second
#define pb push_back
#define sz(a) (int) a.size( )
#define fillArr(n, a) for2(i, 0, n) cin >> a[i];
#define print(a) cout << #a << endl;

using namespace std;

const int maxn = 3e5+10;
int sum[maxn];

int a[maxn], b[maxn];
vector <int> ans;
vector <int> cost;
void main ( ){
	int n, m;
	cin >> n >> m;
	for2 ( i, 0, m ){
		int a, b;
		cin >> a >> b;
		cost.push_back ( b );
	}
	sort ( cost.rbegin( ), cost.rend( ) );
	for ( int i=m; i>=0; i-- ){
		if ( i * (i-1)/2 <= n-1 && i * (i / 2) <= n ){
			int sum = 0;
			for2 ( j, 0, i ){
				sum += cost[j];
			}
			cout << sum << endl;
			return;
		}
	}
}	
