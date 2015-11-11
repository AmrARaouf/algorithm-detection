//Language: GNU C++0x


// In the name of God
#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <queue>
#include <utility>
#include <vector>


using namespace std;


typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> point;

#define siz(x) (int(x.size()))
#define err(x) cerr << #x << " = " << x << endl;

#define X first
#define Y second
// #define X real()
// #define Y imag()

const double eps = 1e-8;

const int maxn = 100 * 1000 + 1;
int f[maxn + 1];
vector<int> adj[maxn + 1];
vector<bool> rep[maxn + 1];
vector<int> ans;
bool DFS(int id, int par, bool is) {
    // cerr << id << " " << par << " " << is << endl;
    // if (siz(adj[id]) == 1 && adj[id][0] == par && is)
	// ans.push_back(id + 1);
    bool flag = false;
    for (int i  = 0; i < siz(adj[id]); i++) {
	if (adj[id][i] == par)
	    continue;
	bool t = DFS(adj[id][i], id, rep[id][i]);
	if (t) {
	    flag = true;
	}
    }
    if (is && !flag)
	ans.push_back(id + 1), flag = true;
    return flag;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
	int x, y, t;
	cin >> x >> y >> t;
	x--, y--;
	adj[x].push_back(y);
	adj[y].push_back(x);
	// cerr << "XL " << x << " " << y << endl;
	rep[x].push_back(t - 1);
	rep[y].push_back(t - 1);
    }

    DFS(0, -1, false);
    cout << siz(ans) << endl;
    // if (siz(ans) == 0)
	// return 0;
    for (int i = 0; i < siz(ans); i++) {
	cout << (i ? " " : "") << ans[i];

    }
    cout << endl;


    return 0;
}
