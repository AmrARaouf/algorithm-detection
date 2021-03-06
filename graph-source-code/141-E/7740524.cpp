//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <iomanip>
#include <ctime>

#define fname "" 
#define mk make_pair
#define pb push_back

#define f first
#define s second


using namespace std;

int n, m;
vector <pair <pair <int, int>, pair <int, int> > >  g;
vector <int> res;
int p[200000];
int x, y;
char c;

int find(int x)
{
 	if (x == p[x]) return x; else return p[x] = find(p[x]);
}
int main() {
	
	cin >> n >> m;
	if (n % 2 == 0)
	{
	 	cout << -1;
	 	return 0;
	}
	srand(time(0));
	for (int i = 1; i <= m; i++)
	{
	 	cin >> x >> y >> c;
	 	g.pb(mk(mk(c == 'S',i), mk(x, y)));
	}

	sort(g.begin(), g.end());
	reverse(g.begin(), g.end());

	for (int i = 1; i <= n; i++)
	p[i] = i;

	for (int i = 0; i < g.size(); i++)
	{
	 	x = find(g[i].s.f);
	 	y = find(g[i].s.s);
	 	if (x != y)
	 	{
	 	 	if (rand() % 2)
	 	 		swap(x, y);
	 	 	p[x] = y;
	    	if (g[i].f.f == 0)
	    		g[i].f.f = -1;
	 	}
	}

	for (int i = 1; i <= n; i++)
	p[i] = i;
	
	int cnt1 = 0, cnt2 = 0;

	sort(g.begin(), g.end());

	for (int i = 0; i < g.size(); i++)
	{
	 	x = find(g[i].s.f);
	 	y = find(g[i].s.s);
	 	if (x == y) continue;
	 	if (cnt1 < (n - 1) / 2 || g[i].f.f > 0)
	 	{
	 	 	if (rand() % 2)
	 	 		swap(x, y);
	 	 	p[x] = y;
	     	if (g[i].f.f <= 0)
	     		cnt1++;
	     	else
	     		cnt2++;
	     	res.pb(g[i].f.s);
	 	}
	}

	
	if (cnt1 != (n - 1) / 2 || cnt1 != cnt2)
	{
	 	cout << -1;
	 	return 0;
	}

	cout << n - 1 << endl;

    for (int i = 0; i < res.size(); i++)
	cout <<res[i] << " ";
	return 0;
}