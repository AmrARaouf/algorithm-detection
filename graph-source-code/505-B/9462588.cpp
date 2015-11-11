//Language: GNU C++



#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
typedef long long ll;
using namespace std;
vector <int> w;
vector <pair<int,int> > v[5000];
int visited[500];
bool check;
void dfs(int s,int target,int l)
{
	visited[s]=1;
	if (s==target)
	{
		check=true;
		return;
	}
	for (int i=0;i<v[s].size();i++)
		if (!visited[v[s][i].ff] && v[s][i].ss==l)
			dfs(v[s][i].ff,target,l);
}
int main() 
{
	int n,m; cin>>n>>m;
	for (int i=0;i<m;i++)
	{
		int q,w,e; cin>>q>>w>>e;
		v[q].pb(mp(w,e));
		v[w].pb(mp(q,e));
	}
	int q; cin>>q;
	for (int i=0;i<q;i++)
	{
		int o,p; cin>>o>>p;
		int ans=0;
		for (int j=0;j<=m;j++)
		{
			for (int j=0;j<=100;j++)
				visited[j]=0;
			check=false;
			dfs(o,p,j);
			if (check)
				ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
	
	