//Language: GNU C++11


#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>

using namespace std;

//DEFINES BEGIN
#define mt make_tuple 
#define mp make_pair
#define ALL(a) a.begin(), a.end()
#define sz(a) (int)a.size()
#define y1 _y1_
#define prev _prev_
//DEFINES END

//TYPEDEFS BEGIN
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;
//TYPEDEFS END

//CONSTANTS BEGIN
const ldb PI = acos(-1.0), EPS = 1E-30;
const int INF = 1000 * 1000 * 1000 + 1234;
const ll LL_INF = 1LL * INF * INF;
const int MAXN = 10 * 1000 * 1000 + 1000;
//CONSTANTS END

//INITIALIZATION BEGIN
int n, m;
map<int, vector<int> > bad;
//INITIALIZATION END

//FUNCTIONS BEGIN
//FUNCTIONS END

int main()
{
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		--a, --b;
		bad[a].push_back(b);
		bad[b].push_back(a);
	}
	for (int i = 0; i < n; ++i)
	{
		if (bad[i].empty())
		{
			cout << n - 1 << '\n';
			for (int j = 0; j < n; ++j)
				if (i != j)
					cout << i + 1 << ' ' << j + 1 << '\n';
			break;
		}
	}
	return 0;
}