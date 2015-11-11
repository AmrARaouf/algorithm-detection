//Language: GNU C++


#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>
#include <cmath>
#include <set>
#include <map>
#include <sstream>

using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define sqr(x) ((x)*(x))

typedef long long ll;
typedef pair <int, int> pie;

#define index shit

const int maxN = 100 * 1000 + 100;

int n, f[maxN];
vector <int> a[maxN];
vector <pie> b;
int index = 1;

void dfs (int x, int edge) {
	f[x] = 1;
	for (int i = 0; i < a[x].size(); i++) {
		int u = a[x][i];
		if (!f[u]) {
			cout << 2 << ' ' << x + 1 << ' ' << u + 1 << endl;
			if (edge != -1) {
				b.push_back (pie (index, edge));
			}
			index++;
			dfs (u, index - 1);
		}
	}
}

int main() {
	ios::sync_with_stdio (false);

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y; cin >> x >> y; x--; y--;
		a[x].push_back (y);
		a[y].push_back (x);
	}

	cout << n - 1 << endl;
	for (int i = 0; i < n; i++) {
		if (a[i].size() == 1) {
			dfs (i, -1);
			break;
		}
	}
	for (int i = 0; i < n - 2; i++)
		cout << b[i].ff << ' ' << b[i].ss << endl;

	return 0;
}
