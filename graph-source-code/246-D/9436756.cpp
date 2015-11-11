//Language: GNU C++0x


#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define mem(a, b) memset(a, b, sizeof(a))
#define mp make_pair

const int oo = (int)1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;

int n,m;
int col[100005];
bool has[100005];
set<int> seen[100005];

int main()
{
	int n,m;
	cin >> n >> m;
	
	for(int i=1;i<=n;i++)
	{
		cin >> col[i];
		has[col[i]]=1;
	}
	
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin >> u >> v;
		if(col[u] != col[v])
		{
			seen[col[u]].insert(col[v]);
			seen[col[v]].insert(col[u]);
		}
	}

	int maxi = -1,ans;
	for(int i=1;i<=100000;i++) if(has[i])
	{
		int sz = seen[i].size();
		if(sz > maxi)
		{
			maxi = sz;
			ans = i;
		}
	}
	
	cout << ans << endl;
	return 0;
}
