//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <ctime>
#include <cassert>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cstdlib>
#include <cstring>

using namespace std;

#ifdef WIN32
	#define lld "%I64d"
#else
	#define lld "%lld"
#endif

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int M = 1e3 + 100;
const int Q = 1e9 + 7;

char s[M];
int a[M][M];
int used[M * M], dp[M * M];
vector<int> g[M * M];
int n, m;
bool ok;
int ans;

int re(int i, int j){
	return (i - 1) * m + j;
}
void dfs(int i){
	used[i] = 1;
	for (int j = 0; j < (int)g[i].size(); j++){
		if (used[g[i][j]] == 1) 
			ok = true;
		if (!used[g[i][j]])
			dfs(g[i][j]);
	}
	used[i] = 2;
	dp[i] = -1;
	for (int j = 0; j < (int)g[i].size(); j++)
		if (dp[g[i][j]] != -1)
			dp[i] = max(dp[i], dp[g[i][j]] + 1);
	int t;
	if (i % m == 0)
		t = m;
	else
		t = i % m;
	if (dp[i] == -1 && a[(i - 1) / m + 1][t] == 3) 
		dp[i] = 1;
	if (a[(i - 1) / m + 1][t] == 0 && dp[i] != -1){
		ans = max(ans, dp[i] / 4);
	}
	
}
int main(){
	srand(time(NULL));
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int i, j, x0, y0;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n + 3; i++)
		for (j = 0; j < m + 3; j++)
			a[i][j] = 1050;
	for (i = 1; i <= n; i++){
		scanf("%s", s);
		for (j = 0; j < m; j++){
			if (s[j] == 'D')
				a[i][j + 1] = 0;
			if (s[j] == 'I')
				a[i][j + 1] = 1;
			if (s[j] == 'M')
				a[i][j + 1] = 2;
			if (s[j] == 'A')
				a[i][j + 1] = 3;	
		}
	}
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++){
			if ((a[i][j] + 1) % 4 == a[i + 1][j])
				g[re(i, j)].pb(re(i + 1, j));
			if ((a[i][j] + 1) % 4 == a[i + -1][j])
				g[re(i, j)].pb(re(i + -1, j));     	
		   	if ((a[i][j] + 1) % 4 == a[i][j + 1])
				g[re(i, j)].pb(re(i, j + 1));
			if ((a[i][j] + 1) % 4 == a[i][j + -1])
				g[re(i, j)].pb(re(i, j + -1));
		
		}
	ans = 0;
	for (i = 1; i <= n * m; i++){
		if (!used[i]){
			ok = false;
			dfs(i);
			if (ok){
				cout << "Poor Inna!";
				return 0;
			}      
		}
	}
	if (ans)
		printf("%d", ans);
	else
		printf("Poor Dima!");
	return 0; 

}