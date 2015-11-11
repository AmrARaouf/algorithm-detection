//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define f first
#define s second
#define next qwertyusdfgh
#define read(x) scanf("%d", &x)
#define write(x) printf("%d ", x)
#define writeln(x) printf("%d\n", x)
#define pb push_back

const int maxN = 200002;

int d[maxN];
vector<int> v[maxN];
int a[maxN], b[maxN];
int n, k, m;

//-------------------------------------------------------------------------------------------------

void no() {
	cout << -1;
	exit(0);
}

int main() {

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> d[i];
		v[d[i]].pb(i);
	}
	int ls = 0;
	if (v[0].size() != 1)
		no();

	for (int i = 0; i < n; i++) {
		if (ls + v[i].size() == n)
			break;
		if (v[i].size() == 0)
			no();
		int cur = 0;
		int y = 0;
		if (i > 0)
			y++;
		for (int j = 0; j < v[i].size(); j++) {
			int x = v[i][j];
			for (int t = 0; t < k - y; t++)
				if (cur < v[i + 1].size()) {
					//add(x, v[i + 1][cur]);
					a[m] = x;
					b[m++] = v[i + 1][cur];
					cur++;
				}
				else
					break;
			if (cur == v[i + 1].size())
				break;
		}
		if (cur < v[i + 1].size())
			no();
		ls += v[i].size();
	}

	printf("%d\n", m);
	for (int i = 0; i < m; i++)
		printf("%d %d\n", a[i], b[i]);
	
	return 0;
}