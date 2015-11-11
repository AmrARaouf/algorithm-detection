//Language: GNU C++


#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <cassert>
#include <cstring>
#include <ctime>
#include <cmath>

#define pairII pair<int, int> 
#define VP vector<pairII > 
#define VL vector<long long>
#define VVL vector<VL >
#define VD vector<double>
#define VVD vector<VD >
#define VI vector<int>
#define VVI vector<VI >
#define VVVI vector<VVI >
#define VB vector<bool>
#define VVB vector<VB >
#define forN(i, n) for (int i = 0; i < n; ++i)
#define rforN(i, n) for (int i = n; i >= 0; --i)
#define forR(i, l, r) for (int i = l; i <= r; ++i)
#define rforR(i, r, l) for (int i = r; i >= l; --i)
#define forV(i, Vec, type) for (type::iterator (i) = (Vec).begin(); (i) < (Vec).end(); ++(i))
#define rforV(i, Vec, type) for (type::reverse_iterator (i) = (Vec).rbegin(); (i) < (Vec).rend(); ++(i))
#define INF 1e9
#define pb push_back
#define mp make_pair
#define min3(a, b, c) min( (a), min ( (b), (c) ))
#define PI = acos(-1.0)

using namespace std;     

int main() {
//	freopen ("in.txt", "r", stdin);
//	freopen ("out.txt", "w", stdout);
	
	int n, ans = 0;
	cin >> n;
	cout << (((n + 1) / 2) * (n / 2)) << endl;
	forR (u, 1, n / 2)
		forR (v, n / 2 + 1, n)
			cout << u << ' ' << v << endl;
	return 0;
}



