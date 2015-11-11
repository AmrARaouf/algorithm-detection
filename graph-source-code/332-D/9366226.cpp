//Language: GNU C++


/*
	Time : 1358Z 20150105
	Task : Codeforces 332D
	Tags : Math
	Stat : Coding
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <map>
#include <set>
#include <cmath>
#include <numeric>

#define fi first
#define se second
#define fo(i,a,b) for (int i = a; i <= b; i ++)
#define fd(i,a,b) for (int i = a; i >= b; i --)
#define fe(i,x,y) for (int i = x, y = lnk[i]; i; i = nxt[i], y = lnk[i])
#define mkp make_pair
#define pb push_back
#define Fill(x,y) memset(x,y,sizeof(x))
#define Cpy(x,y) memcpy(x,y,sizeof(x))
#define Bit(x,y) ((((x) >> (y)) & 1))
#define mit map<int,SI>::iterator
#define sit SI::iterator

using namespace std;
 
typedef long long LL;
typedef long double LD;
typedef pair <double, double> PD;
typedef pair <LL, LL> PLI;
typedef pair <PD, int> PDI;
typedef pair <int, int> PI;
typedef pair <int, PI> PII;
typedef pair <PI, PI> PIII;
typedef set <PI> SI;
typedef vector <int> VI;
 
int Read()
{
    char c; while (c = getchar(), (c != '-') && (c < '0' || c > '9'));
    bool neg = (c == '-'); int ret = (neg ? 0 : c - 48);
    while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + c - 48;
    return neg ? -ret : ret;
}

const int MAXN = 2005;

int N, K;
LL sum, deg[MAXN], s[MAXN];

int main()
{
	scanf("%d%d", &N, &K);
	fo (i, 1, N)
		fo (j, i + 1, N)
		{
			int x = Read();
			if (x >= 0) sum += x, deg[i] ++, deg[j] ++, s[i] += x, s[j] += x;
		}
	if (K != 2) cout << 2 * sum / N << endl;
	else
	{
		sum = 0;
		fo (i, 1, N) sum += s[i] * (deg[i] - 1);
		cout << 2 * sum / N / (N - 1) << endl;
	}
	return 0.0;
}
