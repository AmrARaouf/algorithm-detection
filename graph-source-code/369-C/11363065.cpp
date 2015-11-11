//Language: GNU C++11


#include<iostream>
#include<vector>

using namespace std;

#define f first
#define s second;

const int MAXN=100000+100;
vector<int> ans;
vector< pair<int,int> > N[MAXN];
int dp[MAXN];//problem roads in subtree
bool mark[MAXN];

void dfs(int v,int par)
{
	dp[v]=0;
	for(int i=0;i<N[v].size();i++)
		if(N[v][i].f!=par)
		{
			dp[v]+=N[v][i].s;
			dfs(N[v][i].f,v);
			dp[v]+=dp[ N[v][i].f ];
		}
}

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int x,y,t;
		cin>>x>>y>>t;
		if(t==2)
		{
			mark[x]=1;
			mark[y]=1;
		}
		N[x].push_back( make_pair(y,t-1) );
		N[y].push_back( make_pair(x,t-1) );
	}
	dfs(1,0);
//	for(int i=1;i<=n;i++)
//		cout<<i<<":"<<dp[i]<<endl;
	for(int i=1;i<=n;i++)
		if(dp[i]==0 && mark[i]==1)
			ans.push_back(i);
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	cout<<endl;
}
