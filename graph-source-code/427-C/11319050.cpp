//Language: GNU C++11


#include<iostream>
#include<vector>
#include<stack>
#include<string.h>
using namespace std;

typedef long long i64;
typedef vector<int> vi;

vi graph[100005];
stack<int> stck;
bool inStack[100005];
int low[100005],disc[100005],dfsTime=-1,nComps=0,comps[100005],cost[100005];

void tarjan(int u)
{
	low[u]=disc[u]=++dfsTime;
	stck.push(u);
	inStack[u]=true;
	for(int i=0;i<graph[u].size();i++)
	{
		int v=graph[u][i];
		if(disc[v]==-1) tarjan(v),low[u]=min(low[u],low[v]);
		else if(inStack[v]) low[u]=min(low[u],disc[v]);
	}
	if(disc[u]==low[u])
	{
		nComps++;
		int v=-1;	
		while(1)
		{
			v=stck.top();
			stck.pop();
			inStack[v]=false;
			comps[v]=nComps;
			if(v==u)
				break;
		}
	}
}

int main()
{
	int n,m,a,b;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>cost[i];
	cin>>m;
	for(int i=0;i<m;i++)
		{
			cin>>a>>b;
			graph[a-1].push_back(b-1);
		}
	memset(disc,-1,sizeof(disc));
	for(int i=0;i<n;i++)
	{
		if(disc[i]==-1)
			tarjan(i);
	}
	
	/*
for(int i=0;i<n;i++)
	{
		cout<<i<<" "<<comps[i]<<endl;
	}
	cout<<endl;*/	
	int minCost[100005],minCount[100005];
	for(int i=1;i<=nComps;i++)
		minCost[i]=1000000009;
	for(int i=0;i<n;i++)
	{
		if(minCost[comps[i]]==cost[i])
		{
			minCount[comps[i]]+=1;
		}
		else if(cost[i]<minCost[comps[i]])
		{
			minCost[comps[i]]=cost[i];
			minCount[comps[i]]=1;
		}
		//cout<<"minCost["<<comps[i]<<"]="<<minCost[comps[i]]<<"   i="<<i<<endl;
	}
	i64 finalCost=minCost[1],finalCount=minCount[1];
	for(int i=2;i<=nComps;i++)
		{
			finalCost+=minCost[i];
			finalCount=((long long)finalCount*minCount[i])%1000000007;
		}
	cout<<finalCost<<" "<<finalCount;
	return 0;
}