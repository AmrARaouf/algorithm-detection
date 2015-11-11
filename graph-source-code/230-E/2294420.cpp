//Language: GNU C++


using namespace std;

#include <cmath>
#include <cctype>
#include <cstdio>
#include <climits>
#include <cstring>

#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
#include <bitset>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>

#define  D(x)             cout << #x " = " << (x) << endl;
#define  foreach(it, c)   for(typeof((c).begin()) it = (c).begin(); it!=(c).end(); ++it)
#define  foreachr(it, c)  for(typeof((c).rbegin()) it = (c).rbegin(); it!=(c).rend(); ++it)
#define  EPS              1e-9
#define  PI               acos(-1)

typedef unsigned long long int ull;
typedef long long int ll;
typedef stringstream ss;

inline int cmp(double x, double y=0, double tol=EPS) {
       return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


ull n_graph, n_alice;
ull degree[1000005];

int main() {
	//freopen("input.txt", "r", stdin);

    scanf("%I64d %I64d", &n_graph, &n_alice);

	int u, v;
	register int i;
	for(i = n_alice; i; --i) {
        scanf("%d %d", &u, &v);

        ++degree[u];
        ++degree[v];
	}


    ull n_taken = 0;
	for(i = n_graph; i; --i) // {
	    // cout << i << " " << degree[i] << endl;
        n_taken += degree[i] * (n_graph - degree[i] - 1);
	// } cout << endl;

    cout << (n_graph * (n_graph - 1) * (n_graph - 2) / 6 - n_taken / 2) << endl;

    //while(1);

    return 0;
}
