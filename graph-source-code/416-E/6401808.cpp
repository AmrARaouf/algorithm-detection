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
#define mp make_pair

const int maxN = 501;
const int inf = 1e9;

int a[maxN][maxN], b[maxN][maxN], ans[maxN][maxN];
int n, m;

//-------------------------------------------------------------------------------------------------

int main() {

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] = i == j ? 0 : inf;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		a[x][y] = a[y][x] = z;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			b[i][j] = a[i][j];

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
	//cout << a[1][2] << endl;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			//if (a[i][j] == inf)
			//	continue;
			int cur = 0;
			for (int k = 1; k <= n; k++)
				if (k != j && a[i][k] + b[k][j] == a[i][j])
					cur++;
			for (int k = i + 1; k <= n; k++)
				if (a[i][k] != inf && a[k][j] != inf && a[i][j] + a[k][j] == a[i][k]) {
					ans[i][k] += cur;
				//	cout << i << ' ' << k << ' ' << j << endl;
				}
		}

	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			printf("%d ", ans[i][j]);
	
	return 0;
}