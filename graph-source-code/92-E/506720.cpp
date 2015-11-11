//Language: GNU C++


#include <iomanip>
#include <algorithm>
#include <map>
#include <fstream>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <set>

#include <time.h>
#include <sys/time.h>

#define MODULO 1000000009

using namespace std;

int a[100100];

int Pred(int x)
{
	int y = x;
	while (a[y] != y) y = a[y];
	while (a[x] != y)
	{
		int c = a[x];
		a[x] = y;
		x = c;
	}
	return y;
};

int main()
{
//	freopen("anarc05b.in","r",stdin);
//	freopen("anarc05b.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int ans = 1;

	for (int i = 0; i < n; i++)
		a[i] = i;

	for (int i = 0; i < m; i++)
	{
		int q,w;
		scanf("%d%d",&q,&w);
		q--; w--;
		int p1 = Pred(q);
		int p2 = Pred(w);

		if (p1 != p2) a[p1] = p2;
		else ans = (ans * 2) % MODULO;
		
		printf("%d\n",ans - 1);
	}
//	in.getline(s);

	return 0;	
}
