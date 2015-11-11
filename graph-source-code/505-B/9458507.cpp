//Language: GNU C++


#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n,m,q,ans,ma,x,y,z,u[105];
vector< pair<int,int> > r[105];
int dfs(int t,int c)
{
	if (t==y) return 1;
	int i,j,f,s;
	u[t]=1;
	for (i=0;i<r[t].size();i=i+1)
	{
		f=r[t][i].first;
		s=r[t][i].second;
		if (!u[f] && c==s) if (dfs(f,c)) return 1;
	}
	return 0;
}
int main()
{
	int i,j;
	cin>>n>>m;
	for (i=1;i<=m;i=i+1)
	{
		cin>>x>>y>>z;
		r[x].push_back(make_pair(y,z));
		r[y].push_back(make_pair(x,z));
		if (z>ma) ma=z;
	}
	cin>>q;
	while (q--)
	{
		cin>>x>>y;
		ans=0;
		for (i=1;i<=ma;i=i+1)
		{
			memset(u,0,sizeof(u));
			if (dfs(x,i)) ans=ans+1; 
		}
		cout<<ans<<endl;
	}
	return 0;
}
