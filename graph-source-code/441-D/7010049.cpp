//Language: MS C++


#include <iostream>
#include <algorithm>
#include <fstream>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <iomanip>

using namespace std;

#define rep(i,o,n) for (int i=o;i<=n;i++) 
#define rd cin >> 
#define w cout << 
#define wl cout << endl 
#define road pair<int,int>
//#define cin inf
//#define cout of
#define ll long long 
#define MOD 1000000000
#define N 3002

int a[N],f[N]={0},b[N];
vector<pair<int,int>> ans;
vector<int> v;

int main()
{
	ifstream inf("input.txt");
	//ofstream of("output.txt");
	int n,m;
	rd n;
	rep(i,1,n)
		rd a[i];
	rd m;
	rep(i,1,n)
		b[a[i]] = i;
	int k = 0;
	rep(i,1,n)
		if (!f[i])
		{
			k++;
			int g = b[i];
			int j = a[i];
			f[j] = 1;
			while (j!=i)
			{
				if (b[j]<g) g = b[j];
				j = a[j];
				f[j] = 1;
			}
			v.push_back(g);
		}
	int h = abs(k-(n-m));
	w h << endl;
	sort(v.begin(),v.end());
	if (k<(n-m))
	{
		rep(i,1,n)
			while (a[i]!=i)
			{
				//w i << a[i];
				int u = a[i];
				int g = 4000;
				int j = a[u];
				while (j!=u)
				{
					if (b[j]<g) g = b[j];
					j = a[j];
				}
				ans.push_back(make_pair(i,g));
				//w i << ' ' << g << endl;
				swap(a[i],a[g]);
				b[a[i]] = i;
				b[a[g]] = g;

			}
	}
	else if (k>(n-m))
	{
		int l = v.size();
		rep(i,1,l-1)
		{
			ans.push_back(make_pair(v[0],v[i]));
		}
	}
	//sort(ans.begin(),ans.end());
	rep(i,0,h-1)
		w ans[i].first << ' ' << ans[i].second << ' ';
}