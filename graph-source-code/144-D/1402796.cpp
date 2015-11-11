//Language: GNU C++


#include <cstdio>
#include <cstring>
#define FORE(it,a) for (it = a.begin(); it != a.end(); it++)
#define FOR(i,start,end) for (i = (start); i < (end); i++)
#define FORR(i,start,end) for (i = (start); i <= (end); i++)
#define RFOR(i,start,end) for (i = (end) - 1; i >= (start); i--)
#define RFORR(i,start,end) for (i = (end); i >= (start); i--)
#include <algorithm>
#include <map>
#include <set>
bool strlt(const char* s1, const char* s2) { return strcmp(s1, s2) < 0; }
bool strgt(const char* s1, const char* s2) { return strcmp(s1, s2) > 0; }
#define SORT(a, n) std::sort(a, a + n)
#define USORT(a, n, p) std::sort(a, a + n, p)
#define SSORT(a, n) USORT(a, n, strlt)
#define SORTN(a, count, n) std::partial_sort(a, a + n, a + count)
#define USORTN(a, count, n) std::partial_sort(a, a + n, a + count, p)
#define REVERSE(a, n) std::reverse(a, a + n)
#define RSORT(a, n) SORT(a, n); REVERSE(a, n)
#define SRSORT(a, n) USORT(a, n, strgt)
#define UNIQUE(a, n) (std::unique_copy(a, a + n, a) - (a))
#define BLT(a, n, what) (std::lower_bound(a, a + n, what) - (a))
#define BGT(a, n, what) (std::upper_bound(a, a + n, what) - (a))
struct side
{
	int a, b, w;
	void p() { }//printf("%d %d\n", a, b); }
};
typedef std::map<int, side> row;
typedef row::iterator rowit;
typedef std::map<int, row> graph;
typedef std::map<int, int> use;
typedef std::multimap<int, side> vect;
graph g;
use u;
vect v;
int i, j, k, n, m, s, a1, a2, w, r, res;
int main()
{
	scanf("%d%d%d", &n, &m, &s, &r);
	FOR (i, 0, m)
	{
		scanf("%d%d%d", &a1, &a2, &w);
		g[a1][a2].a = a1;
		g[a1][a2].b = a2;
		g[a1][a2].w = w;
		g[a2][a1].a = a2;
		g[a2][a1].b = a1;
		g[a2][a1].w = w;
	}
	scanf("%d", &r);
	if (r == 0)
	{
		printf("1\n");
		return 0;
	}
	res = 0;
	u[s] = 0;
	rowit it;
	FORE (it, g[s]) v.insert(std::pair<int, side>(it->second.w, it->second));
	while (!v.empty())
	{
		vect::iterator beg = v.begin();
		beg = v.begin();
		std::pair<int, side> p = *beg;
		side sd = p.second;
		v.erase(beg);
		if (!g[sd.a].count(sd.b)) continue;
		g[sd.a].erase(sd.b);
		g[sd.b].erase(sd.a);
		int ss = p.first;
		if (u.count(sd.b))
		{
			if (ss > r)
			{
				int s2 = u[sd.a] + u[sd.b] + sd.w - r * 2;
				if (s2 == 0) res++;
				if (s2 > 0) res += 1 + (u[sd.b] < r);
			}
			continue;
		}
		u[sd.b] = ss;
		if (ss >= r)
		{
			res++;
			continue;
		}
		FORE (it, g[sd.b]) if (it->second.b != sd.a) v.insert(std::pair<int, side>(ss + it->second.w, it->second));
	}
	printf("%d\n", res);
	return 0;
}
