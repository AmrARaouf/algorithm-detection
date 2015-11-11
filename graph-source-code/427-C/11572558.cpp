//Language: GNU C++


#include <bits/stdc++.h>

using namespace std;

#define ll long long int

vector<vector<ll> > V(100010),RV(100010),SCC;
vector<ll> stack1,stack2;
ll visited[100010]={};

void DFS1(ll x)
{
	visited[x]=1;
	ll i;
	for(i=0;i<V[x].size();i++)
		if(visited[V[x][i]]==0)
			DFS1(V[x][i]);
	stack1.push_back(x);
}

void DFS2(ll x)
{
	visited[x]=1;
	ll i;
	for(i=0;i<RV[x].size();i++)
		if(visited[RV[x][i]]==0)
			DFS2(RV[x][i]);
	stack2.push_back(x);
}

void reversegraph(ll n)
{
	ll i,j;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<V[i].size();j++)
			RV[V[i][j]].push_back(i);
	}
}

int main()
{
	ll n,m,i,j,k,a,b;
	cin>>n;
	ll Cost[n+1];
	for(i=1;i<=n;i++)
		cin>>Cost[i];
	cin>>m;
	for(i=0;i<m;i++)
	{
		cin>>a>>b;
		V[a].push_back(b);
	}
	for(i=1;i<=n;i++)
	{
		if(visited[i]==0)
			DFS1(i);
	}
	a=stack1.size()-1;
	// for(i=a;i>=0;i--)
	// 	cout<<stack1[i]<<" ";
	// cout<<endl;
	reversegraph(n);
	for(i=0;i<100010;i++)
		visited[i]=0;
	for(i=a;i>=0;i--)
	{
		if(visited[stack1[i]]==0)
			{
				DFS2(stack1[i]);
				//cout<<stack1[i]<<" "<<stack2.size()<<endl;
				SCC.push_back(stack2);
				stack2.clear();
			}
	}
	a=SCC.size();
	ll ans1=0,ans2=1;
	for(i=0;i<a;i++)
	{
		ll val=10e10,cnt=0;
		b=SCC[i].size();
		for(j=0;j<b;j++)
			val=min(val,Cost[SCC[i][j]]);
		for(j=0;j<b;j++)
			if(Cost[SCC[i][j]]==val)
				cnt++;
		ans1+=val;
		ans2=(ans2*(cnt%1000000007))%1000000007;
	}
	cout<<ans1<<" "<<ans2<<endl;
	return 0;
}