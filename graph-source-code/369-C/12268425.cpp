//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ff first
#define ss second
#define write(x) freopen(x,"w",stdout);
#define read(x) freopen(x,"r",stdin);
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define sz(a) ((int)a.size())
#define fill(a,b) memset(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define debug(x) cout<<#x<<" = "<<x<<endl
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
inline bool eql(double a,double b){return fabs(a-b)<eps;}
int n;
vii g[100005];
vi ans;
bool mark[100005];
bool dfs(ii x)
{
	int u=x.ff,t=x.ss;
	mark[u]=true;
	bool p=false;
	for(int i=0;i<sz(g[u]);i++)
		if(!mark[g[u][i].ff])p|=dfs(g[u][i]);
	if(p)return true;;
	if(t==2)
	{
		ans.pb(u);
		return true;
	}
	return false;
}

int main(int argc,char** argv)
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n;cin>>n;
	int x,y,t;
	fill(mark,false);
	for(int i=1;i<n;i++)
	{
		cin>>x>>y>>t;
		g[x].pb(mp(y,t));
		g[y].pb(mp(x,t));
	}
	dfs(mp(1,1));
	cout<<sz(ans)<<endl;
	for(int i=0;i<sz(ans);i++)cout<<ans[i]<<' ';cout<<endl;
	return 0;
}