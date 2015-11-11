//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <string>
#include <numeric>
#include <functional>
#include <iterator>
#include <typeinfo>
#include <utility>
#include <memory>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstddef>
#include <complex>
#include <ctime>
#include <cassert>
using namespace std;

typedef long long int64;
const int inf = 2000000000;
static inline int Rint()
{
	struct X{ int dig[256]; X(){
	for(int i = '0'; i <= '9'; ++i) dig[i] = 1; dig['-'] = 1;
	}};
	static 	X fuck;int s = 1, v = 0, c;
	for (;!fuck.dig[c = getchar()];);
	if (c == '-') s = 0; else if (fuck.dig[c]) v = c ^ 48;
	for (;fuck.dig[c = getchar()]; v = v * 10 + (c ^ 48));
	return s ? v : -v;
}
typedef vector<int> vi;
typedef vi::iterator ivi;
typedef map<int, int> mii;
typedef mii::iterator imii;
typedef set<int> si;
typedef si::iterator isi;

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define rep(i, s, e) for (int i = (s); i < (e); ++i)
#define foreach(itr, c) for(__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); ++itr)
template<typename T> static inline void cmax(T& a, const T& b){if(b>a)a=b;}
template<typename T> static inline void cmin(T& a, const T& b){if(b<a)a=b;}

int data[3005];
int where[3005];
int flag[3005];
int main()
{
	int n = Rint();
	rep(i, 1, n + 1) data[i] = Rint();
	rep(i, 1, n + 1) where[data[i]] = i;
	memset(flag, 0, sizeof flag);
	int m = Rint();
	int total = 0;
	vector<vi> them;
	for (int i = 1; i <= n; ++i) if (flag[i] == 0)
	{
		vi temp;
		temp.pb(i);
		flag[i] = 1;
		for (int who = data[i]; who != i; who = data[who])
		{
			flag[who] = 1;
			temp.pb(who);
		}
		them.pb(temp);
		total += temp.size() - 1;
	}
	vector<pair<int, int> > ans;
	int need = abs(total-m);
	if (m <= total)
	{
		for (int i = 1; m <= total && i <= n; ++i)
		while (m <= total && data[i] != i)
		{
			int next = data[i];
			int lpos = 5000;
			while (next != i)
			{
				if (next < lpos) lpos = next;
				next = data[next];
			}
			--total;
			swap(data[i], data[lpos]);
			ans.pb(mp(i, lpos));
		}
	}
	else
	{
		for (int i = 1; i < them.size(); ++i)
		{
			ans.pb(mp(them[0][0], them[i][0]));
		}
	}
	printf("%d\n", need);
	
	for (int i = 0; i < need; ++i)
	{
		if (i) putchar(' ');
		printf("%d %d", ans[i].first, ans[i].second);
	}
	puts("");
	return 0;
}
