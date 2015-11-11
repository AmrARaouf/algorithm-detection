//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

#define openfile { freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);}
#define debug 0

int n, m;
int a[1001];

int main()
{
	if (debug) openfile;
	cin>>n>>m;
	for (int i=0; i<m; i++)
	{
		int x, y;
		cin>>x>>y;
		a[x]++;
		a[y]++;
	}
	cout<<n-1<<endl;
	int res = 0;
	for (int i=1; i<=n; i++)
		if (a[i] == 0)
		{
			res = i;
			break;
		}
	for (int i=1; i<=n; i++)
		if (i != res)
			cout<<i<<" "<<res<<endl;
	return 0;
}