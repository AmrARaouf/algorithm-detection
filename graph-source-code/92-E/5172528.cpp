//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <bitset>
#include <cmath>
#include <ctime>
using namespace std;

#define pb push_back
#define mp make_pair
const int inf = 1e9;
const long long INF = 1e18;
typedef long long LL;
typedef pair<int, int> PII;
int rd() { return RAND_MAX == 32767 ? ((rand() << 15) ^ rand()) : rand(); }
template <class T>
void Read_T(T &x)
{
	char ch;
	while ((ch = getchar()) && (ch < '0' || ch > '9'));
	x = ch-'0';
	while ((ch = getchar()) && ch >= '0' && ch <= '9') x = x*10+ch-'0';
}
template <class T>
void Read_S(T &x)
{
	char opt, ch = 1;
	while ((opt = ch) && (ch = getchar()) && (ch < '0' || ch > '9'));
	x = ch-'0';
	while ((ch = getchar()) && ch >= '0' && ch <= '9') x = x*10+ch-'0';
	if (opt == '-') x = -x;
}

const int maxn = 100010;
const int md = 1000000009;

int p[maxn];

int Find(int x)
{
	return p[x] == x ? x : p[x] = Find(p[x]);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) p[i] = i;
	int cnt = 1, res = 0;
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v); u--; v--;
		if (Find(u) == Find(v)) {
			res = (res+cnt) % md;
			cnt = (cnt+cnt) % md;
		}
		else p[p[u]] = p[v];
		printf("%d\n", res);
	}
	return 0;
}

