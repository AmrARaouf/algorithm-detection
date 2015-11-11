//Language: MS C++


#define _CRT_SECURE_NO_DEPRECATE 
#define _USE_MATH_DEFINES

#include <utility> 
#include <iostream> 
#include <cstdio> 
#include <cmath> 
#include <algorithm> 
#include <cstdlib> 
#include <string> 
#include <cstring> 
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>

using namespace std;

typedef long long int64;
#define INF 1234567890
#define prime 999979
#define FOR(a, b) for(int a = 0; a < b; ++a)
#define eps 1e-10

int n, res = 0;
bool wasX[1001], wasY[1001];
vector <vector <int> > X, Y;

void dfs(int s, char v)
{
	if (v == 'x')
	{
		wasX[s] = true;
		FOR(i, X[s].size())
			if (!wasY[X[s][i]]) dfs(X[s][i], 'y');
	}
	else
	{
		wasY[s] = true;
		FOR(i, Y[s].size())
			if (!wasX[Y[s][i]]) dfs(Y[s][i], 'x');
	}
}

int main()
{
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	scanf("%d\n", &n);
	X.resize(1002);
	Y.resize(1002);
	FOR(i, n)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		X[x].push_back(y);
		Y[y].push_back(x);
	}
	memset(wasX, false, sizeof wasX);
	memset(wasY, false, sizeof wasY);
	FOR(i, 1002)
		if (X[i].size() > 0 && !wasX[i]) 
			{
				++res;
				dfs(i, 'x');
			}
	FOR(i, 1002)
		if (Y[i].size() > 0 && !wasY[i]) 
			{
				++res;
				dfs(i, 'y');
			}
	cout << res - 1;
    return 0;
} 