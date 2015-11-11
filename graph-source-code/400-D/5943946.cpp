//Language: GNU C++


#include <cstdio>
#include <algorithm>
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
using namespace std;
typedef long long ll;

inline void R(int &x) {
	char ch = getchar(); x = 0;
	for (; ch<'0'; ch=getchar());
	for (; ch>='0'; ch=getchar()) x = x*10+ch-'0';
}
const int N = 100005, inf = (1<<30)-1;
int n, m, k, t[N], f[N], d[505][505], c[505];
int find(int x) {return f[x]==f[f[x]] ? f[x] : (f[x]=find(f[x]));}
inline int min(int x, int y) {return x < y ? x : y;}
int main() {
	R(n); R(m); R(k);
	int x, y, z, cur = 0;
	c[0] = 0;
	for (int i=1; i<=k; ++i) {
		R(x);
		for (int j=1; j<=x; ++j)
			t[++cur] = i;
		c[i] = cur;
	}
	for (int i=1; i<=k; ++i)
		for (int j=1; j<=k; ++j)
			d[i][j] = inf;
	for (int i=1; i<=k; ++i) d[i][i] = 0;
	for (int i=1; i<=n; ++i) f[i] = i;
	for (int i=1; i<=m; ++i) {
		R(x); R(y); R(z);
		d[t[y]][t[x]] = d[t[x]][t[y]] = min(d[t[x]][t[y]], z);
		if (!z) 
			f[find(x)] = find(y);
	}
	int std;
	for (int i=1; i<=k; ++i) {
		std = find(c[i]);
		for (int j=c[i-1]+1; j<=c[i]; ++j)
			if (find(j) != std) {
				puts("No");
				return 0;
			}
	}
	for (int p=1; p<=k; ++p)
		for (int i=1; i<=k; ++i) if (i != p)
			for (int j=1; j<=k; ++j) if (j != p && j != i)
				d[i][j] = min(d[i][j], d[i][p] + d[p][j]);
	puts("Yes");
	for (int i=1; i<=k; ++i) {
		for (int j=1; j<=k; ++j)
			printf("%d ", d[i][j] < inf ? d[i][j] : -1);
		puts("");
	}
	return 0;
}